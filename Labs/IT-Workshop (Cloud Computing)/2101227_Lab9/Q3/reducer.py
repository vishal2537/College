#!/usr/bin/env python3
import sys
import numpy
from pprint import pprint

all_species = ["iris_sertosa", "iris_versicolor", "iris_virginica"]

counts = {
    "iris_sertosa": 0,
    "iris_versicolor": 0,
    "iris_virginica": 0,
}

sums = {
    "iris_sertosa": numpy.array([0.0] * 4),
    "iris_versicolor": numpy.array([0.0] * 4),
    "iris_virginica": numpy.array([0.0] * 4),
}

for line in sys.stdin:
    species, point = line.strip().split("\t")
    point = numpy.array(list(map(float, point.strip().split(","))))

    counts[species] += 1
    sums[species] += point

candidate_points = {
    "iris_sertosa": numpy.array([5.8, 8.0, 1.2, 0.2]),
    "iris_versicolor": numpy.array([6.1, 2.8, 4.0, 1.3]),
    "iris_virginica": numpy.array([6.3, 2.7, 4.9, 1.8]),
}

for species in all_species:
    if counts[species] != 0:
        candidate_points[species] = sums[species] / counts[species]


pprint(candidate_points)
