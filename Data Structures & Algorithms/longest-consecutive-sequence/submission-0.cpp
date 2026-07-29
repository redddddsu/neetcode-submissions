class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0;
        int longest = 0;
        unordered_set<int> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.insert(nums[i]);
        }

        for (int num : arr) {
            if (arr.count(num - 1) == 0) {
                longest = 1;
                while (arr.count(num + longest)) {
                    longest++;
                }
            answer = max(answer, longest);
            }
        }
        return answer;
    }
};
