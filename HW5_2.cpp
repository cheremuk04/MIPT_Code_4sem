#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

void parallelSort(vector<int>& v) {
    sort(v.begin(), v.end());
}

int main() {
    const int size = 10;
    vector<int> v(size);
    generate(v.begin(), v.end(), []() { return rand() % 100; });

    thread t(parallelSort, ref(v));
    t.join();

    for (int num : v) {
        cout << num << " ";
    }

    return 0;
}
