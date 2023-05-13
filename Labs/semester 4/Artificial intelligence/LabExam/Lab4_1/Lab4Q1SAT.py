clauses = []

# first Clause
clause = []
clause.append(-1)
clause.append(-2)
clause.append(3)
clauses.append(clause)


# second Clause
clause = []
clause.append(2)
clause.append(-3)
clause.append(-4)
clauses.append(clause)


# third Clause
clause = []
clause.append(-2)
clause.append(3)
clause.append(-4)
clauses.append(clause)


# fourth Clause
clause = []
clause.append(3)
clause.append(-4)
clause.append(5)
clauses.append(clause)


# fifth Clause
clause = []
clause.append(1)
clause.append(5)
clause.append(-6)
clauses.append(clause)

with open("output.txt", "w") as f:
    f.write("p cnf {} {}\n".format(6, len(clauses)))
    for clause in clauses:
        f.write(" ".join(str(x) for x in clause) + " 0\n")
