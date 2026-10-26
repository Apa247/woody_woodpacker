open, close, exit

open(const char *pathname, int flags, mode_t mode): Abre un archivo y devuelve un descriptor de archivo. Utilizado para leer y escribir archivos.
close(int fd): Cierra un descriptor de archivo.
exit(int status): Termina el programa con un estado específico.
fputs, fflush, lseek

int fputs(const char *str, FILE *stream): Escribe una cadena en un flujo de salida.
int fflush(FILE *stream): Forza la escritura de datos del búfer hacia el archivo.
off_t lseek(int fd, off_t offset, int whence): Mueve el puntero de lectura/escritura a una posición específica en el archivo.
mmap, munmap, mprotect

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset): Mapea un archivo o dispositivo en la memoria virtual.
int munmap(void *addr, size_t length): Desmapea una región de memoria mapeada.
int mprotect(void *addr, size_t len, int prot): Cambia la protección de una región de memoria.
perror, strerror

void perror(const char *s): Imprime un mensaje de error correspondiente al valor de errno.
char *strerror(int errnum): Convierte un código de error en un mensaje de error legible.
syscall

long syscall(long number, ...): Realiza una llamada al sistema.
printf family

int printf(const char *format, ...): Imprime datos en la salida estándar.
int fprintf(FILE *stream, const char *format, ...): Imprime datos en un flujo de salida específico.
int sprintf(char *str, const char *format, ...): Escribe datos en un búfer.
int snprintf(char *str, size_t size, const char *format, ...): Escribe datos en un búfer con un tamaño límite.
libft functions

void *read(int fd, void *buf, size_t count): Lee datos desde un descriptor de archivo.
ssize_t write(int fd, const void *buf, size_t count): Escribe datos en un descriptor de archivo.
void *malloc(size_t size): Reserva memoria dinámica.
void free(void *ptr): Libera memoria dinámica.
Uso en el Proyecto Woody Woodpacker
open, close, exit
open: Usarás esto para abrir el archivo ELF de entrada que quieres empaquetar.
close: Cierra el archivo después de terminar de trabajar con él.
exit: Utilizado para finalizar el programa con un estado de éxito o error.
fputs, fflush, lseek
fputs: Puedes usarlo para imprimir mensajes de error o log.
fflush: Para asegurarte de que los datos se escriban inmediatamente en el archivo.
lseek: Para navegar dentro del archivo ELF para encontrar y manipular ciertas secciones.
mmap, munmap, mprotect
mmap: Mapea el archivo ELF en la memoria para facilitar el acceso y la manipulación.
munmap: Desmapea el archivo después de que ya no lo necesitas.
mprotect: Cambia la protección de la memoria mapeada para poder leer y escribir en ella.
perror, strerror
perror: Para imprimir mensajes de error en caso de que algo salga mal.
strerror: Para convertir códigos de error en mensajes legibles.
syscall
syscall: Puedes usarlo si necesitas realizar llamadas al sistema que no están directamente disponibles en tu implementación de C.
printf family
printf: Para imprimir mensajes en la consola.
fprintf: Para imprimir mensajes en un archivo de log.
sprintf: Para formatear cadenas antes de escribirlas.
snprintf: Para evitar desbordamientos de búfer al formatear cadenas.
libft functions
read: Para leer datos desde el archivo.
write: Para escribir datos en el archivo o en la salida estándar.
malloc: Para reservar memoria para estructuras y datos.
free: Para liberar memoria cuando ya no se necesite.