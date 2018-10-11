#include <stdio.h>

int x = 0;

int *p1 = &x;

int main(void){
	printf("The value of x is %d and the address is %p", x, p1);	
}