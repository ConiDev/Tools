#!/bin/bash
cd /root/Tools/Born2beroot/Config_Script/RESET_config
printf "\n\t\t### START RESET CONF ###\n"
printf "\n\t\t### RESET CRONTAB MONITOR ###\n\n"
./CRONTAB_resetmonitor.sh && sleep 5 && printf "\n\t\t### RESET PASS POLICY ###\n\n"
./PASS_resetpolicy.sh && sleep 5 && printf "\n\t\t### RESET SUDO RULES ###\n\n"
./SUDO_resetrules.sh && sleep 5 && printf "\n\t\t### RESET PAM RULES ###\n\n"
./PAM_resetrules.sh && sleep 5 && printf "\n\t\t### RESET SSH RULES ###\n\n"
./SSH_resetrules.sh && sleep 5 && printf "\n\t\t### RESET UFW RULES ###\n\n"
./UFW_resetrules.sh && printf "\n\t\t### END RESET CONF ###\n\n"
