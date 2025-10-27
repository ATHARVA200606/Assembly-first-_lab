#define TRIG_PIN 3
#define ECHO_PIN 2
#define LED1 4   // < 100 cm
#define LED2 5   // 100–250 cm
#define LED3 6   // > 250 cm

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo and calculate distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn off all LEDs first
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  // Blink the correct LED based on distance
  if (distance < 100) {
    digitalWrite(LED1, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);
    delay(300);
  } 
  else if (distance <= 250) {
    digitalWrite(LED2, HIGH);
    delay(200);
    digitalWrite(LED2, LOW);
    delay(200);
  } 
  else {
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED3, LOW);
    delay(100);
  }
}
