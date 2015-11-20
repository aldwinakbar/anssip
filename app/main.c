#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_i2c.h"
#include "delay.h"
#include "I2C.h"
#include "LiquidCrystal_I2C.h"

int main()
{
  uint8_t data;
  Delay(3000);

  LCDI2C_init(0x27,16,2);
  LCDI2C_noCursor();
  LCDI2C_leftToRight();

  // ------- Quick 3 blinks of backlight  -------------
  LCDI2C_backlight(); // finish with backlight on
  Delay(2000);
  LCDI2C_clear();
  LCDI2C_setCursor(1,1);
  LCDI2C_write_String("AldwinAk");


}
