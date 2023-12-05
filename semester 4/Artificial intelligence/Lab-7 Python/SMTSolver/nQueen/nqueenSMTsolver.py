from z3 import *

# Create n*n chess board
n = 8

# Create a solver instance
solver = Solver()

# Create 2D array of Boolean variables representing the chess board
board = [[Bool(f"{i} {j}") for j in range(n)] for i in range(n)]

# Add constraints that only one queen can be placed in each row
for i in range(n):
    solver.add(Or([board[i][j] for j in range(n)]))
    solver.add(AtMost(*[board[i][j] for j in range(n)], 1))

# Add constraints that only one queen can be placed in each column
for j in range(n):
    solver.add(Or([board[i][j] for i in range(n)]))
    solver.add(AtMost(*[board[i][j] for i in range(n)], 1))

# Add constraints that only one queen can be placed in each diagonal
for i in range(n):
    for j in range(n):
        if (i > 0 and j > 0):
            solver.add(Implies(board[i][j], Not(
                And(board[i-1][j-1], board[i][j]))))
        if (i > 0 and j < n-1):
            solver.add(Implies(board[i][j], Not(
                And(board[i-1][j+1], board[i][j]))))
        if (i < n-1 and j > 0):
            solver.add(Implies(board[i][j], Not(
                And(board[i+1][j-1], board[i][j]))))
        if (i < n-1 and j < n-1):
            solver.add(Implies(board[i][j], Not(
                And(board[i+1][j+1], board[i][j]))))

# Find a solution
if solver.check() == sat:
    model = solver.model()
    for i in range(n):
        for j in range(n):
            if is_true(model[board[i][j]]):
                print(" Q ", end="")
            else:
                print(" . ", end="")
        print()
else:
    print("No solution found.")
