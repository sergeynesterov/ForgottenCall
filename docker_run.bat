@echo off

SET DOCKER_DIRECTORY=%~dp0/docker

%DOCKER_DIRECTORY%/call_docker.bat -p 3490:3490 build_environment sh -c "/usr/local/bin/dlt-daemon > /dev/null -d 2>&1 && sleep 1 && ./build/bin/ForgottenCall"
