class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        total = m * n
        k %= total
        res = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                index = (i * n + j + k) % total
                r, c = divmod(index, n)
                res[r][c] = grid[i][j]

        return res
