#!/bin/bash

REGIONS=("EUR" "JP" "USA")

build() {
    make clean
    echo -e "\033[32mmake -j REGION=$REGION $1\033[0m"
    make -j REGION=$REGION $1
    echo -e "\033[32mMoving to $2\n\033[0m"
    mv code.ips "$2"
}

createPatches() {
    REGION=$1

    # 3DS
    build "dpad=1 rstick=1 touchscreen=1" "./Patch Files/$REGION/3DS/all/code.ips"
    build "dpad=1" "./Patch Files/$REGION/3DS/dpad/code.ips"
    build "touchscreen=1" "./Patch Files/$REGION/3DS/touchscreen/code.ips"
    build "rstick=1" "./Patch Files/$REGION/3DS/rightstick/code.ips"
    build "dpad=1 rstick=1" "./Patch Files/$REGION/3DS/dpad_rightstick/code.ips"
    build "dpad=1 touchscreen=1" "./Patch Files/$REGION/3DS/dpad_touchscreen/code.ips"
    build "rstick=1 touchscreen=1" "./Patch Files/$REGION/3DS/rightstick_touchscreen/code.ips"

    # Citra
    build "dpad=1 rstick=1 touchscreen=1 citra=1" "./Patch Files/$REGION/Citra/all/code.ips"
    build "dpad=1 citra=1" "./Patch Files/$REGION/Citra/dpad/code.ips"
    build "touchscreen=1 citra=1" "./Patch Files/$REGION/Citra/touchscreen/code.ips"
    build "rstick=1 citra=1" "./Patch Files/$REGION/Citra/rightstick/code.ips"
    build "dpad=1 rstick=1 citra=1" "./Patch Files/$REGION/Citra/dpad_rightstick/code.ips"
    build "dpad=1 touchscreen=1 citra=1" "./Patch Files/$REGION/Citra/dpad_touchscreen/code.ips"
    build "rstick=1 touchscreen=1 citra=1" "./Patch Files/$REGION/Citra/rightstick_touchscreen/code.ips"
}

if [ -n "$1" ]; then
    valid=0
    for r in "${REGIONS[@]}"; do
        [ "$1" = "$r" ] && valid=1
    done

    if [ "$valid" -eq 0 ]; then
        echo "Invalid region: only available are EUR, JP, USA"
        exit 1
    fi

    createPatches "$1"
else
    for reg in "${REGIONS[@]}"; do
        createPatches "$reg"
    done
fi