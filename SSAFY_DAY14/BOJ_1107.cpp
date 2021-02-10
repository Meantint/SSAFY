#include <iostream>

using namespace std;

int answer = 2112345678;
int channel;
int m, b;
bool isPos[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int isVisited[1001000];

void solve()
{
    int q[1001000];
    int front = -1, rear = -1;

    answer = (channel > 100) ? (channel - 100) : (100 - channel);
    if (answer == 0) {
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (isPos[i]) {
            q[++rear] = i;
            isVisited[i] = 1;
        }
    }
    while (front != rear) {
        int cur = q[++front];
        // cout << "cur : " << cur << ", "
        //      << "isVisited[cur] : " << isVisited[cur] << '\n';

        // cur에서의 원하는 채널까지의 번호차이 + cur를 만드는데 누른 횟수
        int comp = ((cur > channel) ? (cur - channel) : (channel - cur)) + isVisited[cur];
        if (comp < answer) {
            answer = comp;
        }
        for (int i = 0; i < 10; ++i) {
            if (isPos[i]) {
                int next = cur * 10 + i;
                if (next < 1001000 && (isVisited[next] > isVisited[cur] + 1)) {
                    // if (((next > channel) ? (next - channel) : (channel - next)) <= answer) {
                    q[++rear] = next;
                    isVisited[next] = isVisited[cur] + 1;
                    // }
                }
            }
        }
    }
    return;
}

void init()
{
    for (int i = 0; i < 1001000; ++i) {
        isVisited[i] = 2112345678;
    }
    return;
}

int main()
{
    cin >> channel >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b;
        isPos[b] = false;
    }

    init();
    solve();
    cout << answer << '\n';

    return 0;
}