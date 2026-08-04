class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            pair<int, int> temp{position[i], speed[i]};
            cars.push_back(temp);
        }

        sort(cars.rbegin(), cars.rend());

        int fleet = 0;

        double lastTime = 0;

        for (int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (time > lastTime) { 
                fleet++;
                lastTime = time;
            }
        }
        return fleet;
    }
};
