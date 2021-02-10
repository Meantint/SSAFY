// 문제에서 범위 설정을 잘 이해하여 추출해내야함.
// 그리고 자료형에서의 실수가 너무 많았음

#include <iostream>

using namespace std;

int n, m, answer = -1;
int arr[10010];

int solve()
{
    long long people = n - m;
    long long lo = 0, hi = 60000000000;
    long long find;

    if (people > 0) {
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long sum = 0;
            for (int i = 0; i < m; ++i) {
                sum += (mid / arr[i]);
                if (sum >= people) {
                    break;
                }
            }
            // 놀이기구 탄 사람의 수가 people(마지막 아이)를 넘어섰다면 시간을 줄여야함
            if (sum >= people) {
                hi = mid - 1;
            }
            // 넘어서지 않은 것들 중 가장 큰 값 저장
            else {
                find = mid;
                lo = mid + 1;
            }
        }
    }
    else {
        return n;
    }
    // cout << find << '\n';
    for (int i = 0; i < m; ++i) {
        people -= (find / arr[i]);
    }
    ++find;

    int answer = 0;
    for (int i = 0; i < m; ++i) {
        if (find % arr[i] == 0) {
            --people;
            if (people == 0) {
                answer = i + 1;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    // 입력
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    cout << solve() << '\n';

    return 0;
}