class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (size_t i = 0; i < nums.size(); i++)
            st.insert(nums[i]);

        for (int element : st) {
            if (st.find(element - 1) == st.end()) { // only start counting from sequence start
                int current = element;
                int currentStreak = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak); // update longest if needed
            }
        }
        

        return longest;
    }
};
