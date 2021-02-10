#include <iostream>

using namespace std;

int n, m;
int board[50][50];

int house_pos[110][2];
int house_idx = -1;
int chicken_pos[13][2];
int chicken_idx = -1;

int answer = 2112345678;

int house_to_chicken[110][13];

int cal(int arr1[2], int arr2[2])
{
    int dist_x = arr1[0] - arr2[0];
    int dist_y = arr1[1] - arr2[1];
    if (dist_x < 0) {
        dist_x *= -1;
    }
    if (dist_y < 0) {
        dist_y *= -1;
    }
    return dist_x + dist_y;
}

void solve(int cnt, int cur, int search)
{
    if (cnt == m) {
        // cout << "search : " << search << '\n';
        int sum = 0;
        for (int i = 0; i < house_idx; ++i) {
            int val = 2112345678;
            for (int j = 0; j < chicken_idx; ++j) {
                if ((search & (1 << j)) != 0) {
                    if (val > house_to_chicken[i][j]) {
                        val = house_to_chicken[i][j];
                    }
                }
            }
            sum += val;
        }
        if (answer > sum) {
            answer = sum;
        }
        return;
    }
    for (int i = cur; i < chicken_idx; ++i) {
        solve(cnt + 1, i + 1, (search | (1 << i)));
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken_pos[++chicken_idx][0] = i;
                chicken_pos[chicken_idx][1] = j;
            }
            else if (board[i][j] == 1) {
                house_pos[++house_idx][0] = i;
                house_pos[house_idx][1] = j;
            }
        }
    }
    ++house_idx;
    ++chicken_idx;
    for (int i = 0; i < house_idx; ++i) {
        for (int j = 0; j < chicken_idx; ++j) {
            house_to_chicken[i][j] = cal(house_pos[i], chicken_pos[j]);
            // cout << "house_to_chicken[" << i << "][" << j << "] : " << house_to_chicken[i][j] << '\n';
        }
    }

    solve(0, 0, 0);
    cout << answer << '\n';

    return 0;
}