// 3번: 최빈수 구하기

#include <iostream>

using namespace std;

int t;
int num;

int main()
{
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int test_case;
        cin >> test_case;

        int score[101] = {0};
        for (int i = 0; i < 1000; ++i) {
            cin >> num;
            score[num]++;
        }

        int answer_highscore = 0;
        int answer_highcount = score[0];

        for (int i = 1; i < 101; ++i) {
            if (answer_highcount <= score[i]) {
                answer_highcount = score[i];
                answer_highscore = i;
            }
        }

        cout << '#' << test_case << ' ' << answer_highscore << '\n';
    }

    return 0;
}