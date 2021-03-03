// Memoization
#include <iostream>

using namespace std;

int n, m;
int board[200][200];
int memo[200][200];

void solve()
{
    // (0, 0)
    memo[0][0] = board[0][0];

    // 왼쪽, 위쪽 끝부분 처리
    for (int i = 1; i < n; ++i) {
        memo[i][0] = memo[i - 1][0] + board[i][0];
    }
    for (int j = 1; j < m; ++j) {
        memo[0][j] = memo[0][j - 1] + board[0][j];
    }

    // 나머지 부분 처리
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int tmp;
            if (memo[i - 1][j] >= memo[i][j - 1]) {
                tmp = memo[i - 1][j];
            }
            else {
                tmp = memo[i][j - 1];
            }
            memo[i][j] = tmp + board[i][j];
        }
    }

    cout << "memo 배열 출력\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n'
         << "최대 개수 : " << memo[n - 1][m - 1] << '\n';
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
