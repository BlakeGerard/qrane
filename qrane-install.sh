#!/bin/bash

all_flag='--install-all'
bison_flag="--install-bison"
barvinok_flag="--install-barvinok"
ntl_flag="--install-ntl"
clean_flag="--clean-all"
help_flag="--help"

bison_version=bison-3.3
barvinok_version=barvinok-0.41.4
ntl_version=ntl-11.4.3

install_all() {
	install_bison
	install_ntl
	install_barvinok
}

install_bison() {
	echo "Installing bison"
	zip=$bison_version.tar.gz
	install_dir=$PWD/lib/bison
	tar -xvzf $zip
	cd ./$bison_version/
	./configure --prefix=$install_dir && make && make install
	cd -
}

install_barvinok() {
	echo "Installing barvinok"
	zip=$barvinok_version.tar.gz
	install_dir=$PWD/lib/barvinok
	ntl_dir=$PWD/lib/ntl
	ntl_build=./$ntl_version/src/
	tar -xvzf $zip
	cd ./$barvinok_version/
	./configure --prefix=$install_dir --with-ntl-prefix=$ntl_dir --enable-shared-barvinok && make && make install
	cd -
}

install_ntl() {
	echo "Installing ntl"
	zip=$ntl_version.tar.gz
	install_dir=$PWD/lib/ntl
	tar -xvzf $zip
	cd ./$ntl_version/src/
	./configure SHARED=on DEF_PREFIX=$install_dir NTL_GMP_LIP=on NTL_THREADS=on NTL_THREAD_BOOST=on NTL_STD_CXX11=on && make && make install
	cd -
}

clean_all() {
	if [ -d $bison_version ]; then
  		rm -rf ./$bison_version/
	fi
	if [ -d $barvinok_version ]; then
		rm -rf ./$barvinok_version/
	fi
	if [ -d $ntl_version ]; then
		rm -rf ./$ntl_version/
	fi
	rm -rf lib
}	

if [ ! -d lib ]; then
  mkdir lib
fi

for arg in "$@"
do 
	if [[ "$arg" == "$clean_flag" ]]; then
		clean_all
	elif [[ "$arg" == "$all_flag" ]]; then
		install_all
	elif [[ "$arg" == "$bison_flag" ]]; then
		install_bison
	elif [[ "$arg" == "$ntl_flag" ]]; then
		install_ntl
	elif [[ "$arg" == "$barvinok_flag" ]]; then
		install_barvinok
	elif [[ "$arg" == "$help_flag" ]]; then
		echo "$all_flag to install bison, barvinok, and ntl"
		echo "$bison_flag to install bison"
		echo "$barvinok_flag to install barvinok"
		echo "$ntl_flag to install ntl" 
		echo "$clean_flag to delete all locally installed libraries and their install directories"
	else 
		echo "Unknown argument. Pass --help for more info."
	fi
done
