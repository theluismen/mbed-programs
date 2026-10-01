#include "Thermistor.h"

#include <cmath>

Thermistor::Thermistor ( PinName pin ) 
    : pin(pin) {

}

float kelvins () {

    float R_serie = 100000.0f; // R_b
    float R_0     = 100000.0f;
    float T_0     = 298.15f;
    float Beta    = 4250.0f;

    float lectura = pin.read(); // [0..1]

    if (lectura <= 0.0f) lectura = 0.00001f;

    float R_th = R_serie * ( ( 1.0f / lectura ) - 1.0f );

    float T_K = 1 / ( std::log( R_th / R_0 ) / Beta + 1 / T_0 );

    return T_K;
}

float celsius() {
    return kelvins() - 273.15f; // Fórmula: T°C = T°K - K[cite: 1]
}