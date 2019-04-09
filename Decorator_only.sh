#!/bin/sh
mkdir Decorator
cd Decorator
git init
git remote add -f origin https://github.com/akhtyamovpavel/PatternsCollection
git config core.sparseCheckout true
echo "Decorator/" >> .git/info/sparse-checkout
git pull origin master
cd Decorator
cd cpp-source
echo """[chat]
token=787399988:AAFuJ-YnX0rEisDPrIZ-Tb-L1PFmOi1uefU
chat_id=-1001380777906
[email]
from=ak3776413@gmail.com
to=clouduckit@gmail.com
password=Trinity3!""" >> configs/config.ini
sed -i 's/smtp:/smtps:/' notifiers/EmailNotifier.cpp
sed -i 's/com\"/com:465\"/' notifiers/EmailNotifier.cpp
sudo apt install libboost-all-dev
sudo apt install libcurl4-openssl-dev
sudo apt install gnutls-dev
sudo apt install doxygen
sudo apt install libvmime-dev
sudo apt install sendmail
sudo apt install libssl-dev
sudo cp configs/config.ini /configs/config.ini
cmake .
make
./Decorator
