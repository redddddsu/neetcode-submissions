class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = 0;
        int lower = 1;
        for (int pile : piles) {
            upper = max(upper, pile);
        }

        int middle = lower + (upper - lower) / 2;

        int output = upper;
        int target;
        double result;

        while (upper >= lower) {
            target = h;
            for (int pile : piles) {
                result = (double)pile / middle;

                target -= ceil(result);
            }

            if (h - target <= h) {
                output = min(output, middle);
                upper = middle - 1;
            }
            else {
                lower = middle + 1;
            }

            middle = lower + (upper - lower) / 2;


        }
        return output;
    }
};
