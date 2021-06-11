#!/bin/bash
hostnamectl set-hostname $1
cat /etc/hostname
sed -i -e "s/$2/$1/g" /etc/hosts
cat /etc/hosts
hostnamectl
