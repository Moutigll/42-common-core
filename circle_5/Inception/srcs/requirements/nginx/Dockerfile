FROM alpine:3.20

RUN apk update && apk add --no-cache \
	nginx \
	openssl \
	curl 

COPY nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 42 \
		-newkey rsa:4096 \
		-keyout /etc/nginx/ssl/nginx.key \
		-out /etc/nginx/ssl/nginx.crt \
		-subj "/CN=tkt_frere/O=42 School/OU=42 School/C=FR/L=Normandie/ST=Le Havre"

RUN mkdir -p /run/nginx /var/www/html && \
	chown -R nginx:nginx /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]