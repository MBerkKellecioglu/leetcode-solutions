class TrieNode:
    def __init__(self):
        self.children = {}
        self.best = -1

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        
        root = TrieNode()

        ans = []

        def insert(word, ind):
            n = len(word)

            curr = root

            curr.best = ind if (n < len(wordsContainer[curr.best]) or curr.best == -1) else curr.best

            for c in reversed(word):
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                
                curr = curr.children[c]

                curr.best = ind if (n < len(wordsContainer[curr.best]) or curr.best == -1) else curr.best
        
        for i in range(len(wordsContainer)):
            insert(wordsContainer[i], i)

        for query in wordsQuery:
            curr = root
            
            for c in reversed(query):
                if c not in curr.children:
                    break
            
                curr = curr.children[c]
            
            ans.append(curr.best)

        return ans
        