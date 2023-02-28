# Born2BeRoot

## Como funciona una máquina virual
Una máquina virtual es un software que simula un sistema de computación y puede ejecutar programas como si fuese una computadora real.
 Una característica esencial de las máquinas virtuales es que los procesos que ejecutan están limitados por los recursos y abstracciones proporcionados por ellas. Estos procesos no pueden escaparse de esta "computadora virtual".

<br>

## CentOS vs Debian
CentoOS:
- Depende de Red-Hat (Empresa del linux de pago)
- Utiliza YUM para gestionar paquetes
- Se actualiza poco, lo que hace que sea estable
- Es más complicado

Debian:
- Depende de la comunidad
- Utiliza Apt para gestionar paquetes
- Es facilmente actualizable
- Es más facil
<br>

## Apt vs Aptitude
Aptitude:
- Sistema de gestión de paquetes de alto nivel

Apt:
- Sistema de gestión de paquetes de bajo nivel

<br>

## APPArmor
Es el módulo de seguridad de linux que da permisos dependiendo de rutas

<br>

## Contraseñas
Politica de contraseñas: `sudo nano /etc/pam.d/common-password`

Ver tiempos de las contraseñas: `chage -l //user`

Cambiar tiempos de las contraseñas: `sudo nano /etc/login.defs`

<br>

## Usuarios y grupos
Nuevo usuario: `adduser //Nombre de usuario a crear`

Nuevo grupo: `groupadd //Nombre de grupo`

Grupos: `groups (del ususario que lo ejecuta | necesita reinicio)`

Añadir usuario a grupo: `usermod -aG //Grupo //User`

<br>

## Hostname y particiones
Ver Hostname: `hostname`

Cambiar Hostname: `sudo nano /etc/hostname` (necesita reinicio)

Ver particiones: `df -h` o `lsblk`

<br>

## Sudo

Verificar log: `sudo nano /var/log/sudo/sudo.log`

<br>

## UFW
Ver estado y puertos: `sudo ufw status`

Añadir puerto: `sudo ufw allow //Puerto`

Eliminar puerto: `sudo ufw delete allow //Puerto`

<br>

## SSH
Estado de SSH: `systemctl status sshd.service`

Ver ssh puerto: `sudo nano /etc/ssh/sshd.conf`

Conectarse: `ssh drosell-@localhost -p 4242`

<br>

## Script
Ver archivo: `sudo nano /usr/local/bin/monitor.sh`

Crontab: `crontab -e`
