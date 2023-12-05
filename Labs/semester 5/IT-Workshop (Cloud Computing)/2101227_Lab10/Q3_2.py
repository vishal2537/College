from pyspark.sql import SparkSession
from pyspark.sql.functions import col
spark = SparkSession.builder.appName("CountryAnalysis").getOrCreate()

from ucimlrepo import fetch_ucirepo
adult = fetch_ucirepo(id=2)
data = adult.data.features
df = spark.createDataFrame(data)

atleast_masters = df.filter((df["education"] == "Masters") | (df["education"] == "Doctorate"))
tech_support = atleast_masters.filter(atleast_masters["occupation"] == "Tech-support")
count = tech_support.count()

print("------------------------------------------------------------------------------------------------")
print("\nNumber of people with at least a Masters or Doctorate degree working in Tech-support:", count, "\n")
print("------------------------------------------------------------------------------------------------")

spark.stop()