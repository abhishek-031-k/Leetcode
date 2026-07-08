class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0, sum = 0;
       string s = to_string(n);
       for(int i = 0; i < s.size(); i++){
          if(s[i] != '0'){
            ans = ans*10 + s[i]-'0';
            sum += s[i]-'0';
          }
       }
       return ans*sum;
    }
};