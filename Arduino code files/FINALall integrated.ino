    
// AUTOMATIC IRRIGATION SYSTEM
 
#include <LiquidCrystal.h> //LCD Library
#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(A4,A5);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int M_Sensor = A0;
int W_Sensor =A1;
int Pump = 13;
const int BUTTON =6; // Naming switch button pin
const int LED1 =8;   // Namin LED pin
const int LED2 =9;
int BUTTONstate = 0;// Namin LED pin
Time t; 
void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode (A1, INPUT);
    pinMode(A0,INPUT);
    pinMode(BUTTON, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

   // Setup Serial connection
  Serial.begin(115200);

  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
   lcd.begin(16,2);
  // The following lines can be uncommented to set the date and time
   // rtc.setTime(23, 28, 30);     // Set the time to 12:00:00 (24hr format)
   //rtc.setDate(26,9,2021);;// Set the date to January 1st, 2014
   //intro
  lcd.setCursor(0,0);
    lcd.print("Introducing");
    lcd.setCursor(0,1);
    lcd.print("DRIPPO :)");
    delay(5000); 
}

void loop()
{ //TIMER
  // Send date
  Serial.print("DATE: ");
  Serial.print(rtc.getDateStr());
  Serial.print(" ");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Date:");
 lcd.print(rtc.getDateStr());
 Serial.println();

  // Send time
  Serial.print("TIME: ");
  Serial.println(rtc.getTimeStr());
   lcd.setCursor(0,1);
    lcd.print("Time:");
 lcd.print(rtc.getTimeStr());
 delay (2000);
 lcd.clear();
 t = rtc.getTime();

 
 BUTTONstate = digitalRead(BUTTON);
  // mannual mode
  if (BUTTONstate == HIGH)  // Condition to check button input
    { digitalWrite(LED1, HIGH);
      digitalWrite(LED2,LOW );
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("MANNUAL");
       delay(1000);
       digitalWrite(Pump , HIGH);
       lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("PUMP:ON");
         delay(2000);
         lcd.clear();
         
    }
//automatic 
  if(BUTTONstate == LOW)
{ 
  digitalWrite(LED2,HIGH );
   digitalWrite(LED1,LOW);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AUTOMATIC");
    delay(1000);  
    lcd.clear();
    
  if((t.hour ==23)||(t.hour ==00 )|| (t.hour == 1))
{ 

  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value
 if (Moisture> 800)   // for dry soil
  { lcd.clear();
        lcd.setCursor(11,0);
        lcd.print("DRY");
        lcd.setCursor(11,1);
        lcd.print("SOIL");
        int val = analogRead(W_Sensor); 
       if (val>800) //test the availability of water in storage
       {
         digitalWrite(Pump, HIGH);
         lcd.setCursor(0,0);
         lcd.print("HIGH:");
          lcd.setCursor(5,0);
         lcd.print(val);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
       }
       else
       {
         digitalWrite(Pump, LOW);
         lcd.setCursor(0,0);
         lcd.print("LOW:");
          lcd.setCursor(5,0);
          lcd.print(val);
         lcd.setCursor(0,1);
         lcd.print("PUMP:OFF");
       }
    }
 
    else if (Moisture>= 0 && Moisture<=800) //for Moist Soil
    { lcd.clear();
      lcd.setCursor(11,0);
     lcd.print("MOIST");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(Pump,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF"); 
  }
 delay(2200);   
}  
}} 
