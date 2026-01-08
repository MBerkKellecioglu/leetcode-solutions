class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        
        """
        Initially i thought of sorting string formats of numbers then comparing every
        consecutive pair by adding their string format together in two ways. a + b compared
        to b + a. This is not a valid sorting way so we use comparator to make these comparisons
        for every pair not just consecutive ones.
        """

        convert = []
        ans = ""

        for num in nums:
            convert.append(str(num))

        def compare(a, b):
            if a + b > b + a:
                return -1
            elif b + a > a + b:
                return 1
            else:
                return 0

        convert.sort(key = cmp_to_key(compare))

        for converted in convert:
            ans += converted
        
        return ans if ans[0] != "0" else "0"
        
                