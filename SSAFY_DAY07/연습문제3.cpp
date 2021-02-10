#include <iostream>

using namespace std;

// 순서대로 오른쪽으로 90도씩 꺾음
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int new_arr[5][5];
int board[5][5] = {
    {9, 20, 2, 18, 11},
    {19, 1, 25, 3, 21},
    {8, 24, 10, 17, 7},
    {15, 4, 16, 5, 6},
    {12, 13, 22, 23, 14}};
bool isVisited[5][5];

bool isSafe(int x, int y)
{
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        return true;
    }
    return false;
}

int main()
{
    // isVisited 초기화
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            isVisited[r][c] = false;
        }
    }
    int dir = 0;  // 시작 방향 오른쪽
    int curpos[2] = {0, 0};

    for (int t = 0; t < 25; ++t) {
        int min_num = 2112345678;
        int pos[2] = {-1, -1};
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (min_num > board[r][c]) {
                    min_num = board[r][c];
                    pos[0] = r;
                    pos[1] = c;
                }
            }
        }
        board[pos[0]][pos[1]] = 2112345678;
        new_arr[curpos[0]][curpos[1]] = min_num;
        isVisited[curpos[0]][curpos[1]] = true;

        if (isSafe(curpos[0] + dx[dir], curpos[1] + dy[dir]) && !isVisited[curpos[0] + dx[dir]][curpos[1] + dy[dir]]) {
        }
        else {
            dir = (dir + 1) % 4;
        }
        curpos[0] += dx[dir];
        curpos[1] += dy[dir];
    }
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            cout << new_arr[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}