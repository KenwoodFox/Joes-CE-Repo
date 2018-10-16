@Echo Off
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)


call :colorEcho 0a "Kahoot Auto Started..."
echo .
set /p gameid= "Imput Your game ID: "
call :colorEcho 0e "Allow up to 12 seconds for bots to start to connect."
echo .
cd C:\Users\User\go\kahoot-hack-master
echo "Make sure you changed the game ID number"
go run kahoot-rand/main.go %gameid% C:\Users\User\go\kahoot-hack-master\name_list.txt
call :colorEcho 0c "Connection Failure"
echo .
pause
exit

:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i