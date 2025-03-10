# get_net_line
# Objetivo general de `get_next_line`

Es implementar una función que:

1. Lea línea por línea desde un descriptor de archivo (**`fd`**) hasta alcanzar el final del archivo (**`EOF`**)o encontrar un error.
2. Devuelva cada línea como una cadena de caracteres, incluyendo el salto de línea (**`\n`**) al final de cada línea, excepto si el archivo no termina en un salto de línea.
3. Mantenga su estado entre llamadas consecutivas:
    - Gestionando los datos sobrantes de las lecturas anteriores.
    - Continuando desde donde quedó al procesar una línea.

Objetivos adicionales del bonus:

1. Desarrolla `get_next_line()` con una sola variable estática.
2. Tu `get_next_line` tiene que ser capaz de gestionar múltiples `fd` a la vez.

---

## 1. Estructura general de `get_next_line`

Para cumplir con este objetivo, `get_next_line` se dividirá en varias etapas. Esto nos permitirá mantener el código modular, legible y eficiente.

### **Prototipos de las funciones**

- **Funciones principales**
  ```c
  char *get_next_line(int fd)
  ```
    - Funcíon principal que será llamada por el usuario.
    - Gestiona el flujo general, devolviendo `line` del archivo cada vez que es llamada o `NULL` si llega al final o si hubiera algún error.
  ---
  ```c
  char *read_line(fd, read_line)
  ```
    - Se encarga de leer el `fd` hasta encontrar `\n` o `EOF`.
    - Retorna `pre_line`, que podría haber leído más bytes después del `\n`, requiriendo limpieza.
  ---
  ```c
  void clean_line(char *pre_line)
  ```
    - Limpia `pre_line`, obteniendo `line` hasta el `\n` incluido o `NULL` si llegamos a `EOF`.
  ---
  ```c
  char *update_line(char *pre_line)
  ```
    - Restablece `pre_line` recuperando los bytes leídos de la llamada anterior.
    - Retorna la línea restablecida a partir del `\n` o `NULL` si hemos llegado a `EOF` o si hubo algún error.

---

## 2. Detalle de la estructura principal

### **Estructura General del Proceso**

1. **Validación Inicial**
    - Comprobar que `fd` es válido.
    - Verificar que `BUFFER_SIZE` > 0.
    - Manejar errores previos retornando `NULL`.
2. **Gestíon de Lectura (`read_line`)**
    - Acumula datos usando `read` y los almacena en un buffer temporal.
    - Concatena datos leídos con los sobrantes previos.
    - Se detiene al encontrar `\n` o `EOF`.
3. **Limpieza de Línea (`clean_line`)**
    - Extrae solo los datos de la línea actual, incluyendo `\n` si está presente.
    - Si no hay datos, devuelve `NULL`.
4. **Actualización del Buffer (`update_buffer`)**
    - Conserva solo los datos después del `\n`.
    - Libera el buffer original si no quedan más datos.

---

## 3. Esquema de Validación y Pruebas

### **Casos de Prueba**

1. **Archivo de texto normal**
    - Leer línea por línea hasta el final.
    - Verificar que el último retorno sea `NULL`.
2. **Archivo vacío**
    - Comprobar que `get_next_line` devuelve `NULL` en la primera llamada.
3. **Entrada estándar (`stdin`)**
    - Probar leyendo desde entrada interactiva y desde un flujo redirigido.
4. **Múltiples descriptores de archivo**
    - Abrir dos archivos y alternar llamadas a `get_next_line` con diferentes `fd`.
    - Verificar que las líneas no se mezclen.

