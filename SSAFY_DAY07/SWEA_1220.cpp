#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

bool isSafe(int r, int c, int len)
{
    if (r >= 0 && r < len && c >= 0 && c < len) {
        return true;
    }
    return false;
}

void move_1(int (*board)[100], int len)
{
    for (int r = len - 1; r >= 0; --r) {
        for (int c = 0; c < len; ++c) {
            if (board[r][c] == 1) {
                if (r == len - 1) {
                    board[len - 1][c] = 0;
                    continue;
                }
                int cp_r = r;
                while (isSafe(cp_r + 1, c, len)) {
                    if (board[cp_r + 1][c] == 0) {
                        SWAP(board[cp_r + 1][c], board[cp_r][c]);
                        ++cp_r;
                        if (cp_r == len - 1) {
                            board[len - 1][c] = 0;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void move_2(int (*board)[100], int len)
{
    for (int r = 0; r < len; ++r) {
        for (int c = 0; c < len; ++c) {
            if (board[r][c] == 2) {
                if (r == 0) {
                    board[0][c] = 0;
                    continue;
                }
                int cp_r = r;
                while (isSafe(cp_r - 1, c, len)) {
                    if (board[cp_r - 1][c] == 0) {
                        SWAP(board[cp_r - 1][c], board[cp_r][c]);
                        --cp_r;
                        if (cp_r == 0) {
                            board[0][c] = 0;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int len;
        cin >> len;

        int board[100][100];
        for (int r = 0; r < len; ++r) {
            for (int c = 0; c < len; ++c) {
                cin >> board[r][c];
            }
        }
        move_1(board, len);
        move_2(board, len);

        int answer = 0;

        for (int c = 0; c < len; ++c) {
            bool is_one = false;
            for (int r = 0; r < len; ++r) {
                if (board[r][c] == 1) {
                    is_one = true;
                }
                else if (board[r][c] == 2) {
                    if (is_one == true) {
                        ++answer;
                    }
                    is_one = false;
                }
            }
        }

        cout << '#' << t + 1 << ' ' << answer << '\n';
    }

    return 0;
}