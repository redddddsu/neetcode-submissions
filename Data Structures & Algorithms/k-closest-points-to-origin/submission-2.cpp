class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            if (maxHeap.size() == k) {
                pair<double, vector<int>> front = maxHeap.top();
                if (front.first > distance) {
                    maxHeap.pop();
                    maxHeap.push({distance, points[i]});
                }
            }
            else {
                maxHeap.push({distance, points[i]});
            }

        }
        vector<vector<int>> answer;

        while (!maxHeap.empty()) {
            answer.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return answer;


    }
};
