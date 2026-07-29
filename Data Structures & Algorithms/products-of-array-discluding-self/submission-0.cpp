class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1, 1);
        vector<int> suffix(nums.size() + 1, 1);


        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] * nums[i];
            suffix[suffix.size() - i - 2] = suffix[suffix.size() - i - 1] * nums[nums.size() - i - 1];
        }

        vector<int> output(nums.size());


        for (int i = 0; i < nums.size(); i++) {
            output[i] = prefix[i] * suffix[i + 1];
        }

        return output;
    }
};
