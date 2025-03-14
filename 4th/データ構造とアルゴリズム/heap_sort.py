def min_heapfy(array, i):
    left = 2 * i + 1
    right = 2 * i + 2
    length = len(array) - 1
    smallest = i

    if left <= length and array[i] > array[left]:
        smallest = left
    if right <= length and array[smallest] > array[right]:
        smallest = right

    if smallest != i:
        array[i], array[smallest] = array[smallest], array[i]
        min_heapfy(array, smallest)

def build_min_heap(array):
    for i in reversed(range(len(array)//2)):
        min_heapfy(array, i)

def heapsort(array):
    array = array.copy()
    build_min_heap(array)
    sorted_array = []
    for _ in range(len(array)):
        array[0], array[-1] = array[-1], array[0]
        sorted_array.append(array.pop())
        min_heapfy(array, 0)

    return sorted_array
