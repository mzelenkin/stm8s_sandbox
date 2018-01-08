/**
 * Пример в котором при нажатии кнопки светодиод меняет свое состояние
 * Т.е. мы по нажатию кнопки зажигаем светодиод, при повторном нажатии 
 * светодиод тухнет, и т.д.
 * 
 * Схема у нас примерно такая
 * -----                  ^ +VCC
 *      |                 |
 *      | PB5      ___    |
 *      |-----|<|-|___|---+
 *      |                 |
 *      |                 |
 *      |                | |
 *      | PB4             |
 *      |-----------------+
 * -----                  |
 *                         \
 *                        |
 *                       ---
 * 
 * @author Mikhail Zelenkin <mzelenkin@mail.ru>
 */
#include "stm8s.h"
#include "stm8s_gpio.h"

// Порт, к которому подключен светодиод - Порт B
#define LED_GPIO_PORT (GPIOB)
// Ножка (pin) к которой подключен светодиод
#define LED_PIN GPIO_PIN_5
// Порт, к которому подключена кнопка - Порт B
#define BUTTON_GPIO_PORT (GPIOB)
// Ножка (pin) к которой подключена кнопка
#define BUTTON_PIN GPIO_PIN_4


// Инициализация окружения
void setup()
{
  // Деинициализирует регистр указанного порта, сбрасывая его в значение по умолчанию
  GPIO_DeInit(LED_GPIO_PORT);

  // Инициализируем ногу светодиода на вывод
  GPIO_Init(LED_GPIO_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
  
  // Инициализируем ногу кнопки на ввод
  //GPIO_Init(BUTTON_GPIO_PORT, BUTTON_PIN, GPIO_MODE_IN_PU_NO_IT);
  GPIO_Init(BUTTON_GPIO_PORT, BUTTON_PIN, GPIO_MODE_IN_FL_NO_IT);

  // Светодиод на плате зажигается низким уровнем.
  // Поэтому чтобы погасить его выставляем высокий уровень по умолчанию
  GPIO_WriteHigh(LED_GPIO_PORT, LED_PIN);
}

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
    setup();

    // Вечный цикл
    while(1) {
        // Если ножку подтянули к земле, обратываем нажатие
        if(GPIO_ReadInputPin(BUTTON_GPIO_PORT, BUTTON_PIN) == FALSE) {
            // Инверсия состояния ножки светодиода
            GPIO_WriteReverse(LED_GPIO_PORT, LED_PIN);
            // Защита от "дребезга" - ждем пока не сменится состояние ножки на противоположное
            while(GPIO_ReadInputPin(BUTTON_GPIO_PORT, BUTTON_PIN) == FALSE);
        }

        // задержка
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
