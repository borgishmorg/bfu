#!/bin/bash

DIRECTORY=$(pwd)
HOME=~

if [ $# == "0" ]
then
        echo 'This isGnuplot installer'
        echo 'Usage : ./gnuplotinstaller GNUPLOT_VERSION(5.2.5 recommended) LIBGD_VERSION(2.2.5 recommended)'
        exit 0
fi

GNUPLOT_VERSION=$1
LIBGD_VERSION=$2

LIBGD_URL="https://github.com/libgd/libgd/releases/download/gd-$LIBGD_VERSION/libgd-$LIBGD_VERSION.tar.gz"
LIBGD_NAME="libgd-$LIBGD_VERSION"
GNUPLOT_URL="https://sourceforge.net/projects/gnuplot/files/gnuplot/$GNUPLOT_VERSION/gnuplot-$GNUPLOT_VERSION.tar.gz/download"
GNUPLOT_NAME="gnuplot-$GNUPLOT_VERSION"

LIBGD_DIR=$LIBGD_NAME-dir
GNUPLOT_DIR=$GNUPLOT_NAME-dir

if [ ! -e $LIBGD_NAME.tar.gz ]
then
	wget -O $LIBGD_NAME.tar.gz $LIBGD_URL
fi

if [ ! -e $GNUPLOT_NAME.tar.gz ]
then
	wget --no-check-certificate -O $GNUPLOT_NAME.tar.gz $GNUPLOT_URL
fi

tar -xvf $LIBGD_NAME.tar.gz
tar -xvf $GNUPLOT_NAME.tar.gz

cd $LIBGD_NAME
./configure --prefix=$DIRECTORY/$LIBGD_DIR
make
make install

echo "export LIBRARY_PATH=\$LIBRARY_PATH:$DIRECTORY/$LIBGD_DIR/lib" >> $HOME/.bash_profile
export LIBRARY_PATH=$LIBRARY_PATH:$DIRECTORY/$LIBGD_DIR/lib
echo "export INCLUDE=\$INCLUDE:$DIRECTORY/$LIBGD_DIR/include" >> $HOME/.bash_profile
export INCLUDE=$INCLUDE:$DIRECTORY/$LIBGD_DIR/include
echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:$DIRECTORY/$LIBGD_DIR/lib" >> $HOME/.bash_profile
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DIRECTORY/$LIBGD_DIR/lib

cd ../$GNUPLOT_NAME
./configure --prefix=$DIRECTORY/$GNUPLOT_DIR --with-texdir=$DIRECTORY/$GNUPLOT_DIR CPPFLAGS=-I$DIRECTORY/$LIBGD_DIR/include
make
make install


mkdir $HOME/bin
cd $HOME/bin
for file in $(ls $DIRECTORY/$GNUPLOT_DIR/bin)
do
        if [ ! -h $DIRECTORY/$GNUPLOT_DIR/bin/$file ]
        then
                ln -s $DIRECTORY/$GNUPLOT_DIR/bin/$file
        fi
done

echo "Write this or reconnect: export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:$DIRECTORY/$LIBGD_DIR/lib"
