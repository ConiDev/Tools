#!/bin/bash

ARCHY=$(uname -a)
PPROC=$(grep "physical id" /proc/cpuinfo | wc -l)
VCPU=$(grep "processor" /proc/cpuinfo | wc -l)
#MEMU=$(free -m | grep "Mem" | awk '{print $3 "/" $2 "MB" " ("$3*100/$2"%)"}')
MEMU=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }')
DISKU=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)\n", $3,$2,$5}')
CPUU=$(top -bn1 | grep "load" | awk '{printf "%.1f%%\n", $(NF-2)}')
LBOOT=$(who -a | grep "syst" | awk '{print $3" "$4}')
LVM=$(Script/LVM_inuse.sh)
TCP=$(ss | grep "tcp" | wc -l)
USER=$(who | wc -l)
IP=$(ifconfig | grep "inet " | head -1 | awk '{print $2}')
MAC=$(Script/MAC.sh)
SUDO=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

MONITOR=$(echo "#Architecture: $ARCHY" > monitor.txt;\
      	echo "#CPU physical : $PPROC" >> monitor.txt;\
	echo "#vCPU : $VCPU" >> monitor.txt; \
	echo "#Memory Usage: $MEMU" >> monitor.txt; \
	echo "#Disk Usage: $DISKU" >> monitor.txt; \
	echo "#CPU load: $CPUU" >> monitor.txt; \
	echo "#Last boot: $LBOOT" >> monitor.txt; \
	echo "#LVM use: $LVM" >> monitor.txt; \
	echo "#Connexions TCP : $TCP ESTABLISHED" >> monitor.txt; \
	echo "#User log: $USER" >> monitor.txt; \
	echo "#Network: IP $IP ($MAC)" >> monitor.txt; \
	echo "#Sudo : $SUDO cmd" >> monitor.txt; \
	)

wall monitor.txt
