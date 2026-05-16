const int ledPin = 13;
unsigned long previousMillis = 0;
int sosState = 0; // 状态机的步骤，0-8对应SOS的每个阶段
const long shortOn = 200;
const long longOn = 600;
const long gap = 200;
const long sosPause = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  switch(sosState) {
    // 前三次短闪（S）
    case 0: case 2: case 4: // 亮的状态
      digitalWrite(ledPin, HIGH);
      if(currentMillis - previousMillis >= shortOn) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    case 1: case 3: case 5: // 灭的状态
      digitalWrite(ledPin, LOW);
      if(currentMillis - previousMillis >= gap) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    // 中间三次长闪（O）
    case 6: case 8: case 10: // 亮的状态
      digitalWrite(ledPin, HIGH);
      if(currentMillis - previousMillis >= longOn) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    case 7: case 9: case 11: // 灭的状态
      digitalWrite(ledPin, LOW);
      if(currentMillis - previousMillis >= gap) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    // 后三次短闪（S）
    case 12: case 14: case 16: // 亮的状态
      digitalWrite(ledPin, HIGH);
      if(currentMillis - previousMillis >= shortOn) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    case 13: case 15: case 17: // 灭的状态
      digitalWrite(ledPin, LOW);
      if(currentMillis - previousMillis >= gap) {
        previousMillis = currentMillis;
        sosState++;
      }
      break;
    // SOS结束，长时间停顿
    case 18:
      digitalWrite(ledPin, LOW);
      if(currentMillis - previousMillis >= sosPause) {
        previousMillis = currentMillis;
        sosState = 0; // 回到开头，重复SOS
      }
      break;
  }
}