class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int back = 0;
        int front = numbers.size() - 1;

        vector<int> answer;

        while (front != back) {
            int add = numbers[back] + numbers[front];

            if (add == target) {
                answer.push_back(back + 1);
                answer.push_back(front + 1);
                break;
            }
            if (add > target) front--;
            else if (add < target) back++;
        }
        return answer;
    }
};
