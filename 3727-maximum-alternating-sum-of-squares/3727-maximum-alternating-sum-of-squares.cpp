class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      int n = nums.size();
      long long ans = 0, i = 0, j = n-1;
      for(auto &it: nums)it = it*it;
      sort(nums.begin(), nums.end());
      while(i <= j){
        ans += nums[j];
        j--;
        if(i <= j)ans -= nums[i];
        i++;
      }
      return ans;
    }
};