import heapq
import random
import numpy as np
import matplotlib.pyplot as plt

MAX_ITER = 1000

def arr_init():
    arr = []
    n = int(input("Enter no. of elements: "))
    print("Input the array elements")
    for i in range(n):
        x = int(input())
        arr.append(x)
    return arr

def getNeighbours(subset, arr):
    neighbours = [[]]
    arr_copy = arr.copy()
    for i in subset:
        subset_copy = subset.copy()
        subset_copy.remove(i)
        neighbours.append(subset_copy)
        arr_copy.remove(i)
    for i in arr_copy:
        subset_copy = subset.copy()
        subset_copy.append(i)
        neighbours.append(subset_copy)
    return neighbours

def f(state, goal):
    # abs(goal - subset sum) h(n) 
    return abs(goal - sum(state))

def g(state):
    # actual path cost
    return 0    

def goal_test(state, goal):
    return goal == sum(state)

def print_sol(state, goal):
    if goal_test(state, goal): print('\nSolved !')
    print('\nFinal State:')
    print(state)
    return

def plot(i, evaluation, state, optimum):
    """
    Plots the resulting evaluation on each iteration.
    :param i: Total number of iterations
    :param evaluation: List of evaluation score
    :param state: The final state of queens
    :param optimum: The highest possible score
    :return:
    """
    # For results which break the loop in the algorithm
    if i == MAX_ITER:
        evaluation.append(g(state))

    plt.plot(range(i ), evaluation, 'teal')
    plt.plot(i, optimum, 'ro')

    plt.xlabel("Iterations")
    plt.ylabel("Evaluation Score")
    plt.show()

def random_sol(arr):
    solution = []
    for _ in arr:
        if random.randint(0,1)==1: solution.append(_)
    return solution

# -------------------------------------------------------------------------------------
# genetic algorithm

def fitness(state, arr, goal):
    subset_sum = 0
    for i in range(len(arr)):
        if state[i]==1: subset_sum += arr[i]
    return abs(goal - subset_sum)

def init_population(arr, n, goal):
    # bitmask
    population = []
    for i in range(n):
        state = []
        for i in range(len(arr)):
            state.append(random.randint(0, 1))
        population.append(fitness(state), state)

def select(population, goal):
    # roullette wheel slection
    new_population  = []
    prop = []
    total_fitness =0
    for i, state in population:
        total_fitness += i
    for i in range(len(population)):
        prop[i] = population[i][0] * len(population) / total_fitness
    for i in prop:
        for j in range(prop[i]):
            new_population.append([population[i][0], population[i][1]])
    heapq.heapify(new_population)
    return [heapq.heappop(new_population) for _ in range(len(population))]

def crossover(population, arr, goal):
    for i in range(1,len(population)):
        c_point = random.randint(1,len(arr))
        child1 = [population[i-1][1][:c_point]] + [population[i][1][c_point:]]
        child2 = [population[i-1][1][c_point:]] + [population[i][1][:c_point]]
        population[i-1] = child1
        population[i] = child2
        i+=1 

# def mutate(population):
    

# -------------------------------------------------------------------------------------------------------

def hill_climbing(arr, goal):
    optimum = i = 0
    cur_v = random_sol(arr)
    evaluation = []
    while(i<MAX_ITER):
        i += 1
        flag=0
        print(f"Iteration {i}: Evaluation = {f(cur_v, goal)} state = {cur_v}")
        evaluation.append(f(cur_v, goal))
        next_v = getNeighbours(cur_v, arr)
        for v in next_v:
            if f(cur_v, goal) > f(v, goal):
                cur_v = v
                flag=1
        if flag == 0: break
    print_sol(cur_v, goal)
    plot(i, evaluation, cur_v, optimum)
    return

def beam_search(arr, goal):
    k = int(input("enter value of beta: "))
    optimum = i = 0
    pq =[]
    cur_v = random_sol(arr)
    pq.append([f(cur_v, goal), cur_v])
    heapq.heapify(pq)
    evaluation = []
    while(i<MAX_ITER):
        cur_pq = []
        while(len(pq)>0 and i<MAX_ITER):
            val, cur_v = heapq.heappop(pq)
            i += 1
            print(f"Iteration {i}: Evaluation = {f(cur_v, goal)} state = {cur_v}")
            if goal_test(cur_v, goal): 
                print_sol(cur_v, goal)
                return
            evaluation.append(f(cur_v, goal))
            next_v = getNeighbours(cur_v, arr)
            for v in next_v:
                cur_pq.append([f(v, goal), list(v)])
            heapq.heapify(cur_pq)
        for it in range(k):
            heapq.heappush(pq, heapq.heappop(cur_pq))
    print_sol(cur_v, goal)
    plot(i, evaluation, cur_v, optimum)
    return

# def GA(arr, goal):



def main():
    x=0
    arr = arr_init()
    goal = int(input('enter subset sum: '))
    while(x!=4):
        x = int(input('1. Hill Climbing\n2. Beam Search\n3. Genetic Algorithm\n4. Exit\n'))
        if x==1: hill_climbing(arr, goal)
        elif(x==2): beam_search(arr, goal)
        elif x==3: GA(arr, goal)
        elif x==4: return

if __name__ == "__main__":
    main()