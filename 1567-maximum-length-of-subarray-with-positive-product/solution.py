class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        
        # This is brilliant. Just keep track of positive and negative lengths of the array
        # Every negative value is just a switch between positive and negative subarrays
        positive, negative = 0, 0

        ans = 0

        for num in nums:
            if num > 0:
                positive += 1

                if negative > 0:
                    negative += 1

            elif num < 0:
                new_positive = negative + 1 if negative > 0 else 0
                new_negative = positive + 1

                positive = new_positive
                negative = new_negative
            else:
                positive = 0
                negative = 0

            ans = max(ans,positive)

        return ans

