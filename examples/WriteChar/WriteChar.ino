#include <TM1637.h>

#define DIO_PIN 6
#define CLK_PIN 7

//----------------------------------------------------------------------------//
void setup()
{
    const int brightness = 7;
    TM1637::setup(CLK_PIN, DIO_PIN, brightness);
}
//----------------------------------------------------------------------------//
void fixed_delay(int t)
{
    uint32_t start = millis();
    while (millis() - start < t)
        yield();
}
//----------------------------------------------------------------------------//
void loop()
{
    TM1637::write('L', 'E', 'S', 'S');
    fixed_delay(500);
    TM1637::write('\0','I', 'S', '\0');
    fixed_delay(500);
    TM1637::write('M', 'O', 'R', 'E');
    fixed_delay(500);
    TM1637::write('\0','\0','\0','\0');
    fixed_delay(500);
}
//----------------------------------------------------------------------------//

