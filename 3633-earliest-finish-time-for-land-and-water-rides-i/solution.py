class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        
        earliestLand = float("inf")
        earliestWater = float("inf")
        ans = float("inf")


        for i in range(len(landDuration)):
            earliestLand = min(earliestLand, landStartTime[i] + landDuration[i])

        for i in range(len(waterDuration)):
            earliestWater = min(earliestWater, waterStartTime[i] + waterDuration[i])
        
        for i in range(len(waterDuration)):
            if waterStartTime[i] <= earliestLand:
                ans = min(ans, earliestLand + waterDuration[i])
            else:
                ans = min(ans, waterStartTime[i] + waterDuration[i])
        
        for i in range(len(landDuration)):
            if landStartTime[i] <= earliestWater:
                ans = min(ans, earliestWater + landDuration[i])
            else:
                ans = min(ans, landStartTime[i] + landDuration[i])

        return ans