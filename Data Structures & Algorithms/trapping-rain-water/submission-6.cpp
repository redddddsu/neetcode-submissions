class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = 1;
       

        while (left < height.size() - 1) {

            right = left + 1;
            int bumps = 0;
                    int highest = 0;
                    int width = 0;
                    int highest_bump = 0, highest_index = -1;
            while (right < height.size()) {
                if (height[right] >= height[left]) {
                    result += (width * height[left]) - bumps;
                    left = right;
                    width = 0;
                    bumps = 0;
                    highest = 0;
                    highest_index = -1;
                    highest_bump = 0;
                }
                else {
                    if (height[right] > highest) {
                        highest = height[right];
                        highest_index = right;
                        highest_bump = bumps;
                    }
                    bumps += height[right];
                    width++;
                }
                right++;

            

            }

            if (highest_index != - 1) {
                    int width = highest_index - left - 1;
                    result += (width * highest) - highest_bump;
                    left = highest_index;
                    width = 0;
                    bumps = 0;
                    highest = 0;
                    highest_index = -1;
                    highest_bump = 0;
            }
            else break;
        }
        return result;
    }
};
