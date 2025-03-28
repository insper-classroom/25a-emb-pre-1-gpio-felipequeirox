#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R = 28;
const int BTN_G = 26;

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {

  stdio_init_all();

  int FLAG_R = 0;
  int FLAG_G = 0;

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_pull_up(LED_PIN_R); 

  gpio_init(BTN_R);
  gpio_set_dir(BTN_R, GPIO_IN);
  gpio_pull_up(BTN_R); 

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_pull_up(LED_PIN_G); 

  gpio_init(BTN_G);
  gpio_set_dir(BTN_G, GPIO_IN);
  gpio_pull_up(BTN_G); 

  while (true) {
     
    if (!gpio_get(BTN_R)) {
        
        if (FLAG_R == 1) {
          FLAG_R = 0;
        } else {
          FLAG_R = 1;
        }
              
        while (!gpio_get(BTN_R)) {
        };
      } 
      
      if (!gpio_get(BTN_G)) {
        
        if (FLAG_G == 1) {
          FLAG_G = 0;
        } else {
          FLAG_G = 1;
        }
                
        while (!gpio_get(BTN_G)) {
        };
      }

      gpio_put(LED_PIN_R, FLAG_R);
      gpio_put(LED_PIN_G, FLAG_G);

  
  }
}