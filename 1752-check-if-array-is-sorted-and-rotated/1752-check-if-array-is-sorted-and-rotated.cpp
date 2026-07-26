class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        int c=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i] > nums[(i+1)%n] && ++c>1) return false;
        // }
        // return true;

      for(int i=0;i<n-1;i++){
        if(nums[i+1]<nums[i] )c++;
      }
      if(c==1 &&nums[0]>=nums[n-1])return true;
if(c==0)return true;
return false;

    }
};