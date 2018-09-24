#!/bin/bash

SHB=/bin/tcsh
SH=./42sh
OUT=tmp
OUTB=tmp2

COMMAND="ls"

check_diff() {
    echo -e "Tested command is " ${COMMAND}
    echo -e "\033[0;31m------------42SH---------\033[00m"
    echo -e ${COMMAND} | ${SH} > ${OUT}
    echo -e "\033[0;31m42sh output: $?"
    echo -e "\033[0;32m------------TCSH---------\033[00m"
    echo -e ${COMMAND} | ${SHB} > ${OUTB}
    echo -e "\033[0;32mtcsh output: $?\033[00m"
    sleep 1s
}

while [ "${COMMAND}" ]
do
    echo -e "\033[1;36mNew Test: \033[00m"
    read COMMAND
    check_diff
    echo -e "----------DIFF-----------"
    diff ${OUT} ${OUTB}
    if (("$?" == 0)) ; then
	echo -e "\033[1;32mNo differences !\033[00m"
    fi
    echo -e "-------------------------"
done
echo -e "\033[00m"
rm ${OUT}
rm ${OUTB}
