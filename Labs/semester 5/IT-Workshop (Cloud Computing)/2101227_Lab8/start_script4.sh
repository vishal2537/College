#!/bin/bash
mkdir /app
aws s3 sync s3://peakyblinders2/portfolio/app /app
cd /app/

yum install -y nodejs npm
npm install
node app.js
