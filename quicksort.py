#!/usr/bin/python
class Solution:
	# @param num, a list of integers
	# @return a string
	def largestNumber(self, num):
		self.quicksort(num, 0, len(num) - 1)
		result = ""
		for item in num:
			result = result + str(item)
		return str(int(result))

	def partition(self, list, start, end):
		pivot = list[end]
		bottom = start - 1
		top = end

		done = 0
		while not done:
			
			while not done:
				bottom = bottom + 1

				if bottom == top:
					done = 1
					break
				
				curr = str(list[bottom])
				pivo = str(pivot)
				
				flag = 0
				for i in range(0, min(len(curr), len(pivo))):
					if int(curr[i]) < int(pivo[i]):
						list[top] = list[bottom]
						flag = 1
						break
					elif int(curr[i]) == int(pivo[i]):
						if i == min(len(curr), len(pivo)) - 1:# and len(curr) > len(pivo):
							if (len(curr) > len(pivo) and int(pivo[0]) < int(curr[len(pivo)])) or (len(curr) < len(pivo) and int(curr[0]) < int(pivo[len(curr)])):
								list[top] = list[bottom]
								flag = 1
								break

						else:
							continue
					else:
						break
				
				if flag:
					break

			while not done:
				top = top - 1

				if top == bottom:
					done = 1
					break

				curr = str(list[top])
				pivo = str(pivot)
				
				flag = 0
				for i in range(0, min(len(curr), len(pivo))):
					if int(curr[i]) > int(pivo[i]):
						list[bottom] = list[top]
						flag = 1
						break
					elif int(curr[i]) == int(pivo[i]):
						if i == min(len(curr), len(pivo)) - 1:# and len(curr) > len(pivo):
							if (len(curr) > len(pivo) and int(pivo[0]) >= int(curr[len(pivo)])) or (len(curr) < len(pivo) and int(curr[0]) < int(pivo[len(curr)])):
								list[bottom] = list[top]
								flag = 1
								break
						else:
							continue
					else:
						break
				
				if flag:
					break

		list[top] = pivot
		return top

	def quicksort(self, list, start, end):
		if start < end:
			split = self.partition(list, start, end)
			self.quicksort(list, start, split - 1)
			self.quicksort(list, split + 1, end)
		else:
			return

if __name__=='__main__':
	solution = Solution()
	print solution.largestNumber([128,12])
	print solution.largestNumber([12,128])
