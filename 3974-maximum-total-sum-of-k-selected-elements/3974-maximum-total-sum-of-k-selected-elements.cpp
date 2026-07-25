class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = 0, i = n-1;
        while(i >= 0 && k > 0){
            if(mul > 1){
              sum += 1LL*nums[i]*mul;
              mul--;  
            }
            else sum += nums[i];
            k--;
            i--;
        }
        return sum;
    }
};