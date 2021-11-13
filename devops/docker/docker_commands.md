# table of contents
- [useable environment variables](#useable-environment-variables)
- [commands](#commands)
    * [docker run examples](#docker-run-examples)
    * [docker attach examples](#docker-attach-examples)
    * [docker build examples](#docker-build-examples)
    * [docker commit examples](#docker-commit-examples)
<br>
<br>
<br>
<br>


# useable environment variables
1) location of docker configuration file
``
DOCKER_CONFIG
``
2) daemon socket to connect to 
``
DOCKER_HOST
`` 
<br>
<br>

# commands
### <ins>docker run examples</ins>
1) create container in detached mode with io open and tty.
```
docker run -dit --name "yuvalweber" alpine:latest
```
2) create container with port mapping
```
docker run -dit --name "yuvalweber" -p 80:80 alpine:latest
```

3) connect container to stdin and stdout
```
docker run -a stdin -a stdout -i -t alpine:latest
```
4) output docker container id to file
```
docker run -dit --cidfile="id.txt" alpine:latest
```
5) attach to another container pid namespace in order to debug
```
docker run --name my_redis -d redis
docker run -it --pid=container:my_redis my_strace bash
strace -p 1
```
6) remove container and its volume when exited.
```
docker run --rm -dit --name "yuvalweber" alpine:latest
```
7) create container with memory limit
```
docker run -dit --name "yuvalweber" -m 300M alpine:latest
```
8) map a device to container
```
docker run -device=/dev/sda:/dev/sda alpine:latest
```
9) add capabilities to container
```
docker run --cap-add=SYS_PTRACE alpine:latest
```
10) run docker with access to all devices (it can also make docker run inside docker).
```
docker run --privileged alpine:latest
```
11) create container with volume mount
```
docker run -v /var:/var alpine:latest
```
<hr>

### <ins>docker attach examples</ins>
the attach command will show the output of entry point or cmd.

1) attach to running container.
``` 
docker attach "<container_name>"
```
if you want to quit from running container click ``CTRL-p`` + ``CTRL-q``
<hr>

### <ins>docker build examples</ins>
1)  build image with tag and dockerfile
```
docker build -t yuvalweber:latest -f Dockerfile
```
2) build with build variable
```
docker build --build-arg TEST=TRY .
```
3) build till a specific level in a multi build Dockerfile
```
docker build --target <level_name> .
```
4) output docker build as tar
```
docker build --output type=tar,dest=output.tar .
```
5) build using cache from another image
```
docker build -t myname/myapp --build-arg BUILDKIT_INLINE_CACHE=1 .

docker build --cache-from myname/myapp .
```
6) write image id to file
```
docker build --iidfile="id.txt" -t try:latest .
``` 
7) remove all docker build cache
```
docker builder prune --force --all
```
8) delete only cache related to specific filter
```
docker builder prune --force --filter 'until=24h'
```
<hr>

### <ins>docker commit examples</ins>
commit a container file changes or settings to new container.

1) save a container to a new image with author name yuval199985@gmail.com
```
docker commit -a "yuval199985@gmail.com" <container_name> <image_name> 
``` 
2) save a container and add comment message
```
docker commit -m "debug message" <container_name> <image_name>
```
3) add commands to the image created.
```
docker commit -c "ENV DEBUG=true" <container_name> <image_name>
```
