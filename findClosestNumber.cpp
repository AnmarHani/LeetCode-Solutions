class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closestNum = nums[0]; // Array is always >= 1

        for (size_t i = 1; i < nums.size(); i++)
            if (abs(nums[i]) < abs(closestNum)) // If there is a num (which will be positive after abs) less than the closestNum assign it
                closestNum = nums[i];

        // If the closestNum is negative, and there is a positive num similar to the closestNum but positive, say 1 and -1, then assign the positive not the negative as mentioned in the question:
        // return the number with the largest value.
        if (closestNum < 0 &&
            find(nums.begin(), nums.end(), abs(closestNum)) != nums.end())
            return abs(closestNum);

        return closestNum;
    }
};
