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
