FROM alpine:3.20

WORKDIR /app

RUN apk add --no-cache \
    python3 \
    py3-pip \
    git \
    bash \
    curl \
    sqlite \
    openssh-client \
    sshfs \
    rsync

RUN mkdir -p /root/.ssh && \
    touch /root/.ssh/known_hosts && \
    ssh-keyscan 176.181.239.55 >> /root/.ssh/known_hosts

RUN git clone https://github.com/OSTJourney/OSTJourney.git
WORKDIR /app/OSTJourney

RUN pip3 install --break-system-packages --upgrade pip && \
    pip3 install --break-system-packages -r requirements.txt

COPY start.sh /start.sh
RUN chmod +x /start.sh

CMD ["/start.sh"]
