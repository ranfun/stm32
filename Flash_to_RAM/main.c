#include<stdint.h>
char const my_data[]="Akatsuki Bankai"; //gets stored in flash because const variables stay in flash
#define RAM_Address 0x20000000
int main(){
	for(int i=0;i<sizeof(my_data);i++){
		*((uint8_t*)RAM_Address+i)=my_data[i];  //typecasting to transfer bit by bit
	}
	return 0;
}