class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int a=n/3;
        vector<int>v;
        for(auto it:mpp){
            if(it.second>a) v.push_back(it.first);
        }
        return v;
    }
};