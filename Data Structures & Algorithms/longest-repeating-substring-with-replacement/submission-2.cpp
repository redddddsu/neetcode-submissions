class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;

        int longest = 0;
        int answer = 0;
        int maxFreq = 0;

        unordered_map<int, int> hash;
    
        while (right != s.size()) {
            hash[s[right]]++;
            maxFreq = max(maxFreq, hash[s[right]]);

            if ((right - left + 1) - maxFreq > k) {
                hash[s[left]]--;
                left++;
            }

            answer = max(answer, right - left + 1);
            right++;


        }

        return answer;
    }
};
