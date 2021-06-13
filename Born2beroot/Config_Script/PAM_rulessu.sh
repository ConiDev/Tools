#!/bin/bash
#grep "# auth       required   pam_wheel.so" /etc/pam.d/su
sed -i -n 1p "s/# auth       required   pam_wheel.so/auth       required   pam_wheel.so group=sudo/g"\
	/etc/pam.d/su
