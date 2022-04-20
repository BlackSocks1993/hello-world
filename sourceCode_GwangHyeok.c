// C++ code
//
int PIN_LED = 7;
int PIN_LED2 = 8;
int PIN_TRIGER = 4;
int PIN_ECHO = 3;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  
  // 시리얼 모니터에 값을 출력
  Serial.begin(9600);
  
}

void loop()
{
  /*
  digitalWrite(7, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(7, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  */
  
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO, HIGH);
  int cm = distance / 57;
  Serial.println(cm);
  
  if(cm <= 100) {
    digitalWrite(PIN_LED, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED, LOW);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, LOW);
  } else if(100 < cm && cm <= 150) {
    digitalWrite(PIN_LED, HIGH);
    delay(400); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED, LOW);
    delay(500); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, HIGH);
    delay(400); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, LOW);
  } else {
    digitalWrite(PIN_LED, HIGH);
    delay(300); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED, LOW);
    delay(50); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, HIGH);
    delay(300); // Wait for 1000 millisecond(s)
    digitalWrite(PIN_LED2, LOW);
  }
}