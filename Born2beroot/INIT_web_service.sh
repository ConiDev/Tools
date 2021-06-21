#!/bin/bash
USERNAME='admin'
PASSWORD='admin'

printf "y\n" | aptitude install lighttpd \
	mariadb-server \
	php7.3 \
	php7.3-fpm \
	php7.3-cli \
	php7.3-cgi \
	php7.3-mysql \
	php7.3-curl \
	php7.3-gd \
	php7.3-intl \
	php7.3-json \
	php7.3-mbstring \
	php7.3-xml \
	php7.3-zip

mysql -e "CREATE user $USERNAME@'localhost' identified by $PASSWORD; \
		GRANT all privileges on *.* to $USERNAME@'localhost'; \
		FLUSH PRIVILEGES;CREATE database wordpress;" \
		&& printf "admin\n n\n y\n y\n y\n y\n y\n" | mysql_secure_installation

echo "<?PHP phpinfo(); ?>" > /var/www/html/info.php

lighty-enable-mod fastcgi
service lighttpd force-reload

cd /var/www/html/ && wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz \
	&& tar xvf /var/www/html/phpMyAdmin-5.1.0-all-languages.tar.gz \
	&& mv /var/www/html/phpMyAdmin-5.1.0-all-languages /var/www/html/phpmyadmin
	&& wget https://fr.wordpress.org/latest-fr_FR.tar.gz \
	&& tar xvf latest-fr_FR.tar.gz \
	&& rm /var/www/html/latest-fr_FR.tar.gz /var/www/html/phpMyAdmin-5.1.0-all-languages.tar.gz

chmod 755 -R /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress
cp /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php
sed -i -e "s/$cfg\['blowfish_secret'\] = '';/$cfg\['blowfish_secret'\] = 'MysecretBlowfisShPassWordIsReaLlyFamOus !';/g" /var/www/html/phpmyadmin/config.inc.php
cp /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php

#modify config wordpress BDD
#sed -i -e "s///g" /var/www/html/wordpress/config.inc.php
