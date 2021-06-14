#!/bin/bash
cd /root/Tools/Born2beroot/Config_Script/SET_config
printf "\n\t\t### START INIT CONF ###\n"
printf "\n\t\t### INIT CRONTAB RULES ###\n\n"
./CRONTAB_setmonitor.sh && sleep 5 && printf "\n\t\t### INIT PASS POLICY ###\n\n"
./PASS_setpolicy.sh && sleep 5 && printf "\n\t\t### INIT SUDO RULES ###\n\n"
./SUDO_setrules.sh && sleep 5 && printf "\n\t\t### INIT PAM RULES ###\n\n"
./PAM_setrules.sh && sleep 5 && printf "\n\t\t### INIT SSH RULES ###\n\n"
./SSH_setrules.sh && sleep 5 && printf "\n\t\t### INIT UFW RULES ###\n\n"
./UFW_setrules.sh && printf "\n\t\t### END INIT CONF ###\n\n"
