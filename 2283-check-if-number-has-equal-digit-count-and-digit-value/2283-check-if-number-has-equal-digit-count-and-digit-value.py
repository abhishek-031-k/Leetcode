class Solution:
    def digitCount(self, num: str) -> bool:
        mpp = {}
        for i in range(0, len(num)):
            mpp[num[i]] = mpp.get(num[i], 0) + 1
            
        for i in range(0, len(num)):
            if mpp.get(str(i), 0) == int(num[i]):
                continue
            else:
                return False
                
        return True