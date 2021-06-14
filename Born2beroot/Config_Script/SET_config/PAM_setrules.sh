#!/bin/bash
sed -i -e "s/# auth       required   pam_wheel.so deny group=nosu/auth       required   pam_wheel.so group=sudo/g" /etc/pam.d/su

sed -i -e "s/pam_pwquality.so retry=3/pam_pwquality.so retry=3 minlen=10 difok=7 dcredit=-1 ucredit=-1 usercheck=1 gecocheck=1 enforce_for_root remember=1/g" /etc/pam.d/common-password
