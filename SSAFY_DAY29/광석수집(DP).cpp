// DP
#include <iostream>

using namespace std;

int n, m;
int board[200][200];

void solve()
{
    // 왼쪽, 위쪽 끝부분 처리
    for (int i = 1; i < n; ++i) {
        board[i][0] += board[i - 1][0];
    }
    for (int j = 1; j < m; ++j) {
        board[0][j] += board[0][j - 1];
    }

    // 나머지 부분 처리
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int tmp;
            if (board[i - 1][j] >= board[i][j - 1]) {
                tmp = board[i - 1][j];
            }
            else {
                tmp = board[i][j - 1];
            }
            board[i][j] = tmp + board[i][j];
        }
    }

    cout << "board 배열 출력\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n'
         << "최대 개수 : " << board[n - 1][m - 1] << '\n';
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    solve();

    return 0;
}