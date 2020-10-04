FROM alpine AS build-binary
RUN apk add go
ADD src /src
RUN cd src && go build -o ts

FROM alpine
EXPOSE 80
RUN mkdir server
COPY --from=build-binary /src/ts /server
ENTRYPOINT ./server/ts