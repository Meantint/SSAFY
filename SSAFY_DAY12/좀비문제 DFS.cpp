#include <iostream>

using namespace std;

int isVisited[1010];
int skill[3];

void solve(int cur, int t, int cnt)
{
    // cout << cur << ", " << t << ", " << cnt << endl;
    // 같으면 계속 돌기 때문에 같은 경우에도 리턴 해줘야 한다.
    if (isVisited[cur] <= cnt) {
        return;
    }
    isVisited[cur] = cnt;
    if (cur == t) {
        return;
    }

    for (int i = 0; i < 3; ++i) {
        int next = cur + skill[i];
        if (next > t) {
            continue;
        }
        solve(next, t, cnt + 1);
    }

    return;
}

int main()
{
    for (int t = 0; t < 3; ++t) {
        for (int i = 0; i < 1001; ++i) {
            isVisited[i] = 2112345678;
        }
        int start, target;
        cin >> start >> target;

        for (int i = 0; i < 3; ++i) {
            cin >> skill[i];
        }
        solve(start, target, 0);
        cout << isVisited[target] << '\n';
    }
    return 0;
}