// 공집합 제외
#include <iostream>

using namespace std;

int size;
int cnt = 0;

int main()
{
    int arr[] = {-1, 3, -9, 6, 7, -6, 1, 5, 4, -2};
    size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < (1 << size); ++i) {
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            // j번째 원소가 i에 존재한다면
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum == 0) {
            cout << "#";
            cout.width(2);
            cout << right << ++cnt << " :";
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    cout.width(3);
                    cout << right << arr[j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}