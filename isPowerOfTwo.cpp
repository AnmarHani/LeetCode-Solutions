class Solution {
public:
    bool isPowerOfTwo(int n) {
        // There will never be a resulting negative number from power of two.
        if (n < 0) return false;
        
        // 1. convert the integer to 32bit bitmask
        // 2. bitmask.count() counts the number of set (1) bits
        // 3. Increasing the zeroes, so it must only contain only 1 set bit: 2^0 = 1, 2^1 = 10, 2^2 = 100, etc. 
        return std::bitset<32>(n).count() == 1;
    }
};
