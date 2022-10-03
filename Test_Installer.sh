#!/bin/bash

#------------------------------------------------
# COLORS
#------------------------------------------------
NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'

REPOSITORIO=$1

echo -e "${YELLOW}Creando carpteta de Test${NOCOLOR}"
mkdir TEST_FOLDER
cd TEST_FOLDER
echo -e "${BLUE}Descargando repositorio a testear${NOCOLOR}"
git clone REPOSITORIO libft
cd libft
rename -nv --
