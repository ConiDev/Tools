#!/bin/bash
printf "### PERSONNAL CHECK ###\n"
crontab -l
printf "\n\n### FOLDER CHECK ###\n"
ls /etc/cron.d/
