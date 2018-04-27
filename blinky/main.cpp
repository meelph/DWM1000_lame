#include "mbed.h"
#include "DW1000Utils.h"
#include "DW1000.h"

Serial pc(PA_9, PA_10); // tx, rx
SPI spi(PA_7, PA_6 ,PA_5); //MOSI, MISO, SerialClock

DigitalOut chipSelect(PA_4); //ChipSelect
InterruptIn irq(PA_0);

DigitalOut Pin0(PB_0) ;
DigitalOut Pin1(PB_1) ;


// main() runs in its own thread in the OS
int main() {
	chipSelect = 1; //deselect chip

	DW1000 dw1000(spi, &irq, PA_4, NC);

	dw1000.writeRegister40( DW1000_GPIO_CTRL , 0x00, 0x00); // Set GPIO as GPIO (no special function)
	dw1000.writeRegister40( DW1000_GPIO_CTRL , 0x08, 0x00); // Set GPIO DirectionRegister to output
  dw1000.writeRegister40( DW1000_GPIO_CTRL , 0x0C, 0x01); // Set GPIO 1 to HIGH





    while (true) {
        Pin1 = 1;
        Pin0 = 1;

        //led1 = !led1;
        wait(1);


        Pin1 = 0;
        Pin0 = 0;

        wait(1);
        pc.printf("Hello World!\n");

    }
}
