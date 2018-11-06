#!/bin/sh

dir=($(ls -F | grep /)) #/がつく奴だけ配列dirに代入

for dir_value in ${dir[@]}; do
    tar -jcvf ${dir_value%/}.tar.bz2 $dir_value #/があれば削除して渡す
done