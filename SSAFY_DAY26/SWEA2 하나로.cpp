#include <iostream>

using namespace std;

int n, tc;
int pos_point[1000][2];  // 각 점의 좌표를 저장하는 배열
bool isVisited[1000];
long double e;
long long table[1000][1000];

long long prim(int start)
{
    long long answer = 0;
    int cnt = 1;
    isVisited[start] = true;

    while (cnt != n) {
        long long min_dist = 10000000LL * 10000000LL;
        int sav_pos[2];
        for (int i = 0; i < n; ++i) {
            // 아직 선택되지 않은 노드에서 찾으면 안된다.
            if (!isVisited[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                // 이미 연결된 노드 구역과의 연결선을 굳이 볼 필요 없다.
                if (isVisited[j]) {
                    continue;
                }
                if (min_dist > table[i][j]) {
                    min_dist = table[i][j];
                    sav_pos[0] = i;
                    sav_pos[1] = j;
                }
            }
        }
        answer += min_dist;
        isVisited[sav_pos[1]] = true;
        ++cnt;
    }

    return answer;
}

void solve(int t)
{
    for (int i = 0; i < n; ++i) {
        isVisited[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                table[i][j] = 100000000LL * 100000000LL;
            }
            else if (i > j) {
                table[i][j] = table[j][i];
            }
            else {
                long long lenX = pos_point[i][0] - pos_point[j][0];
                long long lenY = pos_point[i][1] - pos_point[j][1];
                // i와 j간의 거리를 저장해두는 배열
                table[i][j] = lenX * lenX + lenY * lenY;
            }
        }
    }
    cout << "#" << t + 1 << ' ' << (long long)(e * prim(0) + 0.5) << '\n';

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> pos_point[i][0];
        }
        for (int i = 0; i < n; ++i) {
            cin >> pos_point[i][1];
        }
        cin >> e;

        solve(t);
    }
}