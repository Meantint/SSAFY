#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

// input : (1, 2) (1, 3) (2, 4) (2, 5) (4, 6) (5, 6) (6, 7) (3, 7)
int adj[8][4];
bool isVisited[8];

void recursive_selection(int arr[], int st, int ed)
{
    if (st == ed) {
        return;
    }

    int min_num = arr[st];
    int min_idx = st;
    for (int j = st + 1; j < ed; ++j) {
        if (min_num > arr[j]) {
            min_num = arr[j];
            min_idx = j;
        }
    }
    if (st != min_idx) {
        SWAP(arr[st], arr[min_idx]);
    }

    recursive_selection(arr, st + 1, ed);

    return;
}

void solve(int cur)
{
    cout << cur << ' ';
    isVisited[cur] = true;

    bool isDone = true;
    for (int i = 0; i < 8; ++i) {
        if (!isVisited[i]) {
            isDone = false;
        }
    }
    if (isDone) {
        return;
    }

    for (int c = 0; c < 4; ++c) {
        // 길이 없다면
        if (adj[cur][c] == 2112345678) {
            break;
        }
        // 이미 방문했다면
        if (isVisited[adj[cur][c]]) {
            continue;
        }
        solve(adj[cur][c]);
    }

    return;
}

int main()
{
    // adj 초기화
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 4; ++c) {
            adj[r][c] = 2112345678;
        }
    }
    for (int i = 0; i < 8; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        for (int c = 0; c < 4; ++c) {
            if (adj[v1][c] == 2112345678) {
                adj[v1][c] = v2;
                break;
            }
        }
        for (int c = 0; c < 4; ++c) {
            if (adj[v2][c] == 2112345678) {
                adj[v2][c] = v1;
                break;
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        int len = 0;

        for (int j = 0; j < 4; ++j) {
            if (adj[i][j] == 2112345678) {
                break;
            }
            ++len;
        }
        recursive_selection(adj[i], 0, len);
    }
    for (int i = 0; i < 8; ++i) {
        isVisited[i] = false;
    }

    solve(1);

    return 0;
}