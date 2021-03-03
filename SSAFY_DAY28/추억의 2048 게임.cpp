#include <iostream>

using namespace std;

int n, tc;
char text[4];
int board[20][20];
bool isComb[20][20];

// up, right, down, left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void rotate90()
{
    int copy_board[20][20];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            copy_board[j][n - 1 - i] = board[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = copy_board[i][j];
        }
    }
}

void solve()
{
    int dir = -1;
    if (text[0] == 'u') {
        dir = 0;
    }
    else if (text[0] == 'r') {
        rotate90();
        rotate90();
        rotate90();
    }
    else if (text[0] == 'd') {
        rotate90();
        rotate90();
    }
    else {
        rotate90();
    }

    // 회전

    for (int c = 0; c < n; ++c) {
        for (int r = 1; r < n; ++r) {
            if (board[r][c] == 0) {
                continue;
            }
            else {
                // 같아서 탈출한건지(합쳐야 하는 경우)
                bool isSame = false;
                int cur_row = r - 1;
                while (cur_row >= 0) {
                    if (board[cur_row][c] == 0) {
                        --cur_row;
                    }
                    else if (board[cur_row][c] != board[r][c]) {
                        ++cur_row;
                        break;
                    }
                    else {
                        if (!isComb[cur_row][c]) {
                            isSame = true;
                            break;
                        }
                        else {
                            ++cur_row;
                            break;
                        }
                    }
                }
                if (cur_row == -1) {
                    ++cur_row;
                }
                if (cur_row == r) {
                    continue;
                }
                if (isSame) {
                    board[cur_row][c] *= 2;
                    isComb[cur_row][c] = true;
                    board[r][c] = 0;
                }
                else {
                    board[cur_row][c] = board[r][c];
                    board[r][c] = 0;
                }
            }
        }
    }

    if (text[0] == 'r') {
        rotate90();
    }
    else if (text[0] == 'd') {
        rotate90();
        rotate90();
    }
    else if (text[0] == 'l') {
        rotate90();
        rotate90();
        rotate90();
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n >> text;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
                isComb[i][j] = false;
            }
        }

        solve();

        cout << '#' << t << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}