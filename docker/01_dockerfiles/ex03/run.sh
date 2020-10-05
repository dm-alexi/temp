docker run -it --rm --name gitlab -p 8080:80 -p 8022:22 -p 8443:443 \
	-e DOCKER_IP="172.17.0.1" \
	--shm-size=4g --privileged ft-gitlab

#-e DOCKER_IP=$(echo $DOCKER_HOST | cut -d/ -f3 | cut -d: -f1) \
# git config --global http.sslverify false