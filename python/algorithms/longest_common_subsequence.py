"""
Created by Connor Murray (connormurray7@gmail.com)
10/05/2016

Python implementation of Longest Common Subsequence
"""


def lcs(word1, word2):
    """Longest common subsequence, runs in O(m * n), O(m * n) extra space."""
    m = len(word1) + 1
    n = len(word2) + 1

    matrix = [[0] * n for i in range(m)]
    
    for i in range(1, m):
        for j in range(1, n):
            if word1[i-1] == word2[j-1]:
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

    return _backtrack(matrix, word1, word2, m-1, n-1)


def _backtrack(matrix, word1, word2, i, j):
    if i == 0 or j == 0:
        return ""
    if word1[i-1] == word2[j-1]:
        return _backtrack(matrix, word1, word2, i-1, j-1) + word1[i-1]
    else:
        if matrix[i][j-1] > matrix[i-1][j]:
            return _backtrack(matrix, word1, word2, i, j-1)
        else:
            return _backtrack(matrix, word1, word2, i-1, j)
