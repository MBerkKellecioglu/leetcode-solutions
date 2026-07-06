class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        
        ages.sort()

        n,ans = len(ages),0

        l,r = 0,0

        for i in range(n):
            x_age = ages[i]

            while l < n and ages[l] <= (x_age / 2) + 7:
                l += 1

            while r < n and ages[r] <= x_age:
                r += 1

            if r > l:
                ans += (r - l - 1)

        return ans