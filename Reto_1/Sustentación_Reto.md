# Explicación del análisis del problema:

### Ingresar el nombre del archivo a leer.

El enunciado del reto nos pedía implementar un programa que leyera un archivo de texto .txt cuyo nombre debía ser ingresado por el usuario. El contenido del archivo debía almacenarse en un arreglo de caracteres utilizando memoria dinámica, lo que implica que no podíamos definir un arreglo con un tamaño fijo, sino que teníamos que reservar memoria en tiempo de ejecución de acuerdo con el tamaño real del archivo.

Para resolverlo, primero entendimos que el programa necesitaba tres pasos principales:

Solicitar al usuario el nombre del archivo.

Abrir el archivo en modo lectura y validar que se haya abierto correctamente.

Leer su contenido y almacenarlo en un arreglo dinámico.

Tomé la decisión de usar fopen() para abrir el archivo, malloc() para asignar memoria dinámicamente, y funciones como fgets() para leer su contenido. También consideramos necesario liberar la memoria con free() al final.

### Calcular estadísticas del texto:

En esta parte del reto se nos pidió calcular diferentes estadísticas sobre el contenido de un archivo de texto. Específicamente:

El total de caracteres (con opción de excluir los saltos de línea).

El total de palabras, considerando como separadores los espacios.

El total de espacios en blanco, incluyendo tabulaciones y saltos de línea.

El total de líneas.

Para resolver este problema, primero pensamos en la mejor manera de recorrer el archivo carácter por carácter, lo cual se logró utilizando la función fgetc(). Esto nos permitió tener un control completo sobre cada símbolo leído.

Tomamos la decisión de preguntar al usuario si deseaba contar los saltos de línea (\n) como parte del total de caracteres. Dependiendo de la respuesta, el contador totalCaracteres se incrementa con o sin considerar esos saltos.

Para contar las palabras, decidimos sumar una palabra cada vez que encontramos un separador (espacio, tabulación o salto de línea).

Los espacios en blanco se contaron sumando los caracteres ' ', '\t' y '\n'. 

Para contar las líneas, simplemente se incrementó un contador cada vez que se detectaba un '\n'.

Finalmente, juntamos toda la presentación de las estadísticas en una función menu() para mostrar al usuario de forma anticipada qué datos se van a calcular.

### Calcular la frecuencia de aparición de las vocales (a, e, i, o, u)

En este tercer punto del reto, se nos pidió calcular la frecuencia de aparición de las vocales (a, e, i, o, u), considerando tanto mayúsculas como minúsculas como equivalentes. Es decir, se debía contar cuántas veces aparece cada vocal en el archivo, sin distinguir entre 'a' y 'A'.

Para resolver este problema, primero se solicitó al usuario el nombre del archivo a analizar. Se usó la función fopen() en modo lectura para abrir el archivo, y se verificó que se abriera correctamente.

Una vez abierto el archivo, se utilizó la función fgetc() para leer el texto carácter por carácter. Por cada carácter leído, se verificó si coincidía con alguna de las vocales, en cualquiera de sus dos formas (minúscula o mayúscula), usando una serie de estructuras if. Cada vez que se encontraba una coincidencia, se incrementaba el contador correspondiente (total_A, total_E, etc.).

Al finalizar la lectura, se cerró el archivo y se imprimieron los resultados de las vocales encontradas.

### Cambiar una palabra del texto por otra (find & replace):

En este cuarto punto, el reto consistió en implementar una funcionalidad que permitiera buscar y reemplazar una palabra dentro del texto leído desde un archivo. El usuario debía ingresar una palabra a buscar y otra con la cual reemplazarla, realizando el cambio en todo el contenido.

Para resolver esto, entendimos que era necesario leer el texto completo y almacenarlo en memoria dinámica para poder manipularlo libremente, ya que el tamaño del texto podría variar y la palabra reemplazo podría ser de diferente longitud a la original.

Decidí implementar una función llamada reemplazar_palabra que recibe el texto completo, la palabra original y la palabra nueva. Primero, la función recorre el texto para contar cuántas veces aparece la palabra original, esto permite calcular el tamaño exacto que tendrá el nuevo texto tras el reemplazo.

Luego, se reserva memoria dinámica para almacenar el nuevo texto, teniendo en cuenta la diferencia de tamaño que puede haber entre las palabras original y nueva.

Finalmente, la función recorre el texto original y copia carácter por carácter al nuevo texto, haciendo la sustitución cuando encuentra la palabra buscada. Esta operación garantiza que todas las apariciones se reemplacen correctamente.

Para manejar el archivo, se usa fseek y ftell para conocer el tamaño total y así reservar memoria dinámica adecuada. El texto se carga usando fread y se termina con un caracter nulo para facilitar su manipulación como cadena.

### Guardar los resultados en un nuevo archivo:

El último requerimiento consistió en guardar en un archivo de salida toda la información generada: las estadísticas del texto, la frecuencia de vocales y el texto modificado (si hubo reemplazos).

Para lograrlo, primero decidí implementar funciones separadas para calcular las estadísticas del texto y la frecuencia de vocales, lo que permite una mejor organización y reutilización del código. Estas funciones toman el texto como entrada y devuelven los conteos necesarios mediante punteros.

Luego, en el main, se simula que ya se tiene el texto modificado (resultado de la parte anterior), y se calculan las estadísticas y frecuencias usando esas funciones.

Después, se pide al usuario el nombre del archivo donde desea guardar estos resultados. Se abre ese archivo en modo escritura, y con fprintf se van escribiendo las estadísticas, la frecuencia de vocales y finalmente el texto modificado.

El programa incluye validación para asegurar que el archivo se creó correctamente y muestra un mensaje de confirmación al final.


# Estrategia de solución:

El programa está diseñado con una estructura modular que facilita la interacción y el procesamiento de texto mediante un menú principal controlado desde la función main. El menú, mostrado por la función menu, permite al usuario seleccionar diferentes opciones, como calcular estadísticas, contar vocales, reemplazar palabras o guardar resultados. La función principal coordina la ejecución llamando a funciones específicas según la opción elegida. Por ejemplo, para el reemplazo de palabras, se utiliza la función reemplazarPalabra, que recibe el texto original y las palabras a buscar y reemplazar, devolviendo un nuevo texto modificado. Durante la programación, la idea fue inicialmente desarrollar el código en archivos separados para facilitar la corrección de errores y las pruebas por módulo. Sin embargo, al final se optó por consolidar todas las funciones en un solo archivo y definirlas con tipo void cuando correspondía, para simplificar la integración y la ejecución general. Esta organización modular, aun cuando se integró en un solo archivo, permite mantener el código claro, facilitar futuras ampliaciones y aislar responsabilidades, haciendo que cada función tenga un propósito específico y bien definido dentro del flujo general del programa.

# Tabla de variables:

| **Componente**         | **Función / Módulo**              | **Propósito**                                                 |
| ---------------------- | --------------------------------- | ------------------------------------------------------------- |
| `main`                 | Función principal                 | Controla el flujo general del programa y el menú de opciones. |
| `menu`                 | Función para mostrar opciones     | Muestra al usuario las opciones para analizar el texto.       |
| `leerArchivo`          | Lectura de archivo de texto       | Abre y carga el contenido del archivo en memoria.             |
| `calcularEstadisticas` | Cálculo de estadísticas generales | Analiza datos básicos del texto, como cantidad de palabras.   |
| `frecuenciaVocales`    | Conteo de vocales                 | Cuenta cuántas veces aparece cada vocal en el texto.          |
| `reemplazarPalabra`    | Reemplazo de palabras             | Cambia todas las apariciones de una palabra por otra.         |
| `guardarArchivo`       | Escritura de archivo              | Guarda los resultados o texto modificado en un nuevo archivo. |

# Diagramas, esquemas o pseudocódigo:

A continuacion se mostrara cada uno de los psudocodigos de las funciones:

### Parte 1:

    Inicio
    Repetir
        Mostrar menú
        Leer opción del usuario

        Si opción == 1
            Llamar función calcularEstadisticas()
        Sino si opción == 2
            Llamar función frecuenciaVocales()
        Sino si opción == 3
            Llamar función cambiarPalabraEnArchivo()
        Sino si opción == 4
            Llamar función guardarResultados()
        Sino si opción == 5
            Mostrar mensaje de salida
        Sino
            Mostrar "Opción no válida"
    Hasta que opción == 5
    Fin

### Parte 2:

    Inicio
    Pedir al usuario el nombre del archivo
    Abrir archivo en modo lectura
    Si el archivo no se abre correctamente
        Mostrar mensaje de error
        Terminar proceso
    Fin si

    Mover el cursor al final del archivo para obtener tamaño
    Guardar tamaño del archivo
    Volver al inicio del archivo

    Reservar memoria para almacenar contenido (tamaño + 1 para '\0')
    Si no se puede reservar memoria
        Mostrar mensaje de error
        Cerrar archivo
        Terminar proceso
    Fin si

    Leer todo el contenido del archivo en la memoria reservada
    Añadir caracter nulo al final para terminar la cadena

    Mostrar contenido leído

    Liberar memoria
    Cerrar archivo
    Fin

### Parte 3:

    Inicio
    Mostrar menú explicando qué se calculará

    Preguntar si incluir saltos de línea en el conteo de caracteres (1 = sí, 2 = no)
    Pedir nombre del archivo

    Abrir archivo en modo lectura
    Si no se puede abrir
        Mostrar error
        Terminar proceso
    Fin si

    Inicializar totalCaracteres, totalPalabras, totalEspacios, totalLineas en 0

    Mientras no se llegue al final del archivo
        Leer un carácter

        Si se incluye salto de línea en conteo
            Incrementar totalCaracteres
        Sino
            Si el carácter no es salto de línea
                Incrementar totalCaracteres
            Fin si
        Fin si

        Si el carácter es espacio, tabulación o salto de línea
            Incrementar totalEspacios
            Incrementar totalPalabras
        Fin si

        Si el carácter es salto de línea
            Incrementar totalLineas
        Fin si
    Fin mientras

    Cerrar archivo

    Mostrar los totales calculados: caracteres, palabras, espacios y líneas
    Fin



