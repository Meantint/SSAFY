#include <iostream>

using namespace std;

int n, e;
int v1, v2;
int parent[101];

int myFind(int cur)
{
    if (cur == parent[cur]) {
        return cur;
    }
    else {
        return parent[cur] = myFind(parent[cur]);
    }
}

void myUnion(int n1, int n2)
{
    n1 = myFind(n1);
    n2 = myFind(n2);

    (n1 < n2) ? (parent[n2] = n1) : (parent[n1] = n2);
}

void solve()
{
    // 초기화
    for (int i = 0; i < 101; ++i) {
        parent[i] = i;
    }

    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        cin >> v1 >> v2;
        myUnion(v1, v2);
    }

    int answer = 0;
    int targetNum = myFind(1);  // 1번 컴퓨터와 연결되어있는 것의 개수를 구한다.
    for (int i = 2; i <= n; ++i) {
        if (targetNum == myFind(i)) {
            ++answer;
        }
    }
    cout << answer << '\n';

    return;
}

int main()
{
    solve();

    return 0;
}