class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        nums1.sort()

        sz = len(nums1)
        
        ind2 = defaultdict(list)

        for i in range(sz):
            ind2[nums2[i]].append(i)
        
        nums2.sort()

        low_ind, high_ind  = 0, sz - 1

        ans = [-1] * sz

        for n1 in nums1:
            low_n2 = nums2[low_ind]
            high_n2 = nums2[high_ind]

            if n1 > low_n2:
                org_ind = ind2[low_n2].pop(0)
                low_ind += 1
            else:
                org_ind = ind2[high_n2].pop(0)
                high_ind -= 1
            
            ans[org_ind] = n1

        return ans


        

