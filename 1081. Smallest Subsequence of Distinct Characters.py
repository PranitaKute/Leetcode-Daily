class Solution:
    def smallestSubsequence(self, s: str) -> str:
        vis = [0] * 26
        num = [0] * 26
        for ch in s:
            num[ord(ch) - ord("a")] += 1
        stk = []

        for ch in s:
            index = ord(ch) - ord("a")
            if not vis[index]:
                while stk and stk[-1] > ch:
                    top_index = ord(stk[-1]) - ord("a")
                    if num[top_index] > 0:
                        vis[top_index] = 0
                        stk.pop()
                    else:
                        break
                vis[index] = 1
                stk.append(ch)
            num[index] -= 1

        return "".join(stk)
      
