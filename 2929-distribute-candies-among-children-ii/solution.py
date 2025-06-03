class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        
        limit = min(limit, n) #Assume that first child gets i, second gets j and third gets k candies

        #This might be complicated but the logic is:
        #   lets say our i is fixed then if we decided 
        #   what j is then our k is fixed aswell.*/

        # So that means for every i, the total 
        #   number of ways to distribute candies are exactly
        #   the valid number range for j. If we understand this
        #   the only thing we have to find is min and
        #   max limits for j. 
   
        # To find that we have to deal with equations. I will write them down

        # 0 <= j <= min(n - i, limit) Pretty basic logic here.
        #   But note that for this equation max limit for j is -> max_j = min(n - i, limit) (Eq. 1) 
        #   and min limit for j is -> min_j = 0. This will be important later on

        # We have to write valid number range for k now. k should be
        #   0 <= n - i - j = k <= limit. Forget that we have k since its fixed anyways. 
        #   For this equation min limit for j is -> min_j = max(0, n - i - limit) (Eq. 2)
        #   and max limit for j is max_j = n - i -> this is not important because we have already figured it out
        #   above (Eq.1)*/

        # Eq.2 logic is: for j to have min value we have to assume n - i - j = limit. According to this equation
        #   j = n - i - limit and since (n - i - limit) can be lower than 0 we have to put max(0, ....) in Eq.2 since j
        #  cant be lower than 0. Thats all.

        # So to summarize At max -> max_j = min(n - i, limit)
        #                   At min -> min_j = max(0, n - i - limit) 
        
        ans = 0
        for i in range(0, limit + 1):
            ans += max( min(n - i, limit) - max(0, n - i - limit) + 1, 0)

        return ans