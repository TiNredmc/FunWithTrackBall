//Define Trackballer Breakout pin connections to Arduino
#define Btn 2//button
#define Lft 3//left
#define Rht 4//right
#define Up 5//up
#define Dwn 7//down
#define WHT_LED 6  //PWM white
#define GRN_LED 10 //PWM green
#define RED_LED 9  //PWM red
#define BLU_LED 11 //PWM blue

//Define variables used in sketch
int buttonClick;
unsigned long mouse_Lft;
unsigned long mouse_Rht;
unsigned long mouse_Up;
unsigned long mouse_Dwn;

//define LED colour variables .I will use at dim off leds is void loop 
int W = 0;
int G = 0;
int R = 0;
int B = 0;

void setup() {
  // put your setup code here, to run once:
  //Define pin functionality on the Arduino

  pinMode(Btn, INPUT);
  pinMode(Lft, INPUT);
  pinMode(Rht, INPUT);
  pinMode(Up, INPUT);
  pinMode(Dwn, INPUT);
  pinMode(WHT_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);

  //Pull LED pins low to prevent flickering
  digitalWrite(WHT_LED, LOW);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLU_LED, LOW);
  for (int m = 0; m <= 255; m++) {
    analogWrite(WHT_LED, m);
    delay(5);
  }
  for (int n = 255; n >= 0; n--) {
    analogWrite(WHT_LED, n);
    delay(5);
  }
  for (int m = 0; m <= 255; m++) {
    analogWrite(GRN_LED, m);
    delay(5);
  }
  for (int n = 255; n >= 0; n--) {
    analogWrite(GRN_LED, n);
    delay(5);
  }
  for (int m = 0; m <= 255; m++) {
    analogWrite(RED_LED, m);
    delay(5);
  }
  for (int n = 255; n >= 0; n--) {
    analogWrite(RED_LED, n);
    delay(5);
  }
  for (int m = 0; m <= 255; m++) {
    analogWrite(BLU_LED, m);
    delay(5);
  }
  for (int n = 255; n >= 0; n--) {
    analogWrite(BLU_LED, n);
    delay(5);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  mouse_Lft = pulseIn(Lft, HIGH);
  mouse_Rht = pulseIn(Rht, HIGH);
  mouse_Up = pulseIn(Up, HIGH);
  mouse_Dwn = pulseIn(Dwn, HIGH);
  if (mouse_Lft > 0)// statement 1 scroll to left White LED
  {

    if (G >= 1) // Dim Green off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(GRN_LED, n);
        delay(2.5);
      }
    }

    if (R >= 1) // Dim Red off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(RED_LED, n);
        delay(2.5);
      }

    }

    if (B >= 1) // Dim Blue off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(BLU_LED, n);
        delay(2.5);
      }
    }

    W = W + 1;
    for (int m = 0; m <= 255; m++) {
      analogWrite(WHT_LED, m);
      delay(2.5);
    }
    
    R = 0;
    G = 0;
    B = 0;

  }

  if (mouse_Rht > 0)//statement 2 scroll to rigth Green Led
  {

    if (R >= 1) // Dim Red off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(RED_LED, n);
        delay(2.5);
      }
    }
    if (B >= 1) // Dim Blue off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(BLU_LED, n);
        delay(2.5);
      }
    }
    if (W >= 1) // Dim White off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(WHT_LED, n);
        delay(2.5);
      }
    }

    G = G + 1;
    for (int m = 0; m <= 255; m++) {
      analogWrite(GRN_LED, m);
      delay(2.5);
    }
    W = 0;
    R = 0;
    
    B = 0;
  }

  if (mouse_Up > 0)//statement 3 scroll to up Red LED
  {
    if (G >= 1) // Dim Green off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(GRN_LED, n);
        delay(2.5);
      }
    }
    if (B >= 1) // Dim Blue off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(BLU_LED, n);
        delay(2.5);
      }
    }
    if (W >= 1) // Dim White off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(WHT_LED, n);
        delay(2.5);
      }
    }
    R = R + 1;
    for (int m = 0; m <= 255; m++) {
      analogWrite(RED_LED, m);
      delay(2.5);
    }
    W = 0;
    
    G = 0;
    B = 0;

  }
  if (mouse_Dwn > 0)//statement 4 scroll to down Blue LED
  {
    if (G >= 1) // Dim Green off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(GRN_LED, n);
        delay(2.5);
      }
    }
    if (R >= 1) // Dim Red off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(RED_LED, n);
        delay(2.5);
      }
    }
    if (W >= 1) // Dim White off
    {
      for (int n = 255; n >= 0; n--) {
        analogWrite(WHT_LED, n);
        delay(2.5);
      }
    }
    B = B + 1;
    for (int m = 0; m <= 255; m++) {
      analogWrite(BLU_LED, m);
      delay(2.5);
    }
    W = 0;
    R = 0;
    G = 0;
   



  }
  buttonClick = digitalRead(Btn);// clear all LEDS
  if (buttonClick == LOW)
  {
    W = 0;
    R = 0;
    G = 0;
    B = 0;
    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);
    delay(100);
    for (int m = 0; m <= 255; m++) {
      analogWrite(WHT_LED, m);
      delay(2.5);
    }
    for (int n = 255; n >= 0; n--) {
      analogWrite(WHT_LED, n);
      delay(2.5);
    }
  }
}
