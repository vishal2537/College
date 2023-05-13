with open("decodingInput.txt", "r") as f:
    for i in f.readline().split():
        if int(i) < 0:
            print(' . ', end="")
        else:
            print(' Q ', end="")
        if int(i) % 8 == 0:
            print()
