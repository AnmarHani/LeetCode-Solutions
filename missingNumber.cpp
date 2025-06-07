class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int originalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> expectedArr(nums.size());
        std::iota(expectedArr.begin(), expectedArr.end(), 1); // Fill the vector sequentially from 1 to nums.size();
        
        int expectedSum = accumulate(expectedArr.begin(), expectedArr.end(), 0);


        return expectedSum - originalSum;
    }
};
