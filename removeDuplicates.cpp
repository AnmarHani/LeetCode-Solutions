class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> st;
        std::vector<int> expectedNums (nums.size());
        int k = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                expectedNums[k] = nums[i];
                k++;
            }
            st.insert(nums[i]);
        }

        nums = expectedNums;
        return k;
    }
};
