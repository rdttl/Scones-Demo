@echo off
setlocal

for %%I in ("%~dp0") do set "script_dir=%%~fI"

set "avrdude_conf=%script_dir%\avrdude.conf"
set "avrdude_exe=%script_dir%\avrdude.exe"

"%avrdude_exe%" -C "%avrdude_conf%" -v -V -pattiny414 -cjtag2updi -P COM3 -b 115200  "-Ufuse0:w:0b00000000:m" "-Ufuse2:w:0x02:m" "-Ufuse5:w:0b11000101:m" "-Ufuse6:w:0x04:m" "-Ufuse7:w:0x00:m" "-Ufuse8:w:0x00:m" "-Uflash:w:flash.hex:i"

endlocal
pause	