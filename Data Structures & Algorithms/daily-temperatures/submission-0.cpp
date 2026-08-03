class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> results(temperatures.size());
        int index;

        for (int i = 0; i < temperatures.size(); i++) {
            
            if (stk.empty() || temperatures[stk.top()] > temperatures[i]) {
                stk.push(i);
            }
            else {
                while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    index = stk.top();
                    stk.pop();
                    results[index] = i - index;
                }
                stk.push(i);    
            }
            
        }        

        while (!stk.empty()) {
            index = stk.top();
            results[index] = 0;
            stk.pop();
        }
        
        return results;
    }
};
