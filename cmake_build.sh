#!/bin/sh

# project paths
ROOT_DIR=$(dirname "$(readlink -f "$0")")
BUILD_DIR="$ROOT_DIR"/build

# do configure if required
if [[ ! -d "$BUILD_DIR" ]]; then
   mkdir -p "$BUILD_DIR"
   cmake -S "$ROOT_DIR" -B "$BUILD_DIR" -GNinja
fi

# build
if [[ "$?" -eq 0 ]]; then
   cmake --build "$BUILD_DIR" --target all
fi

# test
if [[ "$?" -eq 0 ]]; then
   cmake --build "$BUILD_DIR" --target test
fi