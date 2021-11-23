def compare(number):
    number = list(map(str, number))                  
    number.sort(key = lambda x:x*2, reverse = True)
    return ''.join(number)                                  

num = [10, 68, 75, 7, 21, 12]
print(compare(num))
