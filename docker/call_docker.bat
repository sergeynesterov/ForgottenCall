@echo off

set SCRIPT_DIRECTORY=%~dp0

docker container run --rm --user 1000:1000 --volume %SCRIPT_DIRECTORY%/../:/prj --workdir /prj %*