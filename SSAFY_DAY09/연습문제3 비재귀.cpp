#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

// input : (1, 2) (1, 3) (2, 4) (2, 5) (4, 6) (5, 6) (6, 7) (3, 7)
int adj[8][4];
bool isVisited[8];

const int MAX_SIZE = 100000;

struct intStack {
    int stack_size = 0;
    int repository[MAX_SIZE];

    int top()
    {
        if (stack_size == 0) {
            return -1;
        }
        return repository[stack_size - 1];
    }
    void push(int push)
    {
        repository[stack_size++] = push;
    }
    void pop()
    {
        if (stack_size != 0) {
            --stack_size;
        }
    }

    bool empty()
    {
        if (stack_size == 0) {
            return true;
        }
        return false;
    }
};

void selection_reverse(int arr[], int st, int ed)
{
    if (st == ed) {
        return;
    }

    int max_num = arr[st];
    int max_idx = st;
    for (int j = st + 1; j < ed; ++j) {
        if (max_num < arr[j]) {
            max_num = arr[j];
            max_idx = j;
        }
    }
    if (st != max_idx) {
        SWAP(arr[st], arr[max_idx]);
    }

    selection_reverse(arr, st + 1, ed);

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
        selection_reverse(adj[i], 0, len);
    }
    for (int i = 0; i < 8; ++i) {
        isVisited[i] = false;
    }

    // 시작 노드 1
    int cur = 1;
    intStack st;
    st.push(cur);
    while (!st.empty()) {
        int next = st.top();
        st.pop();

        if (isVisited[next]) {
            continue;
        }
        cout << next << ' ';
        isVisited[next] = true;

        for (int i = 0; i < 4; ++i) {
            // 길이 없다면
            if (adj[next][i] == 2112345678) {
                break;
            }
            // 이미 방문했다면
            if (isVisited[adj[next][i]]) {
                continue;
            }
            st.push(adj[next][i]);
        }
    }

    return 0;
}