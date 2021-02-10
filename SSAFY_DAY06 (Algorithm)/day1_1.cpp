// 1번: Flatten

#include <iostream>

using namespace std;

int main()
{
    for (int t = 0; t < 10; ++t) {
        // input
        int dump;
        cin >> dump;

        int board[101] = {0};
        int counts[101] = {0};
        for (int i = 0; i < 100; ++i) {
            cin >> board[i];
            counts[board[i]]++;
        }

        int st, ed;
        for (int i = 0; i <= 100; ++i) {
            if (counts[i] != 0) {
                st = i;
                break;
            }
        }
        for (int i = 100; i >= 0; --i) {
            if (counts[i] != 0) {
                ed = i;
                break;
            }
        }
        while (st < ed && dump != 0) {
            --dump;
            counts[st]--;
            counts[st + 1]++;
            counts[ed]--;
            counts[ed - 1]++;
            if (counts[st] == 0) {
                ++st;
            }
            if (counts[ed] == 0) {
                --ed;
            }
            if (ed - st == 1) {
                break;
            }
        }

        cout << '#' << t + 1 << ' ' << ed - st << '\n';
    }

    return 0;
}
