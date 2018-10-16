@Echo Off
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)


call :colorEcho 0a "Kahoot Play Started..."
echo .
set /p gameid= "Imput Your game ID: "
set /p name= "Imput a username: "
call :colorEcho 0e "Make sure you set the game correctly!"
echo .
cd C:\Users\User\go\kahoot-hack-master
call :colorEcho 0c " [Red = 0] "
call :colorEcho 0b " [Blue = 1] "
echo.
call :colorEcho 0e " [Yellow = 2] "
call :colorEcho 0a " [Green = 3] "
echo .
go run kahoot-play/main.go %gameid% %name%
call :colorEcho 0c "Connection Failure"
echo .
pause
exit

:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i