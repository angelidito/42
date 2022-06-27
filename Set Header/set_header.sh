#!/bin/bash
# ./set_header.sh

# Set variables

if [ ! -z "$USER" ]
then
    echo "USER=`/usr/bin/angmarti`" >> ~/.zshrc
    echo "export USER" >> ~/.zshrc
fi

if [ ! -z "$GROUP" ]
then
    echo "GROUP=`/usr/bin/id -gn $user`" >> ~/.zshrc
    echo "export GROUP" >> ~/.zshrc
fi

if [ ! -z "$MAIL" ]
then
    echo "MAIL="$angmarti@student.42madrid.com"" >> ~/.zshrc
    echo "export MAIL" >> ~/.zshrc
fi

mkdir -p ~/.vim/plugin

# Add stdheader to vim plugins
cp stdheader.vim ~/.vim/plugin/

source ~/.zshrc
