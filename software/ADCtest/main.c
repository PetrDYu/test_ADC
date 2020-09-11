#include <stdio.h>
#include "altera_up_avalon_adc.h"
#include "altera_avalon_pio_regs.h"
#include "C:\Users\petry\OneDrive\projects_quartus\test_ADC\software\ADCtest_bsp\HAL\src\alt_irq_register.c"

void button_monitor_isr(void* context, alt_u32 id){
    volatile alt_u32* pPressedMask = (volatile alt_u32*)context;
    *pPressedMask |= IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE) & 0x0F;  // 4-button

    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE,0);
}

int main()
{
	alt_up_adc_dev* adc;
	adc = alt_up_adc_open_dev("/dev/adc_0");
	if(adc != NULL)
		printf("ADC open successfully\n");
	else
		printf("error ADC open\n");

	unsigned int adc_in, adc_in_new, ledr, k;
	volatile alt_u32 btnmask = 0;

	//IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY_BASE, 0x0E);
	//IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE,0);
	//alt_irq_register(KEY_IRQ, (void *)btnmask, &button_monitor_isr);

	ledr = 0x01;
	k = 0;

	alt_up_adc_auto_enable(adc);

	while(1)
	{
		if(btnmask & 0x0F != 0)
		{
			printf("btn");
			btnmask = 0;
		}
		adc_in_new = alt_up_adc_read(adc, 7);

		if (alt_up_adc_read(adc, 3)/*||alt_up_adc_read(adc, 1)||alt_up_adc_read(adc, 2)||alt_up_adc_read(adc, 3)||alt_up_adc_read(adc, 4)||alt_up_adc_read(adc, 5)||alt_up_adc_read(adc, 6)||alt_up_adc_read(adc, 7)*/)
		{
			ledr = 0x01 << k;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, ledr);
			k++;
			if (k == 10)
				k = 0;
			adc_in = adc_in_new;
			printf("%d\n", adc_in_new);
			//alt_up_adc_update(adc);
		}
	}
	return 0;
}
