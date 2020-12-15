/*UNIVERSIDAD TECNICA DEL NORTE
 * FICA - CITEL
 * SISTEMAS EMBEBIDOS
 * PROYECTO FINAL DE 1ER BIMESTRE
 * LISSETH ALBAN
*/
float zj=0;
int N=11;
float myArray[]={1, 1.5, 3, 2, 1.05, 0.7, 2.7, 0.8, 0.9, 1.09, 2};
int n=(N-1)/2;
float xj=0;
float xi=0;
#include<Wire.h>
#include <FaBoLCD_PCF8574.h>

// initialize the library
FaBoLCD_PCF8574 lcd;

//#include<LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x20 ,2,1,0,4,5,6,7,3,POSITIVE);
//LiquidCrystal_I2C lcd(0x27,20,4);  // ajuste la dirección LCD a 0x27 para una pantalla de 16 caracteres y 2 líneas
void setup()
{
lcd.begin(16,2);
lcd.backlight();
Serial.begin(9600);
Serial.setTimeout(50);
}

void loop()
{
  for (int i = -n; i <= n; i++){
xi = myArray[n+i];

  xj=(i+xi+xj);
  }
    zj=xj/(2*n+1);
    lcd.print("Median Filter:");
    lcd.setCursor ( 0, 1 );
    lcd.print(zj);
    delay(200);
    lcd.clear();
  zj=0;
  xj=0;
  xi=0;

}
