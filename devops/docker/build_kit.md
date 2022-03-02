## <ins>build kit</ins>
- [advantages](#advantages)
- [examples](#advantags)
<br>
<br>
in order to activate the buildkit we define the environment variable: 

``export DOCKER_BUILDKIT=1``

<hr>

### <ins> advantages </ins>
1) if we use a multi-stage build that does not depend on each other, they will build in paralel instead of one after another.
(make huge improvement in time!). 

2) if using the --cache-from with docker build, then buildkit will let you use cache from a registry server in order to speed build time. (you also need to path a build arg called BUILDKIT_INLINE_CACHE).

3) you can build image using mounted secrets that are mounted to /run/secrets.

4) you can transfer ssh_key securly to the image for use. 

5) you can use cache in your build also.

### <ins> examples </ins>
1) 
```bash
FROM alpine as build1
RUN touch /opt/binary1

FROM alpine as build2
RUN touch /opt/binary2

FROM alpine as final
COPY --from=build1 /opt/binary1 /opt/
COPY --from=build2 /opt/binary2 /opt/
```
2) build the cache:
```bash
docker build --tag testimage/testimage:1 \
        --build-arg BUILDKIT_INLINE_CACHE=1 .
```
build the image using the cache:
```bash
docker build --cache-from testimage/testimage:1 .
```

3)
the Dockerfile:
```bash
# syntax=docker/dockerfile:experimental
FROM alpine
# will run this command with the secret mounted
RUN --mount=type=secret,id=mysite.key \
  && ls -l /run/secrets \
  && cat /run/secrets/mysite.key
```

build the image using the secret:
```bash
docker build --secret id=mysite.key,src=./mysite.key \
    --progress plain .
```

4)
the Dockerfile:
```bash
# syntax=docker/dockerfile:experimental
FROM alpine-ssh
RUN --mount=type=ssh \
    printenv|grep SSH \
    && ssh-add -l
```
the build command:
```bash
docker build --ssh default --progress plain .
```

5) 
create the cache:
```bash
# syntax=docker/dockerfile:experimental
FROM ubuntu
RUN --mount=type=cache,target=/tmp/cache \
    touch /tmp/cache/file.txt
```

use the cache:
```bash
# syntax=docker/dockerfile:experimental
FROM ubuntu
RUN --mount=type=cache,target=/tmp/cache \
    ls -l /tmp/cache
```