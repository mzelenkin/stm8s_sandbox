/**
 * Пример в котором при нажатии кнопки светодиод меняет свое состояние
 * Т.е. мы по нажатию кнопки зажигаем светодиод, при повторном нажатии 
 * светодиод тухнет, и т.д.
 * 
 * @author Mikhail Zelenkin <mzelenkin@mail.ru>
 */
#include "stm8s.h"
#include "stm8s_gpio.h"

// Порт, к которому подключен светодиод - Порт B
#define LED_GPIO_PORT (GPIOB)
// Ножка (pin) к которой подключен светодиод
#define LED_PIN GPIO_PIN_5

// Тупая задержка
// Просто выполняем цикл t раз
// В реальной жизни лучше так не делать и использовать таймер,
// но мы пока учимся и не будем с этим заморачиваться
static void delay(uint32_t t)
{
  while(t--);
}

// Точка входа aka главная функция
int main(void)
{
  // Деинициализирует регистр указанного порта, сбрасывая его в значение по умолчанию
  GPIO_DeInit(LED_GPIO_PORT);

  // Инициализируем порт и ногу
  GPIO_Init(LED_GPIO_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
  
  // Вечный цикл до отключения питания
  while(1) {
      // Переводим ножку в противоположное состояние
      GPIO_WriteReverse(LED_GPIO_PORT, LED_PIN);
      // Ждем 20000 циклов 
      // Сколько это сек(мс) можно узнать поделив часту на кол-во потраченных тактов. Но зачем?
      delay(20000);
  }
}


#ifdef USE_FULL_ASSERT
// В общем это защита от косяков. Сюда мы попадем если что-то в библиотеке вызовет ошибку assert_param

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
