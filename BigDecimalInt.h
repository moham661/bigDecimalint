#ifndef PROBLEM1_BIGDECIMALINT_H
#define PROBLEM1_BIGDECIMALINT_H

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class BigDecimalInt {
public:
    BigDecimalInt();
    BigDecimalInt (string   decStr); // Initialize from string and rejects bad input
    BigDecimalInt (int decInt); // Initialize from integer
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator>(BigDecimalInt anotherDec);
   int size();
   void add_zeros(BigDecimalInt &A,BigDecimalInt &B);
    friend ostream& operator << (ostream& out, BigDecimalInt b);
    ~BigDecimalInt();
private:
    bool isnegative= false; //for simplicity let 0 positive number
    deque<int>integer;
    deque<int> decimal;
};


#endif //PROBLEM1_BIGDECIMALINT_H
