class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
        };
        
        int result = 0;
        
        for(int index = 0; index < s.length(); index++) {
            if(romanToIntMap[(char) s[index]] < romanToIntMap[(char) s[index + 1]]){
                result += romanToIntMap[(char) s[index + 1]] - romanToIntMap[(char) s[index]];
                index++;
                continue;
            }
            result += romanToIntMap[(char) s[index]];
        }

        return result;
    }
};
