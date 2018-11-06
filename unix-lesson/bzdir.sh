#!/bin/sh

Usage (){ #Usageの関数
    echo "Usage:$ bzdir <dirctory name>"
    exit
}

Error_Message (){ # ファイルがないときのエラー
    echo "Not find this dirctory"
    exit
}

if [ $# -ne 1 ]; then #引数が1出ない時異化を実行
    Usage
fi

if [ ! -d $1 ]; then #ディレクトリがないときエラー
    Error_Message
fi

tar -jcvf ${1%/}.tar.bz2 $1 #/があれば削除して渡す