#include <stdio.h>
#include "freertos/freeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLUE_LED 2
#define YELLOW_LED 4

//Task 1: Blink BLUE_LED every 0.5 sec
void blink_task_1(void *pvParameters)
{
    gpio_set_direction(BLUE_LED, GPIO_MODE_OUTPUT);

    while(1)
    {
        gpio_set_level(BLUE_LED, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(BLUE_LED, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

//Task 2: Blink YELLOW_LED every 0.2 sec
void blink_task_2(void *pvParameters)
{
    gpio_set_direction(YELLOW_LED, GPIO_MODE_OUTPUT);

    while(1)
    {
        gpio_set_level(YELLOW_LED, 1);
        vTaskDelay(pdMS_TO_TICKS(200));
        gpio_set_level(YELLOW_LED, 0);
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}
void app_main(void)
{
    //Create both tasks
    xTaskCreate(blink_task_1, "Blink1", 2048, NULL, 1, NULL);
    xTaskCreate(blink_task_2, "Blink2", 2048, NULL, 1, NULL);
}
