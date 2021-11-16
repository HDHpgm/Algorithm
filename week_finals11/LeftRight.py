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
            return i
    return -1




arr = [5,1,4,3,6,8,10,7,9]
n = len(arr)
idx = findElement(arr,n)
print(idx)
