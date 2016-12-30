def binarySearch(lst, key):
    low=0
    high=len(lst)-1

    while high>=low:
        mid = (low+high)//2
        if key<lst[mid]:
            high = mid -1
        elif key == lst[mid]:
            return mid
        else:
            low = mid + 1

    return - low -1 # 현재 high<low이므로, 키는 발견되지 않음

ㅣ = [1,3,5,7,9,11,13,15,18]
print(ㅣ)
print(binarySearch(ㅣ,7))
print(binarySearch(ㅣ,12))
