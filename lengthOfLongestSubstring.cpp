class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // SOLVED WITH SLIDING WINDOW ALGORITHM.
        set<int> seen;
        int longestCharacters = 0;

        int leftPointer = 0;

        for(size_t rightPointer = 0; rightPointer < s.length(); rightPointer++) {
            while(seen.find(s[rightPointer]) != seen.end()) {
                seen.erase(s[leftPointer]);
                leftPointer++;
            }
            
            int windowLength = (rightPointer - leftPointer) + 1; 
            
            longestCharacters = max(longestCharacters, windowLength);
            seen.insert(s[rightPointer]);
        }

        return longestCharacters;

    }
};
