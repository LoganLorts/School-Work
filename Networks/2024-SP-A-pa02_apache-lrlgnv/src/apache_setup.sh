#!/bin/bash

# Install
# This part will be done for you on the gitlab-ci.
# You may do it manually on your VM.

## Fedora
# sudo dnf install httpd
# Enable incoming http/https using firewall GUI (optional)

## Debain (just fyi, it will behave differently than the grade container).
# sudo apt install apache2
# Use gufw or ufw to enable incoming http/https (optional)

echo "Runing on OS:"
cat /etc/os-release

if grep 'docker\|lxc' /proc/1/cgroup >/dev/null 2>&1; then
    # Apache on the remote docker container
    # (for grading)

    # Enable and start Apache
    # Since systemctl is not on docker,
    # run apache directly in the background.
    httpd &

    # Get the files to serve in the right place to be served:
    # Use sudo here
    sudo cp -r ./www/html/ /var/www/
    sudo cp -r ./www/cgi-bin/ /var/www/

    # Set permissions for web directories
    sudo chmod --recursive drwxr-xr-x /var/www/html/
    sudo chmod --recursive rwxr-xr-x /var/www/cgi-bin/
else
    # Apache on your local machine
    # (for easier development)

    # Enable and start Apache
    systemctl start httpd.service

    # Get the files to serve in the right place to be served:
    sudo cp -r ./www/html/ /var/www/
    sudo cp -r ./www/cgi-bin/ /var/www/

    # Set permissions for web directories
    sudo chmod 755 /var/www/html/
    sudo chmod 755 /var/www/cgi-bin/
    sudo chmod --recursive o=rwx,g=rx,u=rx /var/www/html/
    sudo chmod --recursive o=rwx,g=rx,u=rx /var/www/cgi-bin/
fi
