#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>


#include "header.h"

void intro()
{
    printf("\nWhat options would you be interested?\n");
    printf("\n1 --> Time around the globe");
    printf("\n2 --> Timer");
    printf("\n3 --> Stopwatch\n");

    printf("\nSelect: ");
}

void GlobalClockList()
{
    printf("\t\nHello! Which city's time zone do you have?\n\n");
    printf("1--> Los Angeles\n");
    printf("2--> Denver\n");
    printf("3--> Mexico City\n");
    printf("4--> New York\n");
    printf("5--> Rio de Janeiro\n");
    printf("6--> Reykjavik\n");
    printf("7--> London\n");    
    printf("8--> Berlin\n");
    printf("9--> Moscow\n");
    printf("10--> Dubai\n");
    printf("11--> Mumbai\n");
    printf("12--> Singapore\n");
    printf("13--> Beijing\n");
    printf("14--> Tokyo\n");
    printf("15--> Sydney\n");
    printf("16--> Auckland\n");

    printf("\n\nSelect: ");
}

int checkHourError(int hour, int min, int sec)
{
    if (( sec >= 60 ) || ( min >= 60 ) || ( hour >= 24 ))
    {
        return 1;
    }
    return 0;
}

void hourErrorMessage()
{
    printf("\n\nYou entered something wrong\n");
    printf("Would you like to try again or to convert the time in correct format?\n");
    printf("1--> Convert!\n");
    printf("2--> Try again!\n\n");
    printf("Select: ");
}

void convert(int* a, int* b, int* c)
{
    if(*c >= 60)
    {
        *b += (*c / 60);
        *c %= 60;
    }
    else if( *c < 0 )
    {
        *c = 59;
        *b += -1;
    }

    if(*b >= 60)
    {
        *a += (*b / 60);
        *b %= 60;
    }
    else if( *b < 0 )
    {
        *b = 59;
        *a += -1;
    }

    if(*a >= 24)
    {
        *a %= 24;
    }
    else if( *a < 0 )
    {
        *a = -(*a);
    }
}

void timeDisplay(int hour, int min, int sec)
{
    printf("%02d : %02d : %02d \n", hour, min, sec);
}

void stopwatch()
{
    int h = 0, m = 0, s = 0;

    while (TRUE)
        {
            s++;
            convert(&h, &m, &s);
            printf("Timer: \n");
            timeDisplay(h, m, s);

            Sleep(1000); // slows down the while loop and make it more like a real clock
            system("cls"); // this clear the screen
        }
}

void timer(int h, int m, int s)
{
    _Bool TIME = TRUE;

    while (TIME)
        {
            s--;
            convert(&h, &m, &s);

            if(( h == 0 ) && ( m == 0 ) && ( s == 0 ))
            {
                TIME = FALSE;

                Beep(500,10000); // Alarm after the time is gone
                break;
            }

            printf("Timer: \n");
            timeDisplay(h, m, s); 


            Sleep(1000); // slows down the while loop and make it more like a real clock
            system("cls"); // this clear the screen
        }
}

void BasicClock(int hour, int min, int sec)
{
    while (TRUE)
    {
        sec++;
        convert(&hour, &min, &sec);
        printf("\n Clock: ");
        printf("%02d : %02d : %02d ", hour, min, sec);

        Sleep(1000); // slows down the while loop and make it more like a real clock
        system("cls"); // this clear the screen
    }
}

void tester(int hour, int min, int sec)
{
    int check;

    if (checkHourError(hour, min, sec))
    {
        hourErrorMessage();
        scanf("%d", &check);

        switch (check)
        {
            case 1: 
                convert(&hour, &min, &sec);
                break;
            case 2: 
                break;
            default:
                printf("Let's try again!\n\n");
                break;
        }
    }
}