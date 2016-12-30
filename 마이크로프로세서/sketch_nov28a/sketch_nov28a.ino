
#define PIN_DIGITAL_A 30
#define PIN_DIGITAL_B 32
#define PIN_DIGITAL_C 34
#define PIN_DIGITAL_F 28
#define PIN_DIGITAL_E 36  
#define PIN_DIGITAL_D 38  
const byte PIN_ANALOG_X = 1;
const byte PIN_ANALOG_Y = 2;

#define DELAY 500



void setup(void) {
  Serial.begin(9600);
  pinMode(PIN_DIGITAL_A, INPUT);  
  digitalWrite(PIN_DIGITAL_A, HIGH);
  
   pinMode(PIN_DIGITAL_B, INPUT);  
  digitalWrite(PIN_DIGITAL_B, HIGH);
 
  pinMode(PIN_DIGITAL_C, INPUT);  
  digitalWrite(PIN_DIGITAL_C, HIGH);
 
  pinMode(PIN_DIGITAL_F, INPUT);  
  digitalWrite(PIN_DIGITAL_F, HIGH);
 
  pinMode(PIN_DIGITAL_E, INPUT);  
  digitalWrite(PIN_DIGITAL_E, HIGH);
  
  pinMode(PIN_DIGITAL_D, INPUT);  
  digitalWrite(PIN_DIGITAL_D, HIGH);
  
}

void loop() {
 if(digitalRead(PIN_DIGITAL_A) == LOW) {
   Serial.println("Button A is pressed");
  delay(100);
   }

 else if(digitalRead(PIN_DIGITAL_B) == LOW) {
   Serial.println("Button B is pressed");
    delay(100);
 }
  Serial.print("x:");
  Serial.print(analogRead(PIN_ANALOG_X));
  Serial.print(" ");
 
  Serial.print("y:");
  Serial.print(analogRead(PIN_ANALOG_Y));
  Serial.print(" ");  
 Serial.println();
}
