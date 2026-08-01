class Solution {
public:

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
         vector<int>front(n+1, 0), curr(n+1, 0);
      for(int i = 0; i < n; i++)curr[i] = nums[i];
      for(int i = n-1; i >= 0; i--){
      for(int j = i+1; j < n; j++){
           curr[j] = max(nums[i] - front[j], nums[j] - curr[j-1]);
      }
      front = curr;
      }
        return front[n-1] >= 0 ? true : false;
    }
};