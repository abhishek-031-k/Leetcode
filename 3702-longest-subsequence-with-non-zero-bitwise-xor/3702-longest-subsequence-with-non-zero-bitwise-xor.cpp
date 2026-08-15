class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int value = nums[0], count = 0;
        for(int i = 1; i < n; i++){
            if(value == 0)count++;
            value ^= nums[i];
        }
        if(value != 0)return n;
        if(count == n-1)return 0;
        return n-1;
    }
};