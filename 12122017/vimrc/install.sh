#!/bin/bash
#This is a very simple example

echo Hello World!

cp ~/.vimrc ~/vimrc.bak

cp ./vimrc ~/.vimrc

mkdir -p ~/.vim/bundle/YouCompleteMe/cpp/ycm/
cp ./.ycm_extra_conf.py ~/.vim/bundle/YouCompleteMe/cpp/ycm/
