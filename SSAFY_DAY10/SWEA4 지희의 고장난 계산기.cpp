#include <iostream>

using namespace std;

int answer = 2112345678;
int pos[10];

void solve(int target, int cnt, int cur)
{
    // cout << target << ", " << cur << '\n';
    if (target == cur) {
        if (answer > cnt) {
            answer = cnt;
        }

        return;
    }
    else if (target < cur) {
        return;
    }

    for (int i = 9; i >= 0; --i) {
        if (pos[i] == 1) {
            int next = cur * 10 + i;
            if (next == 0 || next > 1000000) {
                continue;
            }

            if (next != 1 && target % next == 0) {
                solve(target / next, cnt + 2, 0);
            }
            solve(target, cnt + 1, next);
        }
    }

    return;
}

int main()
{
    int tc;
    cin >> tc;

    for (int t = 0; t < tc; ++t) {
        answer = 2112345678;
        int target;
        for (int i = 0; i < 10; ++i) {
            cin >> pos[i];
        }
        cin >> target;
        solve(target, 0, 0);

        if (answer == 2112345678) {
            cout << '#' << t + 1 << ' ' << -1 << '\n';
        }
        else {
            cout << '#' << t + 1 << ' ' << answer + 1 << '\n';
        }
    }

    return 0;
}