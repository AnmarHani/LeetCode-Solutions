class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesesStack;

        if (s.length() < 2)
            return false;

        for (const char character : s) {
            if (character == '(' || character == '{' || character == '[')
                parenthesesStack.push(character);

            else if (!parenthesesStack.empty() && character == ')')
                if (parenthesesStack.top() == '(')
                    parenthesesStack.pop();
                else
                    return false;

            else if (!parenthesesStack.empty() && character == '}')
                if (parenthesesStack.top() == '{')
                    parenthesesStack.pop();
                else
                    return false;

            else if (!parenthesesStack.empty() && character == ']')
                if (parenthesesStack.top() == '[')
                    parenthesesStack.pop();
                else
                    return false;
            else 
                return false;
        }

        return parenthesesStack.empty();
    }
};
