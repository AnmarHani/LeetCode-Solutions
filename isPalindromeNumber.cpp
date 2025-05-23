class Solution {
private:
    unsigned int appendToRightMost(const unsigned int number, const unsigned int digit) {
        // Multiply to 10 to append it to the rightmost position, there will be zero at the end, then add the digit 0 + digit = digit.
        return number * 10 + digit;
    }

    unsigned int getLastDigit(const unsigned int num) {
        return num % 10; // Returns the rightmost digit from num
    }

    unsigned int reverseNumber(unsigned int num) {
        unsigned int result = 0;

        while (num > 0) {
            result = appendToRightMost(result, getLastDigit(num));
            num = num / 10; // Delete the rightmost digit from num
        }

        return result;
    }

public:
    bool isPalindrome(int x) {
        if (x < 0) // No Negative Palindrome
            return false; 

        unsigned int reversedNumber = reverseNumber(x);

        if (reversedNumber == x)
            return true;

        return false;
    }
};
