FROM debian:buster
RUN apt-get update && apt-get install -y wget php php-mysql
RUN apt install nginx -y
RUN apt install openssl -y
RUN apt install php-fpm -y 
RUN apt install php7.3-pgsql -y
COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY www.conf /etc/php/7.3/fpm/pool.d
RUN wget "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-en.php" -O /var/www/adminer.php
RUN mkdir -p /run/php  
RUN chown www-data:www-data /run/php
RUN chown -R www-data:www-data /var/www
EXPOSE 8080

#RUN php-fpm7.3 -F
CMD service php7.3-fpm start && nginx -g "daemon off;"