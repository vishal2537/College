import sys
import numpy as np
from math import sqrt
from pyspark import SparkContext
from pyspark.mllib.clustering import KMeans

def cost(point):
    center = clusters.centers[clusters.predict(point)]
    return sqrt(sum([x**2 for x in (point - center)]))

if __name__ == "__main__":
    spark = SparkContext(appName="KMeansExample")
    data = spark.textFile("file:///home/devil/it-workshop/2101227_Lab10/adultdata.txt")
    dataset = data.map(lambda line: np.array([x for x in line.split(', ')])[np.array([0,2,11])].astype(float))
    clusters = KMeans.train(dataset, 3, maxIterations=50, initializationMode="random")
    
    SSE = dataset.map(lambda point: cost(point)).reduce(lambda x, y: x + y)
    print("\nCenters:",clusters.centers,"\nSSE=",SSE,"\n",file=sys.stdout)
    spark.stop()
