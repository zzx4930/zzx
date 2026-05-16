// 定义LED引脚（ESP32开发板一般用D2引脚，也可以用其他数字引脚）
const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT); // 设置引脚为输出模式
}

void loop() {
  // S：短闪3次
  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(500); // 字母间隔

  // O：长闪3次
  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(600);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(500); // 字母间隔

  // S：短闪3次
  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(2000); // SOS结束后的停顿
}