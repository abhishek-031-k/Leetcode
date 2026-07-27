class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxi = INT_MIN, maxi2 = INT_MIN;
       for(auto &it: nums){
        if(maxi <= it){
            maxi2 = maxi;
            maxi = it;
        }
        else if(maxi2 <= it)maxi2 = it;
       } 
       return (maxi - 1)*(maxi2 - 1);
    }
};