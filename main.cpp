#include "snowman.hpp"
#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    while (true)
    {
        cout << "Enter snowman number: [enter 0 to quit] " << endl;
        cin >> number;
        if (number == 0)
            return 0;
        cout << ariel::snowman(number) << endl;
    }
}