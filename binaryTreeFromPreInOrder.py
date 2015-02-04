#!/usr/bin/python
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        if len(preorder)==len(inorder)==0:
            return None
        root = TreeNode(preorder[0])
        if len(preorder)==len(inorder)==1:
            return root
        rootIndex = inorder.index(preorder[0])
        leftInOrder = inorder[0:rootIndex]
        rightInOrder = inorder[rootIndex+1:]
        leftPreOrder = preorder[1:rootIndex+1]
        rightPreOrder = preorder[rootIndex+1:]
        root.left = self.buildTree(leftPreOrder, leftInOrder)
        root.right = self.buildTree(rightPreOrder, rightInOrder)
        return root

def traverseTree(root):
	if root != None:
		print root.val
		traverseTree(root.left)
		traverseTree(root.right)
	else:
		return
if __name__=='__main__':
	solution = Solution()
	root = solution.buildTree([6,2,1,4,3,5,7,9,8], [1,2,3,4,5,6,7,8,9])
	traverseTree(root)

"""
class Solution:
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        if len(preorder)==len(inorder)==0:
            return None
        root = TreeNode(preorder[0])
        if len(preorder)==len(inorder)==1:
            return root
        rootIndex = inorder.index(preorder[0])
        root.left = self.buildTreeWithIndex(preorder, inorder, 1, rootIndex, 0, rootIndex-1)
        root.right = self.buildTreeWithIndex(preorder, inorder, rootIndex+1, len(preorder)-1, rootIndex+1, len(inorder)-1)
        return root
        
    def buildTreeWithIndex(self, preorder, inorder, leftpre, rightpre, leftin, rightin):
        if rightpre-leftpre<0 and rightin-leftin<0:
            return None
        root = TreeNode(preorder[leftpre])
        if rightpre-leftpre==rightin-leftin==0:
            return root
        rootIndex = inorder.index(root.val)
        leftlen = rootIndex - leftin
        rightlen = rightin - rootIndex + 1
        root.left = self.buildTreeWithIndex(preorder, inorder, leftpre+1, leftpre+leftlen, leftin, rootIndex-1)
        root.right = self.buildTreeWithIndex(preorder, inorder, leftpre+1+leftlen, rightpre, rootIndex+1, rightin)
        return root
"""