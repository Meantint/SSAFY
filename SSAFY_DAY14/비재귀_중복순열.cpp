#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    for (int t1 = 0; t1 < 5; ++t1) {
        for (int t2 = 0; t2 < 5; ++t2) {
            for (int t3 = 0; t3 < 5; ++t3) {
                for (int t4 = 0; t4 < 5; ++t4) {
                    for (int t5 = 0; t5 < 5; ++t5) {
                        cout << arr[t1] << ' ';
                        cout << arr[t2] << ' ';
                        cout << arr[t3] << ' ';
                        cout << arr[t4] << ' ';
                        cout << arr[t5] << '\n';
                    }
                }
            }
        }
    }

    return 0;
}