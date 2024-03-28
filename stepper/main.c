#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include <libopencm3/stm32/nvic.h>
#include <libopencm3/stm32/systick.h>

int main(void) {
	/* add your own code */
	uint32_t rev = 0xaabbccdd;
	rev = rev_bytes(rev);
	return my_func(rev);
}
