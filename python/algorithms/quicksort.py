"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of quick sort with option for randomized quicksor
"""

from random import shuffle


def quicksort(arr, randomized = False):
    """Quick sort, runs in O(n log n), O(1) extra space."""
    if randomized:
        shuffle(arr)

    _quicksort(arr, 0, len(arr) - 1)


def _quicksort(arr, low, high):
    if high <= low:
        return

    p = _partition(arr, low, high)
    _quicksort(arr, low, p - 1)
    _quicksort(arr, p + 1, high)


def _partition(arr, low, high):
    wall = low
    lo = low
    hi = high
    
    p = hi

    while lo < hi:
        if arr[lo] < arr[p]:
            arr[lo], arr[wall] = arr[wall], arr[lo]  # swap
            wall += 1
        lo += 1

    arr[p], arr[wall] = arr[wall], arr[p]
    return wall
