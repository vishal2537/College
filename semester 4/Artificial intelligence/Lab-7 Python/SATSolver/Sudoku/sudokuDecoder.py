with open("decodingInput.txt", "r") as f:
    count = 0
    countrow = 0
    countcol = 0
    print("\t\t+---------+---------+---------+")
    for i in f.readline().split():
        if count == 81:
            count = 0
            countrow += 1
            print()
            if countrow % 3 == 0:
                print("\t\t+---------+---------+---------+")
        if count == 0:
            print("\t\t", end="")
            print("|", end="")
        count += 1
        if int(i) < 0:
            continue
        else:
            countcol += 1
            print(str(" ") + str(int(i) % 9+1)+str(" "), end="")
            if countcol == 3:
                countcol = 0
                print("|", end="")
print()
print("\t\t+---------+---------+---------+")
