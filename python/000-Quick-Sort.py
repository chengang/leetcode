def partition(array, start, end):
    small_ptr = start
    x = array[end]

    for i in range(start, end):
        if array[i] <= x:
            tmp = array[i]
            array[i] = array[small_ptr]
            array[small_ptr] = tmp
            small_ptr += 1

    tmp = x
    array[end] = array[small_ptr]
    array[small_ptr] = tmp
    return small_ptr
    
def quickSort(array):
    qs(array, 0, len(array) - 1)

def qs(array, start, end):
    if start >= end:
        return
    ptr = partition(array, start, end)
    qs(array, start, ptr - 1)
    qs(array, ptr + 1, end)

array9 = [3,4,6,1,324,5,67,2,45,678,987,100]
print(array9)
quickSort(array9)
print(array9)
