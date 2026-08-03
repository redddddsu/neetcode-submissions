class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operations;

        operations.insert("+");
        operations.insert("-");
        operations.insert("*");
        operations.insert("/");

        int answer = 0;
        int left, right;
        int cal;

        if (tokens.size() == 1) {
            return (stoi)(tokens[0]);
        }

        for (string s : tokens) {
            if (operations.count(s) == 0) stk.push((stoi)(s));


            else {
                string op = s;
                right = (stk.top());
                stk.pop();
                left = (stk.top());
                stk.pop();

                if (op == "+") cal = left + right;
                else if (op == "-") cal = left - right;
                else if (op == "*") cal = left * right;
                else if (op == "/") cal = left / right;

                answer = cal;
                stk.push(answer);

            }

        }

        return answer;
    }
};
