#include <stdint.h>


int main(){
	volatile uint16_t a;

	a = (((16000L * 100)/1000)-5)/3;

	return 0;
}
