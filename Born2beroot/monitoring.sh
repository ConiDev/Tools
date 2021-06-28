#!/bin/bash

ARCHY=$(uname -a)
PPROC=$(grep "physical id" /proc/cpuinfo | wc -l)
VCPU=$(grep "processor" /proc/cpuinfo | wc -l)
MEMU=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2}')
DISKU=$(df -h --total | tail -1 | awk '{printf "%d/%dGB (%s)\n", $3,$2,$5}')
CPUU=$(mpstat | grep "all" | awk '{print (100 - $NF)}')
LBOOT=$(who -a | grep "syst" | awk '{print $3" "$4}')
LVM=$(/root/Tools/Born2beroot/Check_Script/LVM_check/LVM_inuse.sh)
TCP=$(ss -tH | grep "ESTAB" | wc -l)
USER=$(who | wc -l)
IP=$(ip a | grep "inet " | tail -1 | awk '{print $2}' | cut -d / -f 1)
MAC=$(ip a | grep "ether " | awk '{print $2}')
SUDO=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

echo -e "\n\t#Architecture: $ARCHY
\t#CPU physical : $PPROC
\t#vCPU : $VCPU
\t#Memory Usage: $MEMU
\t#Disk Usage: $DISKU
\t#CPU load: $CPUU %
\t#Last boot: $LBOOT
\t#LVM use: $LVM
\t#Connexions TCP : $TCP ESTABLISHED
\t#User log: $USER
\t#Network: IP $IP ($MAC)
\t#Sudo : $SUDO cmd" | wall

echo -e "\n\t#Architecture: $ARCHY
\t#CPU physical : $PPROC
\t#vCPU : $VCPU
\t#Memory Usage: $MEMU
\t#Disk Usage: $DISKU
\t#CPU load: $CPUU %
\t#Last boot: $LBOOT
\t#LVM use: $LVM
\t#Connexions TCP : $TCP ESTABLISHED
\t#User log: $USER
\t#Network: IP $IP ($MAC)
\t#Sudo : $SUDO cmd" > /root/Tools/Born2beroot/monitor.txt
