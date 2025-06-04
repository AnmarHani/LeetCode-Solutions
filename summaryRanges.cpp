class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() < 1) return result;
        else if (nums.size() == 1) return {to_string(nums[0])};

        int start = nums[0];
        size_t i = 0;
        while (i < nums.size()) {
            start = nums[i];

            while (i < nums.size() - 1 && nums[i + 1] == nums[i] + 1)
                i++;

            if (start == nums[i])
                result.push_back(to_string(nums[i]));
            else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
                start = nums[i];
            }

            i++;
        }

        return result;
    }
};
