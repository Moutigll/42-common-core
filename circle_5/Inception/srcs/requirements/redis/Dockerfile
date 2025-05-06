FROM alpine:3.20

RUN apk update && \
	apk add --no-cache redis

EXPOSE 6379

CMD ["redis-server", "--protected-mode", "no"]