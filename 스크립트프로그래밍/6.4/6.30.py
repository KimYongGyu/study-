#6.30 게임 : 크랩스의 승리 가능성

import random

#주사위 굴리는 함수
def diceRoll():
    num1 = random.randint(1, 6)
    num2 = random.randint(1, 6)
    diceSum = num1 + num2
    return diceSum

#크랩스 게임
def crapsGame(diceSum):
    if diceSum == 2 or diceSum == 3 or diceSum == 12:
        return False
    
    elif diceSum == 7 or diceSum == 11:
        return True
    
    else:
        second(diceSum)

#두번째 이후로의 크랩스게임
def second(diceSum):
    while 1:
        score = diceRoll()
        if score == 7:
            return False

        elif score == diceSum:
            return True

#메인
count = 0
win = 0
while count <= 10000:
    if crapsGame(diceRoll()):
        win  = win+1
    count = count + 1 
print( win,"번 승리했습니다.")
