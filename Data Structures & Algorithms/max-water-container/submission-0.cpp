class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int answer = 0;

        int width, height;
        while (left < right) {
            width = right - left;
            height = min(heights[right], heights[left]);

            answer = max(answer, width * height);

            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }

        }
        return answer;
    }
};
