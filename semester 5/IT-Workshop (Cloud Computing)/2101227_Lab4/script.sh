#!/bin/bash
sudo yum install httpd -y
sudo service httpd start
# used to synchronize the contents of a local directory with an Amazon S3 bucket.\n
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/