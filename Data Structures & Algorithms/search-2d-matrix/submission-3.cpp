class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first, last;
        int left, right;

        int middle;

        for (int y = 0; y < matrix.size(); y++) {

            left = 0;
            right = matrix[y].size() - 1;

            middle = left + (right - left) / 2;

            while (right >= left) {
                first = matrix[y][0];
                last = matrix[y][matrix[y].size() - 1];
                if (target > last || target < first) continue;

                if (matrix[y][middle] == target) {
                    return true;
                }
                else if (target > matrix[y][middle]) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
                middle = left + (right - left) / 2;
            }
        }
        return false;
    }
};
