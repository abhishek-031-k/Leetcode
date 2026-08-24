class Solution {
public:

    void left(vector<int>&height, vector<int>&leftmax){
      leftmax[0] = height[0];
      for(int i = 1; i < height.size(); i++){
        leftmax[i] = max(leftmax[i-1], height[i]);
      }
    }
    
    void right(vector<int>&height, vector<int>&rightmax){
        int n = height.size();
        rightmax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
          rightmax[i] = max(rightmax[i+1], height[i]);
        }
    }

    int trap(vector<int>& height) {
      int n = height.size();
      vector<int>leftmax(n), rightmax(n);
      left(height, leftmax);
      right(height, rightmax);
      int ans = 0;
      for(int i = 0; i < n; i++){
        ans += min(leftmax[i], rightmax[i]) - height[i];
      }
      return ans;
    }
};