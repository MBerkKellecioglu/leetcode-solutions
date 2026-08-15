class Solution:
    def stoneGameVI(self, aliceVal: List[int], bobVal: List[int]) -> int:
        
        n = len(aliceVal)

        gain = [0] * n

        for i in range(n):
            gain[i] = [aliceVal[i] + bobVal[i], i]

        gain.sort(reverse=True)

        alice, bob = 0, 0

        for turn in range(n):
            if turn % 2 == 0:
                alice += aliceVal[gain[turn][1]]
            else:
                bob += bobVal[gain[turn][1]]

        if alice > bob:
            return 1
        elif bob > alice:
            return -1
        else:
            return 0


