#!/bin/bash

ARCHY=$(uname -a)
PPROC=$(grep "physical id" /proc/cpuinfo | wc -l)
VCPU=$(grep "processor" /proc/cpuinfo | wc -l)
MEMU=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2}')
DISKU=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)\n", $3,$2,$5}')
CPUU=$(mpstat | grep "all" | awk '{print (100 - $NF)}')
LBOOT=$(who -a | grep "syst" | awk '{print $3" "$4}')
LVM=$(/root/Tools/Born2beroot/Check_Script/LVM_check/LVM_inuse.sh)
TCP=$(ss | grep "tcp" | wc -l)
USER=$(who | wc -l)
IP=$(ip a | grep "inet " | tail -1 | awk '{print $2}' | cut -d / -f 1)
MAC=$(ip a | grep "ether " | awk '{print $2}')
SUDO=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

MONITOR=$(echo "#Architecture: $ARCHY" > /root/Tools/Born2beroot/monitor.txt; \
      	echo "#CPU physical : $PPROC" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#vCPU : $VCPU" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Memory Usage: $MEMU" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Disk Usage: $DISKU" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#CPU load: $CPUU %" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Last boot: $LBOOT" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#LVM use: $LVM" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Connexions TCP : $TCP ESTABLISHED" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#User log: $USER" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Network: IP $IP ($MAC)" >> /root/Tools/Born2beroot/monitor.txt; \
	echo "#Sudo : $SUDO cmd" >> /root/Tools/Born2beroot/monitor.txt; \
	)

wall /root/Tools/Born2beroot/monitor.txt
