#include <iostream>

using namespace std;

int pos[2] = {0, 0};

bool isSafe(int y)
{
    if (y >= 0 && y < 100) {
        return true;
    }
    return false;
}

bool solve(int y, int (*board)[100])
{
    for (int i = 0; i < 100; ++i) {
        if (board[i][y] == 2) {
            return true;
        }
        // 왼쪽
        if (isSafe(y - 1) && board[i][y - 1] == 1) {
            --y;
            while (y >= 0) {
                if (!isSafe(y - 1)) {
                    break;
                }
                else if (board[i][y - 1] == 0) {
                    break;
                }
                else {
                    --y;
                }
            }
        }
        // 오른쪽
        else if (isSafe(y + 1) && board[i][y + 1] == 1) {
            ++y;
            while (y < 100) {
                // 범위 벗어나면 컷
                if (!isSafe(y + 1)) {
                    break;
                }
                else if (board[i][y + 1] == 0) {
                    break;
                }
                else {
                    ++y;
                }
            }
        }
    }
    return false;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int test_case;
        cin >> test_case;

        int board[100][100];
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 100; ++c) {
                cin >> board[r][c];
                if (board[r][c] == 2) {
                    pos[0] = r;
                    pos[1] = c;
                }
            }
        }

        for (int c = 0; c < 100; ++c) {
            // 사다리 있으면
            if (board[0][c] == 1) {
                if (solve(c, board)) {
                    cout << '#' << test_case << ' ' << c << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}