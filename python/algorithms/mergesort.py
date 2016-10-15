"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of mergesort
"""


def mergesort(arr, low, high):
    """Runs in O(n log n) with O(n) extra space"""
    if high <= low:
        return
    mid = (high + low) // 2
    mergesort(arr, low, mid)
    mergesort(arr, mid + 1, high)
    _merge(arr, low, high)


def _merge(arr, low, high):
    tmp = [None]*(high-low+1)  # Pre-allocate for speed

    k = 0
    lo = low
    mid = (high + low) // 2
    hi = mid + 1

    while(lo <= mid and hi <= high):
        if arr[lo] < arr[hi]:
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

    # Have to write back.
    lo = low
    for val in tmp:
        arr[lo] = val
        lo += 1
