#include <iostream>
#include <string>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"
using namespace std;
void testBigDecimalInt()
{
    BigDecimalInt num1 = BigDecimalInt("101111");
    BigDecimalInt num2 = BigDecimalInt("202222");
    cout << "--------------------Test #1--------------------" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 + num2 = " << num1 + num2 << endl;
    cout << "output should be = 303333" << endl;

    num1 = BigDecimalInt("88.5");
    num2 = BigDecimalInt(568);
    cout << "--------------------Test #2--------------------" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 - num2 = " << num1 - num2 << endl;
    cout << "output should be = -479.5" << endl;

    num1 = BigDecimalInt("69.69");
    num2 = BigDecimalInt("7.75");
    cout << "--------------------Test #3--------------------" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 - num2 = " << num1 - num2 << endl;
    cout << "output should be = 61.94" << endl;

    num1 = BigDecimalInt(-999);
    num2 = BigDecimalInt("-1.1");
    cout << "--------------------Test #4--------------------" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 - num2 = " << num1 - num2 << endl;
    cout << "output should be = -1000.1" << endl;

    num1 = BigDecimalInt("0.5");
    num2 = BigDecimalInt("0.5");
    cout << "--------------------Test #5--------------------" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num1 + num2 = " << num1 + num2 << endl;
    cout << "output should be = 1" << endl
         << endl;
}
int main() {
    BigDecimalInt result;
    string num1, num2;
    int choose;
    cout << "pls enter num1" << endl;
    cin >> num1;
    BigDecimalInt big1(num1);
    cout << "pls enter num2" << endl;
    cin >> num2;
    BigDecimalInt big2(num2);
    cout << "for Adding type number 1 and for subtraction type number 2 and for test cases 3 " << endl;
    cin >> choose;
    try {
        if (choose == 1) {
            result = big1 + big2;
            cout << result << endl;
        } else if (choose==2){
            result = big1 - big2;
            cout << result << endl;
        } else if (choose==3){
            testBigDecimalInt();
        }
    } catch (const char *e){
       cout<<"Invalid integer"<<endl;
    }
}