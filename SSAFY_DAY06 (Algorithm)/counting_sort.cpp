#include <iostream>

using namespace std;

int len;

int main()
{
    cout << "넣고 싶은 개수를 입력하세요: ";
    cin >> len;

    int* arr = new int[len];

    cout << len << "개 만큼의 숫자 입력: ";
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }

    int max_num = arr[0];
    for (int i = 1; i < len; ++i) {
        if (max_num < arr[i]) {
            max_num = arr[i];
        }
    }

    int* counts = new int[max_num + 1];
    memset(counts, 0, sizeof(int) * (max_num + 1));
    // 각각의 값들의 카운트를 증가시켜준다.
    for (int i = 0; i < len; ++i) {
        counts[arr[i]]++;
    }
    // counts 누적
    for (int i = 1; i <= max_num; ++i) {
        counts[i] += counts[i - 1];
    }

    int* sort_arr = new int[len];
    memset(sort_arr, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        counts[arr[i]]--;
        sort_arr[counts[arr[i]]] = arr[i];
    }
    cout << "Counting Sort: ";
    for (int i = 0; i < len; ++i) {
        cout << sort_arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}