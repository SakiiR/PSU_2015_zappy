#!/bin/bash

echo -e "\e[1m"
echo -e "\e[32m"
git pull origin master 
echo -e "\e[33m"
git pull github master
echo -e "\e[34m"
git push origin master
echo -e "\e[35m"
git push github master
echo -e "\e[39m"
echo "[+] Ending master pushing !"
