class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>v(26, 0);
        int ans = 0, j = 0, n = s.size();
        for(int i = 0; i < n; i++){
            v[s[i]-'a']++;
            while(v[s[i]-'a'] > 2){
                 v[s[j]-'a']--;
                 j++;
            }
        ans = max(ans, i-j+1);
        }
        return ans;
    }
};