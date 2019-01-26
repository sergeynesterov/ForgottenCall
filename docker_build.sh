#!/bin/sh

DOCKER_DIRECTORY="$(dirname "$(readlink -f "$0")")"/docker

docker build --tag runtime_environment - < $DOCKER_DIRECTORY/environment/runtime.Dockerfile
docker build --tag build_environment - < $DOCKER_DIRECTORY/environment/build.Dockerfile

sh $DOCKER_DIRECTORY/call_docker.sh build_environment sh ./cmake_build.sh
