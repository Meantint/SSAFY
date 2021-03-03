// 값 자체가 -1인 경우가 있어서 dp 초기값을 -1로 두면 안된다.
#include <iostream>

using namespace std;

int tc, n;
int op[4];
int operList[11];
int operIdx;
int numList[12];
int dp[11][(1 << 11)];
int maxRes, minRes;

int myCal(int cur, int opIdx, int val)
{
    if (operList[opIdx] == 0) {
        val += numList[cur + 1];
    }
    else if (operList[opIdx] == 1) {
        val -= numList[cur + 1];
    }
    else if (operList[opIdx] == 2) {
        val *= numList[cur + 1];
    }
    else {
        val /= numList[cur + 1];
    }

    return val;
}

// 현재 위치, 현재 연산자, 사용한 oper들의 비트마스크, 현재까지의 값
void myMaxDFS(int cur, int opIdx, int info, int val)
{
    // 이미 방문했다면
    if (((1 << opIdx) & info) != 0) {
        return;
    }
    int newInfo = ((1 << opIdx) | info);
    // cout << "newInfo : " << newInfo << '\n';
    int newVal = myCal(cur, opIdx, val);

    // 처음 방문한 경우
    if (dp[cur][newInfo] == -2112345678) {
        dp[cur][newInfo] = newVal;
    }
    else {
        if (dp[cur][newInfo] < newVal) {
            dp[cur][newInfo] = newVal;
        }
        else {
            return;
        }
    }

    // cout << (1 << (n - 1)) - 1 << '\n';
    // 모두 방문했다면 종료
    if (newInfo == (1 << (n - 1)) - 1) {
        // cout << "cur : " << cur << ", dp[cur][newInfo] : " << dp[cur][newInfo] << '\n';
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        myMaxDFS(cur + 1, i, newInfo, newVal);
    }
}
void myMinDFS(int cur, int opIdx, int info, int val)
{
    // 이미 방문했다면
    if (((1 << opIdx) & info) != 0) {
        return;
    }
    int newInfo = ((1 << opIdx) | info);
    // cout << "newInfo : " << newInfo << '\n';
    int newVal = myCal(cur, opIdx, val);

    // 처음 방문한 경우
    if (dp[cur][newInfo] == -2112345678) {
        dp[cur][newInfo] = newVal;
    }
    else {
        if (dp[cur][newInfo] > newVal) {
            dp[cur][newInfo] = newVal;
        }
        else {
            return;
        }
    }

    if (newInfo == (1 << (n - 1)) - 1) {
        // cout << "cur : " << cur << ", dp[cur][newInfo] : " << dp[cur][newInfo] << '\n';
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        myMinDFS(cur + 1, i, newInfo, newVal);
    }
}

void solve()
{
    int fast1 = n - 1;
    int fast2 = (1 << fast1);
    for (int i = 0; i < fast1; ++i) {
        for (int j = 0; j < fast2; ++j) {
            dp[i][j] = -2112345678;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        // cur = 0인 경우 0번째 숫자와 1번째 숫자가 연산하는 것 (dp[0]에 담을 것)
        myMaxDFS(0, i, 0, numList[0]);
    }
    maxRes = dp[n - 2][(1 << (n - 1)) - 1];

    for (int i = 0; i < fast1; ++i) {
        for (int j = 0; j < fast2; ++j) {
            dp[i][j] = -2112345678;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        // cur = 0인 경우 0번째 숫자와 1번째 숫자가 연산하는 것 (dp[0]에 담을 것)
        myMinDFS(0, i, 0, numList[0]);
    }
    minRes = dp[n - 2][(1 << (n - 1)) - 1];
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n;
        operIdx = -1;
        for (int i = 0; i < 4; ++i) {
            cin >> op[i];
            for (int j = 0; j < op[i]; ++j) {
                operList[++operIdx] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> numList[i];
        }

        solve();

        cout << '#' << t << ' ' << maxRes - minRes << '\n';
    }

    return 0;
}