#selection_sort
def sort(A):
    ecount = 0
    for i in range(0, len(A) - 1):
        select_min(A, i)
        ecount += 1
    print("Exch Count: ", ecount)

def select_min(A, i):
    min = i
    ccount = 0
    for j in range(i + 1, len(A)):
        if A[min] > A[j]:
            min = j
        ccount += 1
    print("Comp Count: ", ccount)
    A[i], A[min] = A[min], A[i]

def main():
    A = [9, 2, 5, 4, 7]
    sort(A)
    print(A)

if __name__ == "__main__":
    main()
