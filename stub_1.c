
#include<stdio.h>
#include<assert.h>
#include "munit.h"
#include "munit.c"

void stub_Activa5g();
void stub_Honda_dio();
void stub_Access125();
void stub_Activa_6G();
void stub_Splendour();
void stub_Bajaj();
void stub_ApacheRTR();
void stub_YamahaV2();
void stub_YamahaV3();
void stub_Hunter();
void stub_classic();
void stub_bullet();
float extra_days_amount(int,float,int );
float bike_discount(float ,int ,int);
float extra_money_kilometres_AndSpeed_limit(float ,float, int );

int main()
{
    stub_Activa5g();
    stub_Honda_dio();
    stub_Access125();
    stub_Activa_6G();
    stub_Splendour();
    stub_Bajaj();   
    stub_ApacheRTR();
    stub_YamahaV2();
    stub_YamahaV3();
    stub_Hunter();
    stub_classic();
    stub_bullet();
}
float bike_discount(float total_price,int days,int helmet)
{
    
    total_price=total_price*days;
    total_price=total_price+helmet*days;
    int discount_percentage;
    if (days>0 && days<5)
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
        return 0;
    }
    float price;
    price=(total_price*discount_percentage)/100;
    total_price=total_price-price;
   // printf("total:%.2f\n",total_price);
   // printf("You got discount in percentage: %d\nYou saved rupees:%.2f\n",discount_percentage,price);
    return total_price;

}
float extra_days_amount(int extra_days,float amount ,int helmet)
{
    // if (extra_days>15)
    // {
    //     float price = extra_days*amount + extra_days*helmet + (extra_days-15)*200;
    //     return price;
    // }

    float price = extra_days*amount + extra_days*helmet;
    return price;
}
float extra_days_amount_morethan_15days(int days,int extra_days,float amount,int helmet)
{
    int t=bike_discount(amount,days,helmet);
    //printf("%d\n",t);
    int p=extra_days_amount(extra_days, amount,helmet);
    //printf("%d\n",p);
    float additional_money=(days+extra_days-15)*200;
//    printf("%f\n",additional_money);
    return t+p+additional_money;
}
float extra_money_kilometres_AndSpeed_limit(float km,float price, int speed_fine)
{
    return (km*price)+speed_fine;
}
float discount(int days,int helmet)
{
    if(days>0 && days<5)
    {
        return 0;
    }
    else if (days>=5 && days<10)
    {
        return 1;
    }
    else if(days>=10 && days<=15)
    {
        return 1;
    }
    else
        return 0;
}
int boundary_value_checking(int days)
{
    if (days<=0)
    {
        return 0;
    }
    else if (days>15)
    {
        return 0;
    }
}
void stub_Activa5g()
{
    printf("1.Test Cases of Activa5G\n");
    //this test case for without taking helmet
    float actual=bike_discount(400.0,5,0);
    float expected=1800;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(400,10,50);
    expected=3825;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

     //checking the discount applied or not without helmet
    actual=discount(1,0);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(12,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameters No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(16);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");    


    //2 days 400rupees perday 0 rupees for helmet
    actual=extra_days_amount(2,400,0); 
    expected=800;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //3 days 400rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(3,400,50); 
    expected=1350;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(10,8,400,50); 
    expected=8025;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //50 is extra kilometres 2.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(50,2.0,0);
    expected=100;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //52 is extra kilometres 2.0 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(52,2.0,500);
    expected=604;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}

void stub_Honda_dio()
{
    printf("2.Test cases of Honda_Dio\n");
    //this test case for without taking helmet
    float actual=bike_discount(500.0,8,0);
    float expected=3600;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(500,4,50);
    expected=2200;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

     //checking the discount applied or not without helmet
    actual=discount(12,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(1,50);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(18); //boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(0); //boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //5 days 500rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,500,0); 
    expected=2500;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1 days 500rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(1,500,50); 
    expected=550;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(10,8,500,50); 
    expected=9675;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //50 is extra kilometres 2.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(100,2.0,0);
    expected=200;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //52 is extra kilometres 2.0 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(75,2.0,500);
    expected=650;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_Access125()
{
    printf("3.Test cases of Access125\n");
    //this test case for without taking helmet
    //500 rupees perday 8 days 0 means no helmet
    float actual=bike_discount(500,8,0);
    float expected=3600;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(500,3,50);
    expected=1650;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(11,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(2,50);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");
    
    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(16); //boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0); //boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //6 days 500rupees perday 0 rupees for helmet
    actual=extra_days_amount(6,500,0); 
    expected=3000;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //3 days 500rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(3,500,50); 
    expected=1650;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(15,3,500,50); //7012+1650+600
    expected=9262;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //120 is extra kilometres 2.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(120,2.0,0);
    expected=240;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 2 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(70,2,500);
    expected=640;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}

void stub_Activa_6G()
{
    printf("4.Test cases of Activa 6G\n");
    //this test case for without taking helmet
    //600 rupees perday 8 days 0 means no helmet
    float actual=bike_discount(600,8,0);
    float expected=4320;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(600,2,50);
    expected=1300;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(12,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(1,50);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(18);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(-2);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //6 days 600rupees perday 0 rupees for helmet
    actual=extra_days_amount(6,600,0); 
    expected=3600;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //2 days 600rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(2,600,50); 
    expected=1300;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(12,7,600,50); //6715+4550+800
    expected=11980;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //100 is extra kilometres 2.5 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(100,2.5,0);
    expected=250;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 2 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(70,2.5,500);
    expected=675;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}

void stub_Splendour()
{
    printf("5.Test cases of Splendour\n");
    //this test case for without taking helmet
    //500 rupees perday 12 days 0 means no helmet
    float actual=bike_discount(500,12,0);
    float expected=5100;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(500,2,50);
    expected=1100;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(10,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(14,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(18);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //3 days 500rupees perday 0 rupees for helmet
    actual=extra_days_amount(3,500,0); 
    expected=1500;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1 days 500rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(1,500,50); 
    expected=550;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(14,3,500,50); //6545+1650+400
    expected=8595;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //120 is extra kilometres 2.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(120,2.0,0);
    expected=240;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 2 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(90,2,500);
    expected=680;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_Bajaj()
{
    printf("6.Test cases of Bajaj Platina\n");
    //this test case for without taking helmet
    //500 rupees perday 8 days 0 means no helmet
    float actual=bike_discount(500,8,0);
    float expected=3600;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(500,3,50);
    expected=1650;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(11,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(8,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(17);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //6 days 500rupees perday 0 rupees for helmet
    actual=extra_days_amount(6,500,0); 
    expected=3000;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1 days 500rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(1,500,50); 
    expected=550;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(15,3,500,50); //7012+1650+600
    expected=9262;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //120 is extra kilometres 2.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(120,2.0,0);
    expected=240;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 2 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(70,2,500);
    expected=640;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_ApacheRTR()
{
    printf("7.Test cases of ApacheRTR\n");
    //this test case for without taking helmet
    //700 rupees perday 8 days 0 means no helmet
    float actual=bike_discount(700,8,0);
    float expected=5040;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(700,3,50);
    expected=2250;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(3,0);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(10,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(17);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //5 days 700rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,700,0); 
    expected=3500;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1 days 700rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(1,700,50); 
    expected=750;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(15,3,700,50); //9562+2250+600
    expected=12412;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //120 is extra kilometres 3.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(120,3.0,0);
    expected=360;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 3 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(70,3,500);
    expected=710;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_YamahaV2()
{
    printf("8.Test cases of Yamaha Version 2\n");
    //this test case for without taking helmet
    //800 rupees perday 11 days 0 means no helmet
    float actual=bike_discount(800,11,0);
    float expected=7480;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(800,3,50);
    expected=2550;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(13,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(2,50);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(17);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(-1);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");    
    //5 days 800rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,800,0); 
    expected=4000;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //3 days 800rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(3,800,50); 
    expected=2550;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(10,7,800,50); //7225+5950+400
    expected=13575;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //100 is extra kilometres 4 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(100,4.0,0);
    expected=400;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //80 is extra kilometres 4 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(80,4,500);
    expected=820;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_YamahaV3()
{
    printf("9.Test cases of Yamaha Version 3\n");
    //this test case for without taking helmet
    //900 rupees perday 8 days 0 means no helmet
    float actual=bike_discount(900,8,0);
    float expected=6480;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(900,3,50);
    expected=2850;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(3,0);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(12,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(16);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //5 days 900rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,900,0); 
    expected=4500;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //2 days 900rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(2,900,50); 
    expected=1900;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(14,3,900,50); //11305+2850+400
    expected=14555;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //120 is extra kilometres 4.5 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(120,4.5,0);
    expected=540;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //90 is extra kilometres 4.5 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(90,4.5,500);
    expected=905;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_Hunter()
{
    printf("10.Test cases of Royal Enfield Hunter\n");
    //this test case for without taking helmet
    //1000 rupees perday 5 days 0 means no helmet
    float actual=bike_discount(1000,5,0);
    float expected=4500;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(1000,12,50);
    expected=10710;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(1,0);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(12,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(18);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(-1);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    //5 days 1000rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,1000,0); 
    expected=5000;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //4 days 1000rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(4,1000,50); 
    expected=4200;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(13,5,1000,50); //11602+5250+600
    expected=17452;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //80 is extra kilometres 5 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(80,5,0);
    expected=400;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //75 is extra kilometres 5 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(75,5,500);
    expected=875;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_classic()
{
    printf("11.Test cases of Royal Enfield Classic\n");
    //this test case for without taking helmet
    //1100 rupees perday 4 days 0 means no helmet
    float actual=bike_discount(1100,4,0);
    float expected=4400;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(1100,8,50);
    expected=8280;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(10,0);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(12,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameters 1:money perday 2:No.of days 3:Helmet money,for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(18);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(-1);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //5 days 1100rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,1100,0); 
    expected=5500;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //3 days 1100rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(3,1100,50); 
    expected=3450;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(12,5,1100,50); //11730+5750+400
    expected=17880;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //80 is extra kilometres 5.5 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(80,5.5,0);
    expected=440;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //70 is extra kilometres 5.0 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(70,5.5,500);
    expected=885;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
void stub_bullet()
{
    printf("12.Test cases of Royal Enfield Bullet\n");
    //this test case for without taking helmet
    //1000 rupees perday 6 days 0 means no helmet
    float actual=bike_discount(1000,6,0);
    float expected=5400;
//    printf("%d\n",actual);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //parameters 1:money perday 2:No.of days 3:Helmet money
    actual=bike_discount(1000,12,50);
    expected=10710;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking the discount applied or not without helmet
    actual=discount(1,0);
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //checking the discount applied or not with helmet
    actual=discount(10,50);
    expected=1;
    munit_assert_int(actual, ==,expected);
    printf("Discount Assertion Passed\n");

    //parameter No.of days for checking the when enter more than 15 days
    //in this case we don't give the bike,so that's why expect the 0
    actual=boundary_value_checking(20);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //5 days 1000rupees perday 0 rupees for helmet
    actual=extra_days_amount(5,1000,0); 
    expected=5000;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //2 days 1000rupees per day 50 rupees for helmet perday
    actual=extra_days_amount(2,1000,50); 
    expected=2100;   
    //assert(actual==expected);
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //for days+extradays more than 15days 
    actual=extra_days_amount_morethan_15days(11,7,1000,50); //9350+900+7000+400
    expected=17767;   
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
    //80 is extra kilometres 5.0 is extra money per km 0 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(80,5.0,0);
    expected=400;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");

    //75 is extra kilometres 5.0 is extra money per km 500 is speed limit cross
    actual=extra_money_kilometres_AndSpeed_limit(75,5.0,500);
    expected=875;
    munit_assert_int(actual, ==,expected);
    printf("Assertion passed\n");
}
