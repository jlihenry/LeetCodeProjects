#!/usr/bin/python

# Definition for an interval
class Interval:
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

# Print out a list of Interval
def printf(intervals):
		for item in intervals:
			print item.start, item.end

class Solution:
	# @param intervals, a list of Interval
	# @return a list of Interval
	def merge(self, intervals):
		intervals=sorted(intervals, key=lambda Interval:Interval.start)
		if len(intervals) == 0:
			return intervals
		result=[]
		result.append(intervals[0])
		for i in range(1, len(intervals)):
			temp=result.pop()
			if intervals[i].start <= temp.end:
				temp=Interval(temp.start, max(intervals[i].end,temp.end))
				result.append(temp)
			else:
				result.append(temp)
				result.append(intervals[i])
		return result


if __name__=='__main__':
	intervals=[Interval(3,5), Interval(2,6), Interval(5,8), Interval(10, 15)]
	solution=Solution()
	result=solution.merge(intervals)
	printf(result)
