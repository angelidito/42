# Born2beroot

## Debian Vs CentoOS


### Diferencias


### Aptitude y apt


### SELinux y AppArmor


### Uso de SSH para crear un nuevo usuario


### Asignar un usuario a un grupo


### Modo TTY

### Diretorios de sudo
- /usr/local/sbin
- /usr/local/bin
- /usr/sbin
- /usr/bin
- /sbin
- /bin
- /snap/bin


### Política fuerte de contraseñas

- [ ] La contraseña debe expirar cada 30 días
- [ ] El mínimo nº de días permitido antes de modificar una contraseña debe ser 2
- [ ] El usuario debe recibir un mensaje de aviso 7 días antes de la expiración
- [ ] Requisitos de las contraseñas:
  - [ ] Mínimo 10 caracteres de longitud
  - [ ] Una mayúscula
  - [ ] Un número
  - [ ] No tener más de 3 veces consecutivas el mismo carácter
  - [ ] No contener el nombre del usuario
  - [ ] Tener al menos 7 caracteres que no sean parte de la antigua contraseña 
(no aplica a root)


## Debian

Se recomienda encarecidamente si no se tiene experiencia en administración de 
sistemas...
- [ ] AppArmor debe ejecutarse al inciar


## CentoOS

- [ ] Configurar CentOS es bastante complejo. Por lo tanto, no hay que
configurar KDump
- [ ] SELinux debe ejecutarse al iniciar y su configuración debe 
adaptarse a las necesidades del proyecto
- [ ] (¿) AppArmor debe ejecutarse al inciar (?)


## El Proyecto

### Tareas generales
- [ ] Crear al menos 2 particiones cifradas usando LVM
- [ ] Ejecutar el servicio SSH sólamente en el puerto 4242
- [ ] No debe ser posible conectarte a través de SSH como root
- [ ] Configurar el SO con el firewall UFW dejando abierto solamente el puerto 4242
- [ ] Política de contraseñas fuerte
- [ ] Instalar y configurar sudo siguiendo reglas estrictas
- [ ] Crear usuario con angmarti como nombre
  - [ ] Debe pertenecer a los grupos user42 y sudo

### Para el grupo *sudo*
- [ ] Autenticarse con sudo debe limitado a tres intentos fallidos de introducir 
la contraseña
- [ ] Mostrar mensaje personalizado en caso de contraseña introducida incorrecta 
al utilizar sudo
- [ ] Para cada comando ejecutado con sudo, tanto el **input** como el **output** 
deben quedar archivados en el directorio **/var/log/sudo/**
- [ ] El modo TTY debe estar activado por razones de seguridad
- [ ] Por seguridad, los directorios utilizables por sudo deben estar restringidos.
Por ejemplo:  
**/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin**


### Script: monitoring.sh

Debe de estar desarrollado en bash.

Cuando el servidor inicie, el script mostrará cierta información (listada debajo) 
en todos los terminales cada 10 minutos (Échale un vistazo a wall).

El banner de wall es opcional. Ningún error debe ser visible

Tu script debe siempre mostrar la siguiente información:
- [ ] La arquitectura de tu sistema operativo y su versión de kernel
- [ ] El número de núcleos físicos
- [ ] El número de núcleos virtuales
- [ ] La memoria RAM disponible actualmente en tu servidor y su porcentaje de uso
- [ ] La memoria disponible actualmente en tu servidor y su utilización como 
  un porcentaje
- [ ] El porcentaje actual de uso de tus núcleos
- [ ] La fecha y hora del último reinicio
- [ ] Si LVM está activo o no
- [ ] El número de conexiones activas
- [ ] El número de usuarios del servidor
- [ ] La dirección IPv4 de tu servidor y su MAC (Media Access Control)
- [ ] El número de comandos ejecutados con sudo

Ejemplo de funcionamiento

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

Caomando utilizable para comprobar algunos requisitos del subject:
> head -n2 /etc/os-release

