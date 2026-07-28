class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        int one, two;

        while (maxHeap.size() > 1) {
            one = maxHeap.top();
            maxHeap.pop();

            two = maxHeap.top();
            maxHeap.pop();

            if (two == one) {

            }
            else if (one > two) {
                maxHeap.push(one - two);
            }
        }

        if (maxHeap.empty()) 
            return 0;
        else
            return maxHeap.top();
    }
};
