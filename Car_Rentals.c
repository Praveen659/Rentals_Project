#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "Invoice.c"
float discount(float total_price,int days)
{
    int discount_percentage;
    if (days>0 && days<5)
    {
        discount_percentage=0;
    }
    else if (days>=5 && days<10)
    {
        discount_percentage=10;
    }
    else if(days>=10 && days<20)
    {
        discount_percentage=15;
    }
    else if (days>=20 && days<=30)  
    {
        discount_percentage=20;
    }
    float price;
    price=(total_price*discount_percentage)/100;
    total_price=total_price-price;
    printf("You got discount in percentage: %d\nYou saved rupees:%.2f\n",discount_percentage,price);
    return total_price;

}
void car()
{
    printf("Welcome you here Cars available for rentals\n");
    printf("Sl.No\t\t\tBike Details\n");
    printf("___   ___________________________________________\n");
    printf ("1.Swift Dezire 1800/per day speedLimit:90"
    "\n2.Hyundai i10 1800/per day speedLimit:90"
    "\n3.Etios 2000/per day speedLimit:90"
    "\n4.Toofan 2200/per day speedLimit:80"
    "\n5.Innova 2500/per day speedLimit:100"
    "\n6.Thor 3000/per day speedLimit:100\n");
    printf("Note:If Cross the speedLimit fine 1000Rupees\n");
    printf("Enter above serial number to select the car\n");
    int choose,amount_per_day,days;
    float speed_limit,total_price;
    scanf("%d",&choose);
    char name[100];
   // gets(car_name);
   while (1)
    {
        printf("Enter no.of days do u want car(less than 30 days):");
        scanf("%d",&days);
        if (days>30)
        {
            printf("We don't provide %d days,only less than 30 days\n",days);
            
        }
        else if(days<=0)
        {
            printf("Entered invalid number\nPlease enter corect values\n");
        }
        else
        {
            break;
        }
    }
    switch (choose)
    {
    case 1:
        strcpy(name,"Swift Dezire");
        speed_limit=90;
        amount_per_day=1800;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    case 2:
        strcpy(name,"Hyundai I10");
        speed_limit=90;
        amount_per_day=1800;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    case 3:
        strcpy(name,"Etios");
        speed_limit=90;
        amount_per_day=2000;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    case 4:
        strcpy(name,"Toofan");
        speed_limit=80;
        amount_per_day=2200;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    case 5:
        strcpy(name,"Innova");
        speed_limit=100;
        amount_per_day=2500;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    case 6:
        strcpy(name,"Thor");
        amount_per_day=3000;
        speed_limit=100;
        total_price=amount_per_day*days;
        if (days>5)
        {
            total_price=discount(total_price,days);
        }
        printf("Need to pay %.2f this amount.\n",total_price);
        break;
    default:
        printf("You entered a wrong number\n");
        break;
    }

    float speed_cross_limit,excess_money=0,toll_fees,extra_amount,fine_for_extra_days=0;
    int extra_days,speed_limit_fine=0;
    printf("Enter any extra days if taken:");
    scanf("%d",&extra_days);
    float extra_days_money=amount_per_day*extra_days;
    if(days+extra_days>30)
    {
        fine_for_extra_days=((days+extra_days)-30)*500;
    }
    // if (extra_days>5)
    // {
    //     excess_money=discount(extra_days_money,extra_days);
    // }
   // printf("Extra money for extra days:%.2f\n",excess_money); 
    excess_money+=extra_days_money; 
    excess_money+=fine_for_extra_days;
    printf("Enter maximum speed travelled:");
    scanf("%f",&speed_cross_limit);
    
    if((speed_cross_limit-speed_limit)>10)
    {
        excess_money+=1000;
        speed_limit_fine=1000;
    }
    printf("Toll fees:");
    scanf("%f",&toll_fees);
    excess_money+=toll_fees;
    extra_amount=extra_days*amount_per_day;
    printf("\n\n\tActevia Rentals\n");
    printf("--------------------------------------------------\n");
    printf("\n__________Invoice Details___________\n\n");
    details();
    printf("________________________________________________________\n");
    printf("Car name:%s\n",name);
    printf("Number of days taken:%d\n",days);
    printf("How much money paid before taken the car:%.2f\n",total_price);
    printf("No.of days extra taken:%d\n",extra_days);
    printf("How much money for extra days:%.2f\n",extra_days_money);
    printf("Extra fine for more than 30 days%.2f:\n",fine_for_extra_days);
    printf("Fine for speed limit cross%d:\n",speed_limit_fine);
    printf("Toll amount:%.2f\n",toll_fees);
    printf("Excess money is:%.2f\n",excess_money);

//    printf("_____________________________________________________\n");
    owner_details();
}
