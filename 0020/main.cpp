#include <iostream>
#include <string>

using namespace std;

int numberSum(int n) {
    int sum = 0;

    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }

    return sum;
}

int main() {
    int n = 0;
    cin >> n;

    int i = 0;
    while (n) {
        n = n - numberSum(n);
        i++;
    }

    cout << i << endl;

    return 0;
}