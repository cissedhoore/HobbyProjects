/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//initialize the buttons
const int ButtonLeft = 8;
const int ButtonRight = 9;
const int ButtonAction = 7;
const int totalQuestions = 3;

char* vragen[][4]={"    CORRECT!","   INCORRECT!","","","Q1) Morocco?", "A) Rabat", "B) Ankara", "C) Marrakech", "Q2) Australia?", "A) Sydney", "B) Canberra" , "C) Melbourne", "Q3) Sweden?", "A) Helsinki", "B) Oslo" , "C) Stockholm"};
int punten[][4]={0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
int buttonStateL = 0; 
int buttonStateR = 0; 
int buttonStateA = 0; 
int question = 1;
int frame = 0;
int points = 0;
int gameover = 0;

void setup() {
  // Initialize the buttons as input
  pinMode(ButtonLeft, INPUT);
  pinMode(ButtonRight, INPUT);
  pinMode(ButtonAction, INPUT);
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  startNewGame();
}

void loop() {
  // Read the state of the buttons
  buttonStateL = digitalRead(ButtonLeft);
  buttonStateR = digitalRead(ButtonRight);
  buttonStateA = digitalRead(ButtonAction);
  if (gameover==1){
    lcd.clear(); lcd.print(" Your score is:"); lcd.setCursor(0,1); lcd.print("       "); lcd.print(points); lcd.print("/"); lcd.print(totalQuestions);
    gameover++;}

 
  else if (gameover==0){
 if (buttonStateL == HIGH) {
     delay(500); frame--;
     if (frame < 0) {frame = 0;}
     updateScreen();
 }
     
 if (buttonStateR == HIGH) {
     delay(500); frame++;
     if (frame > 3) {frame = 3;}
     updateScreen();
 }
      
 if (buttonStateA == HIGH) {
     delay(500); 
     if (frame != 0){
     //Check answer
     if (punten[question][frame]==1){lcd.clear(); lcd.print(vragen[0][0]); delay(1000);} else {lcd.clear(); lcd.print(vragen[0][1]); delay(1000);}
     points = points + punten[question][frame];
     question++; frame = 0;
     updateScreen();
     if (question > totalQuestions){gameover = 1;}
 }      }      }
  else if (gameover==2){if ((buttonStateL == HIGH)||(buttonStateR == HIGH)||(buttonStateA == HIGH)){startNewGame();}}}
    
void updateScreen(){
  lcd.clear();
  lcd.print(vragen[question][frame]);
  }

void startNewGame(){
  question = 1;
  frame = 0;
  points = 0;
  gameover = 0; 
  lcd.clear(); lcd.print("    NEW GAME");
  delay(1000);
  updateScreen();
  delay(500);
  }
