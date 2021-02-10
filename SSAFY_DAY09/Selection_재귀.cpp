#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

void recursive_selection(int arr[], int st, int ed)
{
    if (st == ed) {
        return;
    }

    int min_num = arr[st];
    int min_idx = st;
    for (int j = st + 1; j < ed; ++j) {
        if (min_num > arr[j]) {
            min_num = arr[j];
            min_idx = j;
        }
    }
    if (st != min_idx) {
        SWAP(arr[st], arr[min_idx]);
    }

    recursive_selection(arr, st + 1, ed);

    return;
}

int main()
{
    int len;
    cout << "배열의 길이를 입력하세요 : ";
    cin >> len;

    int* arr = new int[len];
    cout << "숫자를 입력하세요 : ";
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    cout << "정렬 전 : ";
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    recursive_selection(arr, 0, len);

    cout << "정렬 후 : ";
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}