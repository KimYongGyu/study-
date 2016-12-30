
def Cabinet() :
    c = []
    for a in range(100):
        c.append(False)
    for a in range(100):
        for ab in range(a,100, a+1):
            if c[ab] == False:
                c[ab] = True
            elif c[ab] == True:
                c[ab] = False
        if c[a] == True:
            print(a+1)

def main():
    print("열려 있는 사물함은 : ")
    Cabinet()
    
main()
