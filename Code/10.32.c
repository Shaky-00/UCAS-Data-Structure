#include<stdio.h>

int main()
{
	int red=0, white=0, blue=0;
	char c;
	while((c = getchar()) != '\n')
	{
		if(c == '0')
			red++;
		else if(c == '1')
			white++;
		else if(c == '2')
			blue++;
		else
			continue;
	}
	
	int printstate = 0;
	while(red > 0)
	{
		if(printstate == 1)
			printf(",0");
		else{
			printf("0");
			printstate = 1;
		}
		red--;
	}
	while(white > 0)
	{
		if(printstate == 1)
			printf(",1");
		else{
			printf("1");
			printstate = 1;
		}
		white--;
	}
	while(blue > 0)
	{
		if(printstate == 1)
			printf(",2");
		else{
			printf("2");
			printstate = 1;
		}
		blue--;
	}
	
	return 0;	
}
