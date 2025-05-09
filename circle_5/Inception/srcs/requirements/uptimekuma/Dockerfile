FROM alpine:3.20

RUN apk add --no-cache nodejs npm git curl bash python3 make g++

WORKDIR /app

RUN git clone --depth=1 https://github.com/louislam/uptime-kuma.git .

RUN npm install

RUN npm run build

RUN npm prune --production

EXPOSE 3001

CMD ["node", "server/server.js"]
