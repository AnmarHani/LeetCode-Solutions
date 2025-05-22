class Solution {
private:
    string removeSpecialCharactersAndLowerCase(string str) {
        string result = "";

        for (auto character : str) {
            if (isalnum(character)) // Is Alpha Numeric
                result += tolower(character);
        }

        return result;
    }

public:
    bool isPalindrome(string s) {
        string unreversedCleanString = removeSpecialCharactersAndLowerCase(s);
        string reversedCleanString = unreversedCleanString;

        reverse(reversedCleanString.begin(), reversedCleanString.end());

        return reversedCleanString == unreversedCleanString;
    }
};
