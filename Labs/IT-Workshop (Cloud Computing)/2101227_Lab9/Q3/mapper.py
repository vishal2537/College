#!/usr/bin/env python3

import numpy
import sys

candidate_points = {
    "iris_sertosa": numpy.array([5.8, 8.0, 1.2, 0.2]),
    "iris_versicolor": numpy.array([6.1, 2.8, 4.0, 1.3]),
    "iris_virginica": numpy.array([6.3, 2.7, 4.9, 1.8]),
}

def find_candidate(point: numpy.ndarray):
    distance1 = numpy.dot(point.T, candidate_points["iris_sertosa"])
    distance2 = numpy.dot(point.T, candidate_points["iris_versicolor"])
    distance3 = numpy.dot(point.T, candidate_points["iris_virginica"])

    min_distance = min(distance1, distance2, distance3)
    if distance1 == min_distance:
        return "iris_sertosa"
    elif distance2 == min_distance:
        return "iris_versicolor"
    elif distance3 == min_distance:
        return "iris_virginica"
    else:
        raise Exception()

for line in sys.stdin:
    line = line.strip().lower()
    numbers = list(map(float, line.split(",")[:-1]))
    point = numpy.array(numbers)

    print(find_candidate(point), end="\t")
    print(*list(point), sep=",")
