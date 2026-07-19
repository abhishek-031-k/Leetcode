class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int>alpha(26, 0);
      for(int i = 0; i < s.size(); i++)alpha[s[i] - 'a'] = i;
      vector<bool>v(26, false);
        string st = "";
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a'])continue;
            while (!st.empty() && st.back() > s[i] && alpha[st.back() - 'a'] > i) {
                v[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(s[i]);
            v[s[i] - 'a'] = true;
        }
        return st;  
    }
};