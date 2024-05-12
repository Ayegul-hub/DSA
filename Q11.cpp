#include <iostream>
#include <vector>
using namespace std;

int findPagesUtil(vector<int>& A, int n, int m, int current_min) {
    int studentsRequired = 1;
    int curSum = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > current_min) {
            return false;
        }

        if (curSum + A[i] > current_min) {
            studentsRequired++;
            curSum = A[i];

            if (studentsRequired > m) {
                return false;
            }
        }
        else {
            curSum += A[i];
        }
    }

    return true;
}

int findPages(vector<int>& A, int n, int m) {
    long long sum = 0;

    if (n < m) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    long long start = 0, end = sum, result = INT_MAX;

    while (start <= end) {
        long long mid = (start + end) / 2;
        if (findPagesUtil(A, n, m, mid)) {
            result = min(result, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> A = { 12, 34, 67, 90 };
    int n = 4, m = 2;

    cout << findPages(A, n, m) << endl;

    return 0;
}
