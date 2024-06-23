#!/bin/bash

script_dir=$(dirname "$0")
avrdude_conf="$script_dir/avrdude.conf"
"$script_dir/avrdude" -C "$avrdude_conf" -v -V -pattiny414 -cjtag2updi -P/dev/ttyUSB0 -b115200 "-Uflash:r:dump.hex:i"

