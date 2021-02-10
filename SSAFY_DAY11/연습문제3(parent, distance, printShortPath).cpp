#include <iostream>

using namespace std;

int adj[100][100] = {0};
int parent[100], dist[100];
bool isVisited[100] = {0};

int v, e;
int queue[1000];
int front, rear;

void solve()
{
    cout << '\n'
         << "BFS 방문 순서 : ";
    int start = 1;

    queue[++rear] = start;
    isVisited[start] = true;

    while (front != rear) {
        int cur = queue[++front];
        cout << cur << ' ';

        for (int i = 1; i <= adj[cur][0]; ++i) {
            int next = adj[cur][i];
            // 이미 방문한 적이 있다면
            if (isVisited[next]) {
                continue;
            }
            isVisited[next] = true;
            // 부모 결정
            parent[next] = cur;
            // 거리 결정
            dist[next] = dist[cur] + 1;

            queue[++rear] = next;
        }
    }
    cout << '\n';

    return;
}

void printShortPath(int start)
{
    int path[100] = {0};

    int cur = start;
    int path_idx = -1;

    while (1) {
        path[++path_idx] = cur;
        cur = parent[cur];
        if (cur == 0) {
            break;
        }
    }
    for (int i = path_idx; i > 0; --i) {
        cout << path[i] << " -> ";
    }
    cout << path[0] << '\n';

    return;
}

int main()
{
    // 초기화
    front = rear = -1;
    for (int i = 0; i < 100; ++i) {
        parent[i] = 0;
        dist[i] = 0;
    }

    cout << "[vertex 최소최대 범위: (1 ~ 99), 1번 Node 시작]vertex와 edge의 개수를 적으세요" << '\n';
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1][++adj[v1][0]] = v2;
        adj[v2][++adj[v2][0]] = v1;
    }

    solve();

    // 부모 노드 출력
    cout << '\n';
    cout << "1번 Node ~ " << v << "번 Node까지의 부모 : ";
    for (int i = 1; i <= v; ++i) {
        cout << parent[i] << ' ';
    }
    cout << '\n'
         << '\n';

    // 1번 Node로 부터의 거리 출력
    cout << "1번 Node로 부터의 각각의 거리 : ";
    for (int i = 1; i <= v; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n'
         << '\n';

    for (int i = 1; i <= v; ++i) {
        cout << "1번 Node에서의 " << i << "번 Node까지의 최단 거리 : ";
        printShortPath(i);
    }
    cout << '\n';

    return 0;
}