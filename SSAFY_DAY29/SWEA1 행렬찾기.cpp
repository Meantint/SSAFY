#include <iostream>

using namespace std;

int tc, n;
int spIdx = -1;
int savePos[20][3];  // (area, x_len, y_len);
int indirect[20];
int board[100][100];

bool isPos(int x, int y)
{
    if (x == 0 && y == 0) {
        return true;
    }
    else if (x == 0 && y != 0) {
        if (board[x][y - 1] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else if (x != 0 && y == 0) {
        if (board[x - 1][y] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if (board[x - 1][y] != 0 || board[x][y - 1] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

void mySearch(int x, int y)
{
    int r, c;
    for (r = x; board[r][y] != 0; ++r) {
    }
    for (c = y; board[x][c] != 0; ++c) {
    }
    // cout << "r : " << r << ", c : " << c << '\n';
    savePos[++spIdx][0] = (r - x) * (c - y);
    savePos[spIdx][1] = r - x;
    savePos[spIdx][2] = c - y;

    return;
}

void mySort()
{
    for (int i = 0; i <= spIdx; ++i) {
        for (int j = i + 1; j <= spIdx; ++j) {
            if (savePos[indirect[i]][0] > savePos[indirect[j]][0]) {
                int tmp = indirect[i];
                indirect[i] = indirect[j];
                indirect[j] = tmp;
            }
            else if (savePos[indirect[i]][0] == savePos[indirect[j]][0]) {
                if (savePos[indirect[i]][1] > savePos[indirect[j]][1]) {
                    int tmp = indirect[i];
                    indirect[i] = indirect[j];
                    indirect[j] = tmp;
                }
            }
        }
    }
}

void solve()
{
    // 다 탐색한다.
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] != 0 && isPos(r, c)) {
                // savePos에 넣어준다.
                mySearch(r, c);
            }
        }
    }
    mySort();
    for (int i = 0; i <= spIdx; ++i) {
        // cout << savePos[indirect[i]][0] << ", " << savePos[indirect[i]][1] << ", " << savePos[indirect[i]][2] << '\n';
    }

    return;
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // 초기화 && input
        spIdx = -1;
        cin >> n;
        for (int i = 0; i < 20; ++i) {
            savePos[i][0] = savePos[i][1] = savePos[i][2] = 0;
            indirect[i] = i;
        }
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 100; ++c) {
                board[r][c] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        solve();

        cout << '#' << t << ' ' << spIdx + 1 << ' ';
        for (int i = 0; i <= spIdx; ++i) {
            cout << savePos[indirect[i]][1] << ' ' << savePos[indirect[i]][2] << ' ';
        }
        cout << '\n';
    }

    return 0;
}