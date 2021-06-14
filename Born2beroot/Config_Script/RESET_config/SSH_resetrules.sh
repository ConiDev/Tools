#!/bin/bash
sed -i -e "s/Port 4242/#Port 22/g" /etc/ssh/sshd_config
sed -i -e "s/PermitRootLogin no/#PermitRootLogin yes/g" /etc/ssh/sshd_config
sed -i -e "s/LoginGraceTime 2m/#LoginGraceTime 2m/g" /etc/ssh/sshd_config
sed -i -e "s/StrictModes yes/#StrictModes yes/g" /etc/ssh/sshd_config
sed -i -e "s/MaxAuthTries 3/#MaxAuthTries 6/g" /etc/ssh/sshd_config
sed -i -e "s/MaxSessions 5/#MaxSessions 10/g" /etc/ssh/sshd_config
sed -i -e "s/PasswordAuthentification yes/#PasswordAuthentification yes/g" /etc/ssh/sshd_config
sed -i -e "s/PermitEmptyPasswords no/#PermitEmptyPasswords no/g" /etc/ssh/sshd_config
sed -i -e "s/ClientAliveInterval 120/#ClientAliveInterval 0/g" /etc/ssh/sshd_config
sed -i -e "s/X11Forwarding no/X11Forwarding yes/g" /etc/ssh/sshd_config
sed -i -e "s/Banner \/root\/Tools\/Born2beroot\/Banner/#Banner none/g" /etc/ssh/sshd_config
sed -i -e "/AllowGroups sudo user42/d" /etc/ssh/sshd_config
sed -i -e "/DenyUsers root/d" /etc/ssh/sshd_config
sed -i -e "/DenyGroups root/d" /etc/ssh/sshd_config
service sshd restart
