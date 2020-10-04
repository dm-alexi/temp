FROM alpine
EXPOSE 80
RUN mkdir www && apk update && apk add php
ENTRYPOINT php -S 0.0.0.0:8000 -t /www