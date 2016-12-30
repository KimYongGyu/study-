import time
currentTime = time.time()
gap = eval(input("GMT와 시간대 차이를 입력하세요"))
totalSeconds = int(currentTime)
currentSecond =  totalSeconds % 60
totalMinutes = totalSeconds // 60
currentMinute = totalMinutes % 60
totalHours = totalMinutes // 60
currentHour = (totalHours % 24) + gap

print("현재 시간은 ",str(currentHour), ":",str(currentMinute), ":",str(currentSecond) + "입니다.")

##test
print(currentTime)
print(int(currentTime))

