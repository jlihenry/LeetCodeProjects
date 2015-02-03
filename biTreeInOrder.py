#!/usr/bin/python

# Definition for a binary tree
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution:
	# @param root, a tree node
	# @return a list of integers
	def inorderTraversal(self, root):
		inOrder = []
		if root == None:
			return inOrder
		stack = []
		stack.append(root)
		while len(stack) > 0:
			node = stack.pop();
			if node.left == None and node.right == None:
				inOrder.append(node.val)
			else:
				if node.right != None:
					stack.append(node.right)
				left = node.left
				node.left = None
				node.right = None
				stack.append(node)
				if left != None:
					stack.append(left)
		return inOrder

if __name__=='__main__':

