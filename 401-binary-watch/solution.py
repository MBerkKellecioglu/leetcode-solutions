class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:

        hour = defaultdict(list)
        minute = defaultdict(list)
        ans = []

        hour[0] = [0]
        minute[0] = [0]

        for i in range(1,12):
            turn = 0
            tmp = i
            while tmp > 0:
                turn += 1
                tmp = tmp & (tmp - 1)
            
            hour[turn].append(i)
        
        for i in range(1, 60):
            turn = 0
            tmp = i
            while tmp > 0:
                turn += 1
                tmp = tmp & (tmp - 1)
            
            minute[turn].append(i)

        def dfs(turn, h, m, flag):
            if turn < 0:
                return 

            if not flag:
                for i in range(min(turn + 1, 4)):
                    for num in hour[i]:
                        dfs(turn - i, num, m, True)
            else:
                for num in minute[turn]:
                    lead = ""
                    if num < 10:
                        lead = "0"
                    ans.append(str(h) + ":" + lead + str(num))


        dfs(turnedOn, 0, 0, False)

        return ans