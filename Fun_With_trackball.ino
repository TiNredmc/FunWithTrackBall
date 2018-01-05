//Define Trackballer Breakout pin connections to Arduino
#define Btn 2
#define Lft 3
#define Rht 4
#define Up 5
#define Dwn 6
#define WHT_LED 7
#define GRN_LED 8
#define RED_LED 9
#define BLU_LED 10

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
  Serial.begin(9600);
  Serial.println("Begin Trackballer Demo");
}

void loop() {
  // put your main code here, to run repeatedly:
  mouse_Lft = pulseIn(Lft, HIGH, 2000);
  mouse_Rht = pulseIn(Rht, HIGH, 2000);
  mouse_Up = pulseIn(Up, HIGH, 2000);
  mouse_Dwn = pulseIn(Dwn, HIGH, 2000);
  if (mouse_Lft > 0)
  {
    x_position = --x_position;
    digitalWrite(WHT_LED, HIGH);
    digitalWrite(GRN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);
  }
  if (mouse_Rht > 0)
  {
    x_position = ++x_position;
    digitalWrite(GRN_LED, HIGH);
    digitalWrite(WHT_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLU_LED, LOW);
  }
  if (mouse_Up > 0)
  {
    y_position = ++y_position;
    digitalWrite(RED_LED, HIGH);
    digitalWrite(WHT_LED, LOW);
    digitalWrite(BLU_LED, LOW);
    digitalWrite(GRN_LED, LOW);
  }
  if (mouse_Dwn > 0)
  {
    y_position = --y_position;
    digitalWrite(BLU_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(WHT_LED, LOW);
    digitalWrite(GRN_LED, LOW);
  }


  buttonClick = digitalRead(Btn);
  if (buttonClick == LOW)
  {
    digitalWrite(WHT_LED, HIGH);
    delay(1000);
    digitalWrite(WHT_LED, LOW);
  }
}
