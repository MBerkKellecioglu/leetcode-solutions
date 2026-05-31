class Solution:
    def asteroidsDestroyed(self, mass: int, ast: List[int]) -> bool:
        
        ast.sort()

        for roid in ast:
            if mass < roid:
                return False
            
            mass += roid

        return True