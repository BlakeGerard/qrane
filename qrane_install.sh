#!/bin/bash

all_flag='--install-all'
bison_flag="--install-bison"
barvinok_flag="--install-barvinok"
ntl_flag="--install-ntl"
clean_flag="--clean-all"
help_flag="--help"

lib_dir=$PWD/lib

bison_version=bison-3.3
barvinok_version=barvinok-0.41.4
ntl_version=ntl-11.4.3

bison_install=$lib_dir/bison-install
barvinok_install=$lib_dir/barvinok-install
ntl_install=$lib_dir/ntl-install

install_all() {
	install_bison
	install_ntl
	install_barvinok
}

install_barvinok() {
	echo "Installing barvinok"
	zip=$lib_dir/$barvinok_version.tar.gz
	tar -xvzf $zip -C $lib_dir
	cd $lib_dir/$barvinok_version/
	./configure --prefix=$barvinok_install \
		    --with-ntl-prefix=$ntl_install \
		    --enable-shared-barvinok \
	            && make && make install
	cd -
	rm -rf $lib_dir/$barvinok_version/
}

install_bison() {
	echo "Installing bison"
	zip=$lib_dir/$bison_version.tar.gz
	tar -xvzf $zip -C $lib_dir
	cd $lib_dir/$bison_version/
	./configure --prefix=$bison_install && make && make install
	cd -
	rm -rf $lib_dir/$bison_version/
}

install_ntl() {
	echo "Installing ntl"
	zip=$lib_dir/$ntl_version.tar.gz
	tar -xvzf $zip -C $lib_dir
	cd $lib_dir/$ntl_version/src/
	./configure SHARED=on \
		    DEF_PREFIX=$ntl_install \
		    NTL_GMP_LIP=on \
		    NTL_THREADS=on \
		    NTL_THREAD_BOOST=on \
		    NTL_STD_CXX11=on \
	            && make && make install
	cd -
	rm -rf $lib_dir/$ntl_version
}

clean_all() {
    set -x
	if [ -d $bison_install ]; then
  		rm -rf $bison_install
	fi
	if [ -d $barvinok_install ]; then
		rm -rf $barvinok_install
	fi
	if [ -d $ntl_install ]; then
		rm -rf $ntl_install
	fi
}	

if [ ! -d lib ]; then
  mkdir lib
fi

if [ ! -d build ]; then
  mkdir build
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
