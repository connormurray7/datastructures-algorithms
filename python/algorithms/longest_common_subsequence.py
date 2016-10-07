"""
Created by Connor Murray (connormurray7@gmail.com)
10/05/2016

Python implementation of Longest Common Subsequence
"""

def lcs(word1, word2):

    m = len(word1) + 1
    n = len(word2) + 1

    matrix = [[0] * n for i in range(m)]
    
    for i in range(1, m):
        for j in range(1, n):
            if word1[i-1] == word2[j-1]:
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

    return matrix[m-1][n-1]
