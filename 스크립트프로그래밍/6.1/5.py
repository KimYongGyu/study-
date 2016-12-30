pound = eval(input("몸무게를 파운드로  입력하시오"))
inch = eval(input("키를 인치로 입력하시오"))

kilogram = 0.45359237 * pound
meter = 0.0254 * inch

bmi = kilogram / (meter * meter)
print("BMI는 ", bmi)
