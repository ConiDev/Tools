#!/bin/bash
cd /root/Tools/Born2beroot/Check_Script
clear && printf "\n\t\t### START CHECK RULES ###\n" && printf "\n\t\t### CHECK AppArmor ###\n\n"
./CHECK_apparmor.sh && sleep 10 && clear && printf "\n\t\t### CRONTAB RULES ###\n\n"
./CRONTAB_checkrules.sh && sleep 10 && clear && printf "\n\t\t### PAM RULES ###\n\n"
./PAM_checkrules.sh && sleep 10 && clear && printf "\n\t\t### SUDO RULES ###\n\n"
./SUDO_checkrules.sh && sleep 10 && clear && printf "\n\t\t### PSWD POLICY RULES ###\n\n"
./PSWD_policy_check/CHECK_allpasspolicy.sh && sleep 10 && clear && printf "\n\t\t### UFW RULES ###\n\n"
./UFW_checkrules.sh && printf "\n\t\t### END CHECK RULES ###\n\n"
