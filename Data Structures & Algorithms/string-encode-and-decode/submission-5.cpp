class Solution {
public:

    string encode(vector<string>& strs) {

        string concat = "";

        for (int i = 0; i < strs.size(); i++) {
            concat += strs[i];
            concat += "1a3";
        }
        
        return concat;

    }

    vector<string> decode(string s) {
        string word = "";
        bool delimiter = false;
        vector<string> arr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && s[i + 1] == 'a' && s[i + 2] == '3') {
                i += 2;
                arr.push_back(word);
                word = "";
            }
            else
                word += s[i];
            delimiter = true;
            

        }
        return arr;
    }
};
