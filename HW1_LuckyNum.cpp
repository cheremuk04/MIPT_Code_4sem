#include <iostream>

using namespace std;

int Sum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int LuckyNum(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = Sum(slow);
        fast = Sum(Sum(fast));
    } while (slow != fast);

    if (slow == 1) return 1;
    else return -1;
}

int main() {
    int num;
    cin >> num;

    if (LuckyNum(num) == 1) {
        cout << "Lucky Number :)";
    } else {
        cout << "Not Lucky Number :(";
    }

    return 0;
}