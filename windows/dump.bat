@echo off
setlocal

for %%I in ("%~dp0") do set "script_dir=%%~fI"

set "avrdude_conf=%script_dir%\avrdude.conf"
set "avrdude_exe=%script_dir%\avrdude.exe"

"%avrdude_exe%" -C "%avrdude_conf%" -v -V -pattiny414 -cjtag2updi -P COM3 -b 115200 -U flash:r:dump.hex:i

endlocal
pause