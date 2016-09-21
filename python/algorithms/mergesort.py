"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of mergesort
"""

def merge_sort(arr, low, high):
    if high <= low:
        return
    mid = (high + low) // 2
    merge_sort(arr, low, mid)
    merge_sort(arr, mid + 1, high)
    merge(arr, low, high)

def merge(arr, low, high):
    tmp = [None]*(high-low+1) #Pre-allocate for speed

    k = 0
    lo = low
    mid = (high + low) // 2
    hi = mid + 1

    while(lo <= mid and hi <= high):
        if arr[lo] < arr[hi]
            tmp[k] = arr[lo]
            lo += 1
        else:
            tmp[k] = arr[hi]
            hi += 1
        k += 1
        
    while(lo <= mid):
        tmp[k] = arr[lo]
        k += 1
        lo += 1
    
    while(hi <= high):
        tmp[k] = arr[hi]
        k += 1
        hi += 1

    #Have to write back.
    lo = low
    for val in tmp:
        arr[lo] = tmp[k]
        lo += 1
