#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    bool isVisited[5] = {0, 0, 0, 0, 0};
    for (int t1 = 0; t1 < 5; ++t1) {
        isVisited[t1] = true;
        for (int t2 = 0; t2 < 5; ++t2) {
            if (isVisited[t2]) {
                continue;
            }
            isVisited[t2] = true;
            for (int t3 = 0; t3 < 5; ++t3) {
                if (isVisited[t3]) {
                    continue;
                }
                isVisited[t3] = true;
                for (int t4 = 0; t4 < 5; ++t4) {
                    if (isVisited[t4]) {
                        continue;
                    }
                    isVisited[t4] = true;
                    for (int t5 = 0; t5 < 5; ++t5) {
                        if (isVisited[t5]) {
                            continue;
                        }
                        isVisited[t5] = true;
                        cout << arr[t1] << ' ';
                        cout << arr[t2] << ' ';
                        cout << arr[t3] << ' ';
                        cout << arr[t4] << ' ';
                        cout << arr[t5] << '\n';
                        isVisited[t5] = false;
                    }
                    isVisited[t4] = false;
                }
                isVisited[t3] = false;
            }
            isVisited[t2] = false;
        }
        isVisited[t1] = false;
    }

    return 0;
}