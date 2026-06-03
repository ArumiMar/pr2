/**
 * @file    main.c
 * @brief   Punto de entrada del sistema de control de LEDs por potenciometros.
   =============================================================================
 * CONCLUSION DEL EQUIPO
 * Integrantes: Alexa Huerta Sanchez, Arumi Mar Romero 
 *  1. el uso de pvParameters evita usar variables globales o duplicar codigo, 
 * permitiendo instanciar una sola funcion de tarea con configuraciones distintas
 *  2. la diferencia de prioridad se hace visible si dos o mas tareas salen de su 
 * retardo (vTaskDelay) exactamente en el mismo tick; el planificador preemptivo 
 * priorizara siempre la ejecucion de la tarea con mayor prioridad 
 *  3. usar vTaskDelay() bloquea la tarea y cede el procesador al idle task 
 *  4. para agregar un cuarto canal solo haria falta mapear el hardware en 
 * leds.c/adc_reader.c, crear una instancia params_ch3 en tasks.c y llamar a 
 * xTaskCreate una cuarta vez
 *
 * Descripcion:
 *   Inicializa los perifericos (ADC y LEDC) y arranca tres tareas FreeRTOS.
 *   Cada tarea lee un potenciometro y ajusta el brillo del LED correspondiente.
 *
 *   La logica de negocio esta completamente encapsulada en los modulos:
 *     - adc_reader : lectura de potenciometros via ADC oneshot
 *     - leds       : control de brillo via LEDC (PWM)
 *     - tasks      : tareas FreeRTOS y sus parametros
 *
 * Plataforma : ESP32 / ESP-IDF 5.x - 6.x  / FreeRTOS
 * IDE        : VS Code + PlatformIO (framework: espidf)
 * Estandar   : C99
 */

#include "adc_reader.h"
#include "leds.h"
#include "tasks.h"
/* ------------------------------------------------------------------ */
/*  Punto de entrada                                                   */
/* ------------------------------------------------------------------ */

void app_main(void)
{
    /* TODO 1. Inicializar subsistema ADC (tres potenciometros) */
    adc_reader_init();   
    /* TODO 2. Inicializar subsistema LED PWM (tres canales LEDC) */
    leds_init(); 
    }
    /* TODO 3. Crear las tres tareas FreeRTOS e iniciar el scheduler */
    tasks_create_all();
    /* app_main retorna; FreeRTOS continua ejecutando las tareas */
}