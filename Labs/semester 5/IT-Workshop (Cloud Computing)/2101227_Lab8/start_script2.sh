#!/bin/bash
yum update -y
yum install docker -y
service docker start
systemctl start docker

mkdir ratings
aws s3 sync s3://peakyblinders2/portfolio/microservices/ratings ratings
cd ratings/

docker build -t ratings .
docker run -d -p 80:5002 -t ratings
