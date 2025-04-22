FROM alpine:3.20

RUN apk update && apk add --no-cache nginx openssl

COPY nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /run/nginx

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 42 \
    -newkey rsa:4096 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/CN=tkt_frere/O=42 School/OU=42 School/C=FR/L=Normandie/ST=Le Havre"

EXPOSE 443

RUN mkdir -p /var/www/html
RUN chown -R nginx:nginx /var/www/html

CMD ["nginx", "-g", "daemon off;"]
