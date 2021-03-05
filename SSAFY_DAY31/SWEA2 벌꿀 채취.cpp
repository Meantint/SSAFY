#include <iostream>

using namespace std;

int tc, n, m, maxC;
int colSize;
int maxCol;
int board[10][10];
int squared[10][10];
int allCase[10][10];
int maxVal[10];
int answer;
pair<int, int> otherRow;

int myDFS(int x, int cur, int vol, int cost)
{
    vol += board[x][cur];
    if (vol > maxC) {
        return cost;
    }
    cost += squared[x][cur];

    int res = cost;
    for (int c = cur + 1; c < maxCol; ++c) {
        int tmp = myDFS(x, c, vol, cost);
        if (res < tmp) {
            res = tmp;
        }
    }
    return res;
}

void solve()
{
    otherRow.first = otherRow.second = -1;
    colSize = n - m + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < colSize; ++j) {
            allCase[i][j] = 0;
        }
        maxVal[i] = 0;
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < colSize; ++c) {
            maxCol = c + m;
            for (int i = c; i < maxCol; ++i) {
                int tmp = myDFS(r, i, 0, 0);
                if (allCase[r][c] < tmp) {
                    allCase[r][c] = tmp;
                }
            }
            // cout << allCase[r][c] << ' ';
        }
        // cout << '\n';
    }
    // cout << '\n';

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < colSize; ++c) {
            int tmp;
            if (c + m < colSize) {
                tmp = allCase[r][c] + allCase[r][c + m];
            }
            else {
                tmp = allCase[r][c];
            }
            if (maxVal[r] < tmp) {
                maxVal[r] = tmp;
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        int tmp = 0;
        for (int c = 0; c < colSize; ++c) {
            int curVal = allCase[r][c];
            if (tmp < curVal) {
                tmp = curVal;
            }
        }
        if (otherRow.first <= tmp) {
            otherRow.second = otherRow.first;
            otherRow.first = tmp;
        }
        else {
            if (otherRow.second < tmp) {
                otherRow.second = tmp;
            }
        }
    }

    answer = -1;
    for (int i = 0; i < n; ++i) {
        if (answer < maxVal[i]) {
            answer = maxVal[i];
        }
    }
    if (answer < otherRow.first + otherRow.second) {
        answer = otherRow.first + otherRow.second;
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n >> m >> maxC;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
                squared[i][j] = board[i][j] * board[i][j];
            }
        }

        solve();

        cout << '#' << t << ' ' << answer << '\n';
    }

    return 0;
}