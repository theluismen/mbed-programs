#include "mbed.h"

DigitalOut led(D2);
AnalogIn pot(A0);
// main() runs in its own thread in the OS
int main()
{
    while (true) {
        float potVal = pot.read();
        int delay = 100 + potVal*900;
        led=!led;
        ThisThread::sleep_for(delay); 
    }
}

