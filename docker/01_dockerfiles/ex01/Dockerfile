FROM debian
ENV TS3SERVER_LICENSE=accept
EXPOSE 9987/udp 30033
WORKDIR /home
RUN apt-get update && apt-get -y upgrade && apt-get -y install wget bzip2 \
	&& wget https://files.teamspeak-services.com/releases/server/3.12.1/teamspeak3-server_linux_amd64-3.12.1.tar.bz2 \
	&& tar -xf teamspeak3-server_linux_amd64-3.12.1.tar.bz2 \
	&& rm teamspeak3-server_linux_amd64-3.12.1.tar.bz2
ENTRYPOINT ["bash", "teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]