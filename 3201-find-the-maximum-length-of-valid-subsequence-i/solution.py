class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        
        n = len(nums)

        s0,s1,s2,s3 = 0,0,0,0

        l0,l1,l2,l3 = -1,-1,-1,-1

        # 0 means E + E, 1 means O + O , 2 means E + O, 3 means O + E + O

        if nums[0] % 2:
            l1 = nums[0]
            l3 = nums[0]
            s1 += 1
            s3 += 1
        else:
            l0 = nums[0]
            l2 = nums[0]
            s0 += 1
            s2 += 1

        for i in range(1, n):
            if nums[i] % 2:
                s1 += 1
                l1 = nums[i]

                if not (l3 % 2) or l3 == -1:
                    s3 += 1
                    l3 = nums[i]

                if not (l2 % 2):
                    s2 += 1
                    l2 = nums[i]
            else:
                s0 += 1
                l0 = nums[i]

                if l2 % 2 or l2 == -1:
                    s2 += 1
                    l2 = nums[i]
                
                if l3 % 2:
                    s3 += 1
                    l3 = nums[i]

        return max(s0,s1,s2,s3)
