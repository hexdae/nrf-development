#!/usr/bin/env bash

# Create a unique container name based on the current folder.
container_name=$(pwd)
container_name="${container_name/\//}"
container_name="${container_name//\//_}"
container_name="$(echo $container_name | tr '[A-Z]' '[a-z]')" 

# Force a rebuild of the container.
if [[ $1 == "--build" ]]; then
    docker build -t ${container_name} .
    shift
fi

# Build the Docker image if it doesn't exist.
if ! docker image ls | grep "\b$container_name\b" > /dev/null ; then
    docker build -t ${container_name} .
fi

# Run the command with the Docker image.
docker run --mount type=bind,source="$(pwd)",target=/app ${container_name} "$@"
