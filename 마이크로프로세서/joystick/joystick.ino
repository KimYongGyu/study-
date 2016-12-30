int joystick_x = 0;    
int joystick_y = 1;
int joystick_z = 2;    //조이스틱 X,Y,Z축을 저장

void setup() 
{ 
   //핀번호 설정 및 시리얼통신 초기화
   pan.attach(9);  
   tilt.attach(10);  
   pinMode (up_button, INPUT);
   pinMode (down_button, INPUT);
   pinMode (left_button, INPUT);
   pinMode (right_button, INPUT);
   pinMode (select_button, INPUT);
   pinMode (start_button, INPUT);
   pinMode (analog_button, INPUT);
   digitalWrite (up_button, HIGH);
   digitalWrite (down_button, HIGH);
   digitalWrite (left_button, HIGH);
   digitalWrite (right_button, HIGH);
   digitalWrite (select_button, HIGH);
   digitalWrite (start_button, HIGH);
   digitalWrite (analog_button, HIGH);
   
pinMode(joystick_z,INPUT);    // Z를 입력모드로
 Serial.begin(9600);// 시리얼 통신을, 9600속도로 받습니다. (숫자 조정은 자유)

  
   delay(10);
 }

void loop() {
  // put your main code here, to run repeatedly:
int x = analogRead(joystick_x); // 조이스틱 X축의 아날로그 신호를 x에 저장
 int y = analogRead(joystick_y); // 조이스틱 Y축의 아날로그 신호를 y에 저장
 int z = analogRead(joystick_z); // 조이스틱 Z축의 아날로그 신호를 z에 저장 
  Serial.print("X: ");                   
  Serial.print(x);            //시리얼 모니터에 'X: x값'을 표기
  Serial.print("  Y: ");
  Serial.print(y);            //시리얼 모니터에 '  Y: y값'을 표기
  Serial.print("  Z: ");
 Serial.println(z);           //시리얼 모니터에 '  Z: z값'을 표기하고 줄넘김
delay(100);                 // 100만큼 지연
}
