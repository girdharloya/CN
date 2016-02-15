#!/bin/sh
c++ tcp_fork_client.cpp -o client
c++ tcp_fork_server.cpp -o server

echo "compiled successfully !"

# open server and 3 client in each new terminal

gnome-terminal -e "bash -c \" ./server; exec bash\""
sleep 1
gnome-terminal -e "bash -c \" ./client 127.0.0.1; exec bash\""
sleep 1
gnome-terminal -e "bash -c \" ./client 127.0.0.2; exec bash\""
sleep 1
sleep 1
gnome-terminal -e "bash -c \" ./client 127.0.0.3; exec bash\""

exit
/* usage :
----------
run command --> bash exec.sh  <-- in the Terminal


