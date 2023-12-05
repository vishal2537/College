#!/bin/bash
yum update -y
yum install docker -y
systemctl start docker

mkdir feedback
aws s3 sync s3://peakyblinders2/portfolio/microservices/feedback feedback
cd feedback/

docker build -t feedback .
docker run -d -p 80:5001 -t feedback