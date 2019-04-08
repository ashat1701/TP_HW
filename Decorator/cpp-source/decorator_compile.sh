#!/bin/sh
sudo apt install libboost1.67-all-dev
sudo apt install libcurl4-openssl-dev
sudo apt install gnutls-dev
sudo apt install doxygen
sudo apt install libvmime-dev
sudo apt install sendmail
cmake .
make
./Decorator
