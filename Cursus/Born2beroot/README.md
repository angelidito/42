# Born2beroot

Como consiste en configurar un servidor e instalar el número mínimo de servicios. Por este motivo, una interfaz gráfica no tiene sentido

Está prohibido por tanto instalar X.org o cualquier servidor gráfico equivalente. En caso de hacerlo, la nota será 0

Elegir como sistema operativo la última versión estable de Debian o CentOS


## Debian y CentoOS: a tener en cuenta

### Gestión de paquetes
Debian usa el formato de paquete DEB con dpkg/APT

CentOS usa el formato de paquete RPM, con YUM/DNF como administrador de paquetes derivado de Red Hat

### Sistemas de archivos
CentoOS usa XFS por defecto, y Debian EXT4. Sin embargo, ambas opciones (y otras) son soportadas por ambas distribuciones.


## Debian

Se recomienda encarecidamente si no se tiene experiencia en administración de sistemas...
- [x] AppArmor debe ejecutarse al inciar


## CentoOS

Configurar CentOS es bastante complejo. Por lo tanto, no hay que configurar KDump
- [ ] SELinux debe ejecutarse al iniciar y su configuración debe adaptarse a las necesidades del proyecto
- [ ] (¿) AppArmor debe ejecutarse al inciar (?)


# ¿Qué hay que hacer?

- [x] Crear al menos 2 particiones cifradas usando LVM
- [x] Ejecutar el servicio SSH sólamente en el puerto 4242
  - [x] No debe ser posible conectarte a través de SSH como root
- [x] Configurar el SO con el firewall UFW dejando abierto solamente el puerto 4242
- [x] Usar la política de contraseñas fuerte
- [x] Instalar y configurar sudo siguiendo reglas estrictas
- [x] El hostname de la máquina virtual angmarti42
- [x] Crear usuario con angmarti como nombre
  - [x] Debe pertenecer a los grupos user42 y sudo
- [x] Script: monitoring.sh



# Desarrollo

## Sudo

Reglas estrictas:
- [x] Autenticarse con sudo debe limitado a tres intentos fallidos de introducir 
la contraseña
- [x] Mostrar mensaje personalizado en caso de contraseña introducida incorrecta 
al utilizar sudo
- [x] Para cada comando ejecutado con sudo, tanto el **input** como el **output** 
deben quedar archivados en el directorio **/var/log/sudo/**
- [x] El modo TTY debe estar activado por razones de seguridad
- [x] Por seguridad, los directorios utilizables por sudo deben estar restringidos.
Por ejemplo:  
**/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin**

```
	su -
	apt-get install sudo
	usermod -aG sudo angmarti  # Or "adduser angmarti sudo"
	getent group sudo
```

Escribimos reglas estrictas en `/etc/sudoers.d/sudorules`:
```
Defaults        passwd_tries=3
Defaults        insults
Defaults        logfile="/var/log/sudo/sudorules"
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
Defaults        requiretty
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```


## SSH
```
sudo apt install openssh-server
sudo nano /etc/ssh/sshd_config
sudo systemctl restart ssh
sudo systemctl status ssh
```

## UFW
```
sudo ufw allow 4242
```

## Conexión SSH
Desde el terminal del ordenador host:
```
ssh angmarti@localhost -p 4242
ssh angmarti@127.0.0.1 -p 4242
```

## Política fuerte de contraseñas

### Tiempos
- [x] La contraseña debe expirar cada 30 días
- [x] El mínimo nº de días permitido antes de modificar una contraseña debe ser 2
- [x] El usuario debe recibir un mensaje de aviso 7 días antes de la expiración

```
sudo vi /etc/login.defs
```
Editamos las lineas a:
```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
Estos cambios no se aplican automaticamente a los usuarios ya existentes, por lo que hacemos:
```
sudo chage -l    angmarti
sudo chage -l    root

sudo chage -M 30 angmarti
sudo chage -m 2  angmarti
sudo chage -W 7  angmarti

sudo chage -M 30 root
sudo chage -m 2  root
sudo chage -W 7  root

sudo chage -l    angmarti
sudo chage -l    root
``` 


### Requisitos de las contraseñas
- [x] Mínimo 10 caracteres de longitud
- [x] Una mayúscula
- [x] Un número
- [x] No tener más de 3 veces consecutivas el mismo carácter
- [x] No contener el nombre del usuario
- [x] Tener al menos 7 caracteres que no sean parte de la antigua contraseña (no aplica a root)
```
sudo apt install libpam-pwquality
sudo vi /etc/security/pwquality.conf
```
Editamos:
```
minlen = 10
ucredit = -1
dcredit = -1
maxrepeat = 3
usercheck = 1
difok = 7
retry = 3
enforce_for_root
```
Después de preparar los archivos de configuración, hay que cambiar la contraseña de todas las cuentas presentes en la máquina virtual, root incluida: ```sudo passwd <angmarti/root>```.


## Cambiar hostname
```
sudo hostnamectl set-hostname angmarti42		# ó sudo vi /etc/hostname
```
```
hostnamectl status
```


## Gestión de usuarios y grupos
Durante la defensa se deberá crear un usuario y asignarlo a un grupo.

### Usuarios
Debe de haber **al menos dos**: root y angmarti.  
Comandos:
- **useradd** : crea un nuevo usuario
- **usermod** : cambia los parámetros del usuario: -l username, -c full name, -g grupos por group ID
- **userdel -r** : elimina un usuario y sus archivos
- **id -u** : muestra user ID
- **users** : muestra una lista de todos los usuarios conectados actualmente
- **cat /etc/passwd | cut -d ":" -f 1** : muestra una lista de todos los usuarios de la máquina

### Grupos
*angmarti* debe de estar en los grupos sudo y en user42.  
Comandos:
- **groupadd** : crea un nuevo grupo.
- **gpasswd -a** : añade un usuario a un grupo.
- **gpasswd -d** : elimina a un usuario de un grupo.
- **groupdel** : borra a grupo.
- **groups** : muestra los grupos de un usuario.
- **id -g** : muestra el group ID del grupo principal del usuario.
- **getent group** : muestra una lista de todos los usuarios de un grupo.




## Script: monitoring.sh

Debe de estar desarrollado en bash.

Cuando el servidor inicie, el script mostrará cierta información (listada debajo) en todos los terminales cada 10 minutos (Échale un vistazo a wall).

El banner de wall es opcional. Ningún error debe ser visible

Tu script debe siempre mostrar la siguiente información:
- [x] La arquitectura de tu sistema operativo y su versión de kernel
- [x] El número de núcleos físicos
- [x] El número de núcleos virtuales
- [x] La memoria RAM disponible actualmente en tu servidor y su porcentaje de uso
- [x] La memoria disponible actualmente en tu servidor y su utilización como un porcentaje
- [x] El porcentaje actual de uso de tus núcleos
- [x] La fecha y hora del último reinicio
- [x] Si LVM está activo o no
- [x] El número de conexiones activas
- [x] El número de usuarios del servidor
- [x] La dirección IPv4 de tu servidor y su MAC (Media Access Control)
- [x] El número de comandos ejecutados con sudo

### Ejemplo de funcionamiento

```
Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):

	#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
	#CPU physical : 1
	#vCPU : 1
	#Memory Usage: 74/987MB (7.50 %)
	#Disk Usage: 1009/2Gb (39 %)
	#CPU load: 6.7 %
	#Last boot: 2021-04-25 14:45
	#LVM use: yes
	#Connexions TCP : 1 ESTABLISHED
	#User log: 1
	#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
	#Sudo : 42 cmd
```

### Comandos para comprobar los requisitos: 
```
uname -srvmo
nproc --all
cat /proc/cpuinfo | grep processor | wc -l
free -m
free -m | grep Mem | awk '{print $3}'
free -m | grep Mem | awk '{print $2}'
free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}'
df -m --total | grep total | awk '{print $3}'
df -m --total | grep total | awk '{print $4}'
df -m --total | grep total | awk '{print $5}'
top -bn1 | grep '^%Cpu' | cut -c 9- | awk '{printf("%.1f%%"), $1 + $3}'
who -b | awk '{print($3 " " $4)}'
if [ $(lsblk | grep lvm | wc -l) -gt 0 ]; then echo yes; else echo nope; fi
grep TCP /proc/net/sockstat | awk '{print $3}'
who | wc -l
hostname -I | awk '{print $1}'
grep COMMAND /var/log/sudo/sudolog | wc -l

head -n2 /etc/os-release
sestatus
ss -lputn
ufw status
```

### El script
```
#!/bin/bash

wall "
	#Architecture $(uname -srvmo)
	#CPU physical : $(cat /proc/cpuinfo | grep 'physical id' | wc -l)
	#vCPU : $(cat /proc/cpuinfo | grep processor | wc -l)
	#Memory Usage: $(free -m | grep Mem | awk '{print $3}')/$(free -m | grep Mem | awk '{print $2}')MB \($(free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')\)
	#Disk Usage: $(df -m --total | grep total | awk '{print $3}')/$(df -m --total | grep total | awk '{print $4}') \($(df -m --total | grep total | awk '{print $5}')\)
	#CPU load: $(top -bn1 | grep '^%Cpu' | cut -c 9- | awk '{printf("%.1f%%"), $1 + $3}')
	#Last boot: $(who -b | awk '{print($3 " " $4)}')
	#LVM use: $(if [ $(lsblk | grep lvm | wc -l) -gt 0 ]; then echo yes; else echo nope; fi)
	#Connexions TCP : $(grep TCP /proc/net/sockstat | awk '{print $3}') ESTABLISHED
	#User log: $(who | wc -l)
	#Network: IP $(hostname -I | awk '{print $1}') \($(ip link show | grep link/ether | awk '{print $2}')\)
	#Sudo : $(grep COMMAND /var/log/sudo/sudolog | wc -l) cmd
"
```

### Tarea cron
**Como root**
```
sudo systemctl enable cron
sudo crontab -u root -e
```

0 * * * * bash /root/monitoring.sh
10 * * * * bash /root/monitoring.sh
20 * * * * bash /root/monitoring.sh
30 * * * * bash /root/monitoring.sh
40 * * * * bash /root/monitoring.sh
50 * * * * bash /root/monitoring.sh