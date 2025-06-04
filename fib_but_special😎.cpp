class Solution {
public:
    int fib(int n) {
        // Bottom Up DP (Without Tabulation, Space O(1), No Recursion)

        // No Looping Cases
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int prevNum = 0;
        int currentNum = 1;

        for (size_t i = 2; i < n + 1; i++) {
            int tmp = prevNum;

            prevNum = currentNum;
            currentNum += tmp;
        }

        return currentNum;
    }
};
// // Naive Recursive
// if(n == 0)
//     return 0;

// if(n == 1)
//     return 1;

// return fib(n - 1) + fib(n - 2);

// private:
//     // Top Down DP (Memoization)
//     int f(int x, unordered_map<int, int> &memo) {
//         if (memo.find(x) != memo.end())
//             return memo[x];

//         memo[x] = f(x - 1, memo) + f(x - 2, memo);
//         return memo[x];
//     }

// public:
//     int fib(int n) {
//         // Top Down DP (Memoization or Caching)
//         unordered_map<int, int> memo{{0, 0}, {1, 1}};

//         return f(n, memo);
//     }

// // Bottom Up DP (Tabulation, No Recursion)

// // No Looping Cases
// if(n == 0) return 0;
// if(n == 1) return 1;

// int size = n + 1;
// vector<int> table(size, 0);  // array with length variable size, filled with
// 0 table[1] = 1; // Set the second element as 1, since fib(1) = 1.

// for (size_t i = 2; i < size; i++)
//     table[i] = table[i-1] + table[i-2];

// return table[n];
