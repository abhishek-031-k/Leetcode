class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int rightmax = 0, leftmax = 0, l = 0, r = n-1;
        int total = 0;
        while(r > l){
            if(height[l] <= height[r]){
            if(height[l] < leftmax)total += leftmax - height[l];
            else leftmax = height[l];
            l++;
            }
            else {
            if(height[r] < rightmax)total += rightmax - height[r];
            else rightmax = height[r];
            r--;
            }
        }
     return total;
    }
};