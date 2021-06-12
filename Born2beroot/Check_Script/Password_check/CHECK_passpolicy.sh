#!/bin/bash
cat /etc/login.defs | grep -e "PASS_MAX_DAYS" -A 2

#chage -l $1
