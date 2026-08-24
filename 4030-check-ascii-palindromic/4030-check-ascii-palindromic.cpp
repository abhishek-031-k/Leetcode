class Solution {
public:
    bool isPalindromic(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            for (int i = 7; i >= 0; i--) {
                int leftBit  = (s[l] >> i) & 1;
                int rightBit = (s[r] >> (7 - i)) & 1;
                if (leftBit != rightBit) return false;
            }
            l++;
            r--;
        }
        return true;
    }
};