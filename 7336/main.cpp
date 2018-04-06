#include <iostream>

using namespace std;

int main() {
    int cash = 0;
    int money = 0;
    int count = 0;

    cin >> cash >> money >> count;

    money = money * count;
    cash = cash * count;
    
    cash = cash + money / 100;
    money = money % 100;

    cout << cash << " " << money << endl;

    return 0;
}