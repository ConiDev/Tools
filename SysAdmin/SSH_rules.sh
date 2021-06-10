#!/bin/bash
sed "s/#Port 22/Port 4242/g" /etc/ssh/sshd_config
sed "s/#PermitRootLogin without-password/PermitRootLogin no" /etc/ssh/ssh_config
sed "s/#PermitRootLogin yes/PermitRootLogin no" /etc/ssh/ssh_config
