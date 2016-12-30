// Store the Arduino pin associated with each input

// Select button is triggered when joystick is pressed
const byte PIN_BUTTON_SELECT = 38; 

const byte a = 34;
const byte b = 32;
const byte c = 28;
const byte d = 26;

const byte PIN_ANALOG_X = 1;
const byte PIN_ANALOG_Y = 2;


void setup() {
  Serial.begin(9600);

  pinMode(a, INPUT);  
  digitalWrite(a, HIGH);
 
  pinMode(d, INPUT);  
  digitalWrite(d, HIGH);
 
  pinMode(b, INPUT);  
  digitalWrite(b, HIGH);
 
  pinMode(c, INPUT);  
  digitalWrite(c, HIGH);
 
  pinMode(PIN_BUTTON_SELECT, INPUT);  
  digitalWrite(PIN_BUTTON_SELECT, HIGH);  
}


void loop() {
 
  Serial.print("x:");
  Serial.print(analogRead(PIN_ANALOG_X));
  Serial.print(" ");
 
  Serial.print("y:");
  Serial.print(analogRead(PIN_ANALOG_Y));
  Serial.print(" ");  
 
  Serial.println();
}
