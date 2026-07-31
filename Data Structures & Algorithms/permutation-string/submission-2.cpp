class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = 0;

        unordered_map<char, int> hash;

        for (char c : s1) {
            hash[c]++;
        }

        while (right != s2.size()) {
            if (hash.find(s2[right]) == hash.end()) {
                while (left != right) {
                    hash[s2[left]]++;
                    left++;
                }

                left = right + 1;

            }
            else {
                hash[s2[right]]--;

                while (hash[s2[right]] < 0) {
                    hash[s2[left]]++;
                    left++;
                }

                if (right - left + 1 == s1.size()) {
                    return true;
                }

            }
            right++;


        }

 

        return false;
    }
};
