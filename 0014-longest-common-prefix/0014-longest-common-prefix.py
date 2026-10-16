class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        s = ""
        n = len(strs)
        ptr = 0
        for i in range(0, 201):
            flag = True
            if(len(strs[0]) == i):
                break
            val = strs[0][i]
            for j in range(1, n):
                if(len(strs[j]) == i):
                    flag = False
                    break
                flag = flag and (strs[j][i] == val)
            if (flag):
                s += val
                ptr+=1
            else:
                break
        return s
           
