#!/bin/bash
printf '\033[0;34m Installation Started!\n'
printf '\033[0;34m Installing GLAD\n\033[0;31m'

mv ./glad /usr/include

printf '\033[0;34m Finished Installing GLAD\n'

mkdir $HOME'/NEON Engine'
mv ./assets $HOME'/NEON Engine/'
mv 'NEON Engine' $HOME'/NEON Engine/'

printf '\033[0;34m Engine Installation successfully finished!'

echo > $HOME'/Desktop/NEON Engine.desktop'

echo "[Desktop Entry]
Name=NEON Engine
Comment=Perfect game engine. Suits all your needs!
GenericName=NEON
Exec=/home/martin/NEONEngine/NEONEngine
Terminal=true
Path=/home/martin/NEONEngine
Icon=unity-editor-icon
Type=Application
Categories=Development;Utility;
Name[en_US]=NEON" > $HOME'/Desktop/NEONEngine.desktop'