#include <LiquidCrystal.h>


#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(6,7);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);

  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
   lcd.begin(16,2);
  // The following lines can be uncommented to set the date and time
 // rtc.setTime(23, 46, 30);     // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(28,8,2021);   // Set the date to January 1st, 2014
   //intro
  lcd.setCursor(0,0);
    lcd.print("Introducing");
    lcd.setCursor(0,1);
    lcd.print("DRIPPO :)");
    delay(3000);
    
    lcd.clear(); 
}

void loop()
{
  //TIMER
  // Send date
  Serial.print("DATE: ");
  Serial.print(rtc.getDateStr());
  Serial.print(" ");
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
 delay (1000);
 lcd.clear(); 
 
}
