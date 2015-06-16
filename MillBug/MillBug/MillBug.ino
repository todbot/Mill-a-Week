/*
 * MillBug -- simple robot made with pager motors
 *
 * Uses ATtiny support package from David Mellis & High/Low Tech Group
 *  http://highlowtech.org/?p=1695
 *
 * Tod E. Kurt, http://todbot.com/blog/
 */
 
const int motor1 = 4;
const int motor2 = 3;

void setup() {                
  pinMode(motor1, OUTPUT);     
  pinMode(motor2, OUTPUT);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  delay(2000);
}

void loop() {
  digitalWrite(motor1, HIGH);
  delay(500);              
  digitalWrite(motor1, LOW);
  delay(1000);
  digitalWrite(motor2, HIGH);
  delay(500);              
  digitalWrite(motor2, LOW);
  delay(1000);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  delay(700);              
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  delay(1000);

}

