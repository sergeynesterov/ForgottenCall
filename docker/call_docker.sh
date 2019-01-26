#!/bin/sh

SCRIPT_DIRECTORY="$(dirname "$(readlink -f "$0")")"

docker container run --rm --user $(id -u):$(id -g) --volume $SCRIPT_DIRECTORY/../:/prj --workdir /prj "${@:1}"