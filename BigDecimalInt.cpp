#include "BigDecimalInt.h"
#include <deque>
#include <string>
using namespace std;
BigDecimalInt::BigDecimalInt(){};
BigDecimalInt::BigDecimalInt(string decStr)
{
    deque<int> *current = &integer;
    if (decStr[0] == '-')
    {
        isnegative = true;
        for (int i = 1; i < decStr.size(); ++i)
        {
            if (decStr[i] == '.')
            {
                current = &decimal;
                continue;
            }
            int number = decStr[i] - '0';
            if (number < 0 || number > 9)
            {
                throw "invalid input";
            }
            current->push_back(number);
        }
    }
    else
    {
        for (int i = 0; i < decStr.size(); ++i)
        {
            if (decStr[i] == '.')
            {
                current = &decimal;
                continue;
            }
            int number = decStr[i] - '0';
            if (number < 0 || number > 9)
            {
                throw "invalid input";
            }
            current->push_back(number);
        }
    }
}
BigDecimalInt::BigDecimalInt(int decInt)
{
    if (decInt < 0)
    {
        isnegative = true;
        decInt *= -1;
    }
    while (decInt != 0)
    {
        int number = decInt % 10;
        integer.push_front(number);
        decInt /= 10;
    }
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{

    if (!this->isnegative && anotherDec.isnegative){
        anotherDec.isnegative=0;
        return *this-anotherDec;
    }
    if (this->isnegative && !anotherDec.isnegative){
        this->isnegative=0;
        return (anotherDec-*this);
    }
    if (this->isnegative&& anotherDec.isnegative){
        BigDecimalInt equal;
        this->isnegative=0;anotherDec.isnegative=0;
        equal =*this+anotherDec;
        equal.isnegative= true;
        return equal;
    }
    int num1, num2, carry = 0, sum;
    deque<int>::iterator it1=decimal.end()-1;
    deque<int>::iterator it2=anotherDec.decimal.end()-1;
    BigDecimalInt result;
    while(it1>=decimal.begin()||it2>=anotherDec.decimal.begin())    {
        int num1 = (it1 >= decimal.begin())? *it1 : 0;
        int num2 = (it2 >= anotherDec.decimal.begin())? *it2 : 0;   //9 5  0
        sum = num1 + num2 + carry;      //14  11   1
        carry = sum / 10;               //1.4=1  1.1=1  1
        sum = sum % 10;                 //4  1  1
        result.decimal.push_front(sum); //           114
        it1--;
        it2--;
    }
    it1=integer.end()-1;
    it2=anotherDec.integer.end()-1;
    while(it1>=integer.begin()||it2>=anotherDec.integer.begin())
    {                                   //0.55 + 0.59
        int num1 = (it1 >= integer.begin())? *it1 : 0;
        int num2 = (it2 >= anotherDec.integer.begin())? *it2 : 0;   //9 5  0
        sum = num1 + num2 + carry;      //14  11   1
        carry = sum / 10;               //1.4=1  1.1=1  1
        sum = sum % 10;                 //4  1  1
        result.integer.push_front(sum); //           11
        it1--;
        it2--;
    }
    if (carry)
    {
        result.integer.push_front(carry);
    }
    return result;
}
int BigDecimalInt::size()
{
    return integer.size() + decimal.size();
}
void BigDecimalInt::add_zeros(BigDecimalInt &A,BigDecimalInt &B){
 if (A.decimal.size()>B.decimal.size()){
     while(A.decimal.size()!=B.decimal.size()){
         B.decimal.push_back(0);
 }
}else{while(A.decimal.size()!=B.decimal.size()){
         A.decimal.push_back(0);
     }}
    if (A.integer.size()>B.integer.size()){
        while(A.integer.size()!=B.integer.size()){
            B.integer.push_front(0);
        }
    }else{while(A.integer.size()!=B.integer.size()){
            A.integer.push_front(0);
        }}
}
bool BigDecimalInt::operator>(BigDecimalInt anotherDec){
    add_zeros(*this,anotherDec);
    for (int i = 0; i <integer.size() ; ++i) {
        if (integer[i]==anotherDec.integer[i]){
            continue;
        } else if(integer[i]>anotherDec.integer[i]){
            return true;
        }
        else
            return false;
    }
    for (int i = 0; i <decimal.size() ; ++i) {
        if (decimal[i]==anotherDec.decimal[i]){
            continue;
        } else if(decimal[i]>anotherDec.decimal[i]){
            return true;
        }
        else
            return false;
    }
    return false;
}
BigDecimalInt BigDecimalInt ::operator-(BigDecimalInt anotherDec)
{
    if(!this->isnegative&&anotherDec.isnegative){
        anotherDec.isnegative=0;
        return *this+anotherDec;
    }
    if(this->isnegative&&!anotherDec.isnegative) {
        BigDecimalInt equal;
        this->isnegative = 0;
        equal = *this + anotherDec;
        equal.isnegative = 1;
        return equal;
    }
    if (this->isnegative&&anotherDec.isnegative){
        BigDecimalInt equal;
        this->isnegative=0;
        anotherDec.isnegative=0;
        equal=*this-anotherDec;
        equal.isnegative=1;
        return equal;
    }

    if (anotherDec>*this){
        BigDecimalInt equal;
        equal=anotherDec-*this;
        equal.isnegative=true;
        return equal;
    }
    int num1, num2, diff;
    BigDecimalInt result;
    add_zeros(*this,anotherDec);
    for (int i = decimal.size()-1; i>=0 ;--i) {
        num1=decimal[i];
        num2=anotherDec.decimal[i];
        if (num1 >= num2)
        {
            diff = num1 - num2;
            result.decimal.push_front(diff);
        }
        else{
            if(i == 0) {
                integer[integer.size() - 1]--;
            }else {
                decimal[i - 1]--;
            }
            num1 += 10;
            diff = num1 - num2;
            result.decimal.push_front(diff);
        }
    }
    for (int i = integer.size()-1; i >= 0; --i)
    {
        num1 = integer[i];
        num2 = anotherDec.integer[i];
        if (num1 >= num2)
        {
            diff = num1 - num2;
            result.integer.push_front(diff);
        }
        else
        {
            integer[i - 1]--;
            num1 += 10;
            diff = num1 - num2;
            result.integer.push_front(diff);
        }
    }
    return result;
}
ostream &operator<<(ostream &out, BigDecimalInt b)
{
    if (b.isnegative)
    {
        out << "-";
    }
    for (int i = 0; i < b.integer.size(); ++i)
    {
        out << b.integer[i];
    }
    if (b.decimal.size() > 0)
    {
        out << ".";
    }
    for (int j = 0; j < b.decimal.size(); ++j)
    {
        out << b.decimal[j];
    }
    return out;
}

BigDecimalInt::~BigDecimalInt(){};
