class Solution {
private:
    void backtrack(int i, vector<int>& nums, vector<int> sol, vector<vector<int>> &result) {
        // If in the end of the array, return because its a base case.
        if(i==nums.size()) {
            result.push_back(sol); // Push the sol array into the result
            return;
        }

        // at each step, for a number at index [i], we make a binary choice.

        // first case; traverse to the last element without including it in the sol, just excluding nums[i]. move on to the next element without including it in our current subset.
        backtrack(i+1, nums, sol, result);

        // second case; traverse but add nums[i], include it. add it to the current subset and continue.
        sol.push_back(nums[i]);
        backtrack(i+1, nums, sol, result);
        sol.pop_back(); // undo (backtrack) to go back and continue to the next side of the tree.
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sol;

        backtrack(0, nums, sol, result);

        return result;
    }
};

// input: nums = {1, 2}

// backtrack(0, nums, [])
// │
// ├── Exclude nums[0] (1)
// │   └── backtrack(1, nums, [])
// │       ├── Exclude nums[1] (2)
// │       │   └── backtrack(2, nums, []) ➜ reached end ➜ save []
// │       └── Include nums[1] (2)
// │           └── backtrack(2, nums, [2]) ➜ reached end ➜ save [2]
// │
// └── Include nums[0] (1)
//     └── backtrack(1, nums, [1])
//         ├── Exclude nums[1] (2)
//         │   └── backtrack(2, nums, [1]) ➜ reached end ➜ save [1]
//         └── Include nums[1] (2)
//             └── backtrack(2, nums, [1,2]) ➜ reached end ➜ save [1,2]

// output: [ [], [2], [1], [1, 2] ]
