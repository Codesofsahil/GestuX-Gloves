#include <LiquidCrystal.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int buttonPin1 = A0;
const int buttonPin2 = A1;
const int buttonPin3 = A2;
const int buttonPin4 = 2;
const int buttonPin5 = 3;

int buttonStatus1, buttonStatus2, buttonStatus3, buttonStatus4, buttonStatus5;

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

//SINGLE

String f1 = "how are you?";
String f2 = "I need food";
String f3 = "Are you ok";
String f4 = "I need water";
String f5 = "Nice to meet you";


//DOUBLE

String d12 = "Thank you";
String d13 = "You are welcome";
String d14 = " Sorry";
String d15 = "Excuse me";

String d23 = "What time is it";
String d24 = " I am hungry";
String d25 = "I am tired";

String d34 = "I want to sleep";
String d35 = "I need medicine";

String d45 = "Call the doctor";


//TRIPPLE

String t123 = "Where is the toilet?";
String t134 = " Let's go";
String t145 = "I know him";
String t124 = "Please wait";
String t125 = "Come with me";
String t135 = "Be careful";

String t234 = "Where are you going?";
String t245 = "What is your name?";
String t235 = "How much is this?";

String t345 = "Bus stop?";


//TETRA

String t1234 = "I don't understand";
String t1345 = "Please write it";
String t1245 = "Can you repeat";
String t1235 = "Yes";


//PENTA

String t12345 = "No";



void setup() {

  Wire.begin();
  mpu.initialize();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.clear();
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}


void loop() {

  lcd.clear();
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  //Serial.print("X: ");
  //Serial.println(data.X);
  //Serial.print("Y: ");
  //Serial.println(data.Y);

  if ((data.X >= 135 && data.X <= 165) && (data.Y >= 65 &&
      data.Y <= 85)) { //gesture : down
    lcd.clear();
    Serial.println("Call mom please");
    lcd.setCursor(0, 0);
    lcd.print("Call mom ");
    lcd.setCursor(1, 1); //(col.row)
    lcd.print("please");
    delay(1500);
    //lcd.clear();
  }

  if ((data.X >= 135 && data.X <= 165) && (data.Y >= 230 &&
      data.Y <= 255)) { //gesture : up
    lcd.clear();
    Serial.println("Call an ambulance");
    lcd.setCursor(0, 0);
    lcd.print("Call an ");
    lcd.setCursor(1, 1); //(col.row)
    lcd.print("ambulance");
    delay(1500);
    //lcd.clear();
  }

  if ((data.X >= 235 && data.X <= 255) && (data.Y >= 130 &&
      data.Y <= 150)) { //gesture : left
    lcd.clear();
    Serial.println("I need Help");
    lcd.setCursor(0, 0);
    lcd.print("I need Help");
    delay(1500);
    //lcd.clear();
  }

  if ((data.X >= 10 && data.X <= 35) && (data.Y >= 90 &&
      data.Y <= 120)) { //gesture : right
    lcd.clear();
    Serial.println("See you soon");
    lcd.setCursor(0, 0);
    lcd.print("See you soon");
    delay(1500);
    //lcd.clear();
  }

  buttonStatus1 = digitalRead(buttonPin1);
  buttonStatus2 = digitalRead(buttonPin2);
  buttonStatus3 = digitalRead(buttonPin3);
  buttonStatus4 = digitalRead(buttonPin4);
  buttonStatus5 = digitalRead(buttonPin5);

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH) {
    lcd.clear();
    Serial.println(f1);
    lcd.setCursor(0, 0);
    lcd.print(f1);
    delay(1500);
    //lcd.clear();
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f2);
    lcd.setCursor(0, 0);
    lcd.print(f2);
    delay(1500);
    //lcd.clear();
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f3);
    lcd.setCursor(0, 0);
    lcd.print(f3);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f4);
    lcd.setCursor(0, 0);
    lcd.print(f4);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(f5);
    lcd.setCursor(0, 0);
    lcd.print(f5);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  /////DOUBLE FINGERS


  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d12);
    lcd.setCursor(0, 0);
    lcd.print(d12);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d13);
    lcd.setCursor(0, 0);
    lcd.print(d13);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }
  //

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d14);
    lcd.setCursor(0, 0);
    lcd.print(d14);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d15);
    lcd.setCursor(0, 0);
    lcd.print(d15);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }



  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d23);
    lcd.setCursor(0, 0);
    lcd.print(d23);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d24);
    lcd.setCursor(0, 0);
    lcd.print(d24);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d25);
    lcd.setCursor(0, 0);
    lcd.print(d25);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d34);
    lcd.setCursor(0, 0);
    lcd.print(d34);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d35);
    lcd.setCursor(0, 0);
    lcd.print(d35);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d45);
    lcd.setCursor(0, 0);
    lcd.print(d45);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  //Serial.println("LOOP");

  /////TRIPLE FINGERS


  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t123);
    lcd.setCursor(0, 0);
    lcd.print(t123);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t134);
    lcd.setCursor(0, 0);
    lcd.print(t134);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }
  //
  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t145);
    lcd.setCursor(0, 0);
    lcd.print(t145);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t124);
    lcd.setCursor(0, 0);
    lcd.print(t124);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }



  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t125);
    lcd.setCursor(0, 0);
    lcd.print(t125);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t135);
    lcd.setCursor(0, 0);
    lcd.print(t135);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t234);
    lcd.setCursor(0, 0);
    lcd.print(t234);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t245);
    lcd.setCursor(0, 0);
    lcd.print(t245);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t235);
    lcd.setCursor(0, 0);
    lcd.print(t235);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t345);
    lcd.setCursor(0, 0);
    lcd.print(t345);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  //TETRA

  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t1234);
    lcd.setCursor(0, 0);
    lcd.print(t1234);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == HIGH &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1345);
    lcd.setCursor(0, 0);
    lcd.print(t1345);
    delay(1500);
    //lcd.clear();
    // cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == HIGH && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1245);
    lcd.setCursor(0, 0);
    lcd.print(t1245);
    delay(1500);
    //lcd.clear();
  }

  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == HIGH &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1235);
    lcd.setCursor(0, 0);
    lcd.print(t1235);
    delay(1500);
    //lcd.clear();
  }



  //PENTA

  if (buttonStatus1 == LOW && buttonStatus2 == LOW &&
      buttonStatus3 == LOW && buttonStatus4 == LOW &&
      buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t12345);
    lcd.setCursor(0, 0);
    lcd.print(t12345);
    delay(1500);
    //lcd.clear();
  }
}
