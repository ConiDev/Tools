#!/bin/bash
echo "SU RULES:"
grep "auth       required" /etc/pam.d/su
echo "PASSWORD RULES:"
grep "pam_pwquality.so" /etc/pam.d/common-password
