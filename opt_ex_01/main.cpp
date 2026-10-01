#include "mbed.h"

#include "Thermistor.h"

// Creamos el objeto termistor en el pin analógico A0
Thermistor therm(A0);

// main() runs in its own thread in the OS
int main()
{
    
    while (true) {
        float kelvins = therm.kelvins();
        float celsius = therm.celsius();
        
        printf("Thermistor -> %.2f K (%.2f C)\r\n", kelvins, celsius);
        
        ThisThread::sleep_for(500ms);
    }
}