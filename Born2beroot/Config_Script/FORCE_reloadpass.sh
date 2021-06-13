#!/bin/bash
passwd -e $1
chage -l $1
