def happy(n):
    n = int(n)
    numlist = set()
    numlist.add(n)
    old = None
    while True:
        new = len(numlist)
        if new == old:
            return False
        old = len(numlist)
        n = eval('**2+'.join(str(n)+'0'))
        if n == 1:
            return True
        numlist.add(n)
def main():
    n =eval(input())
    print(happy(n))
   
main()
