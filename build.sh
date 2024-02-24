#!/bin/sh

set -xe

cc -Wall -Wextra -pedantic -std=c11 -o pwgen pwgen.c
