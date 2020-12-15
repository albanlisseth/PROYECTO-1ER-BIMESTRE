/*UNIVERSIDAD TECNICA DEL NORTE
 * FICA - CITEL
 * SISTEMAS EMBEBIDOS
 * PROYECTO FINAL DE 1ER BIMESTRE
 * LISSETH ALBAN
*/
float myArray[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3, 2, 1};
float kernel[] = {0.05, 0.24, 0.4, 0.24, 0.05};
float G[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3, 2, 1};
int N = 25, Nk = 5;
float den = 0, c = 0, zj = 0;
#include<Wire.h>
#include <FaBoLCD_PCF8574.h>

// initialize the library
FaBoLCD_PCF8574 lcd;

//#include<LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LiquidCrystal_I2C lcd(0x27,20,4);
//LiquidCrystal_I2C lcd(0x20 ,2,1,0,4,5,6,7,3,POSITIVE);
void setup()
{
  lcd.begin(16, 2);
//  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Filtro Gauss:"); 
}

void loop()
{
  den = 0;
  for (int i = 0; i < Nk; i++) {
    den = den + kernel[i];
  }

  for (int i = 0; i < N - Nk; i++) {
    for (int i2 = 0; i2 < Nk; i2++) {
      c = c + kernel[i2] * myArray[i2 + i];
    }
    c = c / den;
    G[i + 2] = c;
    Serial.print(c);
    Serial.print(",");
    Serial.println(myArray[i + 2]);

    lcd.setCursor ( 0, 1 ); lcd.print(c);
    delay(300);
    c = 0;

  }
}
