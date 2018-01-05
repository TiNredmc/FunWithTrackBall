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
int x_position;
int y_position;

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

}

void loop() {
  // put your main code here, to run repeatedly:
  mouse_Lft = pulseIn(Lft, HIGH);
  mouse_Rht = pulseIn(Rht, HIGH);
  mouse_Up = pulseIn(Up, HIGH);
  mouse_Dwn = pulseIn(Dwn, HIGH);
  if (mouse_Lft > 0)// statement 1 scroll to left White LED 
  {
    x_position = --x_position;

    for (int l = 0; l <= 255; l++) {
      analogWrite(WHT_LED, l);
      delay(5);
    }



    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);
  }

  if (mouse_Rht > 0)//statement 2 scroll to rigth Green Led
  {
    x_position = ++x_position;

    for (int i = 0; i <= 255; i++) {
      analogWrite(GRN_LED, i);
      delay(5);
    }

    digitalWrite(WHT_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);

  }
  if (mouse_Up > 0)//statement 3 scroll to up Red LED
  {
    y_position = ++y_position;

    for (int j = 0; j <= 255; j++) {
      analogWrite(RED_LED, j);
      delay(5);
    }


    digitalWrite(WHT_LED, LOW);
    digitalWrite(GRN_LED, LOW);
    digitalWrite(BLU_LED, LOW);
  }
  if (mouse_Dwn > 0)//statement 4 scroll to down Blue LED 
  {
    y_position = --y_position;

    for (int k = 0; k <= 255; k++) {
      analogWrite(BLU_LED, k);
      delay(5);
    }

    digitalWrite(WHT_LED, LOW);
    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, LOW);

  }
  buttonClick = digitalRead(Btn);// clear all LEDS
  if (buttonClick == LOW)
  {
    
    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);
    delay(100);
    for (int m = 0; m <= 255; m++) {
      analogWrite(WHT_LED, m);
      delay(5);
    }
    for (int n = 255; n >= 0; n--) {
      analogWrite(WHT_LED, n);
      delay(5);
    }
  }
}
