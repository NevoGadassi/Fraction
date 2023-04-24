
#pragma once
#ifndef Fraction_HPP
#define Fraction_HPP

#include <vector>
#include <iostream>
using namespace std;

 namespace ariel{

 class Fraction
    {
    private:
        int counter, denominator;

    public:
         Fraction(int numerator, int denominator){
            if(denominator==0){
               throw("cant divide by o");
            }
            this->counter=numerator;
            this->denominator=denominator ;
         }
         Fraction(float num);
         int getcountre() const {
            return this->counter;
        }
         int getdenom()const {
            return this->denominator;
        }
        //plus operators
        Fraction operator+( Fraction &other)const ;
        Fraction operator+ ( float num)const ;  
         friend Fraction operator+(float num,  Fraction & other) {
            return other.operator+(num);
         }
        Fraction operator++(int num); //postfix
        Fraction& operator++(); //prefix

        //minus operators
        Fraction operator-( Fraction &other)const;
         Fraction operator-(float num)const ;   
         friend Fraction operator-(float num,  Fraction & second) {
            Fraction first(num);
            return first.operator-(second);
         }
        Fraction operator--(int num); //postfix
        Fraction& operator--(); //prefix

        //multipication operators
        Fraction operator*( Fraction &other)const;
         Fraction operator*(float num)const ;
      friend Fraction operator*(float num,  Fraction & second) {
         return second.operator*(num);
      } 
 

        //divide operators
        Fraction operator/( Fraction &other)const;
         Fraction operator/(float num)const;
         friend Fraction operator/(float num,  Fraction & second) {
            Fraction first(num);
            if(second.getcountre()==0){
               throw("cant divide by 0");
            }
         return first.operator/(second);
      } 

        
        //comparison operators
         bool operator> ( Fraction &other)const ;
         bool operator> (float num)const;
         friend bool operator>(float num,  Fraction & second){
              Fraction first(num);
            return first.operator>(second);
         }
         
         bool operator>= ( Fraction &other)const;
         bool operator>= (float num)const ; 
           friend bool operator>=(float num,  Fraction & second){
              Fraction first(num);
            return first.operator>=(second);
         }

         bool operator< ( Fraction &other)const;
         bool operator< (float num)const;
           friend bool operator<(float num,  Fraction & second){
              Fraction first(num);
            return first.operator<(second);
         }

         bool operator<= ( Fraction &other)const;
         bool operator<= (float num)const;
           friend bool operator<=(float num,  Fraction & second){
              Fraction first(num);
            return first.operator<=(second);
         }

         bool operator== ( Fraction &other)const;
         bool operator== (float num)const; 
           friend bool operator==(float num,  Fraction & second){
              Fraction first(num);
            return first.operator==(second);
         } 
        
friend ostream& operator<<(ostream& output, const Fraction& other){
    output << " "<<other.counter <<'/' << other.denominator;
    return output;
}

friend istream& operator>>(istream& input, Fraction& other) {
    int counter=0;
    int denominator=0;
    char slas='\'';

   input >> counter >> slas >> denominator;

    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    other = Fraction(counter, denominator);

    return input;
}

 };
 }
 #endif
