from pyspark.sql import SparkSession
from pyspark.sql.functions import col
spark = SparkSession.builder.appName("CountryAnalysis").getOrCreate()

from ucimlrepo import fetch_ucirepo
adult = fetch_ucirepo(id=2)
data = adult.data.features
df = spark.createDataFrame(data)

usa = df.filter(df["native-country"] != "United-States")
adults = usa.filter(df["age"] > 18)
count_country = adults.groupBy("native-country").agg({"age": "count"})
max_count_row = count_country.orderBy(col("count(age)").desc()).first()

print("------------------------------------------------------------------------------------------------")
print("\nCountry with the highest number of adults (excluding USA):", max_count_row["native-country"], "\n")
print("------------------------------------------------------------------------------------------------")

spark.stop()