integrantes: 
    Alexa Huerta Sánchez 
    Arumi Mar Romero 

   Descripción del circuito:

El circuito implementa un sistema que controla el brillo de tres leds utilizando una ESP32

El circuito consta de dos partes:
1. Entrada analógica (ADC): se tienen 3 potenciómetros de 10K conectados. los extremos de cada potenciómetro se conectan a los pines de 3.3V y GND del ESP32,
   mientras que el pin central se conecta a los pines del ADC (GPIO 36, 39 y 34) para leer valores entre 0 y 4095
2. Salida PWM: tres leds (rojo, verde y azul). el ánodo de cada led se conecta a los pines GPIO (25, 26 y 27) configurados con PWM de 8 bits (0-255)
   y el cátodo de cada led se conecta en serie con una resistencia de 330 ohms hacia la línea de GND

Pines asignados:

    POT0: cursor al centro: GPIO 36 (SENSOR_VP) - CH0; LED0 rojo: GPIO 25 
   
    POT1: cursor al centro: GPIO 39 (SENSOR_VN) - CH3; LED1 verde: GPIO 26
    
    POT2: cursor al centro: GPIO 34 - CH6; LED2 azul:  GPIO 27 
