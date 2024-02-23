#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int size, int el) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] == el) {
            return mid;
        } else if (arr[mid] < el) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    int el;
    cin >> el;
    sort(A, A+n);
    for (int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
    int index = binarySearch(A, n, el);

    if (index != -1) {
        cout << index << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
