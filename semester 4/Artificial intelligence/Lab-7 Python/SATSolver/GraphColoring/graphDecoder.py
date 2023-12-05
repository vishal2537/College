with open("decodingInput.txt", "r") as f:
    count = 0
    node = 0
    for i in f.readline().split():
        if count % 3 == 0:
            node += 1
            count = 0
        if count == 0:
            print(f"Node {node}: ", end="")
        count += 1
        if int(i) < 0:
            continue

        print(int(i) % 3+1)
