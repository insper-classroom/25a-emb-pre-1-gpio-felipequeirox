#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN_BLUE = 7;

int main() {

  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN); 

  gpio_init(BTN_BLUE);
  gpio_set_dir(BTN_BLUE, GPIO_IN);
  gpio_pull_up(BTN_BLUE); 

  while (true) {
      if (!gpio_get(BTN_BLUE)) {
        printf("Botao 2 \n");
        while (!gpio_get(BTN_BLUE)) {
        };
      } 
      
      if (!gpio_get(BTN_PIN)) {
        printf("Botao 1 \n");
        while (!gpio_get(BTN_PIN)) {
        };
      }
  }
}