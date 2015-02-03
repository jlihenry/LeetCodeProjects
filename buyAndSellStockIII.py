#!/usr/bin/python

class Solution:
	# @param prices, a list of integer
	# @return an integer
	def maxProfit(self, prices):
		minPrice = prices[0]
		maxProfit = 0
		profits = []
		for i in range(0, len(prices)):
			minPrice = min(minPrice, prices[i])
			maxProfit = max(maxProfit, prices[i] - minPrice)
			profits.append(maxProfit)
		
		maxPrice = 0
		maxProfit = 0
		profit = profits[-1]
		for i in range(len(prices)-1, 0, -1):
			maxPrice = max(maxPrice, prices[i])
			maxProfit = max(maxProfit, maxPrice - prices[i])
			profit = max(profit, maxProfit + profits[i-1])
		
		return profit

if __name__=='__main__':
	solution = Solution()
	input = [2,1,2,0,1]
	print solution.maxProfit(input)
