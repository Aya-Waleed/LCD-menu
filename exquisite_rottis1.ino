#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16, 2);

const byte bu = 4;  //up button
const byte bd = 5;  //down button

bool bus = 1; //upp button state
bool bds = 1; //upp button state
bool lbus = 1; //upp button state
bool lbds = 1; //upp button state

const byte nmo = 4; //number of menu options
const String mo[nmo] = { //menu options
  "Select Program",
  "Settings",
  "Power Saving",
  "Shut Down"
};

int co = 4;  //current options
byte shm[8]={
  B10000,
  B11000,
  B11100,
  B11110,
  B11100,
  B11000,
  B10000,
  B00000
};

void setup() {
 
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,shm);
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print(mo[nmo-co]);
  lcd.setCursor(0, 1);
  lcd.print(mo[nmo-co+1]);
 
  pinMode(bu, INPUT_PULLUP);
  pinMode(bd, INPUT_PULLUP);
}

void loop() {
  bus = digitalRead(bu);
  bds = digitalRead(bd);

  if (bus != lbus) {
    if(bus==0){
    if(co!=4){
       co++;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(byte(0));
      lcd.setCursor(1, 0);
      lcd.print(mo[nmo-co]);
      lcd.setCursor(0, 1);
      lcd.print(mo[nmo-co+1]);
      
    }
    delay(50);
  }
  lbus = bus;}

  if (bds != lbds) {
    if(bds==0){
    if (co!=1) {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.write(byte(0));
      lcd.setCursor(0, 0);
      lcd.print(mo[nmo-co]);
      lcd.setCursor(1, 1);
      lcd.print(mo[nmo-co+1]);
      co--;
    } 
      delay(50);
    }lbds=bds;}
}


  
  
  