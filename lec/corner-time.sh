#! /bin/bash
# escape sequences can be found 

ESC=^[
while [ 1 ]; do
    printf "${ESC}[s"
    printf "${ESC}[H
    printf "$ESC{ESC}[37;41;1m"

