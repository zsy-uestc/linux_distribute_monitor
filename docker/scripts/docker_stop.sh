#!/usr/bin/env bash

docker_name=$(docker ps --format "{{.Names}}")

if [[ -n $docker_name ]]; then
    echo "try to stop ${docker_name}..."
    docker stop ${docker_name} > /dev/null
    docker rm -v -f linux_distribute_monitor > /dev/null
    echo -e "\nstop ${docker_name} success!\n"
fi

