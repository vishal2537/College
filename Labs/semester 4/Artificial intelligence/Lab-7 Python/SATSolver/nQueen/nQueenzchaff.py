N = 8  # number of queens

# The variables in the SAT problem are the positions of the queens
# We number the positions row by row, from left to right,
# so the variable for the queen in row i and column j is i*N+j+1
# We use a dictionary to keep track of the variable for each queen
variables = {}

for i in range(N):
    for j in range(N):
        variables[(i, j)] = i*N + j + 1
clauses = []

# Constraint 1: Each column must have exactly one queen
for i in range(N):
    clause = []
    for j in range(N):
        clause.append(variables[(i, j)])
    clauses.append(clause)
    for j in range(N):
        for k in range(j+1, N):
            clause = [-variables[(i, j)], -variables[(i, k)]]
            clauses.append(clause)


# Constraint 2: Each row must have exactly one queen
for j in range(N):
    clause = []
    for i in range(N):
        clause.append(variables[(i, j)])
    clauses.append(clause)
    clause = []
    for i in range(N):
        for k in range(i+1, N):
            clause = [-variables[(i, j)], -variables[(k, j)]]
            clauses.append(clause)


# # Constraint 3: Diagonal conflicts
for i in range(N):
    for j in range(N):
        for k in range(1, N):
            if i+k < N and j+k < N:
                clause = [-variables[(i, j)], -variables[(i+k, j+k)]]
                clauses.append(clause)

# We also check the diagonals that go from top-right to bottom-left
for i in range(N):
    for j in range(N):
        for k in range(1, N):
            if i+k < N and j-k >= 0:
                clause = [-variables[(i, j)], -variables[(i+k, j-k)]]
                clauses.append(clause)

# Write the clauses to a file in DIMACS format
with open("nqueens.txt", "w") as f:
    f.write("p cnf {} {}\n".format(N*N, len(clauses)))
    for clause in clauses:
        f.write(" ".join(str(x) for x in clause) + " 0\n")
