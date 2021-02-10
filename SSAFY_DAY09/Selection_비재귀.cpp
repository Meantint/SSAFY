#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

int len;

int main()
{
    cout << "배열의 길이를 입력하세요 : ";
    cin >> len;

    char* arr = new char[len];
    cout << "숫자를 입력하세요 : ";
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    cout << "정렬 전 : ";
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    for (int i = 0; i < len - 1; ++i) {
        int min_num = arr[i];
        int min_idx = i;
        for (int j = i + 1; j < len; ++j) {
            if (min_num > arr[j]) {
                min_num = arr[j];
                min_idx = j;
            }
        }
        // 같은 인덱스면 스왑 필요 X
        if (i != min_idx) {
            SWAP(arr[i], arr[min_idx]);
        }
    }
    cout << "정렬 후 : ";
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}