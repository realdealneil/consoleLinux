#include <stdio.h>
#include <unistd.h>
#include "consoleLinux.h"

int main(void)
{
	consoleLinux con;
	con.clearScreen();
	con.setCursorPosition(1, 1);
	printf("first line here");
	con.setCursorPosition(2,10);
	
	con.setColor(COL_RED);
	printf("second line here");
	con.setCursorPosition(30,1);
	con.setColor(COL_NORMAL);
	printf("last line here");
	con.setCursorPosition(12,1);
	
	int count=0;
	while(count++ < 5) {
		con.clearScreen();
		con.setCursorPosition(2,1);		
		printf("Replaced second line %d times", count);		
		con.updateScreen();
		usleep(1000000);
	}	

	con.setCursorPosition(31,1);
	return 0;
}
