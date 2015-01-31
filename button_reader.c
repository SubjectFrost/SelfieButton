#include <stdlib.h>
#include <stdio.h>
#include <bcm2835.h>

#define PIN_IN RPI_V2_GPIO_P1_11
#define PIN_OUT RPI_V2_GPIO_P1_15

int main(int argc, char** argv){

	if(!bcm2835_init()){
		printf("Failed to init bcm\n");
		return 1;
	}

	//Set PIN_OUT to be output
	bcm2835_gpio_fsel(PIN_OUT, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(PIN_OUT, HIGH);
	
	//Set PIN_IN to be input with pulldown
	bcm2835_gpio_fsel(PIN_IN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_set_pud(PIN_IN, BCM2835_GPIO_PUD_DOWN);

	while(1){
		uint8_t val = bcm2835_gpio_lev(PIN_IN);
		if(val == HIGH){
			system("./button_pressed");
			printf("Button pressed\n");
		}
		delay(500);
	}	

	return 0;
}
