from pulp import *

# Define the decision variables
tasks = ['A', 'B', 'C', 'D']
agents = [1, 2, 3, 4]
x = LpVariable.dicts('x', [(i, j) for i in tasks for j in agents], cat='Binary')

# Define the objective function
prob = LpProblem('Task Assignment', LpMaximize)

prob += lpSum([10*x[('A', 1)] + 12*x[('A', 2)] + 19*x[('A', 3)] + 11*x[('A', 4)] +
               5*x[('B', 1)] + 10*x[('B', 2)] + 7*x[('B', 3)] + 8*x[('B', 4)] +
               12*x[('C', 1)] + 14*x[('C', 2)] + 13*x[('C', 3)] + 11*x[('C', 4)] +
               8*x[('D', 1)] + 15*x[('D', 2)] + 11*x[('D', 3)] + 9*x[('D', 4)]  ])

# Define the constraints
for i in tasks:
    prob += lpSum([x[(i, j)] for j in agents]) == 1  #ensures that each task is assigned to exactly one agent.
for j in agents:
    prob += lpSum([x[(i, j)] for i in tasks]) <= 1   #each agent is assigned at most one task

# Solve the problem
prob.solve()

# Print the solution status
print(f"Status: {LpStatus[prob.status]}")

# Print the optimal assignment of tasks to agents
for i in tasks:
    for j in agents:
        if x[(i, j)].varValue == 1:
            print(f"Task {i} is assigned to Agent {j} with profit {x[(i, j)].varValue}")