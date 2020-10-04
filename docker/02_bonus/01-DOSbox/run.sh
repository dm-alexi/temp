xhost +local:docker

docker run -ti --rm --ipc=host -e DISPLAY=unix$DISPLAY \
	-v /tmp/.X11-unix:/tmp/.X11-unix:ro -v $PWD/dosbox:/dosbox \
	--name dosbox dosbox
