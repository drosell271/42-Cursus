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
echo -e "${GREEN}Comprobando Makefile${NOCOLOR}"
echo -e "${YELLOW}Comprobando ReLink (Make Make)${NOCOLOR}"
make
make
delay 15
echo -e "${YELLOW}Comprobando Clean${NOCOLOR}"
ls -a
delay 20
make clean
ls -a
delay 20
echo -e "${YELLOW}Comprobando Fclean${NOCOLOR}"
ls -a
delay 20
make fclean
ls -a
delay 20
echo -e "${YELLOW}Comprobando ReLink (Make_Bonus Make_Bonus)${NOCOLOR}"
make bonus
make bonus
delay 15
make fclean
echo -e "${YELLOW}Comprobando ReLink (Make Make_Bonus)${NOCOLOR}"
make
make bonus
delay 15
echo -e "${GREEN}Preparando archivos para Testers${NOCOLOR}"
for f in *.jpg; do mv "$f" "$(echo "$f" | sed s/IMG/VACATION/)"; done
rm -rf Makefile
cd ..
mv Makefile libft/
ls -ls
echo -e "${YELLOW}Comprueba los archivos${NOCOLOR}"
delay 20
echo -e "${GREEN}Descargando War Machine${NOCOLOR}"
git clone git@github.com:y3ll0w42/libft-war-machine.git
echo -e "${YELLOW}Ejecutando War Machine${NOCOLOR}"
cd libft-war-machine
bash grademe.sh
delay 20
echo -e "${GREEN}Descargando LibftTester${NOCOLOR}"
cd ..
git clone git@github.com:Tripouille/libftTester.git
echo -e "${YELLOW}Ejecutando War Machine${NOCOLOR}"
cd libftTester
make a
delay 20
echo -e "${GREEN}Descargando Libft Unit Tester${NOCOLOR}"
cd ..
cd ..
git clone git@github.com:alelievr/libft-unit-test.git
echo -e "${YELLOW}Ejecutando Libft Unit Tester${NOCOLOR}"
cd libft-unit-tests
make f




