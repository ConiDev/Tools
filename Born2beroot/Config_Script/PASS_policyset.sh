#!/bin/bash
sed -i -e "s/PASS_MAX_DAYS	99999/PASS_MAX_DAYS	30/g" /etc/login.defs
sed -i -e "s/PASS_MIN_DAYS	0/PASS_MIN_DAYS	2/g" /etc/login.defs
sed -i -e "s/PASS_WARN_AGE	7/PASS_WARN_AGE	7/g" /etc/login.defs
