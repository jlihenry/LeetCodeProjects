#!/usr/bin/python

class Solution:
	# @param prices, a list of integer
	# @return an integer
	def maxProfit(self, prices):
		i = 0
		n = len(prices)
		profit = 0
		for i in range(0, n-1):
			profit += max(prices[i+1]-prices[i], 0)
		return profit	

if __name__=='__main__':
	solution = Solution()
	list = [1,3,2,10]
	print solution.maxProfit(list)
