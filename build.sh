#!/bin/bash
set -e

gcc src/main.c \
  -o net \
  -Wall \
  -Wextra \
  -g \
&& ./net "$@"
