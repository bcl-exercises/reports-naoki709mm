#!/bin/sh

extgz="tar.gz"
extbz2="tar.bz2"

if [ ${1#*.} = ${extgz} ]; then
    echo ${1%%.*}.$extbz2 #.の２つ目からそれ以下を変換
fi