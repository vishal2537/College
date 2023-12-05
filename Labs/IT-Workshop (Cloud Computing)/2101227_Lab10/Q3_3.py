from pyspark.sql import SparkSession
from pyspark.sql.functions import col
spark = SparkSession.builder.appName("CountryAnalysis").getOrCreate()

from ucimlrepo import fetch_ucirepo
adult = fetch_ucirepo(id=2)
data = adult.data.features
df = spark.createDataFrame(data)

unmarried = df.filter((df["marital-status"] == "Divorced") | (df["marital-status"] == "Never-married"))
males = unmarried.filter(unmarried["sex"] == "Male")
local_govt = males.filter(males["workclass"] == "Local-gov")
count = local_govt.count()

print("------------------------------------------------------------------------------------------------")
print("\nNumber of unmarried males working in Local-govt:", count,"\n")
print("------------------------------------------------------------------------------------------------")

spark.stop()