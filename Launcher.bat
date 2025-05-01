@echo off
setlocal EnableDelayedExpansion
color 0A
title System Resource Manager

set "bdir=C:\Users\mathe\OneDrive\Desktop\Bloody7_V2023.0411_TestActivate\Bloody7\Bloody7-2"
set "mdir=%bdir%\Modules"
set "cdir=%bdir%\Config"

:: Launch with high priority, adaptive learning and LMB-triggered aim
"%bdir%\Bloody7.exe" -module "%mdir%\precision_core.b7m" -interface "Modules\interface\apex_control.lua" -config "%cdir%\settings.json" -system_config "%cdir%\system_config.json" -silent -priority high -adaptive

echo.
echo Launch complete. Press any key to exit.
pause > nul