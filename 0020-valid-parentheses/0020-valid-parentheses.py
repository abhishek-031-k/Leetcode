class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for i in range(0, len(s)):
            if(s[i] == '[' or s[i] == '{' or s[i] == '('):
                st.append(s[i])
            else:
                if(len(st) == 0):
                    return False
                c = st[-1]
                if((s[i] == ']' and c == '[') or (s[i] == '}' and c == '{') or
                   (s[i] == ')' and c == '(')):
                   st.pop()
                else:
                    return False
        return not st               