class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        unordered_map<string, function<int(int, int)>> op_map;
        
        op_map["+"] = [](int a, int b) { return a + b; };
        op_map["-"] = [](int a, int b) { return a - b; };
        op_map["*"] = [](int a, int b) { return a * b; };
        op_map["/"] = [](int a, int b) { return a / b; };

        for(size_t i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-") {
                int firstOperand = stk.top();
                stk.pop();
                
                int secondOperand = stk.top();
                stk.pop();

                int result = op_map[tokens[i]](secondOperand, firstOperand);

                stk.push(result);
                continue;
            }

            stk.push(stoi(tokens[i])); // stoi converts it into an int
        }

        return stk.top();
    }
};
