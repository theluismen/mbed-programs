#include "mbed.h"
#include "Flasher.h"

Flasher led1(LED1);
Flasher led2(LED2);

// main() runs in its own thread in the OS
int main()
{
    /* Flash 10 times */
    led1.flash(10);
    led2.flash(10);
}

