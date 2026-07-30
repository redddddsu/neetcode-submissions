class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int longest = 0;

        int left = 0;
        int right = left;

        unordered_set<char> arr;

        while (right < s.size()) {
            if (arr.count(s[right]) == 0) {
                arr.insert(s[right]);
                right++;
                longest++;
                answer = max(longest, answer);
            }
            else {
                arr.erase(s[left]);
                longest--;
                left++;
            }
        }
        if (s.size() == 1) {
            return 1;
        }
        return answer;
    }
};
