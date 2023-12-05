#!/bin/bash
mkdir portf
sudo aws s3 sync s3://peakyblinders1/portfolio/ portf/
cd portf

sudo yum install -y npm
sudo npm install
sudo node app.js

