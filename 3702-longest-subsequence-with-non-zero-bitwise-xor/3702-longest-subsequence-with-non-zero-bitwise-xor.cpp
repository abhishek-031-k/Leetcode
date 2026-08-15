class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int count = 0, value = nums[0];
        for(int i = 1; i < n; i++){
            if(value == 0)count++;
            value = value ^ nums[i];
        }
        if(value == 0 && count == n-1)return 0;
        else if(value == 0)return n-1;
        return n;
    }
};