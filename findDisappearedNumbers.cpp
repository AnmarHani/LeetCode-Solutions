class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> nonAppearingNumbers;
        const int ARRAY_SIZE = nums.size(); // n

        vector<bool> seenNumbers(ARRAY_SIZE + 1,
                                 false); // 1 to n, seenNumbers[0] is ignored.
                                         // All initialized with false

        // n + n = BigO(n)
        // 1. Put the numbers that are in nums as an index to assign in the seenNumbers array either true or false, for instance:
        // If nums[index] = 2
        // then, it will go to seenNumbers[2] and put its value to true, if another 2 came, it will be as true. So no duplicates there.
        for (int index = 0; index < ARRAY_SIZE; index++) {
            seenNumbers[nums[index]] = true;
        }


        // 2. Search for all false values (which are the default) which arent assigned by the past loop
        // 3. Push them to the nonAppearingNumbers vector
        for (int index = 1; index <= ARRAY_SIZE; index++) {
            if (seenNumbers[index] == false) {
                nonAppearingNumbers.push_back(index);
            }
        }

        // Past Solution (Time Exceeded on it, with Sort and Double Nesting
        // bigO(n^2)) sort(nums.begin(), nums.end()); for (int counter = 0;
        // counter < nums.size(); counter++) {
        //     bool isFound = false;
        //     for (int itr = 0; itr < nums.size(); itr++) {
        //         if (nums[itr] == counter + 1) {
        //             isFound = true;
        //         }
        //     }
        //     if (isFound == false) {
        //         nonAppearingNumbers.push_back(counter + 1);
        //     }
        // }

        return nonAppearingNumbers;
    }
};
