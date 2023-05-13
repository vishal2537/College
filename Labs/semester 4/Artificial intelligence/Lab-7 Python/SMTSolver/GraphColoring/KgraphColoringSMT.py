from z3 import *

# Create a solver instance
solver = Solver()

# Graph
VERTICES = 5
EDGES = [(0, 1), (1, 2), (2, 3), (3, 4), (4, 0), (0, 2)]
COLORS = 3

vertices={}
for vertice in range(VERTICES):
    value=Int(f"{vertice}")
    solver.add(And(value >= 1, value <= COLORS))
    vertices[vertice]=value

for edge in EDGES:
    solver.add(Distinct([vertices[edge[0]], vertices[edge[1]]]))
    

if solver.check() == sat:
    model = solver.model()
    for vertice in vertices:
        print(f"Vertice {vertice} has color {model[vertices[vertice]]}")
else:
    print("No solution found.")

