#!/bin/bash
printf "### SU RULES ###\n"
grep "auth       required" /etc/pam.d/su
printf "\n\n### PASSWORD RULES ###\n"
grep "pam_pwquality.so" /etc/pam.d/common-password
