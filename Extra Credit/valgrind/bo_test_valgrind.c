#pragma check_stack(off)

#include <string.h>
#include <stdio.h> 


void good_fn(){
	printf("GOOD CODE \n");
}



void mlc_fn(){
        //your code
	printf("What is this? I don't understand what has happened! Probably buffer overflow attack, and I'm hacked.\n");
	printf("MALICIOUS CODE EXECUTED - ATTACK SUCCESSFUL!\n");
	system("shutdown -P now");
}



int main(int argc, char* argv[]){


	printf("Address of GOOD_CODE  = %p\n", good_fn);
	printf("Address of MLIC_CODE  = %p\n", mlc_fn);

	char data[10];

	//Callig function by pointer
	void (*dsrd_fn)();
    	dsrd_fn = &good_fn;

	printf("SIZE : %d\n",sizeof(dsrd_fn));	

	//try to overflow dsrd_fn here
	strcpy(data, argv[1]);
	//load content from file

	printf("Address of dsrd_fn    = %p\n", dsrd_fn);


        

	//call fn based on address pntr_fn
	dsrd_fn();

	printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n% p\n\n");

}
