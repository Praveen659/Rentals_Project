#include<stdio.h>
#include<assert.h>
#include "munit.h"
#include "munit.c"
void stub_Swift_Dezire();
void stub_Hyundai();
void stub_Etios();
void stub_Toofan();
void stub_Innova();
void stub_Thor();
float car_money_discount(float,int);
int boundary_value_checking(int);
int main()
{
    stub_Swift_Dezire();
    stub_Hyundai();
    stub_Etios();
    stub_Toofan();
    stub_Innova();
    stub_Thor();

}
float car_money_discount(float total_price,int days)
{
    total_price=total_price*days;
    int discount_percentage=0;
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
    else
    {
        return 0;
    }
    float price;
    price=(total_price*discount_percentage)/100;
    total_price=total_price-price;
    //printf("You got discount in percentage: %d\nYou saved rupees:%.2f\n",discount_percentage,price);
    return total_price;

}
float extra_days(float money,int days)
{
    return money*days;
}
float extra_days_morethan_30days(int days,int extra_day,float money)
{
    float t=car_money_discount(money,days);
    float p=extra_days(money,extra_day);
    float extra_amount=((days+extra_day)-30)*500;
    return t+p+extra_amount;
    
}
int speed_limit_And_toll_fees(int speed_limit_money,float toll_fees)
{
    return speed_limit_money+toll_fees;
}
int discount(int days)
{
    if (days>0 && days<5)
        return 0;
    else if(days>=5 && days<=30)
        return 1;
    else
        return 0;
}
int boundary_value_checking(int days)
{
    if (days<=0)
        return 0;
    else if(days>30)
        return 0;
}

void stub_Swift_Dezire()
{
    printf("1.Test cases for the Swift Dezire\n");
    //1800rupees perday 8 days 
    float actual = car_money_discount(1800,8);
    float expected = 12960;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //10 is no.of days
    actual=discount(10);//checking discount applied or not
    expected=1;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //parameter 32 is no.of days,we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(32);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(-1);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 1800 rupees per day,3 is no.of days
    actual=extra_days(1800,3);
    expected=5400;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 3000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(25,15,1800);//36000+27000+5000
    expected=68000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,1100.5);
    expected=2100.5;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}

void stub_Hyundai()
{
    printf("2.Test cases for Hyundai\n");
    //1800rupees perday 5 days 
    float actual = car_money_discount(1800,5);
    float expected = 8100;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1 is no.of days
    actual=discount(1);//checking discount applied or not
    expected=0;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //parameter 35 is no.of days, we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(35);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 1800 rupees per day,4 is no.of days
    actual=extra_days(1800,4);
    expected=7200;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 3000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(25,15,1800);//36000+27000+5000
    expected=68000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,110.5);
    expected=1110.5;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}
void stub_Etios()
{
    printf("3.Test cases for the Etios\n");
    //2000rupees perday 6 days 
    float actual = car_money_discount(2000,6);
    float expected = 10800;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //15 is no.of days
    actual=discount(15);//checking discount applied or not
    expected=1;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //here 2000 rupees perday,32 no.of days we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(32);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(-1);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 2000 rupees per day,4 is no.of days
    actual=extra_days(2000,4);
    expected=8000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 2000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(20,15,2000);//32000+30000+2500
    expected=64500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,1100);
    expected=2100;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}
void stub_Toofan()
{
    printf("4.Test cases for the Toofan\n");
    //2200rupees perday 5 days 
    float actual = car_money_discount(2200,5);
    float expected = 9900;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //4 is no.of days
    actual=discount(4);//checking discount applied or not
    expected=0;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //here 2200 rupees perday,32 no.of days we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(31);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(-2);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 2200 rupees per day,4 is no.of days
    actual=extra_days(2200,4);
    expected=8800;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 3000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(20,15,2200);// 35200+33000+2500
    expected=70700;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,1500);
    expected=2500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}
void stub_Innova()
{
    printf("5.Test cases for Innova\n");
    //2500rupees perday 8 days 
    float actual = car_money_discount(2500,8);
    float expected = 18000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //8 is no.of days
    actual=discount(8);//checking discount applied or not
    expected=1;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //here 2500 rupees perday,35 no.of days we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(35);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed boundary\n");

    actual=boundary_value_checking(-2);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 2500 rupees per day,4 is no.of days
    actual=extra_days(2500,4);
    expected=10000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 3000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(20,15,2500);//40000+37500+2500
    expected=80000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,2500);
    expected=3500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}
void stub_Thor()
{
    printf("Test cases for Thor\n");
    //3000rupees perday 5 days 
    float actual = car_money_discount(3000,5);
    float expected = 13500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 is no.of days
    actual=discount(20);//checking discount applied or not
    expected=1;
    munit_assert_int(actual,==,expected);
    printf("Assertion Passed\n");

    //here 3000 rupees perday,32 no.of days we give upto 30days only if more than 30 we don't give
    actual=boundary_value_checking(32);//bounday value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    actual=boundary_value_checking(0);//boundary value checking
    expected=0;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //checking for extradays money 3000 rupees per day,4 is no.of days
    actual=extra_days(3000,4);
    expected=12000;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //20 1st taken days,15 extra days taken 3000rupees per day,in this case taken more than 30days have to pay extra fine
    actual=extra_days_morethan_30days(20,15,3000);//48000+45000+2500
    expected=95500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");

    //1000 if cross the speed limit fine 1000,and toll fees
    actual=speed_limit_And_toll_fees(1000,1500);
    expected=2500;
    munit_assert_int(actual, ==,expected);
    printf("Assertion Passed\n");
    
}