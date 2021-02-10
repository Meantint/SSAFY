#include <iostream>

using namespace std;

int main()
{
    // 예제 : 5C3 출력
    int arr[5] = {1, 2, 3, 4, 5};
    for (int t1 = 0; t1 < 5; ++t1) {
        for (int t2 = t1 + 1; t2 < 5; ++t2) {
            for (int t3 = t2 + 1; t3 < 5; ++t3) {
                cout << arr[t1] << ' ';
                cout << arr[t2] << ' ';
                cout << arr[t3] << '\n';
            }
        }
    }

    return 0;
}