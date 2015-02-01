#!/usr/bin/python

class Solution:
	# @param digits, a list of integer digits
	# @return a list of integer digits
	def plusOne(self, digits):
		if len(digits) == 0:
			return [1]
		lastDigit=digits[len(digits)-1]
		if lastDigit<9:
			digits[len(digits)-1]=lastDigit+1
			return digits
		else:
			#print digits
			#print digits[:len(digits)-1]
			digits=self.plusOne(digits[:len(digits)-1])
			digits.append(0)
			return digits

if __name__=='__main__':
	intList=[0]
	solution=Solution()
	print solution.plusOne(intList)
