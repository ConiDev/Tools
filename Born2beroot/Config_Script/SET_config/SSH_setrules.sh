#!/bin/bash
sed -i -e "s/#Port 22/Port 4242/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitRootLogin without-password/PermitRootLogin no/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitRootLogin prohibit-password/PermitRootLogin no/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitRootLogin yes/PermitRootLogin no/g" /etc/ssh/sshd_config
sed -i -e "s/#LoginGraceTime 2m/LoginGraceTime 2m/g" /etc/ssh/sshd_config
sed -i -e "s/#StrictModes yes/StrictModes yes/g" /etc/ssh/sshd_config
sed -i -e "s/#MaxAuthTries 6/MaxAuthTries 3/g" /etc/ssh/sshd_config
sed -i -e "s/#MaxSessions 10/MaxSessions 5/g" /etc/ssh/sshd_config
sed -i -e "s/#PasswordAuthentification yes/PasswordAuthentification yes/g" /etc/ssh/sshd_config
sed -i -e "s/#PermitEmptyPasswords no/PermitEmptyPasswords no/g" /etc/ssh/sshd_config
sed -i -e "s/#ClientAliveInterval 0/ClientAliveInterval 120/g" /etc/ssh/sshd_config
sed -i -e "s/X11Forwarding yes/X11Forwarding no/g" /etc/ssh/sshd_config
sed -i -e "s/#Banner none/Banner \/root\/Tools\/Born2beroot\/Banner/g" /etc/ssh/sshd_config
echo "AllowGroups sudo user42" >> /etc/ssh/sshd_config
echo "DenyUsers root" >> /etc/ssh/sshd_config
echo "DenyGroups root" >> /etc/ssh/sshd_config
cat /etc/ssh/sshd_config
service sshd restart
service sshd status
