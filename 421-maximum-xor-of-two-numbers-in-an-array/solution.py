class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:

        root =  {}

        ans = 0

        for num in nums:
            node = root
            # Should start from MSB (Most Significant Bit) so we dont have to check every path of Trie
            # 2^31 > 2^30 + 2^29..... (Same Rule goes for every positions e.g 2^4 > 2^3 + 2^2...)
            for shift in range(31,-1,-1):
                # find nth bit
                bit = (num >> shift) & 1
                # add path if it does not exist
                if bit not in node:
                    node[bit] = {}
                node = node[bit]
        
        for num in nums:
            node = root
            xor = 0
            for shift in range(31,-1,-1):
                bit = (num >> shift) & 1
                toggle = 1 - bit

                if toggle in node:
                   xor |= (1 << shift)
                   node = node[toggle]
                else:
                    node = node[bit]

            ans = max(ans, xor)

        return ans 