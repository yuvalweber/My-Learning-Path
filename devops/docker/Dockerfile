# arg is for build variables.
ARG version=latest
# the base image.
FROM alpine:${version}
# add metadata to container.
LABEL app=frontend
# define environment variables
ENV Example="this is test environment var"
# used for running commands.
RUN apk add --no-cache gcc musl-dev
# instruct which port to open in order to make the container work.
EXPOSE 5000/tcp
# define default user for container.
USER 1001:1001
# mkdir + chdir
WORKDIR /dir
# used to add files to container (can open tar file).
ADD --chown=1001:1001 example_file /dir/
# used to copy files to container.
COPY --chown=1001:1001 requirements.txt requirements.txt
# create mount point
VOLUME [ "/data" ]
# provide default for an executing container.
CMD ["gcc","example.c","-o","example"]
# if we define entrypoint we can make container run as executable.
ENTRYPOINT [ "python3","script.py" ]
# choose a signal that will kill the container.
STOPSIGNAL SIGKILL
# create health check for container.
HEALTHCHECK --interval=5m --timeout= \
    CMD curl -f http://localhost:5000 || exit 1