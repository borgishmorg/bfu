#!/bin/bash

if [ $# == "0" ]
then
	echo 'This is python installer'
	echo 'Usage : ./pythoninstaller VERSION'
	exit 0
fi

url1='http://www.python.org/ftp/python/'
url2='/Python-'
url3='.tar.xz'
url="$url1$1$url2$1$url3"
name="Python-$1$url3"
way=$(pwd)

mkdir Python-$1-dir
cd Python-$1-dir

if [ -f $name ]
then
	echo "File already downloaded"
else
	wget $url
fi

#tar -xvf $name

#./Python-$1/configure --prefix=$way/Python-$1-dir

#make 
#make install 



mkdir ~/bin
way=$(pwd)/bin/
cd ~/bin

for file in $(ls $way)
do
	if [ ! -h $way$file ]	
	then
		ln -s $way$file
	fi
done
