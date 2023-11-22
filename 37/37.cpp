#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> blank;
    bool row[9][9];
    bool col[9][9];
    bool box[3][3][9];
    bool ans = 0;


    void dfs(vector<vector<char>>& board, int t) {
        if (t >= blank.size()) {
            ans = 1;
            return;
        }
        int x = blank[t].first, y = blank[t].second;
        for (int i = 0; i < 9 && !ans; i++) {
            if (row[x][i] == 0 && col[y][i] == 0 && box[x / 3][y / 3][i] == 0) {
                row[x][i] = col[y][i] = box[x / 3][y / 3][i] = 1;
                board[x][y] = '0' + i + 1;
                dfs(board, t + 1);
                row[x][i] = col[y][i] = box[x / 3][y / 3][i] = 0;
            }
        }
    }


public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int x = c - '0' - 1;
                    row[i][x] = 1;
                    col[j][x] = 1;
                    box[i / 3][j / 3][x] = 1;
                }
                else {
                    blank.push_back({ i, j });
                }
            }
        }
        dfs(board, 0);
    }
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    sol.solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
