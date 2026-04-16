class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        
        index, n = defaultdict(list), len(nums)

        ans = []

        def binarySearch(lst, target):
            l, r = 0, len(lst) - 1

            while l <= r:
                mid = (l + r) // 2

                num = lst[mid]

                if num < target:
                    l = mid + 1
                elif num > target:
                    r = mid - 1
                else:
                    return mid

            return -1

        for i in range(n):
            index[nums[i]].append(i)

        for q in queries:
            num = nums[q]
            ind_lst = index[num]
            m = len(ind_lst)

            if m < 2:
                ans.append(-1)
                continue

            ind = binarySearch(ind_lst, q)

            mini = float("inf")

            q1 = ind_lst[(ind + 1) % m]
            q2 = ind_lst[(ind - 1) % m]

            mini = min(n - abs(q - q1), abs(q - q1), n - abs(q - q2), abs(q - q2))
            ans.append(mini)

        return ans