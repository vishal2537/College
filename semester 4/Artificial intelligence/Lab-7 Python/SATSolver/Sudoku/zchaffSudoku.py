# !/usr/bin/python3
import sys
D = 3    # Subgrid dimension
N = 9  # Grid dimension

if __name__ == '__main__':
    # Read the inClauses from the file given as the first argument
    file_name = sys.argv[1]

    inClauses = []
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
              '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

    with open(file_name, "r") as f:
        for line in f.readlines():
            assert len(line.strip()) == N, "'"+line+"'"
            for col in range(0, N):
                assert (line[col] in digits.keys() or line[col] == '.')
            inClauses.append(line.strip())
    assert (len(inClauses) == N)

    # A helper: get the Dimacs CNF variable number for the variable v_{row,col,v}
    # encoding the fact that the cell at (row,col) has the value v
    def var(r, c, v):
        return ((r-1)*N*N+(c-1)*N+(v-1) % 9)+1

    clauses = []
    for row in range(1, N+1):  # row runs over 1,...,N
        for col in range(1, N+1):
            # The cell at (row,col) has at least one value
            clause = []
            for k in range(1, N+1):
                clause.append(var(row, col, k))
            clauses.append(clause)

            # The cell at (row,col) has at most one value
            for v in range(1, N+1):
                for w in range(v+1, N+1):
                    clauses.append([-var(row, col, v), -var(row, col, w)])

    for v in range(1, N+1):
        # Each row has the value v
        for row in range(1, N+1):
            clauses.append([var(row, col, v) for col in range(1, N+1)])
        # Each column has the value v
        for col in range(1, N+1):
            clauses.append([var(row, col, v) for row in range(1, N+1)])
        # Each subgrid has the value v
        for sr in range(0, D):
            for sc in range(0, D):
                clauses.append([var(sr*D+rd, sc*D+cd, v)
                                for rd in range(1, D+1) for cd in range(1, D+1)])

    # The inClauses must be respected
    for row in range(1, N+1):
        for col in range(1, N+1):
            if inClauses[row-1][col-1] in digits.keys():
                clauses.append(
                    [var(row, col, digits[inClauses[row-1][col-1]])])

    # Output the DIMACS CNF representation
    # Print the header line
    print("p cnf %d %d" % (N*N*N, len(clauses)))

    # Print the inClauses
    with open("output.txt", "w") as f:
        f.write("p cnf {} {}\n".format(N*N*N, len(clauses)))
        for col in clauses:
            # print(" ".join([str(l) for l in col])+" 0")
            f.write(" ".join(str(x) for x in col) + " 0\n")
