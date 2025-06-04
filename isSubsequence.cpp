class Solution {
public:
    bool isSubsequence(string s, string t) {
        string result = "";
        int sCounter = 0;

        for (size_t i = 0; i < t.length(); i++) {
            if (s[sCounter] == t[i]) {
                result += t[i];
                sCounter++;
            }
        }

        if (result == s)
            return true;

        return false;
    }
};
