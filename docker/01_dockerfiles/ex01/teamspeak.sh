docker build . -t ts && docker run --rm --name teamspeak -p 9987:9987/udp -p 30033:30033 -d ts