class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       vector<int>ans;
       int maxi = 0, mini = INT_MAX;
       for(auto &it: nums){
        maxi = max(maxi, it);
        mini = min(mini, it);
       } 
      unordered_set<int>st(nums.begin(), nums.end());
       
       for(int i = mini; i < maxi; i++){
         if(st.count(i) == 0)ans.push_back(i);
       }
       return ans;
    }
};