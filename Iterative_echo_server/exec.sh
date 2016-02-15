#!/bin/sh
c++ iter_conn_echo_server.cpp -o server
c++ iter_tcp_client.cpp -o client

echo "compiled successfully !"

# open each server and client in new terminal

gnome-terminal -e "bash -c \" ./server; exec bash\""
sleep 1
gnome-terminal -e "bash -c \" ./client 127.0.0.1; exec bash\""

exit
