import gurobipy as gp

# Create a new optimization model
model = gp.Model()

# Define the decision variables
x1 = model.addVar(vtype=gp.GRB.BINARY, name="x1")
x2 = model.addVar(vtype=gp.GRB.BINARY, name="x2")
x3 = model.addVar(vtype=gp.GRB.BINARY, name="x3")
x4 = model.addVar(vtype=gp.GRB.BINARY, name="x4")
x5 = model.addVar(vtype=gp.GRB.BINARY, name="x5")
x6 = model.addVar(vtype=gp.GRB.BINARY, name="x6")


variables = {}
variables[1] = x1
variables[2] = x2
variables[3] = x3
variables[4] = x4
variables[5] = x5
variables[6] = x6

listOfClauses = [[-1, -2, 3], [2, -3, -4], [-2, 3, -4], [3, -4, 5], [1, 5, -6]]

# Define the constraints
# Define the constraints
for clause in listOfClauses:
    clause_vars = []
    for value in clause:
        if value > 0:
            clause_vars.append(variables[value])
        else:
            clause_vars.append(1 - variables[abs(value)])
    model.addConstr(gp.quicksum(clause_vars) == 1)

# Optimize the modelclear
model.optimize()

# Print the optimal solution
for v in model.getVars():
    print(f"{v.varName}: {v.x}",end=" ")
    if(v.x==0):
        print("False")
    else:
        print("True")
