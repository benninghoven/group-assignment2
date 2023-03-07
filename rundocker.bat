@echo off

set NAME=os_assignment2

set IMAGE=%NAME%_image
set CONTAINER=%NAME%_container

for /f "tokens=*" %%i in ('docker images -q %IMAGE%') do set found=%%i

if [%found%] == [] (
  echo 🐳 Image not found, creating...
  docker build -t %IMAGE% .
) else (
  echo 🐳 Image found
)

set "current_dir=%CD%"
set "current_dir=\"!current_dir!\""

docker run -it ^
    -v %current_dir%/src:/app/src ^
    --name %CONTAINER% ^
    %IMAGE%

docker rm %CONTAINER%
