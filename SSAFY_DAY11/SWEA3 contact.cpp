#include <iostream>

using namespace std;

int len, st;
int queue[100000];
int answer = -1;
int front, rear;

void solve(int adj[][101], int start, bool isVisited[])
{
    answer = start;
    isVisited[start] = true;
    queue[++rear] = start;

    while (front != rear) {
        int cp_rear = rear;
        answer = -1;
        for (int j = front; j < cp_rear; ++j) {
            int cur = queue[++front];
            if (answer < cur) {
                answer = cur;
            }

            for (int i = 1; i <= adj[cur][0]; ++i) {
                int next = adj[cur][i];
                if (isVisited[next]) {
                    continue;
                }
                isVisited[next] = true;
                queue[++rear] = next;
            }
        }
    }

    return;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        int adj[101][101] = {0};
        bool isVisited[101] = {0};
        front = -1, rear = -1;

        cin >> len >> st;

        for (int i = 0; i < len / 2; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1][++adj[v1][0]] = v2;
        }

        solve(adj, st, isVisited);

        cout << '#' << t + 1 << ' ' << answer << '\n';
    }

    return 0;
}