class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incsub=1,decsub=1;
        int n=nums.size();
        int i=0,j=1;
        int maxi=1;
        while(i<n&&j<n){
            if(nums[j-1]<nums[j]){
                incsub++;
                j++;
                maxi=max(maxi,incsub);
            }
            else{ 
                i=j;
                j++;
            
            incsub=1;
            }
        }
        int longi=1;
        i=0,j=1;
                while(i<n&&j<n){
            if(nums[j-1]>nums[j]){
                decsub++;
                j++;
                longi=max(longi,decsub);
            }
            else 
            {
                i=j;
                j++;
            
            decsub=1;
            }
        }
        return max(maxi,longi);

    }
};