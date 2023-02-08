#include "main.h"

// Input pull down rising edge trigger interrupt pins:
// Row1 PD3, Row2 PD5, Row3 PD7, Row4 PB4
GPIO_TypeDef *const Row_ports[] = {GPIOD, GPIOD, GPIOD, GPIOB};
const uint16_t Row_pins[] = {GPIO_PIN_3, GPIO_PIN_5, GPIO_PIN_7, GPIO_PIN_4};
// Output pins: Column1 PD4, Column2 PD6, Column3 PB3, Column4 PB5
GPIO_TypeDef *const Column_ports[] = {GPIOD, GPIOD, GPIOB, GPIOB};
const uint16_t Column_pins[] = {GPIO_PIN_4, GPIO_PIN_6, GPIO_PIN_3, GPIO_PIN_5};
volatile uint32_t last_gpio_exti;
typedef enum {
    IntroState,
    MenuState,
	AboutState,
	NameState,
	difficultyState,
    PlayingState,
    endState,
} programStateType;

programStateType programState = IntroState;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  if (last_gpio_exti + 200 > HAL_GetTick()) // Simple button debouncing
  {
    return;
  }
  last_gpio_exti = HAL_GetTick();
//  send_deftask();
  int8_t row_number = -1;
  int8_t column_number = -1;

  if (GPIO_Pin == GPIO_PIN_0)
  {
    // blue_button_pressed = 1;
    // return;
  }

  for (uint8_t row = 0; row < 4; row++) // Loop through Rows
  {
    if (GPIO_Pin == Row_pins[row])
    {
      row_number = row;
    }
  }

  HAL_GPIO_WritePin(Column_ports[0], Column_pins[0], 0);
  HAL_GPIO_WritePin(Column_ports[1], Column_pins[1], 0);
  HAL_GPIO_WritePin(Column_ports[2], Column_pins[2], 0);
  HAL_GPIO_WritePin(Column_ports[3], Column_pins[3], 0);

  for (uint8_t col = 0; col < 4; col++) // Loop through Columns
  {
    HAL_GPIO_WritePin(Column_ports[col], Column_pins[col], 1);
    if (HAL_GPIO_ReadPin(Row_ports[row_number], Row_pins[row_number]))
    {
      column_number = col;
    }
    HAL_GPIO_WritePin(Column_ports[col], Column_pins[col], 0);
  }

  HAL_GPIO_WritePin(Column_ports[0], Column_pins[0], 1);
  HAL_GPIO_WritePin(Column_ports[1], Column_pins[1], 1);
  HAL_GPIO_WritePin(Column_ports[2], Column_pins[2], 1);
  HAL_GPIO_WritePin(Column_ports[3], Column_pins[3], 1);

  if (row_number == -1 || column_number == -1)
  {
    return; // Reject invalid scan
  }
  //   C0   C1   C2   C3
  // +----+----+----+----+
  // | 1  | 2  | 3  | 4  |  R0
  // +----+----+----+----+
  // | 5  | 6  | 7  | 8  |  R1
  // +----+----+----+----+
  // | 9  | 10 | 11 | 12 |  R2
  // +----+----+----+----+
  // | 13 | 14 | 15 | 16 |  R3
  // +----+----+----+----+
  const uint8_t button_number = row_number * 4 + column_number + 1;
//  send_string(button_number);
//  print("2");
//  send_number(2);

  switch (programState){
  case IntroState:

	  break;
  case MenuState:
	  break;
  case AboutState:
	  break;
  case NameState:
	  break;
  case difficultyState:
	  break;
  case PlayingState:
	  break;
  case endState:
	  break;
  default:
	  break;
  }
  switch (button_number){
  case 1:
	print("1");
    break;
  case 2:
	print("2");
    break;
  case 3:
    print("3");
    break;
  case 4:
	  print("4");
    break;
  case 5:
	  print("5");
    break;
  case 6:
	  print("6");
    break;
  case 7:
	  print("7");
    break;
  case 8:
	  print("8");
    break;
  case 9:
	  print("9");
    break;
  case 10:
	  print("a");
    break;
  case 11:
	  print("b");
    break;
  case 12:
	  print("c");
    break;
  case 13:
	  print("d");
    break;
  case 14:
	  print("e");
    break;
  case 15:
	  print("f");
    break;
  case 16:
	  print("g");
    break;

  default:
    break;
  }
}
