#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R = 28;
const int BTN_G = 26;

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {

  int flag_G = 0;
  int flag_R = 0;

  stdio_init_all();

  gpio_init(BTN_R);
  gpio_set_dir(BTN_R, GPIO_IN);
  gpio_pull_up(BTN_R);

  gpio_init(BTN_G);
  gpio_set_dir(BTN_G, GPIO_IN);
  gpio_pull_up(BTN_G);

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_R)) {
      if (flag_R == 0) {
        gpio_put(LED_PIN_R, 1);
        flag_R = 1;
        while (!gpio_get(BTN_R)) {
        };
      } else {
        gpio_put(LED_PIN_R, 0);
        flag_R = 0;
        while (!gpio_get(BTN_R)) {
        };
      }
    }

    if (!gpio_get(BTN_G)) {
      if (flag_G == 0) {
        gpio_put(LED_PIN_G, 1);
        flag_G = 1;
        while (!gpio_get(BTN_G)) {
        };
      } else {
        gpio_put(LED_PIN_G, 0);
        flag_G = 0;
        while (!gpio_get(BTN_G)) {
        };
      }
    }

  }
}
