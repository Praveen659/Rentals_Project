
#include<stdio.h>
#include<string.h>
#include "Invoice.c"
float bike_discount(float total_price,int days)
{
    int discount_percentage;
    if (days<=0 && days<5)
    {
        discount_percentage=0;
    }
    else if (days>=5 && days<10)
    {
        discount_percentage=10;
    }
    else if(days>=10 && days<=15)
    {
        discount_percentage=15;
    }
    else   
    {
        // discount_percentage=20;
        return 0;
    }
    float price;
    price=(total_price*discount_percentage)/100;
    total_price=total_price-price;
    printf("You got discount in percentage: %d\nYou saved rupees:%.2f\n",discount_percentage,price);
    return total_price;

}
void bike()
{
    printf("Yes,here bike rentals available\n");
    //details();
    //printf("----------Choose Bike----------\n");
    printf("Sl.No\t\t\tBike Details\n");
    printf("___   _______________________________________________________________________________\n");
    printf("1\tActiva 5G 400/per day include 180km,exceeds 2.0Rs/per km speedLimit:60"
    "\n2\tHonda Dio 500/per day include 200km,exceeds 2.0Rs/per km speedLimit:60"
    "\n3\tAccess125 500/per day include 200km,exceeds 2.0Rs/per km speedLimit:70"
    "\n4\tActiva 6G 600/per day include 220km,exceeds 2.5Rs/per km speedLimit:70"
    "\n5\tSplendour 500/per day include 220km,exceeds 2.0Rs/per km speedLimit:65"
    "\n6\tBajaj Platina 500/per day include 240km,exceeds 2.0Rs/per km speedLimit:65"
    "\n7\tApache RTR 150 700/per day include 250km,exceeds 3.0Rs/per km speedLimit:80\n");
    printf("8\tYamaha version2.0 800/per day include 270km,exceeds 4.0Rs/per km speedLimit:90"
    "\n9\tYamaha version3.0 900/per day include 280km,exceeds 4.5Rs/per km speedLimit:100" 
    "\n10\tRoyal Enfield Hunter 350 1000/per day include 300km,exceeds 5.0Rs/per km speedLimit:110\n");
    printf("11\tRoyal Enfield Classic 350 1100/per day include 290km,exceeds 5.5Rs/per km speedLimit:110"
    "\n12\tRoyal Enfield Bullet 350 1000/per day include 280km,exceeds 5.0Rs/per km speedLimit:100\n");
    printf("Enter above serial number to select the bike:");
    int bike;
    char bike_name[40];
    scanf("%d",&bike);
    int days,limit,first_booking_days;
    float excess_money,speed_limit;
    while (1)
    {
        printf("Enter no.of days do u want bike(less than 15 days):");
        scanf("%d",&days);
        if (days>15)
        {
            printf("We don't provide %d days,only less than 15 days\n",days);
            
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
    first_booking_days=days;
    int helmet=-1;
    printf("If you want extra helemet then press 1 otherwise press 0:");
    scanf("%d",&helmet);
    float total_price=0;
    if (helmet==1)
    {
        total_price+=days*50;
    }
    int amount;
    switch(bike)
    {
        case 1: ;
           // printf("Hi");
            // int activa_5g=400;
            strcpy(bike_name,"Activa 5G");
            amount=400; //for activa_5g
            limit=180;
            excess_money=2.0;
            speed_limit=60;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.\n",total_price);
            break;
        case 2: ;
            //printf("hi");
//            int honda_dio=500;
            strcpy(bike_name,"Honda Dio");
            amount=500;  //for honda dio
            limit=200;
            excess_money=2.0;
            speed_limit=60;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.\n",total_price);
            break;
        case 3: ;
            strcpy(bike_name,"Access125");
            amount=500; //access125
            limit=200;
            excess_money=2.0;
            speed_limit=70;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 4: ;
            strcpy(bike_name,"Activa 6G");
            amount=600;     //activa_6g
            limit=220;
            excess_money=2.5;
            speed_limit=70;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 5: ;
            strcpy(bike_name,"Splendour");
            amount=500;  //splendour
            limit=220;
            excess_money=2.0;
            speed_limit=65;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 6: ;
            strcpy(bike_name,"Bajaj");
            amount=500;  //bajaj
            limit=240;
            excess_money=2.0;
            speed_limit=60;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 7: ;
            strcpy(bike_name,"Apache");
            amount=700; //apache
            limit=250;
            excess_money=3.0;
            speed_limit=80;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 8: ;
            strcpy(bike_name,"Yamaha2.0");
            amount=800;     //yamaha2.0
            limit=270;
            excess_money=4.0;
            speed_limit=90;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 9: ;
            strcpy(bike_name,"Yamaha3.0");
            amount=900;   //yamaha3.0
            limit=280;
            excess_money=4.5;
            speed_limit=100;
            total_price += amount*days;
            if(days>5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 10: ;
            strcpy(bike_name,"Royal Enfield Hunter");
            amount=1000;    //hunter
            limit=300;
            excess_money=5.0;
            speed_limit=110;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 11: ;
            strcpy(bike_name,"Royal Enfield Classic");
            amount = 1100;  //classic
            limit=290;
            excess_money=5.5;
            speed_limit=110;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.",total_price);
            break;
        case 12: ;
            strcpy(bike_name,"Royal Enfield Bullet");
            amount = 1000;  //bullet    
            limit=280;      
            excess_money=5.0;
            speed_limit=100;
            total_price += amount*days;
            if(days>=5)
            {
                total_price=bike_discount(total_price,days);
            }
            printf("Present please pay the %.2f rupees.\n",total_price);
            break;
        default:
            printf("Enter wrong number");
            break;
    }
    float extra_money=0,speed,money_for_extra_days_helmet=0,fine_for_extra_days=0;
    printf("\nIf have taken Extra days press 1 otherwise press 0:");
    int days_check,extra_days;
    scanf("%d",&days_check);
    if (days_check==1)
    {
        printf("No.of extra days taken:");
        scanf("%d",&extra_days);
        int extra_helmet_money=0;
        if (helmet==1)
        {
            extra_helmet_money=extra_days*50;
        }
        if (days+extra_days>15)
        {
            fine_for_extra_days=((days+extra_days)-15)*200;
        }
        money_for_extra_days_helmet=(amount*extra_days)+extra_helmet_money;
        extra_money+=(amount*extra_days)+extra_helmet_money;
        extra_money+=fine_for_extra_days;
        days+=extra_days;
    }
    printf("\nEnter no.of kilometers he travelled:");
    int km;
    float money_extra_km=0;
    scanf("%d",&km);
    int actual_km;
    actual_km=days*limit;                       //After taking the extra days according to that calculating the kilometers included
    if (km>actual_km)
    {
        money_extra_km=(km-actual_km)*excess_money;
        extra_money+=(km-actual_km)*excess_money;
        //printf("You need to pay %.2f for exceed kilometers",extra_money);
    }
    printf("Enter maximum speed travelled:");
    scanf("%f",&speed);
    int fine=0;
    int cross_speed_limit=speed-speed_limit;        //checking the how much cross the speed limit 
    if (cross_speed_limit>5)
    {
        fine=500;                       //fine for cross the speed limit
        
        extra_money+=500;
    }
    printf("Fine speed:%d",fine);
    printf("\n\n\tActevia Rentals\n");
    printf("--------------------------------------------------\n");
    printf("\n__________Invoice Details___________\n\n");
    details();
    printf("Bike Name:%s\n",bike_name);
    printf("First bike booking for how many days:%d\n",first_booking_days);
    if (helmet==1)
    {
        printf("Extra helmet taken or not:YES\n");
    }
    else
    {
        printf("Extra helmet taken or not:NO\n");
    }
    printf("First money paid to take the bike:%f\n",total_price);
    printf("----------Due Amount----------\n");
    printf("Extra days taken:(include the helmet if helmet taken):%d\n",extra_days);
    printf("Extra money for extra days(include helmet if taken):%.2f\n",money_for_extra_days_helmet);
    printf("Total Kilometers travelled:%d\n",km);
    printf("Actual Kilometers we provided:%d\n",actual_km);
    if((km-actual_km)<0)
    {
        printf("Extra kilometers travelled:%d\n",0);
    }
    else
        printf("Extra kilometers travelled:%d\n",km-actual_km);
        
    printf("Extra money for extra kilometers:%.2f\n",money_extra_km);
    printf("Maximum speed travelled:%.2f\n",speed);
    printf("Fine for speed limit cross:%d\n",fine);
    printf("Fine for more than 15 days:%.2f\n",fine_for_extra_days);
    printf("Total money you need to pay: %.2f\n",extra_money);
    owner_details();
    
}

