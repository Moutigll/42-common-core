#!/bin/sh

echo "PasswordAuthentication yes" >> /etc/ssh/sshd_config
echo "Subsystem sftp /usr/lib/ssh/sftp-server" >> /etc/ssh/sshd_config

/usr/sbin/sshd -D
