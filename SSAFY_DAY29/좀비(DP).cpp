#include <iostream>

using namespace std;

int tc, a, b;
int dp[1010];
int skill[3];

void mySwap(int& n1, int& n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void mySort(int arr[], int lo, int hi)
{
    if (lo >= hi) {
        return;
    }

    int& pivot = arr[hi];
    int i = lo - 1;
    int j = lo;
    for (; j < hi; ++j) {
        if (arr[j] > pivot) {
            mySwap(arr[++i], arr[j]);
        }
    }
    mySwap(arr[++i], pivot);

    mySort(arr, lo, i - 1);
    mySort(arr, i + 1, hi);
}

void myDFS(int cur, int curSkill)
{
    int next = cur + curSkill;
    if (next > b) {
        return;
    }
    if (dp[next] > dp[cur] + 1) {
        dp[next] = dp[cur] + 1;
    }
    else {
        return;
    }
    if (next == b) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        myDFS(next, skill[i]);
    }
}

void solve()
{
    mySort(skill, 0, 2);

    dp[a] = 0;
    for (int i = 0; i < 3; ++i) {
        myDFS(a, skill[i]);
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        // 초기화 & input
        for (int i = 0; i < 1010; ++i) {
            dp[i] = 2112345678;
        }
        cin >> a >> b;
        for (int i = 0; i < 3; ++i) {
            cin >> skill[i];
        }

        solve();

        cout << '#' << t << ' ' << dp[b] << '\n';
    }
}