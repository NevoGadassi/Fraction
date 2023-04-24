#include <cmath>


#include "Fraction.hpp"
using namespace ariel;

int gcd(int a, int b) 
{  
    if (a == 0) 
       return 1;  
    if (b == 0)
       return 1; 
    
    if (a == b) 
        return a;   
    if (a > b) 
        return gcd(a-b, b);  
    return gcd(a, b-a); 
}  


Fraction::Fraction(float num) {
        int power = 1;
        while (num * power != floor(num) * power && power < 1000) {
            power *= 10;
        }
        int counter = num * power;
        int denominator = power;
        int commonDivisor = gcd(counter, denominator);
        this->counter=counter/commonDivisor;
        this->denominator=denominator/commonDivisor;
}
//plus operators
Fraction Fraction::operator+ ( Fraction &other)const {
    int num = this->counter*other.denominator + this->denominator*other.counter;
    int denom = this->denominator * other.denominator;
     int commonDivisor = gcd(num,denom);
    return Fraction(num / commonDivisor, denom / commonDivisor);
}
 Fraction Fraction::operator+ ( float num)const {
    Fraction second(num);
    return this->operator+(second);

}


Fraction &Fraction::operator++(){
    Fraction f1=this->operator+(1);
    this->counter=f1.getcountre();
    this->denominator=f1.getdenom();
    return *this;

}
Fraction Fraction::operator++(int num){
    Fraction res = *this;
    ++(*this);
    return res;
}


//minus operators
Fraction Fraction::operator-( Fraction &other)const {
     int num = this->counter*other.denominator - this->denominator*other.counter;
    int denom = this->denominator * other.denominator;
     int commonDivisor = gcd(num,denom);
    return Fraction(num / commonDivisor, denom / commonDivisor);
   

}
Fraction Fraction::operator-(float num)const{
  Fraction second(num);
    return this->operator-(second);

}


Fraction &Fraction::operator--(){
      Fraction f1=this->operator-(1);
    this->counter=f1.getcountre();
    this->denominator=f1.getdenom();
    return *this;
}
Fraction Fraction::operator--(int num){
    Fraction res = *this;
    --(*this);
    return res;

}

//multipication operators

Fraction Fraction::operator*( Fraction &other)const{
    int num = this->counter*other.counter;
    int denom = this->denominator * other.denominator;
    int commonDivisor = gcd(num,denom);
    return Fraction(num / commonDivisor, denom / commonDivisor);

}
Fraction Fraction::operator*( float num) const{
    Fraction other(num);
    return this->operator*(other);

}



//divide operators
Fraction Fraction::operator/( Fraction &second)const {
    if(second.getcountre()==0){
        throw("cant divide by 0");
    }

    Fraction temp = Fraction(second.getdenom(), second.getcountre());
    return this->operator*(temp);
}
Fraction Fraction::operator/(float num)const{
    Fraction second(num);
    return this->operator/(second);

}
 //comparison operators
bool Fraction ::operator<( Fraction &other)const{
    double first=(double)this->counter/this->denominator;
    double second=(double)other.getcountre()/other.getdenom();
return first<second;
}
bool Fraction ::operator<(float num)const{
    Fraction second(num);

return this->operator<(second);

}
bool Fraction ::operator<=( Fraction &other)const{
return this->operator<(other)||this->operator==(other);

}
bool Fraction ::operator<=(float num)const{
Fraction second(num);
return this->operator<=(second);

}
bool Fraction ::operator>( Fraction &other)const{
double first=(double)this->counter/this->denominator;
double second=(double)other.getcountre()/other.getdenom();
return first>second;

}
bool Fraction ::operator>(float num)const{
    Fraction second(num);

return this->operator>(second);

}
bool Fraction ::operator>=( Fraction &other)const{
return this->operator>(other)||this->operator==(other);

}
bool Fraction ::operator>=( float num)const{
Fraction second(num);
return this->operator>=(second);
}
bool Fraction ::operator==( Fraction &other)const{
    double first=(double)this->counter/this->denominator;
    double second=(double)other.getcountre()/other.getdenom();
    return first==second;

}
bool Fraction ::operator==(float num)const{
    Fraction other(num);
return other.operator==(other);

}


