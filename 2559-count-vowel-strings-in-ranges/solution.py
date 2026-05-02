class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        
        n, m = len(words), len(queries)

        pre = [0 for i in range(n)]
        ans = [] 

        for i in range(n):
            word = words[i]
            pre[i] = pre[i - 1]

            if word[0] in "aeiou" and word[-1] in "aeiou":
                pre[i] += 1
        
        for i in range(m):
            start, end = queries[i]
            add = 1 if words[start][0] in "aeiou" and words[start][-1] in "aeiou" else 0

            ans.append(pre[end] - pre[start] + add)

        return ans