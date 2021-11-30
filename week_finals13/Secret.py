arr1 = [40, 32, 30, 18, 11]
arr2 = [30, 19, 2, 15, 20]

r = 0

for i in range(0, len(arr1)):
    r = arr1[i] | arr2[i]
    print("[", end="")
    for j in range(len(arr1) - 1, -1, -1):
        if(((r >> j ) & 1) == 1 ):
            print("#", end="")
        else:
            print(" ", end="")
    print("]")
