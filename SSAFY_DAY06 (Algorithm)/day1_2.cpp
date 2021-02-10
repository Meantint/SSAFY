// 2번: View

#include <iostream>

using namespace std;

int main()
{
    // testCase
    for (int t = 0; t < 10; ++t) {
        int len;
        cin >> len;

        int *board = new int[len];
        // 입력
        for (int i = 0; i < len; ++i) {
            cin >> board[i];
        }

        int answer = 0;
        for (int i = 2; i < len - 2; ++i) {
            int max = board[i - 2];
            if (max < board[i - 1]) {
                max = board[i - 1];
            }
            if (max < board[i + 1]) {
                max = board[i + 1];
            }
            if (max < board[i + 2]) {
                max = board[i + 2];
            }

            if (max < board[i]) {
                answer += (board[i] - max);
                i += 2;
            }
        }
        cout << '#' << t + 1 << ' ' << answer << '\n';
    }
}