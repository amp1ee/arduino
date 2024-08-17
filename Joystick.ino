// Code to control OS mouse from joystick sensor for Arduino Nano

#define SW_PIN 7
#define RX_PIN A1
#define RY_PIN A2

void setup()  
{
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT);     // SW pin
  digitalWrite(SW_PIN, HIGH);
}

int  prev_state = 0;

void loop() {
  int btn = 0, xpos = 0, ypos=0;
  int x=analogRead(RX_PIN);
  int y = analogRead(RY_PIN);
  int sensitivity = 10;

  if(x >= 550)                   //  move up 
      xpos = map(x, 550, 1023, 0, sensitivity); 
  if(x <= 450)                   //  move down
      xpos = map(x, 450, 0, 0, -sensitivity);   
  if(y >= 550)                   //  move right
      ypos = map(y, 550, 1023, 0, sensitivity);  
  if(y <= 450)                   //  move left
      ypos = map(y, 450, 0, 0, -sensitivity); 

  int cur_state = digitalRead(SW_PIN);

  if (cur_state == 1 && prev_state == 0) 
      btn = 1;
  else
      btn = 0;

  if (xpos != 0 or ypos != 0 or btn == 1)
  {
      Serial.print(xpos);
      Serial.print(", ");
      Serial.print(ypos);
      Serial.print(", ");
      Serial.println(btn);
  }

  prev_state = cur_state;
  delay(10);
}
