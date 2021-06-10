#!/bin/bash
ufw enable
ufw default allow
ufw status verbose
ufw disable
ufw default deny incoming
ufw default deny outgoing
ufw logging on
ufw allow out 4242/tcp
ufw allow in 4242/tcp
