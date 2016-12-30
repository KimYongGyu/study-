def fibonacci( n):
    m=n-1
    if m<2:
        return m
    else:
        tmp =1
        current =1
        last = 0
        for i in range(2,m+1):
            tmp = current
            current+=last
            last = tmp
    return current
def main():
    for i in range(0,10):
       print(fibonacci(i))
main()
