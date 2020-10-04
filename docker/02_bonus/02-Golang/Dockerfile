FROM debian
RUN apt-get update && apt-get upgrade -y && apt-get install -y curl
RUN curl --remote-name --progress https://dl.google.com/go/go1.15.2.linux-amd64.tar.gz \
	&& echo 'b49fda1ca29a1946d6bb2a5a6982cf07ccd2aba849289508ee0f9918f6bb4552 go1.15.2.linux-amd64.tar.gz' | sha256sum -c - \
	&& tar -C /usr/local -xzf go1.15.2.linux-amd64.tar.gz && rm go1.15.2.linux-amd64.tar.gz && ln -sf /usr/local/go/bin/go /usr/local/bin/go \
	&& ln -sf /usr/local/go/bin/gofmt /usr/local/bin/gofmt && ln -sf /usr/local/go/bin/godoc /usr/local/bin/godoc && mkdir /home/projects
ENTRYPOINT bash