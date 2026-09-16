class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        int result = 0;
        int clock = 0;

        for (char c : tasks) {
            hash[c]++;
        }

        priority_queue<int> maxHeap;

        for (auto& i : hash) {
            maxHeap.push(i.second);
        }

        queue<pair<int, int>> cooldown;

        int top;

        while (!maxHeap.empty() || !cooldown.empty()) {
            while (!cooldown.empty() && cooldown.front().second <= clock) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
            
            if (!maxHeap.empty()) {
                top = maxHeap.top();
                maxHeap.pop();
                if (top - 1 > 0) cooldown.push({top - 1, n + clock + 1});;
            }
            

       

            clock++;
        }

        return clock;

    }
};
