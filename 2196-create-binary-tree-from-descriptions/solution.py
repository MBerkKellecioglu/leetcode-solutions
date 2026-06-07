# Definition for a binary tree node_to_value.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, desc: List[List[int]]) -> Optional[TreeNode]:
        
        node_to_value = {}

        find_root = defaultdict(lambda: True)

        for parent, child, side in desc:
            if parent in node_to_value:
                parent_node = node_to_value[parent]
            else:
                parent_node = TreeNode(parent)

            if child in node_to_value:
                child_node = node_to_value[child]
            else:
                child_node = TreeNode(child)
            
            if side % 2:
                parent_node.left = child_node
            else:
                parent_node.right = child_node
            
            node_to_value[parent] = parent_node
            node_to_value[child] = child_node

            find_root[child_node] &= False
            find_root[parent_node] &= True
        
        for parents, ifroot in find_root.items():
            if ifroot:
                return parents
        
        return -1


                
            