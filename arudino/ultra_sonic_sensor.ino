int trigger_pin = 13;  /* Trigger pin of the sensor is connected and set to pin number 13 */
int echo_pin = 11;     /* Echo pin of the sensor is connected and set to pin number 11 */
float time_taken;      /* variable declaration to store the calculated value */

void setup() {
  Serial.begin(9600);            /* Setting baud rate to 9600 */
  pinMode(trigger_pin, OUTPUT);  /* pin 13 is set as output pin */
  pinMode(echo_pin, INPUT);      /* pin 11 is set as input pin */
}

void loop() {

  /* Sending an pulse signal from sensor low-high-low */
  
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  /* time_taken will now detect incoming signal to calculate the time */
  
  time_taken = pulseIn(echo_pin, HIGH);
  Serial.println(time_taken); /* data is now written to serial interface */
  delay(50);
  
}
