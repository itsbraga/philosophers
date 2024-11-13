#!/bin/bash

BOLD='\033[1m'
RED='\033[38;2;255;105;97m'
ORANGE='\033[38;2;255;178;127m'
YELLOW='\033[38;2;255;234;150m'
GREEN='\033[38;2;173;235;179m'
BLUE='\033[38;2;179;235;242m'
LT_PURPLE='\033[38;2;224;176;255m'
PINK='\033[38;2;255;182;193m'
D_PINK='\033[38;2;197;75;140m'
WHITE='\033[0;37m'
RESET='\033[0m'

COLORS=($RED $ORANGE $YELLOW $GREEN $BLUE $LT_PURPLE $PINK $D_PINK $WHITE)

rainbow_text() {
    TEXT=$1
    for i in $(seq 0 $((${#TEXT}-1))); do
        COLOR=${COLORS[$((i%${#COLORS[@]}))]}
        echo -ne "${COLOR}${BOLD}${TEXT:$i:1}${RESET}"
    done
}

rainbow_text "$1"