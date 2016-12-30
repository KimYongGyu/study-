fahrenheit = eval(input("-58 이상 41사이의 온도를 입력하시오"))
windSpeed = eval(input("2이상의 풍속을 입력하시오"))
sensibleTemperature = 35.74 + (0.6215 * fahrenheit) - 35.75 * pow(windSpeed, 0.16) + (0.4275 * fahrenheit * pow(windSpeed, 0.16))
print("체감온도는 " , sensibleTemperature, "입니다.")
