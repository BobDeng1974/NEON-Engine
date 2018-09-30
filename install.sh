#!/bin/bash
printf '\033[0;34m Installation Started!\n'
printf '\033[0;34m Installing GLAD\n\033[0;31m'

#mv ./glad /usr/include

printf '\033[0;34m Finished Installing GLAD\n'
printf '\033[0;34m Installing Engine\n'

#DIRECTORY=$(cd `dirname $0` && pwd)
#mv $(cd `dirname $0` && pwd)/debugLog.log ~$USER

eval echo $(cd `dirname $0` && pwd)/assets;
eval echo ~$USER