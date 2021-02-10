#include <iostream>

using namespace std;

int queue[8];
int front = -1, rear = 7;

int main()
{
    for (int t = 0; t < 10; ++t) {
        front = -1, rear = 7;
        int test_case;
        cin >> test_case;

        for (int i = 0; i < 8; ++i) {
            cin >> queue[i];
        }

        int idx = 0;
        int cnt = 1;
        while (1) {
            queue[idx] -= cnt;
            if (queue[idx] <= 0) {
                break;
            }
            idx = (idx + 1) % 8;
            cnt = cnt % 5 + 1;
        }
        cout << '#' << test_case << ' ';
        for (int i = idx + 1; i < 8; ++i) {
            cout << queue[i] << ' ';
        }
        for (int i = 0; i < idx; ++i) {
            cout << queue[i] << ' ';
        }
        cout << 0 << '\n';
    }

    return 0;
}