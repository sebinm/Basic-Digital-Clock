#ifndef _DIGITAL_CLOCK_
#define _DIGITAL_CLOCK_

#define TRUE 1
#define FALSE 0

void intro();

void GlobalClockList();

int checkHourError (int hour, int min, int sec);

void hourErrorMessage();

void convert (int* a, int* b, int* c);

void timeDisplay (int hour, int min, int sec);

void stopwatch();

void timer (int h, int m, int s);

void BasicClock (int hour, int min, int sec);

void tester (int hour, int min, int sec);

#endif