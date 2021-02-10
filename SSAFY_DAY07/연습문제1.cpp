#include <iostream>

#define ABS(N) \
    if (N < 0) N *= -1

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int abs_array[5][5];
int sum_all_abs = 0;

int board[5][5] = {
    {9, 20, 2, 18, 11},
    {19, 1, 25, 3, 21},
    {8, 24, 10, 17, 7},
    {15, 4, 16, 5, 6},
    {12, 13, 22, 23, 14}};

bool isSafe(int r, int c)
{
    if (r >= 0 && r < 5 && c >= 0 && c < 5) {
        return true;
    }
    return false;
}

int main()
{
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            int sum = 0;
            for (int i = 0; i < 4; ++i) {
                // 배열 범위 안이라면 연산한다.
                if (isSafe(r + dx[i], c + dy[i])) {
                    int val = board[r + dx[i]][c + dy[i]] - board[r][c];
                    ABS(val);
                    sum += val;
                }
            }
            abs_array[r][c] = sum;
        }
    }

    cout << "Base Array\n";
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "Abs Array\n";
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            cout << abs_array[r][c] << ' ';
            sum_all_abs += abs_array[r][c];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << "sum_all_abs: " << sum_all_abs << '\n';

    return 0;
}