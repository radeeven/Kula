#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Wire.h>

int currentPos = 11;
long startTime;
int centiseconds = 0;
int seconds = 0;
int minutes = 0;
int hours = 0;
bool inputMode = true;

const byte rad = 4;
const byte kolonne = 3;
// definerer keypadden
char keys[rad][kolonne] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
//setter pins til rader og kolonner på keypadden
byte radPins[rad] = {5, 4, 3, 2};
byte kolonnePins[kolonne] = {9, 8, 7};
Keypad keypad = Keypad(makeKeymap(keys), radPins, kolonnePins, rad, kolonne);

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  displayEntryScreen();
  analogWrite(10,20);
}

void loop() {
  
  // henter en key som trykkes på keypadden
  char key = keypad.getKey();
  
  if (inputMode == true) { // dersom inputMode er true kan du skrive inn på skjermen
    
    if (key == '*') {  //tar vekk input som er skrevet inn og starter på nytt
      resetNummer();
      currentPos = 11;
    }

    else if (currentPos == 16 && key == '#') { //starter timer med nummeret som er satt
      inputMode = false;
      startTime = millis();
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Tid:   ");
      Serial.println("Timer mode");
    }
    
    else if (key != NO_KEY) { //setter input inn i skrivefeltet
      lcd.setCursor(currentPos, 1);
      lcd.print(key);
      currentPos++;
      Serial.println(key);
    }

  }
  
  else {
    timer();
    if (key != NO_KEY) { // når timer er i gang, vil den stoppes dersom noe input gis
      inputMode = true;
      displayEntryScreen();
      Serial.println("Input mode");
      delay(1000);
    }
  }
  
  delay(10);
}

void resetNummer() { // metode for å slette input
  lcd.setCursor(11, 1);
  lcd.print("     ");
}

void clearScreen() { // tar alt vekk fra skjermen
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void displayEntryScreen() { // hovedmenyen
  clearScreen();
  lcd.setCursor(0,0);
  lcd.print("Skriv inn");
  lcd.setCursor(0, 1);
  lcd.print("bilnummer:       ");
  lcd.setCursor(11, 1);
  currentPos = 11;
}

void timer() { //stoppeklokke som skriver ut tiden på skjermen
  int elapsed = millis() - startTime;
  seconds = elapsed / 1000;
  minutes = seconds / 60;
  hours = minutes / 24;
  centiseconds = centiseconds - seconds * 100;
  seconds = seconds - minutes * 60;
  minutes = minutes - hours * 60;
  lcd.setCursor(8,0);
  if (hours < 10) {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);   
}
  
     
