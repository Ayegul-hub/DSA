#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compareJobs);

    vector<int> result(n, -1);
    vector<bool> slot(n, false);

    int countJobs = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = arr[i].id;
                slot[j] = true;
                countJobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    return { countJobs, maxProfit };
}

int main() {
    int N = 4;
    Job arr[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    vector<int> result = JobScheduling(arr, N);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
    int start, end, pos;
};

bool compareMeetings(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int N) {
    vector<Meeting> meetings(N);

    for (int i = 0; i < N; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

    sort(meetings.begin(), meetings.end(), compareMeetings);

    vector<int> answer;
    int limit = meetings[0].end;
    answer.push_back(meetings[0].pos);

    for (int i = 1; i < N; i++) {
        if (meetings[i].start > limit) {
            limit = meetings[i].end;
            answer.push_back(meetings[i].pos);
        }
    }

    return answer.size();
}

int main() {
    int N = 6;
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    cout << maxMeetings(start, end, N) << endl;

    return 0;
}
