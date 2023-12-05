from z3 import *

# Create n*n sudoku board
N = 9
D = 3

# Create a solver instance
solver = Solver()

# Create 2D array of integer variables representing the sudoku board

inputBoard = [[0, 0, 3, 0, 2, 0, 6, 0, 0],
              [9, 0, 0, 3, 0, 5, 0, 0, 1],
              [0, 0, 1, 8, 0, 6, 4, 0, 0],
              [0, 0, 8, 1, 0, 2, 9, 0, 0],
              [7, 0, 0, 0, 0, 0, 0, 0, 8],
              [0, 0, 6, 7, 0, 8, 2, 0, 0],
              [0, 0, 2, 6, 0, 9, 5, 0, 0],
              [8, 0, 0, 2, 0, 3, 0, 0, 9],
              [0, 0, 5, 0, 1, 0, 3, 0, 0]]

board = []

for i in range(N):
    col = []
    for j in range(N):
        value = Int(f"{i} {j}")
        if inputBoard[i][j] != 0:
            solver.add(value == inputBoard[i][j])
        else:
            solver.add(And(value >= 1, value <= N))
        col.append(value)
    board.append(col)


# Add constraints for rows, columns, and sub-grids
for i in range(N):
    solver.add(Distinct([board[i][j] for j in range(N)]))

for j in range(N):
    solver.add(Distinct([board[i][j] for i in range(N)]))

for x in range(0, N, D):
    for y in range(0, N, D):
        subgrid = [board[i][j] for i in range(x, x+D) for j in range(y, y+D)]
        solver.add(Distinct(subgrid))

# Find a solution
if solver.check() == sat:
    model = solver.model()
    for i in range(N):
        if(i%3==0):
            print("\t\t+-------+-------+-------+")
        print("\t\t",end="")            
        for j in range(N):
            if(j%3==0):
                print("|",end=" ")
            print(model[board[i][j]], end=" ")
        print("|")
    print("\t\t+-------+-------+-------+")
else:
    print("No solution found.")
