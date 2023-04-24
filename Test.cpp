#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

 namespace ariel{
   
TEST_CASE("opertor with zero"){
    //constructor
    CHECK_NOTHROW(Fraction build(1,12));
    CHECK_NOTHROW(Fraction build2(0,5));
    Fraction num1(0,5);
    Fraction num2(4,9);
    Fraction c(2);
    CHECK_THROWS(c=num2/num1);
    CHECK_NOTHROW(c=num1/num2);
    CHECK(num1==0);

}
TEST_CASE("opertor +"){
    Fraction a(6,12);
    Fraction b(4,12);
    Fraction c(10,12);
    CHECK(b+a==c);
    CHECK(0.5+a==1);
    CHECK(a+0.5==0);
    CHECK(a++==0.5);
    CHECK(++a==2.5);
}

TEST_CASE("opertor -"){
    Fraction b(8,15);
    Fraction c(13,15);
    CHECK(c-b== 5/15);
    Fraction num(1.5);
    CHECK(--num==0.5);
    CHECK(num-0.5==0);
}
TEST_CASE("opertor *"){
    Fraction f1(1, 4);
    Fraction f2(15,5);
    CHECK(f1*f2==3/4);
    CHECK(f1*0.5==3/2);
    CHECK(0.5*f1==3/2);
}
TEST_CASE("opertor /"){
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    CHECK(f1/f1==0.25);
    CHECK(f1/0.5==1);
    CHECK(f1/f2==3/2);
    CHECK_THROWS(f2=f1/0);



}
TEST_CASE("opertor comparison"){
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    CHECK(f1>f2);
    CHECK(f1>=f2);
    CHECK(f1<1);
    CHECK(f1<=1);
}

 }