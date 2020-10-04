FROM alpine
RUN apk add --no-cache sdl libxxf86vm libstdc++ libgcc build-base sdl-dev linux-headers file
ADD [ "https://sourceforge.net/projects/dosbox/files/dosbox/0.74-3/dosbox-0.74-3.tar.gz/download", "/build/dosbox-0.74-3.tar.gz" ]
RUN mkdir /dosbox && cd /build && tar x -z -f dosbox-0.74-3.tar.gz && cd dosbox-0.74-3 && ./configure --prefix=/usr \
	&& make && make install \
	&& apk del build-base sdl-dev linux-headers \
	&& rm -R /build
ADD [ "resources/dosbox-docker.conf", "/root/.dosbox/" ]
ENTRYPOINT dosbox -conf /root/.dosbox/dosbox-docker.conf