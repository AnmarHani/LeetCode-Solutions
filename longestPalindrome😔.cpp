// Solve Using Tabulation Bottom-Up DP
class Solution {
private:
public:
    string longestPalindrome(string s) {
        string result = "";

        int stringLength = s.length();

        int rows = stringLength, cols = stringLength;

        vector<vector<int>> table(
            rows,
            vector<int>(
                cols,
                0)); // First create the table matrix, and fill it with zeroes

        // Gradually increase the length of the substring
        for (int substringLength = 1; substringLength <= stringLength; substringLength++) {
            for (size_t i = 0; i <= stringLength - substringLength; i++) {
                size_t j = i + substringLength - 1; 
                                    // j at the end of the current substring
                                    // Say i is = 3, and substringLength = 6, 3 + 6 = 9 - 1 = 8, and there will j be.
                                    // Which we say from 3 to 8 is 6 indices, and this is the substringLength.

                if (substringLength == 1)
                    table[i][j] = 1; // When the length is 1, it is one
                                     // character, it is definetely a palindrome

                else if (substringLength == 2)
                    table[i][j] = static_cast<int>(s[i] == s[j]); 
                               // Check if they equal each other the start and
                               // the end of the string currently i and j, then
                               // put 1 or 0 depedning on the bool val

                else
                    table[i][j] = static_cast<int>( s[i] == s[j] && table[i + 1][j - 1] == 1); 
                                // This means that if not length 1 or 2, it is
                                // larger, then it will check for current start
                                // and end, and the middle between it keep going
                                // i+1 tighten the start by going inside. and
                                // j-1 tighten the end by going inside and
                                // checking if its also 1 and keep going like
                                // that.
                                
                // If the table has ones placed, and the current subStringLength is the maximum lengthed substring (because result acts as the maximum substring holder), it will be replaced.
                if (table[i][j] == 1 && substringLength > result.length()) 
                    result = s.substr(i, substringLength);
            }
        }
        return result;
    }
};
