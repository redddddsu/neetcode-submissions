class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count >= k) {
                int top = heap.top();
                if (top < nums[i]) {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
            else {
                heap.push(nums[i]);
            }
            count++;
        }

        return heap.top();
    }
};
