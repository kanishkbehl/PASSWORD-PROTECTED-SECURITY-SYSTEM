#include<Keypad.h>

const byte row = 4;
const byte col = 4;
const int redLed = 10;
const int greenLed = 11;
const int piezo = 12;

char numPad[row][col] = {
  {'1','2','3'},{'4','5','6'},
  {'7','8','9'},{'*','0','#'}
};

byte rowPin[row] = {9, 8, 7, 6};
byte colPin[row] = {5, 4, 3, 2};

String password = "0713";
String vatup = "";

Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin, colPin, row, col);


void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(piezo, OUTPUT);
  digitalWrite(redLed, HIGH);
  Serial.begin(9600);
  Serial.print("ENTER THE PASSCODE: ");
}

void loop()
{
  char cKey= cKeypad.getKey();
  
  if(cKey){
    if(vatup.length()==4){
      delay(1500);
      if(password == vatup) {
        Serial.println("\n CORRECT PASSCODE, ENTER");
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        tone(piezo,500);
        delay(100);
        noTone(piezo);
      }
      else
      {
        Serial.println("\n WRONG PASSCODE!");
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        tone(piezo,1000);
        delay(800);
        tone(piezo,1000);
        delay(800);
        noTone(piezo);
      }
      delay(1500);
      vatup= "";
      Serial.println("ENTER PASSCODE: ");
      digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
    }
  }
}
        
        
  