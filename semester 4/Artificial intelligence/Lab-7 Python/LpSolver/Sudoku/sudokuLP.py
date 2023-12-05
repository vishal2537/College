import sys
import math
import gurobipy as gp
from gurobipy import GRB


if len(sys.argv) < 2:
    print('Usage: sudoku.py filename')
    sys.exit(0)

f = open(sys.argv[1])

grid = f.read().split()

n = len(grid[0])
s = int(math.sqrt(n))


# Create our 3-D array of model variables

model = gp.Model('sudoku')

vars = model.addVars(n, n, n, vtype=GRB.BINARY, name='G')


# Fix variables associated with cells whose values are pre-specified

for i in range(n):
    for j in range(n):
        if grid[i][j] != '.':
            v = int(grid[i][j]) - 1
            vars[i, j, v].LB = 1

# Each cell must take one value

model.addConstrs((vars.sum(i, j, '*') == 1
                 for i in range(n)
                 for j in range(n)), name='V')

# Each value appears once per row

model.addConstrs((vars.sum(i, '*', v) == 1
                 for i in range(n)
                 for v in range(n)), name='R')

# Each value appears once per column

model.addConstrs((vars.sum('*', j, v) == 1
                 for j in range(n)
                 for v in range(n)), name='C')


# Each value appears once per subgrid

model.addConstrs((
    gp.quicksum(vars[i, j, v] for i in range(i0*s, (i0+1)*s)
                for j in range(j0*s, (j0+1)*s)) == 1
    for v in range(n)
    for i0 in range(s)
    for j0 in range(s)), name='Sub')

model.optimize()

model.write('sudoku.lp')

print('')
print('Solution:')
print('')

# Retrieve optimization result

solution = model.getAttr('X', vars)

for i in range(n):
    sol = ''
    for j in range(n):
        for v in range(n):
            if solution[i, j, v] > 0.5:
                sol += str(v+1)
    print(sol)
