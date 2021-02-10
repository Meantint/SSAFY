#include <iostream>

using namespace std;

int* h;
int answer = 1234567;
int n, b;

void solve(int start, int cur)
{
    // 현재 정답보다 더 작은 경우가 있다면
    if (cur - b >= 0 && cur - b < answer) {
        answer = cur - b;
        return;
    }

    for (int i = start; i < n; ++i) {
        solve(i + 1, cur + h[i]);
    }
}

int main()
{
    int tc;
    cin >> tc;

    for (int t = 0; t < tc; ++t) {
        answer = 1234567;
        cin >> n >> b;

        h = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        solve(0, 0);

        cout << '#' << t + 1 << ' ' << answer << '\n';
    }

    return 0;
}