#!/bin/bash
printf "y\n" | ufw reset
ufw enable
ufw status verbose
