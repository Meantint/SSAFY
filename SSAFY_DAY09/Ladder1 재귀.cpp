#include <iostream>

using namespace std;

int answer = -1;
// up, left, right
int dr[3] = {-1, 0, 0};
int dc[3] = {0, -1, 1};

bool isSafe(int c)
{
    if (c >= 0 && c < 100) {
        return true;
    }
    return false;
}

void solve(int (*board)[100], int cur_r, int cur_c, int dir)
{
    // cout << '(' << cur_r << ", " << cur_c << ')' << '\n';
    if (cur_r == 0) {
        answer = cur_c;

        return;
    }
    if (dir == 1 || dir == 2) {
        if (cur_c != 0 && cur_c != 99 && board[cur_r][cur_c + dc[dir]] == 1) {
            solve(board, cur_r, cur_c + dc[dir], dir);
        }
        else {
            solve(board, cur_r + dr[0], cur_c, 0);
        }
    }
    else {
        if (isSafe(cur_c - 1) && board[cur_r][cur_c - 1] == 1) {
            solve(board, cur_r, cur_c - 1, 1);
        }
        else if (isSafe(cur_c + 1) && board[cur_r][cur_c + 1] == 1) {
            solve(board, cur_r, cur_c + 1, 2);
        }
        else {
            solve(board, cur_r + dr[0], cur_c, 0);
        }
    }

    return;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        answer = -1;
        int test_case;
        cin >> test_case;

        int board[100][100];
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 100; ++c) {
                cin >> board[r][c];
            }
        }

        for (int c = 0; c < 100; ++c) {
            if (board[99][c] == 2) {
                solve(board, 99, c, 0);
                cout << '#' << test_case << ' ' << answer << '\n';
            }
        }
    }
}