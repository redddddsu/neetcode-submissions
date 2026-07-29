class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> hashX;
        unordered_map<int, int> hashY;
        unordered_map<int, int> box;

        for (int i = 0; i < board.size(); i++) {
            for (int x = 0; i < board[x].size(); x++) {
                if (board[i][x] != '.') {
                    hashX[board[i][x]]++;
                    if (hashX[board[i][x]] > 1) {
                        return false;
                    }
                }
            }

            for (int y = 0; y < board.size(); y++) {
                if (board[y][i] != '.') {
                    hashY[board[y][i]]++;
                    if (hashY[board[y][i]] > 1) {
                        return false;
                    }
                }
            }

            hashX.clear();
            hashY.clear();
        }

        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[i].size(); j += 3) {
                box.clear();

                for (int y = 0; y < 3; y++) {
                    for (int x = 0; x < 3; x++) {
                        if (board[i + y][j + x] != '.') box[board[i + y][j + x]]++;
                        if (box[board[i + y][j + x]] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};
