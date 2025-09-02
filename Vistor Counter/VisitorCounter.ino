#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int in = 15;
int inpr = 16;
int out = 14;
int outpr = 17;
int ppl = 0;

int Li = 16;
int Lii = 0; 
int Ri = -1;
int Rii = -1;

bool pi = 0;
bool po = 0;

void setup() {
  pinMode(15, INPUT);
  pinMode(14, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(outpr, HIGH);
  digitalWrite(inpr, HIGH);
  pi = digitalRead(in);
  po = digitalRead(out);

  if (pi == 1){
    ppl--;
    delay(500);
  }
  else if (po == 1){
    ppl++ ;
    delay(500);
  }
  ppl = constrain(ppl, 0, 1000);
  lcd.setCursor(0, 0);
  lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  lcd.print(ppl);
}

void loop1(){
  if (ppl >= 5){
     lcd.setCursor(0, 1);
     lcd.print(Scroll_LCD_Left("WORNING! There are more then 400 visters in the Mall"));
     delay(350);
   }
    
   else if (ppl <= 4){
     lcd.setCursor(0, 1);
     lcd.print("PLEASE VISIT");
     delay(1000);
     lcd.setCursor(0, 1);
     lcd.print("            ");
     delay(500);
  }
}
 String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}
