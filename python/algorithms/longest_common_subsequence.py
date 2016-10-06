"""
Created by Connor Murray (connormurray7@gmail.com)
10/05/2016

Python implementation of Longest Common Subsequence
"""

def lcs(word1, word2):

    matrix = [[0]*len(word2)]*len(word1)
    
    for i in range(1, len(word1)):
        for j in range(1, len(word2)):
            if word1[i] == word2[j]:
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

    return matrix[len(word1)-1][len(word2)-1]
