#include<stdio.h>
#include<stdlib.h>
#include "Bike_Rentals.c"
#include "Car_Rentals.c"
#include"munit.h"

//#include "bike.c"

int main()
{
    int a;
    printf("1.Bike Rentals\n2.Car Rentals\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        bike();
        break;
    case 2:
        car();
        break;
    
    default:
        printf("You entered wrong option\n");
        break;
    }
}