class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        size_t rightPointer = 0;
        double currentSum = 0;

        // Build the Initial Window
        for (size_t i = 0; i < k; i++) {
            currentSum += nums[i];
        }

        double maxAvg = currentSum / k;

        for (size_t i = k; i < nums.size(); i++) {
            currentSum += nums[i]; // Add the proceeding number after the last position of the window
            currentSum -= nums[i-k]; // Subtract the preceeding number in the first position of the window

            maxAvg = max(maxAvg, currentSum / k);
        }

        return maxAvg;
    }
};
