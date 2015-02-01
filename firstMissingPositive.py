#!/usr/bin/python
import math

class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        # put all non-positive numbers on the left side and 
		# put all positive numbers on the right side
		index=0
        for i in range(0, len(A)):
            if A[i]<=0:
                temp=A[i]
                A[i]=A[index]
                A[index]=temp
                index=index+1

		# mark an element A[i] by change A[A[i]] to negative value
        for i in range(index, len(A)):
            if abs(A[i])-1<len(A)-index:
                if A[abs(A[i])-1+index] < 0:
                    continue
                else:
                    A[abs(A[i])+index-1]*=-1

		# the index of the first positive value in A
        for i in range(index, len(A)):
            if A[i]>0:
                return i+1-index
        return len(A)-index+1

if __name__=='__main__':
	solution = Solution()
	list = [1,1]# [1,2,-3,4,-5]
	print solution.firstMissingPositive(list)
