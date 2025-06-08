class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<array<int, 26>, vector<string>> mp;
        
        for(size_t i = 0; i < strs.size(); i++) {
            array<int, 26> chars = {0};

            for(char character : strs[i]) 
                chars[character - 'a'] += 1;
            
            mp[chars].push_back(strs[i]);
        }

        for(auto it : mp) 
            result.push_back(it.second);

        return result;
    }
};
