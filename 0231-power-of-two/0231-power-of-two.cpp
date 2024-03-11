class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if n is positive and has only one set bit
        return n > 0 && (n & (n - 1)) == 0;
    }
};