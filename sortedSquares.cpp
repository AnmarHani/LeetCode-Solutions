class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // SOLVED WITH TWO POINTERS METHOD
        
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        vector<int> decreasingSortedArray;

        while(leftPointer <= rightPointer) {
            if(abs(nums[leftPointer]) > abs(nums[rightPointer])) {
                decreasingSortedArray.push_back((nums[leftPointer] * nums[leftPointer]));
                leftPointer++;
            }
            else {
                decreasingSortedArray.push_back((nums[rightPointer] * nums[rightPointer]));
                rightPointer--;
            }
        }

        reverse(decreasingSortedArray.begin(), decreasingSortedArray.end());

        return decreasingSortedArray;
    }
};
