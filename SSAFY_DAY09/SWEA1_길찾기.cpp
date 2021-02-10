#include <iostream>

using namespace std;

int adj[100][2];
bool isVisited[100];

bool solve(int cur)
{
    isVisited[cur] = true;
    if (cur == 99) {
        return true;
    }
    bool isPos = false;
    for (int c = 0; c < 2; ++c) {
        // 이미 방문 가능한 것을 알았다면 break
        if (isPos) {
            break;
        }
        // 길이 없다면
        if (adj[cur][c] == -1) {
            break;
        }
        isPos = solve(adj[cur][c]);
    }
    isVisited[cur] = false;

    return isPos;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        // 간선 초기화 & 방문 정보 초기화
        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c < 2; ++c) {
                adj[r][c] = -1;
            }
            isVisited[r] = false;
        }

        int test_case, edge;
        cin >> test_case >> edge;

        for (int i = 0; i < edge; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            for (int c = 0; c < 2; ++c) {
                // 아직 넣지 않았다면 이곳에 넣어준다.
                if (adj[v1][c] == -1) {
                    adj[v1][c] = v2;
                    break;
                }
            }
        }
        if (solve(0)) {
            cout << '#' << test_case << ' ' << 1 << '\n';
        }
        else {
            cout << '#' << test_case << ' ' << 0 << '\n';
        }
    }

    return 0;
}