#include <iostream>
#include <vector>
using namespace std;

vector<string> findWords(vector<vector<char>>& board, vector<string>& dictionary) {
    vector<string> words;

    if (board.empty() || board[0].empty() || dictionary.empty()) {
        return words;
    }

    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (string word : dictionary) {
        bool found = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, 0, i, j, visited)) {
                    words.push_back(word);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }

    return words;
}

bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j, vector<vector<bool>>& visited) {
    if (index == word.size()) {
        return true;
    }

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
        return false;
    }

    visited[i][j] = true;

    if (dfs(board, word, index + 1, i + 1, j, visited) ||
        dfs(board, word, index + 1, i - 1, j, visited) ||
        dfs(board, word, index + 1, i, j + 1, visited) ||
        dfs(board, word, index + 1, i, j - 1, visited)) {
        return true;
    }

    visited[i][j] = false;

    return false;
}
