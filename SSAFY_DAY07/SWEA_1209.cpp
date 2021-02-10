#include <iostream>

using namespace std;

int main()
{
    for (int t = 0; t < 10; ++t) {
        int board[100][100];

        int test_case;
        cin >> test_case;
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 100; ++c) {
                cin >> board[r][c];
            }
        }

        int answer = 0;
        for (int r = 0; r < 100; ++r) {
            int sum = 0;
            for (int c = 0; c < 100; ++c) {
                sum += board[r][c];
            }
            if (answer < sum) {
                answer = sum;
            }
        }
        for (int c = 0; c < 100; ++c) {
            int sum = 0;
            for (int r = 0; r < 100; ++r) {
                sum += board[r][c];
            }
            if (answer < sum) {
                answer = sum;
            }
        }
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < 100; ++i) {
            sum1 += board[i][i];
            sum2 += board[i][99 - i];
        }
        if (answer < sum1) {
            answer = sum1;
        }
        if (answer < sum2) {
            answer = sum2;
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;
}