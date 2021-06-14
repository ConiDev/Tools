#!/bin/bash

CHECK=$(lsblk | grep "lvm" | wc -l)

if [[ $CHECK == 0 ]] ;then
	echo "no";
elif [[ $CHECK > 0 ]] ;then
	echo "yes";
fi
