class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        
        positions = defaultdict(int)

        n = len(nums)

        ans = []

        for i in range(n):
            positions[nums[i]] += 1
        
        for i in range(len(moveFrom)):
            move = moveFrom[i]
            to = moveTo[i]
            freq = positions[move]
            positions[move] = 0
            positions[to] += freq

        for num, freq in positions.items():
            if freq > 0:
                ans.append(num)

        ans.sort()
        return ans