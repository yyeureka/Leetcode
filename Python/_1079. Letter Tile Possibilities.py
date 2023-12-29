class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        n = len(tiles)
        if n <= 1:
            return n

        tiles = sorted(tiles)
        visited = [False for i in range(n)]
        self.res = 0
        self.helper(tiles, visited)

        return self.res

    def helper(self, tiles, visited):
        pre = None
        for i in range(len(tiles)):
            if visited[i] or tiles[i] == pre:
                continue

            self.res += 1
            pre = tiles[i]
            visited[i] = True
            self.helper(tiles, visited)
            visited[i] = False