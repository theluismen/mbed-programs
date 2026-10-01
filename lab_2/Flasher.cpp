#include "Flasher.h"
#include "mbed.h"

Flasher::Flasher( PinName pin ) : _pin(pin) {
    _pin = 0;
}

void Flasher::flash ( unsigned int times ) 
{
    for ( int i = 0; i < 2*times; i++ ) 
    {
        _pin = ! _pin;
        ThisThread::sleep_for(500ms);
    }
}
