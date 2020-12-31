#include  <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int hitung = 10;
const int tombol = 13;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
 pinMode(tombol, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print("rubi hartanto");
 delay(2000);
 lcd.clear();
}

void loop()
{
  if(digitalRead(tombol) == LOW)  {
    hitung--;
    delay(1000);
    lcd.setCursor(8, 0);
    lcd.print(hitung);
  }
  while (hitung == 0) {
    int i;
    lcd.setCursor(0, 0);
    lcd.print("selamat tahun baru 2021");
    for (i = 0 ; i < 16; i++)
    {
      lcd.scrollDisplayLeft();
      delay(250);
    }
  }
}
