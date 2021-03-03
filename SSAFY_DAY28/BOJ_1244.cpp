#include <iostream>

using namespace std;

int n, query;
int* arr;
int isMan, start;

int main()
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> query;
    for (int i = 0; i < query; ++i) {
        cin >> isMan >> start;

        if (isMan == 1) {
            for (int j = start - 1; j < n; j += start) {
                arr[j] = (arr[j] + 1) % 2;
            }
        }
        // 여자(시작 범위로 최대 대칭 지점까지 퍼진다.
        else {
            int l = start - 1;
            int r = start - 1;
            while (l >= 0 && r < n) {
                if (arr[l] == arr[r]) {
                    --l;
                    ++r;
                }
                else {
                    break;
                }
            }
            ++l;
            --r;
            for (int i = l; i <= r; ++i) {
                arr[i] = (arr[i] + 1) % 2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0 && i % 20 == 0) {
            cout << '\n';
        }
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}