#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// Генерация случайных чисел в диапазоне от min до max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Сортировка пузырьком
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Быстрая сортировка (quicksort)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int p = i + 1;
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    const int size = 10000;
    vector<int> numbers(size);

    // Заполнение контейнера случайными числами
    for (int i = 0; i < size; ++i) {
        numbers[i] = getRandomNumber(1, 10000);
    }

    // Измерение времени выполнения сортировки пузырьком
    auto startBubbleSort = chrono::steady_clock::now();
    bubbleSort(numbers);
    auto endBubbleSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedBubbleSort = endBubbleSort - startBubbleSort;

    // Измерение времени выполнения быстрой сортировки
    auto startQuickSort = chrono::steady_clock::now();
    quickSort(numbers, 0, size - 1);
    auto endQuickSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedQuickSort = endQuickSort - startQuickSort;

    // Вывод результатов
    if (elapsedBubbleSort < elapsedQuickSort) {
        cout << "Быстрая сортировка быстрее. Время: " << elapsedQuickSort.count() << " секунд" << endl;
    } else {
        cout << "Сортировка пузырьком быстрее. Время: " << elapsedBubbleSort.count() << " секунд" << endl;
    }

    return 0;
}