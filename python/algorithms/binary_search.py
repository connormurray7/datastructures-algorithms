"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of a recursive and iterative binary search
"""

def binary_search_recursive(arr, low, high, val):
    """Binary search using recursion on sorted array, O(log n)"""
    mid = (high + low) // 2
    if arr[mid] == val:
        return mid
    
    if val < arr[mid]:
        return binary_search_recursive(arr, low, mid -1, val)

    return binary_search_recursive(arr, mid + 1, high, val)

def binary_search_iterative(arr, val):
    """Iterative binary search on sorted array, O(log n)"""
    low = 0
    high = len(arr) - 1

    while(low <= high):
        mid = (high + low) // 2

        if arr[mid] == val:
            return mid

        if val < arr[mid]:
            low = mid + 1
        else:
            high = mid - 1
    
    return None
