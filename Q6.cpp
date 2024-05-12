#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSafe(int i, int j, int N, vector<vector<int>>& m, vector<vector<bool>>& visited) {
    return (i >= 0 && j >= 0 && i < N&& j < N&& m[i][j] == 1 && !visited[i][j]);
}

void findPaths(int i, int j, int N, vector<vector<int>>& m, vector<vector<bool>>& visited, string path, vector<string>& paths) {
    if (i == N - 1 && j == N - 1) {
        paths.push_back(path);
        return;
    }

    visited[i][j] = true;

    if (isSafe(i + 1, j, N, m, visited)) {
        findPaths(i + 1, j, N, m, visited, path + "D", paths);
    }
    if (isSafe(i - 1, j, N, m, visited)) {
        findPaths(i - 1, j, N, m, visited, path + "U", paths);
    }
    if (isSafe(i, j + 1, N, m, visited)) {
        findPaths(i, j + 1, N, m, visited, path + "R", paths);
    }
    if (isSafe(i, j - 1, N, m, visited)) {
        findPaths(i, j - 1, N, m, visited, path + "L", paths);
    }

    visited[i][j] = false;
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<string> paths;

    if (m[0][0] == 1) {
        findPaths(0, 0, N, m, visited, "", paths);
        sort(paths.begin(), paths.end());
    }

    return paths;
}

int main() {
    int N = 4;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = printPath(N, m);

    if (paths.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (string path : paths) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
