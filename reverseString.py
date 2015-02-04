#!/usr/bin/python
class Solution:
	# @param s, a string
	# @return a string
	def reverseWords(self, s):
		list = s.split(" ")
		output = ""
		print list
		for i in range(len(list)-1, -1, -1):
			if list[i] == "":
				continue
			output += list[i]+" "
		return output[:len(s)]

if __name__=='__main__':
	solution = Solution()
	print solution.reverseWords(" ")
