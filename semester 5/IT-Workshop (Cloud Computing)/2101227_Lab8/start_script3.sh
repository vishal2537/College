#!/bin/bash
yum update -y
yum install docker -y
service docker start
systemctl start docker

mkdir recommendation
aws s3 sync s3://peakyblinders2/portfolio/microservices/recommendation recommendation
cd recommendation/

docker build -t recommendation .
docker run -d -p 80:5003 -t recommendation