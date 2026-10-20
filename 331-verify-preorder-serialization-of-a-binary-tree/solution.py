class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        
        space = 1

        preorder = preorder.split(",")

        for node in preorder:
            space -= 1

            if space < 0:
                return False
            
            if node != "#":
                space += 2
            
        return space == 0
        