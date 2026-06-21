// ==============================================
// FSAE PADDLE SHIFT CONTROLLER
// 3-position control + double-paddle neutral
// ==============================================

// -------- PINS --------
const int UP_PIN = 2;
const int DOWN_PIN = 3;
const int CLUTCH_PIN = 4;

const int RPWM_PIN = 9;
const int LPWM_PIN = 10;
const int FEEDBACK_PIN = A0;

// -------- POSITIONS --------
int FULL_RETRACT_POS = 33;
int FULL_EXTEND_POS  = 888;

int DOWNSHIFT_POS    = 292;
int NEUTRAL_POS      = 400;
int UPSHIFT_POS      = 508;
int NEUTRAL_SHIFT_POS = 454;   // half upstroke

// -------- TUNING --------
int MOVE_PWM_FAST = 255;
int MOVE_PWM_SLOW = 150;

int POS_TOL = 6;
int SLOW_BAND = 25;

int DWELL_TIME = 5;
int LOCKOUT_TIME = 300;
int DEBOUNCE_TIME = 25;

unsigned long MOVE_TIMEOUT = 2000;

// -------- DIRECTION --------
bool RPWM_INCREASES_POS = true;

// -------- STATE --------
bool lastUpReading = HIGH;
bool lastDownReading = HIGH;
bool lastBothReading = HIGH;

bool upState = HIGH;
bool downState = HIGH;
bool bothState = HIGH;

unsigned long lastUpChange = 0;
unsigned long lastDownChange = 0;
unsigned long lastBothChange = 0;

bool lockoutActive = false;
unsigned long lockoutStart = 0;

// ==============================================
// MOTOR
// ==============================================

void stopMotor() {
  analogWrite(RPWM_PIN, 0);
  analogWrite(LPWM_PIN, 0);
}

void driveRPWM(int pwmVal) {
  analogWrite(RPWM_PIN, pwmVal);
  analogWrite(LPWM_PIN, 0);
}

void driveLPWM(int pwmVal) {
  analogWrite(RPWM_PIN, 0);
  analogWrite(LPWM_PIN, pwmVal);
}

int readPosition() {
  return analogRead(FEEDBACK_PIN);
}

// ==============================================
// POSITION CONTROL
// ==============================================

void moveToPosition(int target) {
  unsigned long startTime = millis();
  int pos = readPosition();

  while (abs(pos - target) > POS_TOL) {
    pos = readPosition();

    if (millis() - startTime > MOVE_TIMEOUT) {
      stopMotor();
      Serial.println("Move timeout");
      return;
    }

    int pwmCmd = (abs(pos - target) > SLOW_BAND) ? MOVE_PWM_FAST : MOVE_PWM_SLOW;

    if (pos < target) {
      if (RPWM_INCREASES_POS) driveRPWM(pwmCmd);
      else driveLPWM(pwmCmd);
    } else {
      if (RPWM_INCREASES_POS) driveLPWM(pwmCmd);
      else driveRPWM(pwmCmd);
    }
  }

  stopMotor();
  delay(20);
}

void ensureNeutral() {
  if (abs(readPosition() - NEUTRAL_POS) > POS_TOL) {
    moveToPosition(NEUTRAL_POS);
  }
}

// ==============================================
// SHIFT CYCLES
// ==============================================

void doUpshiftCycle() {
  Serial.println("UP");
  ensureNeutral();
  moveToPosition(UPSHIFT_POS);
  delay(DWELL_TIME);
  moveToPosition(NEUTRAL_POS);
}

void doDownshiftCycle() {
  Serial.println("DOWN");
  ensureNeutral();
  moveToPosition(DOWNSHIFT_POS);
  delay(DWELL_TIME);
  moveToPosition(NEUTRAL_POS);
}

void doNeutralCycle() {
  Serial.println("NEUTRAL");
  ensureNeutral();
  moveToPosition(NEUTRAL_SHIFT_POS);
  delay(DWELL_TIME);
  moveToPosition(NEUTRAL_POS);
}

// ==============================================
// SETUP
// ==============================================

void setup() {
  pinMode(UP_PIN, INPUT_PULLUP);
  pinMode(DOWN_PIN, INPUT_PULLUP);
  pinMode(CLUTCH_PIN, INPUT_PULLUP);

  pinMode(RPWM_PIN, OUTPUT);
  pinMode(LPWM_PIN, OUTPUT);

  stopMotor();

  Serial.begin(115200);
  delay(300);

  Serial.println("Shift controller start");
  Serial.print("POS: ");
  Serial.println(readPosition());
}

// ==============================================
// LOOP
// ==============================================

void loop() {
  unsigned long now = millis();

  if (digitalRead(CLUTCH_PIN) == HIGH) {
    stopMotor();
    lockoutActive = false;
    return;
  }

  // keep original working behavior
  ensureNeutral();

  if (lockoutActive) {
    if (now - lockoutStart >= LOCKOUT_TIME) {
      lockoutActive = false;
    } else {
      return;
    }
  }

  bool upRaw = digitalRead(UP_PIN);
  bool downRaw = digitalRead(DOWN_PIN);
  bool bothRaw = (upRaw == LOW && downRaw == LOW) ? LOW : HIGH;

  // ---- BOTH PADDLES = NEUTRAL ----
  if (bothRaw != lastBothReading) {
    lastBothChange = now;
    lastBothReading = bothRaw;
  }

  if ((now - lastBothChange) > DEBOUNCE_TIME) {
    if (bothState != bothRaw) {
      bothState = bothRaw;

      if (bothState == LOW) {
        doNeutralCycle();
        lockoutActive = true;
        lockoutStart = millis();
        return;
      }
    }
  }

  if (bothRaw == LOW) {
    return;
  }

  // ---- UP ----
  if (upRaw != lastUpReading) {
    lastUpChange = now;
    lastUpReading = upRaw;
  }

  if ((now - lastUpChange) > DEBOUNCE_TIME) {
    if (upState != upRaw) {
      upState = upRaw;

      if (upState == LOW) {
        doUpshiftCycle();
        lockoutActive = true;
        lockoutStart = millis();
        return;
      }
    }
  }

  // ---- DOWN ----
  if (downRaw != lastDownReading) {
    lastDownChange = now;
    lastDownReading = downRaw;
  }

  if ((now - lastDownChange) > DEBOUNCE_TIME) {
    if (downState != downRaw) {
      downState = downRaw;

      if (downState == LOW) {
        doDownshiftCycle();
        lockoutActive = true;
        lockoutStart = millis();
        return;
      }
    }
  }
}