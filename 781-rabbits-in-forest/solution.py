class Solution:
    def numRabbits(self, answers: list[int]) -> int:
        
        freq = defaultdict(int)

        n = len(answers)

        rabbits = 0

        for ans in answers:
            if ans == 0:
                rabbits += 1
                continue
            
            f = freq[ans]

            f += 1
            f %= (ans + 1)

            freq[ans] = f

            if f == 1:
                rabbits += (ans + 1)

        return rabbits