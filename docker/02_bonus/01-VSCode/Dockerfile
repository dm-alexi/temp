FROM debian
RUN apt-get update && apt-get upgrade -y && apt-get install -y build-essential git software-properties-common apt-transport-https curl \
	&& curl -sSL https://packages.microsoft.com/keys/microsoft.asc | apt-key add \
	&& add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" \
	&& apt update && apt install -y code
