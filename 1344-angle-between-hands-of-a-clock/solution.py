class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        
        m_degree = minutes * 6

        h_degree = (hour % 12) * 30 + (minutes * 1/2)

        diff = max(h_degree, m_degree) - min(h_degree, m_degree)

        explementary = 360 - diff

        return min(diff, explementary)