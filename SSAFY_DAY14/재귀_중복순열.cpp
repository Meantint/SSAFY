#include <iostream>

using namespace std;

int n;
int* arr;
int* order;

void permutation(int cnt)
{
    if (cnt == n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[order[i]] << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = 0; i < n; ++i) {
        order[cnt] = i;
        permutation(cnt + 1);
        order[cnt] = -1;
    }
}

void init()
{
    arr = new int[n];
    order = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
        order[i] = -1;
    }
    cout << '\n'
         << '\n';

    return;
}

int main()
{
    cout << "1부터 7사이의 숫자 중 원하는 수를 입력하세요(중복 순열) : ";
    cin >> n;

    init();
    permutation(0);

    return 0;
}