class Solution {
public:
    int minimumPushes(string word) {
      vector<int>v(26, 0);
        for(auto &it : word)v[it - 'a']++;
        
        int count = 0, ans = 0, value = 1;
        for(int i = 0; i < 26; i++){
           if(v[i] > 0){  ans += value;
             count++;
           if(count % 8 == 0)value++;
        }
        }
        return ans;
    }
};