class Solution {
public:
    int minimumPushes(string word) {
       map<char, int>mpp;
        for(auto &it : word)mpp[it]++;
        
        int count = 0, ans = 0, value = 1;
        for(auto &it : mpp){
             ans += value * it.second;
           count++;
           if(count % 8 == 0)value++;
        }
        return ans;
    }
};