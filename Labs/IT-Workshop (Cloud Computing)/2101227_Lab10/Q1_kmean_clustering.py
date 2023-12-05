import pandas as pd
from sklearn.cluster import KMeans

filename = 'adult.data'
data = pd.read_csv(filename, header=None)

X = data[[0, 2, 11]].copy()
kmeans = KMeans(n_clusters=3 ,max_iter=500, random_state=10).fit(X)

print("Cluster Centers :", kmeans.cluster_centers_)
print("Sum Squared Error :",kmeans.inertia_)

# 0 --> age
# 2 --> work class
# 11 --> capital-loss