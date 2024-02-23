#include <iostream>
#include <vector>

using namespace std;

void factorialSystem(int n) {
    vector<int> factorialD;
    int factorial = 1;
    while (n > 0) {
        factorialD.push_back(n % (factorial + 1));
        n /= (factorial + 1);
        factorial++;
    }

    for (int i = factorialD.size() - 1; i >= 0; i--) {
        cout << factorialD[i];
        if (i != 0) {
            cout << ".";
        }
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    factorialSystem(num);

    return 0;
}