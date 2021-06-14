#!/bin/bash
for user in $(ls /home) ; do
	printf "\n### $user ###\n"
	chage -l $user
	printf "\n"
done
echo "### root ###"
chage -l root
