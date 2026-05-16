class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)

        initial, energy = 0, 0

        for actual, minimum in tasks:
            if energy < minimum:
                diff = minimum - energy
                initial += diff
                energy += diff

            energy -= actual

        return initial