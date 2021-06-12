#!/bin/bash
sed -i -e "s/#Port 22/Port 4242/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitRootLogin without-password/PermitRootLogin no/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitRootLogin yes/PermitRootLogin no/g" /etc/ssh/sshd_config
/etc/init.d/ssh restart
