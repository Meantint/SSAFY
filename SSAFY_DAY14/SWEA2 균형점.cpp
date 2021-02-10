// 오차 범위 지정이 어려움, 한 번 더 보기!!
#include <iostream>

using namespace std;

int tc;
int n;
double st, ed;
double* arr;
double* w;
int ans_idx = -1;
double answer[10000];

double force(double dist, double weight)
{
    return (weight / (dist * dist));
}

void solve()
{
    double mid;

    for (int f = 0; f < n - 1; ++f) {
        bool isFind = true;
        double l = arr[f], r = arr[f + 1];
        while (l <= r) {
            mid = (l + r) / (double)2;

            double p = 0.0;
            for (int i = 0; i < n; ++i) {
                // 왼쪽
                if (arr[i] <= mid) {
                    p -= force(mid - arr[i], w[i]);
                }
                // 오른쪽
                else {
                    p += force(mid - arr[i], w[i]);
                }
            }
            // 오차 범위가 어려움!!
            if (p > -0.0000000000001 && p < 0.0000000000001) {
                break;
            }
            // 왼쪽이 더 쎄다면
            else if (p < 0.0) {
                l = mid + 0.0000000000001;
            }
            // 오른쪽이 더 쎄다면
            else {
                r = mid - 0.0000000000001;
            }
        }
        if (isFind) {
            answer[++ans_idx] = mid;
        }
    }

    return;
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        ans_idx = -1;
        st = 2112345678.0;
        ed = -2112345678.0;
        cin >> n;

        arr = new double[n];
        w = new double[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (st > arr[i]) {
                st = arr[i];
            }
            if (ed < arr[i]) {
                ed = arr[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }

        cout << fixed;
        cout.precision(10);
        cout << '#' << t + 1 << ' ';
        solve();
        for (int i = 0; i <= ans_idx; ++i) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}