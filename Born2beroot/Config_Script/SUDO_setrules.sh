#!/bin/bash
echo "# Custom Sudo rules for Born2beroot" > /etc/sudoers.d/sudo_rules && \
echo "Defaults	env_reset" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	mail_badpass" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	secure_path=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	log_host, log_year, logfile=/var/log/sudo/sudo.log" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	log_input, log_output" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	iolog_dir=/var/log/sudo/sudo-io" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	requiretty" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	use_pty" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	lecture=always" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	passwd_timeout=2" >> /etc/sudoers.d/sudo_rules && \
echo "Defaults	insults" >> /etc/sudoers.d/sudo_rules
cat /etc/sudoers.d/sudo_rules
chmod 440 /etc/sudoers.d/sudo_rules
