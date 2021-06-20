#!/bin/bash
printf "y\n" | ufw reset
ufw default allow incoming
ufw default allow outgoing
ufw enable
