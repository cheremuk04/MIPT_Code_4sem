#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>

using namespace std;

void FindLargestSum(const vector<int>& v, int& result) {
    vector<int> copyV = v;
    //сортируем по убываню элементы копии вектора
    sort(copyV.rbegin(), copyV.rend());
    //функция accumulate используется для вычисления суммы всех элементов в диапазоне контейнера или массива
    result = accumulate(copyV.begin(), copyV.begin() + 3, 0);
}

int main() {
    const int size = 10;
    vector<int> v(size);
    generate(v.begin(), v.end(), []() { return rand() % 100; });

    int sum = 0;
    thread t(FindLargestSum, ref(v), ref(sum));
    t.join();
    for (int num: v){
        cout << num << ' ';
    }
    cout << endl;
    cout << sum << endl;

    return 0;
}