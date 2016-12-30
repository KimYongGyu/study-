def ugly_number(n):
    while True:
        test = n
        while True:
            if (test % 5) != 0:
                break
            test=test/5
        while True:
            if (test % 3) != 0:
                break
            test=test/3
        while True:
            if (test % 2) != 0:
                break
            test=test/2
        if test == 1:
            return True
        return False

print(ugly_number(12))
