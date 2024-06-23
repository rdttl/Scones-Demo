#!/bin/bash

script_dir=$(dirname "$0")
avrdude_conf="$script_dir/avrdude.conf"
"$script_dir/avrdude" -C "$avrdude_conf" -v -V -pattiny414 -cjtag2updi -P/dev/ttyUSB0 -b115200 "-Ufuse0:w:0b00000000:m" "-Ufuse2:w:0x02:m" "-Ufuse5:w:0b11000101:m" "-Ufuse6:w:0x04:m" "-Ufuse7:w:0x00:m" "-Ufuse8:w:0x00:m" "-Uflash:w:flash.hex:i"
