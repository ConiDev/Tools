# choose basic image OS
FROM debian:buster

# define actual version and creator of the file
LABEL version="1.0" maintainer="nduvelle <nduvelle@student.42nice.fr>"

# modify next env to off to disable autoindex
ENV autoindex=on

# update OS
RUN apt-get update -y && apt-get upgrade -y
#RUN apt-get install -y openssl nginx mariadb-server php7.3 
RUN apt-get update -y && apt-get install -y openssl nginx mariadb-server php7.3 php7.3-mysql php7.3-fpm php7.3-mbstring php7.3-xml wget

# create https secure certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/conf.d/webtest.key -out /etc/nginx/conf.d/webtest.crt -subj '/C=FR/ST=PACA/L=Nice/O=42 Nice/CN=localhost'

# start mysql service and create user
RUN service mysql start && mysql -e "CREATE user 'nduvelle'@'localhost' identified by '123';GRANT all privileges on *.* to 'nduvelle'@'localhost';FLUSH PRIVILEGES;CREATE database wordpress;" && printf "123\n n\n n\n n\n y\n y\n y\n" | mysql_secure_installation

# install wordpress and phpmyadmin in good folder and supress tar file
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz && tar xvf latest-fr_FR.tar.gz && mv wordpress /var/www/html/wordpress
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz && tar xvf phpMyAdmin-5.1.0-all-languages.tar.gz && mv /phpMyAdmin-5.1.0-all-languages /var/www/html/phpmyadmin
RUN rm -rf /latest-fr_FR.tar.gz /phpMyAdmin-5.1.0-all-languages.tar.gz /var/www/html/index.html

# copy homemade config file to all services and test php info
COPY srcs/wp-config.php /var/www/html/wordpress/
COPY srcs/config.inc.php /var/www/html/phpmyadmin/
COPY srcs/nginx-config.conf /etc/nginx/conf.d/
COPY srcs/info.php /var/www/html/

# copy script to modify and start services
COPY srcs/service_start.sh /home/
RUN chmod 755 /home/service_start.sh

WORKDIR /var/www/html/
CMD "/home/service_start.sh"
