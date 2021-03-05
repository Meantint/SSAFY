#include <stdio.h>

#include <iostream>

#define INIT 2112345678
#define PII pair<int, int>

using namespace std;

int tc, n, answer;
int board[10][10];

pair<int, int> pp[10], stair[2];  // 위치 정보
int stairSize[2];                 // 계단 길이
int infoStair[2][10];             // 계단 정보

int chooseStair[10];  // i번 사람이 고른 계단
int arriveTime[10];   // i번 사람의 도착 시간

bool isDone[10];  // 계단을 다 내려갔다면

int ppIdx = -1;
int stIdx = -1;

void mySort(int* arr, int lo, int hi)
{
    if (lo >= hi) {
        return;
    }

    int& pivot = arr[hi];

    int i = lo - 1;
    int j = lo;
    for (; j < hi; ++j) {
        if (arr[j] < pivot) {
            int tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[++i];
    arr[i] = pivot;
    pivot = tmp;

    mySort(arr, lo, i - 1);
    mySort(arr, i + 1, hi);
}

int dist(PII p1, PII p2)
{
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;

    if (x < 0) {
        x *= -1;
    }
    if (y < 0) {
        y *= -1;
    }

    return x + y;
}

void simul()
{
    int infoIdx[2] = {-1, -1};
    for (int i = 0; i <= ppIdx; ++i) {
        infoStair[chooseStair[i]][++infoIdx[chooseStair[i]]] = dist(pp[i], stair[chooseStair[i]]);
    }
    mySort(infoStair[0], 0, infoIdx[0]);
    mySort(infoStair[1], 0, infoIdx[1]);
    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j <= infoIdx[i]; ++j) {
    //         cout << infoStair[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= infoIdx[i]; ++j) {
            if (j >= 3) {
                int tmp1 = infoStair[i][j];
                int tmp2 = infoStair[i][j - 3];
                if (tmp2 <= tmp1) {
                    infoStair[i][j] += (stairSize[i] + 1);
                }
                else {
                    infoStair[i][j] = tmp2 + stairSize[i];
                }
            }
            else {
                infoStair[i][j] += (stairSize[i] + 1);
            }
        }
    }
    // cout << "infoStair[0][infoIdx[0]] : " << infoStair[0][infoIdx[0]] << '\n';
    // cout << "infoStair[1][infoIdx[1]] : " << infoStair[1][infoIdx[1]] << '\n';
    int res = infoStair[0][infoIdx[0]];
    if (res < infoStair[1][infoIdx[1]]) {
        res = infoStair[1][infoIdx[1]];
    }
    // cout << "res : " << res << "\n\n";

    if (answer > res) {
        answer = res;
    }
}

void myDFS(int cur)
{
    if (cur == ppIdx + 1) {
        simul();

        return;
    }
    chooseStair[cur] = 0;
    myDFS(cur + 1);

    chooseStair[cur] = 1;
    myDFS(cur + 1);
}

void solve()
{
    for (int i = 0; i < 10; ++i) {
        isDone[i] = false;
    }
    answer = INIT;

    myDFS(0);
}

int main()
{
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        ppIdx = stIdx = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &board[i][j]);
                if (board[i][j] == 1) {
                    pp[++ppIdx].first = i;
                    pp[ppIdx].second = j;
                }
                else if (board[i][j] > 1) {
                    stair[++stIdx].first = i;
                    stair[stIdx].second = j;
                    stairSize[stIdx] = board[i][j];
                }
            }
        }

        solve();

        printf("#%d %d\n", t, answer);
    }
}