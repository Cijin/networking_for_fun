#!/bin/bash
set -e

gcc src/main.c \
  -o net \
  -Wall \
  -Wextra \
  -Wshadow \
  -Wstrict-prototypes \
  -Wmissing-prototypes \
  -Wconversion \
  -Wpedantic \
  -std=c11 \
  -g \
  -fsanitize=address,undefined \
  -fno-omit-frame-pointer \
&& ./net "$@"
