#include <iostream>

#define SWAP(X, Y) \
    if (X != Y) X ^= Y ^= X ^= Y

using namespace std;

int tc;
int size;
int num, change;

bool findSame(int arr[])
{
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }

    return false;
}

int getNum(int arr[])
{
    int val = 0;
    for (int i = 0; i < size; ++i) {
        val = val * 10 + arr[i];
    }
    return val;
}

int solve(int arr[], int st, int c)
{
    int val = 0;
    // 교환 횟수가 끝이 났다면
    if (c == 0) {
        return getNum(arr);
    }
    // 이미 내림차순 구조인지의 여부
    bool isDesc = true;
    for (int i = 1; i < size; ++i) {
        if (arr[i - 1] < arr[i]) {
            isDesc = false;
            break;
        }
    }
    // 정렬이 완료되었다면 c가 짝수 홀수인지에 따라 다르게 리턴
    if (isDesc) {
        // 짝수라면 그대로 리턴
        if (c % 2 == 0) {
            return getNum(arr);
        }
        // 홀수라면
        else {
            // 같은 수가 하나라도 있으면 그대로 리턴
            if (findSame(arr)) {
                return getNum(arr);
            }
            else {
                int cp_arr[6];
                for (int i = 0; i < size; ++i) {
                    cp_arr[i] = arr[i];
                }
                SWAP(cp_arr[size - 2], cp_arr[size - 1]);
                return getNum(cp_arr);
            }
        }
    }

    int target = arr[st];
    int max_num = -1;
    for (int i = st + 1; i < size; ++i) {
        if (max_num < arr[i]) {
            max_num = arr[i];
        }
    }

    int p;
    // 이미 범위 내에서 arr[st]가 가장 크다면
    if (target >= max_num) {
        p = solve(arr, st + 1, c);
        if (val < p) {
            val = p;
        }
    }
    else {
        for (int i = st + 1; i < size; ++i) {
            if (max_num == arr[i]) {
                int cp_arr[6];
                for (int i = 0; i < size; ++i) {
                    cp_arr[i] = arr[i];
                }
                SWAP(cp_arr[st], cp_arr[i]);
                p = solve(cp_arr, st + 1, c - 1);
                if (val < p) {
                    val = p;
                }
            }
        }
    }

    return val;
}

// 초기화
void init(int arr[])
{
    for (int i = 0; i < 6; ++i) {
        arr[i] = -1;
    }

    size = 0;
    while (num != 0) {
        arr[size] = (num % 10);
        ++size;
        num /= 10;
    }
    for (int i = 0; i < size / 2; ++i) {
        SWAP(arr[i], arr[size - i - 1]);
    }

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        int arr[6];
        cin >> num >> change;

        init(arr);

        cout << '#' << t + 1 << ' ' << solve(arr, 0, change) << '\n';
    }

    return 0;
}