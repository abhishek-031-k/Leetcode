class Solution {
public:
    int minimumPushes(string word) {
          vector<int>v(26, 0);
        for(auto &it : word)v[it - 'a']++;
        sort(v.begin(), v.end());
        int count = 0, ans = 0, value = 1;
        for(int i = 25; i >= 0; i--){
           ans += value*v[i];
           count++;
           if(count % 8 == 0)value++;
        }
        return ans;
    }
};