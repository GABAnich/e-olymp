#include <iostream>

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

    int count = 0;
    for (int i = 10; i <= 99; i++) {
        if (numberSum(i) == numberSum(i * n)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}