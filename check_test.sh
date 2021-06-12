#!/bin/bash
head -n 2 /etc/os-release
/usr/sbin/aa-status
ss -tnulp
/usr/sbin/ufw status
