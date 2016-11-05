#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(10,9,4,5,6,8);

char hexakeys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };

byte rowPins[4] = {30,32,34,36};
byte colPins[4] = {38,40,42,44};

Keypad customKeypad = Keypad(makeKeymap(hexakeys),rowPins,colPins,4,4);

int screen = 0;
int keyCount = 0; 
String pin = "1111";
String key = "";
boolean doorLocked = true;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600); 
}

void loop() {
    switch(screen){
      case 0: screen0();
              break;
      case 1: screen1();
              break;
      case 2: screen2();
              break;
      }
}

void screen0(){
  //lcd.clear();

 
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  lcd.setCursor(0,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("ENTER PIN");
  delay(100);
  
  char c=customKeypad.getKey();

  if(c!= NO_KEY){
    key = key + c;
    keyCount=1;
    screen=1;
    screen1();
    }
  }

void screen1(){
  //lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  lcd.setCursor(0,0);
  
  for(int i=1;i<=keyCount;++i){
   lcd.print("*");
   delay(100);
  }
  
  char c=customKeypad.getKey();
  if(c!=NO_KEY){
    key = key + c;
    ++keyCount;

    if(keyCount==4){
      if(key != pin){
        //lcd.clear();
        
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
        lcd.setCursor(0,0);
        lcd.print("INCORRECT");
        lcd.setCursor(0,1);
        lcd.print("TRY AGAIN");
        delay(2000);
        screen = 0;
        key="";
        keyCount=0;
        }
      else{
        screen = 2;
        key="";
        keyCount=0;
        doorLocked = false;
        
        //lcd.clear();
        
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
        lcd.setCursor(0,0);
        lcd.print("UNLOCKED");
        delay(2000);
        
        }
      }
    }
  }

void screen2(){
  //lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  lcd.setCursor(0,0);
  lcd.print("DO SOMETHING");
  delay(100);

  char c=customKeypad.getKey();

  if(c!=NO_KEY){
    if(c=='D'){
      //lcd.clear();
      
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
      lcd.setCursor(0,0);
      lcd.print("LOCKED");
      delay(2000);
      screen=0;
      }
    }
        
}

