#include <iostream>

using namespace std;

int n, m;
int* arr;
int* order;

void combination(int cnt)
{
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout.width(2);
            cout << right << arr[order[i]] << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = (cnt == 0) ? 0 : order[cnt - 1] + 1; i < n; ++i) {
        order[cnt] = i;
        combination(cnt + 1);
        order[cnt] = -1;
    }
}

void init()
{
    arr = new int[n];
    order = new int[m];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        order[i] = -1;
    }
    cout << '\n'
         << '\n';

    return;
}

int main()
{
    cout << "1부터 24사이의 숫자 중 원하는 수를 입력하세요(조합) : ";
    cin >> n;
    cout << "뽑을 숫자의 개수를 적으세요 : ";
    cin >> m;

    init();
    combination(0);

    return 0;
}