def findElement(arr,n):
    leftMax = [0]*n
    rightMin = [0]*n

    leftMax[0] = -99999
    rightMin[n-1] = 99999

    for i in range(1,n):
        if(leftMax[i-1]>arr[i-1]):
            leftMax[i] = leftMax[i-1]
        else:
            leftMax[i] = arr[i-1]

    for i in range(n-2,-1,-1):
        if(rightMin[i+1]>arr[i+1]):
            rightMin[i] = arr[i+1]
        else:
            rightMin[i] = rightMin[i+1]

    for i in range(0,n):
        if((leftMax[i]<=arr[i]) & (rightMin[i]>=arr[i])):
            print(i, end=" ")
    return -1




arr = [1,2,3,4,5,6,7,8,9]
n = len(arr)
findElement(arr,n)
