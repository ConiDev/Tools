#!/bin/bash
for user in $(ls /home) ; do
	echo "$user stats validity :"
	chage -l $user
done
echo "root stats validity :"
chage -l root
