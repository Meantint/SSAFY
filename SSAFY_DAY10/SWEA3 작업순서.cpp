#include <iostream>

using namespace std;

int stack[1001];
int top = -1;

void solve(int adj[][100], int ind[], bool isVisited[])
{
    while (top != -1) {
        int cur = stack[top--];

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        cout << cur << ' ';

        for (int i = 1; i < 100; ++i) {
            int next = adj[cur][i];
            if (next == 0) {
                break;
            }
            --ind[next];
            if (ind[next] == 0) {
                stack[++top] = next;
            }
        }
    }

    return;
}

int main()
{
    for (int t = 0; t < 10; ++t) {
        top = -1;
        int adj[1001][100] = {0};
        int indegree[1001] = {0};
        bool isVisited[1001] = {0};

        int v, e;
        cin >> v >> e;

        for (int i = 0; i < e; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1][++adj[v1][0]] = v2;
            ++indegree[v2];
        }
        for (int i = 1; i <= v; ++i) {
            if (indegree[i] == 0) {
                stack[++top] = i;
            }
        }

        cout << '#' << t + 1 << ' ';
        solve(adj, indegree, isVisited);
        cout << '\n';
    }

    return 0;
}