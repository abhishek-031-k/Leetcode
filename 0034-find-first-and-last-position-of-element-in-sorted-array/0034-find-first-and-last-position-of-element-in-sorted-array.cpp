class Solution {
public:

   
    int findlast(int n, vector<int>&nums, int target){
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
            ans = mid;
            low = mid+1;
            }
            else if(nums[mid] > target)high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
  
    int findfirst(int n, vector<int>&nums, int target){
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
            ans = mid;
            high = mid-1;
            }
            else if(nums[mid] > target)high = mid-1;
            else low = mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = findfirst(n, nums, target);
        if(first == -1)return {-1, -1};
        int last = findlast(n, nums, target);
        return {first, last};
    }
};