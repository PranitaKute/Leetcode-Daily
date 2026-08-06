class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def ck(num: int) -> bool:
            product = 1
            while num > 0:
                product *= num % 10
                num //= 10
                if product == 0:
                    break
            return product % t == 0

        while not ck(n):
            n += 1
        return n
