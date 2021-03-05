#include <iostream>

using namespace std;

int tc, n, m, l, answer;
int board[50][50];
bool isVisited[50][50];
pair<int, int> stPos;

int front, rear;
pair<int, int> queue[100000];
int queueTime[100000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

void solve()
{
    answer = 0;
    front = rear = -1;

    queue[++rear] = stPos;
    queueTime[rear] = 1;
    while (front != rear) {
        int x = queue[++front].first;
        int y = queue[front].second;
        int curTime = queueTime[front];

        if (isVisited[x][y]) {
            continue;
        }
        isVisited[x][y] = true;
        ++answer;
        // cout << "++answer : " << x << ", " << y << ", " << curTime << '\n';
        if (curTime == l) {
            continue;
        }

        int caseNum = board[x][y];
        if (caseNum == 1) {
            int cx = x - 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 4 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x + 1;
            cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 5 && tmp != 6) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y + 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 4 && tmp != 5) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y - 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 6 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 2) {
            int cx = x - 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 4 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x + 1;
            cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 5 && tmp != 6) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 3) {
            int cx = x;
            int cy = y + 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 4 && tmp != 5) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y - 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 6 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 4) {
            int cx = x - 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 4 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y + 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 4 && tmp != 5) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 5) {
            int cx = x + 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 5 && tmp != 6) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y + 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 4 && tmp != 5) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 6) {
            int cx = x + 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 5 && tmp != 6) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y - 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 6 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
        else if (caseNum == 7) {
            int cx = x - 1;
            int cy = y;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 3 && tmp != 4 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
            cx = x;
            cy = y - 1;
            if (isSafe(cx, cy)) {
                int tmp = board[cx][cy];
                if (tmp != 0 && tmp != 2 && tmp != 6 && tmp != 7) {
                    queue[++rear] = make_pair(cx, cy);
                    queueTime[rear] = curTime + 1;
                }
            }
        }
    }
}

int main()
{
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        cin >> n >> m >> stPos.first >> stPos.second >> l;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
                isVisited[i][j] = false;
            }
        }

        solve();

        cout << '#' << t << ' ' << answer << '\n';
    }

    return 0;
}