@echo off

SET DOCKER_DIRECTORY=%~dp0/docker

docker build --tag runtime_environment - < %DOCKER_DIRECTORY%/environment/runtime.Dockerfile
docker build --tag build_environment - < %DOCKER_DIRECTORY%/environment/build.Dockerfile

%DOCKER_DIRECTORY%/call_docker.bat build_environment sh ./cmake_build.sh
