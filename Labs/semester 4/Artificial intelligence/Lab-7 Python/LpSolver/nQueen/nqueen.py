import gurobipy as gb

n = 8
m = gb.Model()
x = m.addVars(n, n, vtype=gb.GRB.BINARY, name="x")

# one Queen per row
m.addConstrs((gb.quicksum(x[i, j] for j in range(n))
             == 1 for i in range(n)), name="rowsum")

# one queen per column
m.addConstrs((gb.quicksum(x[i, j] for i in range(n))
             == 1 for j in range(n)), name="colsum")

# no more than one queen per "/" diagonal
m.addConstrs(gb.quicksum(x[i, j] for i in range(n) for j in range(
    n) if i - j == k) <= 1 for k in range(-n + 2, n - 2 + 1))
# no more than one queen per "\" diagonal
m.addConstrs(gb.quicksum(x[i, j] for i in range(n) for j in range(
    n) if i + j == k) <= 1 for k in range(2 * n - 1))

m.optimize()

for i in range(n):
    for j in range(n):
        if x[i, j].X:
            print(' Q ', end='')
        else:
            print(' . ', end='')
    print()
