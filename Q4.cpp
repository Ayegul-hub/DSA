#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs(Pair a, Pair b) {
    return a.second < b.second;
}

int maxChainLen(struct Pair arr[], int n) {
    sort(arr, arr + n, comparePairs);

    int count = 1;
    int prev_end = arr[0].second;

    for (int i = 1; i < n; i++) {
        if (arr[i].first > prev_end) {
            count++;
            prev_end = arr[i].second;
        }
    }

    return count;
}

int main() {
    int N = 5;
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };

    cout << maxChainLen(arr, N) << endl;

    return 0;
}
