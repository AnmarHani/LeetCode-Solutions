class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        int leftMult = 1, rightMult = 1;
        vector<int> leftArr(nums.size()), rightArr(nums.size());

        // Loop through arr nums and go forward with i from left of the nums array and build leftArr
        // and go backward with j from right of the nums array and build rightArr
        // building both left and right Arr with the multiplier, and then the mulitplier is multiplied
        // by the correspoinding nums element and cumulate (build up) with what is before of it
        // finally we multiply both leftArr and rightArr respective indices (like leftArr[0] * rightArr[0])
        // and put the resulting element into the result arr, then returning the result arr.
        for (size_t i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            leftArr[i] = leftMult;
            rightArr[j] = rightMult;

            leftMult *= nums[i];
            rightMult *= nums[j];
        }

        std::transform(leftArr.begin(), leftArr.end(), rightArr.begin(),
                       result.begin(), [](int x, int y) { return x * y; });

        return result;
    };
};
