import copy, time


def manhattan(state, goal):
    heuristic = 0
    for i in range(len(state)):
        for j in range(len(state)):
            row, col = find(goal, state[i][j])
            if row != -1:
                heuristic += abs(row - i) + abs(col - j)
            else:
                heuristic += 9999
    return heuristic


def misplaced(state, goal):
    heuristic = 0
    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] != goal[i][j] and state[i][j] != 0:
                heuristic += 1
    return heuristic


def find(state, x):
    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] == x:
                return i, j
    return -1, -1


def switch(row1, col1, row2, col2, state):
    temp = state[row1][col1]
    state[row1][col1] = state[row2][col2]
    state[row2][col2] = temp

    return state


def getNeighbour(state):
    ret = []
    row, col = find(state, 0)

    if row > 0:
        oneUp = switch(row, col, row - 1, col, copy.deepcopy(state))
        ret.append(oneUp)

    if row < 2:
        oneDown = switch(row, col, row + 1, col, copy.deepcopy(state))
        ret.append(oneDown)

    if col > 0:
        oneLeft = switch(row, col - 1, row, col, copy.deepcopy(state))
        ret.append(oneLeft)

    if col < 2:
        oneRight = switch(row, col + 1, row, col, copy.deepcopy(state))
        ret.append(oneRight)

    return ret


def isEqual(state1, state2):
    for i in range(len(state1)):
        for j in range(len(state1)):
            if state1[i][j] != state2[i][j]:
                return False
    return True


def aStar(states, goal, cost):
    closed = []

    while states:
        current = states.pop(0)
        neighbours = getNeighbour(current[1])
        cost += 1
        for i in neighbours:
            total = 0

            if isEqual(i, goal):
                closed.append((cost, i))
                return closed
            else:
                total = misplaced(i, goal) + cost

            trav = None
            flag = 0
            for trav in states:
                if isEqual(i, trav[1]):
                    if trav[0] < total:
                        flag = 1
                        break

            if flag == 1:
                continue

            for trav in closed:
                if isEqual(i, trav[1]):
                    if trav[0] < total:
                        flag = 1
                        break

            if flag == 1:
                continue

            states.append((total, i))
            states.sort()
            time.sleep(0.5)
        closed.append((current[0] - misplaced(current[1], goal), current[1]))
        print("cost : ", cost)
        print(states)
        print()

    return closed


goal = [[2, 3, 4, 0], [1, 6, 7, 8], [5, 10, 11, 12], [9, 13, 14, 15]]

initial = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 0]]
closed = []
cost = 0

states = []
states.append((misplaced(initial, goal), initial))
print(aStar(states, goal, cost))