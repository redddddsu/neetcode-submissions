class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int middle = left + (right - left) / 2;

        while (right >= left) {
            if (nums[middle] == target) return middle;

            else if (nums[middle] < nums[right]) {
                if (nums[middle] < target && nums[right] >= target) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
            else {
                if (nums[middle] > target && nums[left] <= target) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
            middle = left + (right - left) / 2;
        }
        return -1;
    }
};
