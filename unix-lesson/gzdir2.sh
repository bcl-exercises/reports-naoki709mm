#!/bin/sh

dir=($(ls -F | grep /)) #/がつく奴だけ配列dirに代入

for dir_value in ${dir[@]}; do
    tar -zcvf ${dir_value%/}.tar.gz $dir_value #/があれば削除して渡す
done