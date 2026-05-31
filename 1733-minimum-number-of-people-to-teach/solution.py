class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        
        # neat little trick i learned from GPT to check if there is common element between two lists
        # instead of comparing them in nested for loops we can just (list1 & list2)
        compare = [set(x) for x in languages]

        not_common = set()

        for f1, f2 in friendships:
            if not (compare[f1 - 1] & compare[f2 - 1]):
                not_common.add(f1)
                not_common.add(f2)

        ans = float('inf')

        for l in range(1, n + 1):
            teach = 0

            for p in not_common:
                if l not in compare[p - 1]:
                    teach += 1

            ans = min(ans, teach)

        return ans