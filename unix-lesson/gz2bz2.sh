#!/bin/sh

dir=($(ls -F))

extgz="tar.gz"
extbz2="tar.bz2"

for dir_val in ${dir[@]}; do
    if [ ${dir_val#*.} = ${extgz} ]; then #拡張子判定
	tar -zxf $dir_val                 #一旦解凍
	bz2_val=${dir_val%%.*}.$extbz2    #bz2_valに拡張子を変えた文字列を代入
	tar -jcf $bz2_val ${dir_val%%.*}  #bz2に圧縮
	
	echo -n ${dir_val} : $(ls -lh | grep $dir_val | awk '{print $5}')
	echo "  "${bz2_val} : $(ls -lh | grep $bz2_val | awk '{print $5}')
    fi
done
