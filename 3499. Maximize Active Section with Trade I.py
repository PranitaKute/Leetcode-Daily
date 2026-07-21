class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        count1 = s.count("1")
        n = len(s)
        i = 0
        gain = 0
        prev = -inf
        while i < n:
            start = i
            while i < n and s[i] == s[start]:
                i += 1
            if s[start] == "0":
                curr = i - start
                gain = max(gain, prev + curr)
                prev = curr
        return count1 + gain
