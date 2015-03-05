#!/usr/bin/python
def partition(numList, start, end):
	pivot = numList[end]
	bottom = start - 1
	top = end

	done = 0
	while not done:
		while not done:
			bottom = bottom + 1
			if bottom == top:
				done = 1
				break
			for i in range(0, min(len(str(numList[bottom])), len(str(pivot)))):
				if int(str(numList[bottom])[i]) > int(str(pivot)[i]):		# Compare the first digits of two numbers
					numList[top] = list[bottom]
					break
				elif int(str(numList[bottom])[i]) == int(str(pivot)[i]):	# If the first digits are the same
					continue
				else:
					break
		while not done:
			top = top - 1
			if top == bottom:
				done = 1
				break
			for i in range(0, min(len(str(numList[bottom])), len(str(pivot)))):
				if int(str(numList[bottom])[i]) < int(str(pivot)[i]):		# Compare the first digits of two numbers
					numList[bottom] = list[top]
					break
				elif int(str(numList[bottom])[i]) == int(str(pivot)[i]):	# If the first digits are the same
					continue
				else:
					break
	numList[top] = pivot
	return top

def quicksort(numList, start, end):
	if start < end:
		split = partition(numList, start, end)
		quicksort(numList, start, split - 1)
		quicksort(numList, split + 1, end)
	else:
		return

if __name__=='__main__':
	import sys
	numList = [3, 30, 34, 5, 9]
	start = 0
	end = len(numList) - 1
	quicksort(numList, start, end)
	print numList

					
