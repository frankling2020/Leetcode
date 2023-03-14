class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter
        a = Counter(s)
        b = Counter(t)
        
        isFlag = True
        if len(a) == len(b):
            for k, v in a.items():
                if k not in b.keys() or v != b[k]:
                    isFlag = False
                    break
        else:
            isFlag = False
        return isFlag