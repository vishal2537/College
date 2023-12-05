#!/bin/bash
sudo yum update -y
sudo yum install sudo docker -y
sudo service sudo docker start
sudo systemctl enable 
sudo systemctl start docker

sudo curl -fsSL https://rpm.nodesource.com/setup_16.x | bash -
sudo yum update -y
sudo yum install -y nodejs
sudo npm install -g npm@latest

mkdir portfolio
aws s3 sync s3://peakyblinders2/portfolio portfolio
cd portfolio/microservices/

# mkdir /feedback
# aws s3 sync s3://peakyblinders2/portfolio/microservices/feedback/ /feedback
cd feedback/
# echo 'const endpoint = "{}";module.exports=endpoint;' >> endpoint.js
sudo docker build -t feedback .
sudo docker run -d -p 5001:5001 -t feedback

cd ..
# mkdir /ratings
# aws s3 sync s3://peakyblinders2/portfolio/microservices/ratings/ /ratings
cd ratings/
# echo 'const endpoint = "{}";module.exports=endpoint;' >> endpoint.js
sudo docker build -t ratings .
sudo docker run -d -p 5002:5002 -t ratings

cd ..
# mkdir /recommendation
# aws s3 sync s3://peakyblinders2/portfolio/microservices/recommendation/ /recommendation
cd recommendation/
# echo 'const endpoint = "{}";module.exports=endpoint;' >> endpoint.js
sudo docker build -t recommendation .
sudo docker run -d -p 5003:5003 -t recommendation        


# mkdir /app
# aws s3 sync s3://peakyblinders2/portfolio/app /app
cd ../../app/
sudo yum install -y npm
sudo npm install
sudo node app.js

