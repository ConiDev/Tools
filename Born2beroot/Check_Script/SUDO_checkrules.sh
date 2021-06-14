#!/bin/bash
visudo -c
printf "\n### SHOW DEFAULT FILE ###\n"
cat /etc/sudoers
printf "\n### SHOW FOLDER CUSTOM FILE ###\n"
ls /etc/sudoers.d
