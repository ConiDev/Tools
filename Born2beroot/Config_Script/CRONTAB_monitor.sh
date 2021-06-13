#!/bin/bash
echo "*/10 * * * *	root	bash /root/Tools/Born2beroot/monitoring.sh" > /etc/cron.d/monitor
cat /etc/cron.d/monitor
