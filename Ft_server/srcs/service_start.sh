#!/bin/sh
sed -i -e "s/autoindex on/autoindex $autoindex/g" /etc/nginx/conf.d/nginx-config.conf
service php7.3-fpm start 
service nginx restart
service mysql start
tail -f /dev/null
