class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        stack = []
        postOrder = []
        if root == None:
            return postOrder
        stack.append(root)
        while len(stack) > 0:
            node = stack.pop()
            if node.left==None and node.right==None:
                postOrder.append(node.val)
            else:
                left = node.left
                right = node.right
                node.left = None
                node.right = None
                stack.append(node)
                if right != None:
                    stack.append(right)
                if left != None:
                    stack.append(left)
        return postOrder