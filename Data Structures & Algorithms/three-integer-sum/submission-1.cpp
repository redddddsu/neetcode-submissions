class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left, right, first, sum;

        vector<vector<int>> answer;

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1;
            right = nums.size() - 1;


            while (left < right) {
                first = nums[left] + nums[right];
                sum = first + nums[i];

                if (sum == 0) {
                    answer.push_back({nums[left], nums[right], nums[i]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                
            }
        }
        return answer;
    }
};
