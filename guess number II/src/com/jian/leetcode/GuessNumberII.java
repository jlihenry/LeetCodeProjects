package com.jian.leetcode;

public class GuessNumberII {
	int m_number;
	
	public GuessNumberII(int num) {
		m_number = num;
	}
	
	public int guess(int num) {
		if (m_number > num) return 1;
		else if (m_number < num) return -1;
		else return 0;
	}
	
	public int getMoneyAmount(int n) {
		int[][] dp = new int[n+2][n+2];
		
		for (int j=2; j<n+1; j++) {
			for (int i=j-1; i>=1; i--) {
				dp[i][j] = Integer.MAX_VALUE;
				for (int pick=i; pick<=j; pick++) {
					int tmp = pick + Math.max(dp[i][pick-1], dp[pick+1][j]);
					if (tmp < dp[i][j]) dp[i][j] = tmp;
				}
			}
		}
		
		return dp[1][n];
	}
}
