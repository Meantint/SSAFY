#include <iostream>

using namespace std;

int n, s;
int answer = 2112345678;

int main()
{
    cin >> n >> s;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int st = 0, ed = 0;
    int sum = arr[0];
    while (ed < n) {
        if (sum >= s) {
            if (ed - st + 1 < answer) {
                answer = ed - st + 1;
            }
            sum -= arr[st];
            ++st;
        }
        else {
            ++ed;
            if (ed == n) {
                if (sum >= s) {
                    if (ed - st + 1 < answer) {
                        answer = ed - st + 1;
                    }
                    sum -= arr[st];
                    ++st;
                }
                break;
            }
            else {
                sum += arr[ed];
            }
        }
    }
    if (answer == 2112345678) {
        answer = 0;
    }
    cout << answer << '\n';

    return 0;
}