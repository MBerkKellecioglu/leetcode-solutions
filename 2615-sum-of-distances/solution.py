class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        
        n = len(nums)

        occurances = defaultdict(list)

        ans = []

        ans_ind = defaultdict(int)

        for i in range(n):
            if nums[i] not in occurances:
                occurances[nums[i]].append(i)
            else:
                occurances[nums[i]].append(occurances[nums[i]][-1] + i)
      
        for i in range(n):
            num = nums[i]
            occurance = occurances[num]
            m = len(occurance)

            ind = ans_ind[num]
            ans_ind[num] += 1

            left_size = ind
            right_size = m - ind - 1
            left_sum = occurance[ind] - i
            right_sum = occurance[-1] - occurance[ind]

            val = right_sum + i * (left_size - right_size) - left_sum

            ans.append(val)

        #print(occurances)

        return ans