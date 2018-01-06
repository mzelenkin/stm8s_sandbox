#include "stm8s.h"
#include "stm8s_gpio.h"

#define LED_GPIO_PORT (GPIOB)

static void delay(uint32_t t)
{
  while(t--);
}

int main( void )
{
    GPIO_Init(LED_GPIO_PORT, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    
    while(1) {
        GPIO_WriteReverse(LED_GPIO_PORT, GPIO_PIN_5);
        delay(20000);
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
