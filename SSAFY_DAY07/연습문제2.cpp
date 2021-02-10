#include <iomanip>
#include <iostream>

using namespace std;

int cnt = 1;
int arr[10] = {-1, 3, -9, 6, 7, -6, 1, 5, 4, -2};

int main()
{
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < (1 << (size)); ++i) {
        int sum = 0;
        int temp[10];

        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum == 0) {
            cout.setf(ios::right);
            cout << "Count #" << setw(2) << cnt++ << ": ";
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    cout << setw(2) << arr[j] << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}