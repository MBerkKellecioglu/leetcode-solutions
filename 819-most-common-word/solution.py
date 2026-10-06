class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        
        banned_set = set(banned)
        
        punctuations = "!?',;."
        convert = str.maketrans(punctuations, " " * len(punctuations))
        
        words = paragraph.lower().translate(convert).split()

        freq = Counter(word for word in words if word not in banned_set)

        return freq.most_common(1)[0][0]
