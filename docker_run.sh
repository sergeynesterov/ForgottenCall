#!/bin/sh

DOCKER_DIRECTORY="$(dirname "$(readlink -f "$0")")"/docker

sh $DOCKER_DIRECTORY/call_docker.sh -p 3490:3490 build_environment sh -c "/usr/local/bin/dlt-daemon > /dev/null -d 2>&1 && sleep 1 && ./build/bin/ForgottenCall"