class Solution:
    def shoppingOffers(self, price: list[int], special: list[list[int]], needs: list[int]) -> int:
        
        memo = {}

        n = len(needs)

        def dfs(need):
            nonlocal n

            # tuple is faster
            memo_key = tuple(need)

            if memo_key in memo:
                return memo[memo_key]

            # base case where we dont use any special offers
            min_cost = sum(p * n for p, n in zip(price,need))

            for offer in special:
                nxt_need = need[:]
                cost = offer[-1]

                valid = True

                for idx in range(n):
                    # offered piece for idxth item
                    piece = offer[idx]

                    # restriction -> cant buy more items than we need to
                    if nxt_need[idx] - piece < 0:
                        valid = False
                        break
                    
                    nxt_need[idx] -= piece
            
                if valid:
                    # special offer cost + remaining need cost
                    min_cost = min(min_cost, cost + dfs(nxt_need))
            
            memo[memo_key] = min_cost

            return min_cost
        
        return dfs(needs)