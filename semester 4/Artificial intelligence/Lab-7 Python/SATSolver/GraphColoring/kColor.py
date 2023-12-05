import sys
import re

with open("output.txt", "w") as f:

    for line in open(sys.argv[1]):
        # f.write line

        if line[0] == 'p':
            data = line.split()
            # f.write(data)
            colors = int(data[1])
            vertices = int(data[2])
            edges = int(data[3])
            f.write("p cnf " + str(colors*vertices) + " " + str(vertices +
                    vertices * colors*(colors - 1)/2 + colors*edges) + "\n")
            X = [[0]*(colors+1) for _ in range(vertices+1)]
            counter = 1
            i = 1
            while (i < vertices+1):
                j = 1
                while (j < colors+1):

                    X[i][j] = counter
                    counter = counter + 1

                    j = j + 1

                i = i + 1

            # print X
            # print "No of Vertices:: " + vertices + ", No of edges:: " + edges
            i = 1
            while (i <= vertices):
                # print i,
                c = 1
                while (c <= colors):
                    # print i,
                    # print c,
                    # print ","
                    f.write(str(X[i][c]) + " ")
                    if (c == colors):
                        f.write("0")

                    c = c + 1

                i = i + 1
                f.write("\n")

            i = 1
            while (i <= vertices):
                c = 1
                while (c <= colors-1):
                    d = c + 1
                    while (d <= colors):
                        f.write("-"+str(X[i][c])+" -"+str(X[i][d])+" 0\n")
                        d = d + 1

                    c = c + 1

                i = i + 1

        if line[0] == 'e':
            data = line.split()
            u = data[1]
            v = data[2]

            c = 1
            while (c <= colors):
                f.write("-"+str(X[int(u)][c]) + " -" +
                        str(X[int(v)][c])+" 0\n")
                c = c + 1
