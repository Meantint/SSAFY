#include <iostream>

using namespace std;

int tc, n, m;
int pp[101];
int parent[101];
bool answer[101];
int res = 0;

int find(int cur)
{
    if (parent[cur] == cur) {
        return cur;
    }

    return parent[cur] = find(parent[cur]);
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        res = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            answer[i] = false;
        }
        for (int i = 0; i < m; ++i) {
            int p1, p2;
            cin >> p1 >> p2;

            int f1 = find(p1);
            int f2 = find(p2);
            if (f1 == f2) {
                continue;
            }
            if (f1 < f2) {
                int tmp = f1;
                f1 = f2;
                f2 = tmp;
            }
            parent[f1] = f2;
        }

        for (int i = 1; i <= n; ++i) {
            if (!answer[find(i)]) {
                answer[find(i)] = true;
                ++res;
            }
        }

        cout << '#' << t << ' ' << res << '\n';
    }

    return 0;
}