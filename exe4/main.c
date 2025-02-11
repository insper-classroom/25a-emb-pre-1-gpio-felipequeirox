#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R = 28;

const int LED_PIN_R = 5;
const int LED_PIN_P = 8;
const int LED_PIN_A = 11;
const int LED_PIN_Y = 15;



int main() {
  stdio_init_all();

  gpio_init(BTN_R);
  gpio_set_dir(BTN_R, GPIO_IN);
  gpio_pull_up(BTN_R);

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_P);
  gpio_init(LED_PIN_A);
  gpio_init(LED_PIN_Y);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);


  while (true) {
    if (!gpio_get(BTN_R)) {
      gpio_put(LED_PIN_R, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_A, 0);
      gpio_put(LED_PIN_Y, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Y, 0);
      while (!gpio_get(BTN_R)) {
        sleep_ms(10);
      };
    } 
  }
}
