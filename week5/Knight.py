# 나이트가 이동할 수 있는 8가지 방향 정의
steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

knight = input()  #현재 나이트의 위치 입력받기
row = int(knight[1])
column = int(ord(knight[0])) - int(ord('a')) + 1

result = 0

# 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
for step in steps:
    # 이동하고자 하는 위치 확인
    nRow = row + step[0]
    nCol = column + step[1]

    # 해당 위치로 이동이 가능하다면 카운트 증가
    if nRow >= 1 and nRow <= 8 and nCol >= 1 and nCol <= 8:
        result += 1

print(result)
