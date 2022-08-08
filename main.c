#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>


#include "header.h"

int main(void)
{

    int hour, min, sec;
    int x;
    // int timeSet;

    intro();
    
    while (TRUE)
    {
        scanf("%d",&x);
        if (( x == 1) || ( x == 2 ) || ( x == 3 ))
        {
            break;
        }
        printf("\n\nInvalid option, let's try again!\n\n");
    }
    

    while (TRUE)
    {

        switch (x)
        {
            case 1: 
            {
                // GlobalClockList();
                printf("\nWhat time is now?\n");
                printf("Hour: ");
                scanf("%d", &hour);
                printf("Minutes: ");
                scanf("%d", &min);
                printf("Seconds: ");
                scanf("%d", &sec);

                tester(hour, min, sec);
                BasicClock(hour, min, sec);
                break;
            }
            case 2: 
            {
                printf("\nWhat time to start?\n");
                printf("Hour: ");
                scanf("%d", &hour);
                printf("Minutes: ");
                scanf("%d", &min);
                printf("Seconds: ");
                scanf("%d", &sec);

                tester(hour, min, sec);
                timer(hour, min, sec);
                break;
            }
            case 3:
            {
                stopwatch();
                break;
            }
            default:
                break;
        }
    }

    return 0;
}