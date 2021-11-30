def solution(s) :
    answer = len(s)
    length = len(s)
    count = 0
    equ = ''
    string = ''
    for i in range(1, int(length/2)+1, 1) :
        string=''
        for j in range(0, length, i) :
            if j == 0 :
                equ = s[j : j+i]
            if s[j : j+i] == equ :
                count += 1
            else :
                if count > 1 :
                    string += str(count)+equ
                else :
                    string += equ
                equ=s[j : j+i]
                count = 1
        if count > 1 :
            string += str(count) + equ
        else :
            string += equ
        count = 0
        if answer > len(string) :
            answer = len(string)
    print(answer)
    
solution("ddaaebbacc")
