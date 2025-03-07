// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//initialize the constants
const char* screens1[5];
const char* screens2[5];

const int ButtonL = 8;
const int ButtonR = 9;
const int ButtonA = 7;

//initialize other variables
int buttonStateL = 0; 
int buttonStateR = 0; 
int buttonStateA = 0; 
int currentScreen = 0;

void setup() {
  // Initialize the buttons as input
  pinMode(ButtonL, INPUT);
  pinMode(ButtonR, INPUT);
  pinMode(ButtonA, INPUT);
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}



void loop() {
  
  checkButtons();

}

// Update the screen to the right frame    
void updateScreen(){
  lcd.clear();
  lcd.print(screens1[currentScreen]);
  lcd.setCursor(0,1);
  lcd.print(screens2[currentScreen]);
}

// Read the state of the buttons
void checkButtons(){  
  buttonStateL = digitalRead(ButtonL);
  buttonStateR = digitalRead(ButtonR);
  buttonStateA = digitalRead(ButtonA);     
  if ((buttonStateL != HIGH)&&(buttonStateR != HIGH)&&(buttonStateA != HIGH)) {checkButtons();} 
  else {delay(500);}
}
