#!/bin/bash

if [[ ! -z $(find . -name "*.o" -print) ]]
then
    echo "[-] ARRETEZ DE PUSH LES .o"
    exit
fi

make fclean
clear
echo -e "\e[1m"
echo -e "\e[39m---------------------------------------------------------------------"
echo -e "\e[32m"
git pull origin master 
echo -e "\e[33m"
git pull github master
echo -e "\e[39m---------------------------------------------------------------------"
echo -e "\e[34m"
git push origin master
echo -e "\e[35m"
git push github master
echo -e "\e[39m---------------------------------------------------------------------"
echo -e "\e[36m"
echo "__________                           "
echo "\____    /____  ______ ______ ___.__."
echo "  /     /\__  \ \____ \\____ <   |  |"
echo " /     /_ / __ \|  |_> >  |_> >___  |"
echo "/_______ (____  /   __/|   __// ____|"
echo "        \/    \/|__|   |__|   \/     "
echo -e "\e[37m"
echo -e "[\e[32m+\e[39m] Ending \e[2mmaster\e[0m pushing !"
echo -e "\e[39m"
