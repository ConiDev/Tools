#!/bin/bash
printf "y\n" | ufw enable
printf "y\n" | ufw reset
ufw status verbose
ufw disable
ufw default deny incoming
ufw default deny outgoing
ufw logging on
ufw allow 4242/tcp
ufw allow 80
printf "y\n" | ufw enable
ufw status verbose
