#!/bin/bash

ARCHY=$(uname -a)
PPROC=$(grep "physical id" /proc/cpuinfo | wc -l)
VCPU=$(grep "processor" /proc/cpuinfo | wc -l)
#MEMU=$(free -m | grep "Mem" | awk '{print $3 "/" $2 "MB" " ("$3*100/$2"%)"}')
MEMU=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }')
DISKU=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)\n", $3,$2,$5}')
CPUU=$(top -bn1 | grep "load" | awk '{printf "%.1f%%\n", $(NF-2)}')
LBOOT=$(who -a | grep "syst" | awk '{print $3" "$4}')
LVM=$(SysAdmin/Check_Script/LVM_check/LVM_inuse.sh)
TCP=$(ss | grep "tcp" | wc -l)
USER=$(who | wc -l)
IP=$(ifconfig | grep "inet " | head -1 | awk '{print $2}')
MAC=$(Script/MAC.sh)
SUDO=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

MONITOR=$(echo "#Architecture: $ARCHY" > /root/Tools/monitor.txt;\
      	echo "#CPU physical : $PPROC" >> /root/Tools/monitor.txt;\
	echo "#vCPU : $VCPU" >> /root/Tools/monitor.txt; \
	echo "#Memory Usage: $MEMU" >> /root/Tools/monitor.txt; \
	echo "#Disk Usage: $DISKU" >> /root/Tools/monitor.txt; \
	echo "#CPU load: $CPUU" >> /root/Tools/monitor.txt; \
	echo "#Last boot: $LBOOT" >> /root/Tools/monitor.txt; \
	echo "#LVM use: $LVM" >> /root/Tools/monitor.txt; \
	echo "#Connexions TCP : $TCP ESTABLISHED" >> /root/Tools/monitor.txt; \
	echo "#User log: $USER" >> /root/Tools/monitor.txt; \
	echo "#Network: IP $IP ($MAC)" >> /root/Tools/monitor.txt; \
	echo "#Sudo : $SUDO cmd" >> /root/Tools/monitor.txt; \
	)

wall monitor.txt
