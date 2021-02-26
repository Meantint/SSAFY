#include <iostream>

using namespace std;

char text[] = "banana";
int tSize;

bool isChange(int n1, int n2)
{
    bool is_n1_morebig = (n1 < n2) ? true : false;

    while (n1 < tSize && n2 < tSize) {
        if (text[n1] < text[n2]) {
            return false;
        }
        else if (text[n1] == text[n2]) {
            ++n1;
            ++n2;
        }
        else {
            return true;
        }
    }
    if (is_n1_morebig) {
        return true;
    }
    else
        false;
}

// 퀵소트
void mySort(int* arr, int low, int high)
{
    if (low >= high) {
        return;
    }

    int& pivot = arr[high];
    int i = low - 1, j = low;
    for (; j < high; ++j) {
        if (isChange(pivot, arr[j])) {
            int tmp = arr[j];
            arr[j] = arr[++i];
            arr[i] = tmp;
        }
    }
    int tmp = arr[++i];
    arr[i] = pivot;
    pivot = tmp;

    mySort(arr, low, i - 1);
    mySort(arr, i + 1, high);
}

int main()
{
    for (tSize = 0; text[tSize] != 0; ++tSize) {
    }

    int* suffix = new int[tSize];
    for (int i = 0; i < tSize; ++i) {
        suffix[i] = i;
    }

    mySort(suffix, 0, tSize - 1);

    int* lcp = new int[tSize];
    for (int i = 0; i < tSize; ++i) {
        lcp[i] = 0;
    }
    for (int i = 1; i < tSize; ++i) {
        int l = suffix[i - 1];
        int r = suffix[i];
        while (l < tSize && r < tSize) {
            if (text[l] == text[r]) {
                ++lcp[i];
                ++l;
                ++r;
            }
            else {
                break;
            }
        }
    }

    cout << "My Suffix & LCP \n";
    for (int i = 0; i < tSize; ++i) {
        int start = suffix[i];
        cout << "#" << i + 1 << ' ';
        for (int j = start; j < tSize; ++j) {
            cout << text[j];
        }
        for (int j = 0; j < start; ++j) {
            cout << ' ';
        }
        cout << ", LCP[" << i << "] : " << lcp[i];
        cout << '\n';
    }

    return 0;
}