#include <iostream>

using namespace std;

void mySwap(int start, int end, int arr[])
{
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        ++start;
        --end;
    }

    return;
}

void next_permutation(int arr[], int size)
{
    int cand1 = -1, cand2 = -1;
    // cout << size << '\n';

    for (int i = size - 1; i >= 0; --i) {
        if (arr[i - 1] < arr[i]) {
            cand1 = i - 1;
            break;
        }
    }
    // 이미 내림차순이 완료가 된 상태라면 할 필요 없음
    if (cand1 == -1) {
        return;
    }
    for (int i = size - 1; i >= 0; --i) {
        if (arr[cand1] < arr[i]) {
            cand2 = i;
            break;
        }
    }
    int temp = arr[cand1];
    arr[cand1] = arr[cand2];
    arr[cand2] = temp;

    mySwap(cand1 + 1, size - 1, arr);

    return;
}

void prev_permutation(int arr[], int size)
{
    int cand1 = -1, cand2 = -1;
    // cout << size << '\n';

    for (int i = size - 1; i >= 0; --i) {
        if (arr[i - 1] > arr[i]) {
            cand1 = i - 1;
            break;
        }
    }
    // 이미 내림차순이 완료가 된 상태라면 할 필요 없음
    if (cand1 == -1) {
        return;
    }
    for (int i = size - 1; i >= 0; --i) {
        if (arr[cand1] > arr[i]) {
            cand2 = i;
            break;
        }
    }
    int temp = arr[cand1];
    arr[cand1] = arr[cand2];
    arr[cand2] = temp;

    mySwap(cand1 + 1, size - 1, arr);

    return;
}

int main()
{
    int arr[5] = {3, 2, 5, 4, 1};

    cout << "Current: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    cout << "Next Permutation\n";
    for (int i = 0; i < 20; ++i) {
        next_permutation(arr, sizeof(arr) / sizeof(arr[0]));
        for (int i = 0; i < 5; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "Prev Permutation\n";
    for (int i = 0; i < 20; ++i) {
        prev_permutation(arr, sizeof(arr) / sizeof(arr[0]));
        for (int i = 0; i < 5; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}