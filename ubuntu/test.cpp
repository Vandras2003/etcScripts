#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	int i = system("ls");
	
	printf("this value was returned %d\n", i);

	return 0;
}
