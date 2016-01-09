#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "consoleLinux.h"

/**
 *  double ms_time(void): returns the current time as a double floating point
 *  time since an arbitrary initial time.  We use the monotonic timer which can't
 *  go backwards.
 */
double ms_time(void)
{
    struct timespec now_timespec;
    clock_gettime(CLOCK_MONOTONIC, &now_timespec);
    return ((double)now_timespec.tv_sec)*1000.0 + ((double)now_timespec.tv_nsec)*1.0e-6;
}

int main(void)
{
	double start_time = ms_time();
	consoleLinux con;
	con.clearScreen();
	con.setCursorPosition(2,10);
	
	int count=0;
	while(count++ < 50) {
		con.clearScreen();
		
		con.setCursorPosition(1, 1);
		printf("first line here");
		con.setCursorPosition(2,1);		
		printf("Updated " ANSI_COLOR_BLUE "%d" ANSI_COLOR_NORMAL " times", count);		\
		con.setCursorPosition(3,1);
		printf("Time since start: " ANSI_COLOR_RED "%07.2lf" ANSI_COLOR_NORMAL, ms_time() - start_time);
		con.updateScreen();
		usleep(100000);
	}	

	con.setCursorPosition(31,1);
	return 0;
}
