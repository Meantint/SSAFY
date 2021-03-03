#include <iostream>

using namespace std;

int tc;
int res;
int ticket[4];
int month[12];
int cnt = 0;

bool isClean(int m[])
{
    for (int i = 0; i < 12; ++i) {
        if (m[i] != 0) {
            return false;
        }
    }
    return true;
}

void myDFS(int m[], int cur, int tIdx, int cost)
{
    if (tIdx == 0) {
        cost += (m[cur] * ticket[tIdx]);
        m[cur] = 0;
    }
    else if (tIdx == 1) {
        cost += ticket[tIdx];
        m[cur] = 0;
    }
    // tIdx == 2
    else {
        cost += ticket[tIdx];
        for (int i = 0; i < 3; ++i) {
            if (cur + i >= 12) {
                break;
            }
            m[cur + i] = 0;
        }
    }

    if (res < cost) {
        return;
    }
    if (isClean(m)) {
        if (res > cost) {
            // cout << "input" << '\n';
            res = cost;
        }
        return;
    }

    int cpMonth[12];
    for (int i = 0; i < 12; ++i) {
        cpMonth[i] = m[i];
    }
    for (int i = cur; i < 12; ++i) {
        if (cpMonth[i] != 0) {
            for (int j = 2; j >= 0; --j) {
                myDFS(cpMonth, i, j, cost);
                for (int k = cur; k < 12; ++k) {
                    cpMonth[k] = m[k];
                }
            }
        }
    }
}

void solve()
{
    res = ticket[3];

    int cpMonth[12];
    for (int i = 0; i < 12; ++i) {
        cpMonth[i] = month[i];
    }
    for (int i = 0; i < 12; ++i) {
        if (cpMonth[i] != 0) {
            for (int j = 2; j >= 0; --j) {
                myDFS(cpMonth, i, j, 0);
                for (int k = 0; k < 12; ++k) {
                    cpMonth[k] = month[k];
                }
            }
        }
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        for (int i = 0; i < 4; ++i) {
            cin >> ticket[i];
        }
        for (int i = 0; i < 12; ++i) {
            cin >> month[i];
        }

        solve();

        cout << '#' << t << ' ' << res << '\n';
    }

    return 0;
}