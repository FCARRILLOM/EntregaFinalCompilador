Equipo Obj7
Fernando Carrillo
Lucia Cantu-Miller

Avances:
- 08/04/21 Implementación de tokens y gramática descritos en el documento con los diagramas
- 16/04/21 Implementación de Directorio de funciones y tablas de variables. Las funciones son agregadas junto con su tipo al directorio, 
            y las variables son agregadas a las tablas de su respectivo scope junto con su tipo.
- 23/04/21 Implementación de Cubo Semántico y generación de cuádruplos para operaciones aritméticas con variables (sin tipo) y valores cte.
- 25/04/21 Generación de código para estatutos lineales (asignación, lectura, escritura)
- 30/04/21 Generación de código para estatutos condicionales (If/else, while, for)
- 08/04/21 Generación de código para declaración de funciones y llamadas a funciones. Falta calcular num de variables temporales
- 13/05/21 Se agregó el main a directorio de variables con sus variables globales y se agregó la cantidad de variables temporales utilizadas por función
- 15/05/21 Se agregó funcionalidad de mapa de memoria que asigna direcciones a variables globales y locales
- 16/05/21 Se agregó funcionalidad de mapa de memoria que asigna direcciones al resto de las variables (constantes, temporales). 
            Los cuádruplos ahora utilizan las direcciones virtuales. Se genera un archivo de código intermedio con DirFunc, Tabla Constantes, 
            Cuádruplos con direcciones virtuales.
- 18/05/21 Se agregó el administrador de memoria de la máquina virtual y función que parsea y guarda elementos del código intermedio generado por el compilador
- 19/05/21 Se agregaron instrucciones para manejar las operaciones de los cuadruplos de aritmetica, impresion y lectura
- 21/05/21 Se agregaron instrucciones de condicionales y estatutos no lineales. Tambien se agrego ejecucion de funciones simples
- 22/05/21 Se agregó funcionalidad de parámetros.
- 23/05/21 Se ajustó el manejo de memoria de la máquina virtual para manejar recursion.
- 26/05/21 Se agregó funcionalidad de declarar variables con arreglos y se guarda su dirección de memoria.


Pendiente:
- Investigar y arreglar warnings de shift/reduce reduce/reduce
- Arreglar detalle de asignación a chars se toman como ints

Cambios personales a la descripción original del proyecto
- En lugar de llamar los tipos en español 'entero, flotante', se cambiaron a inglés 'int, float'
- En lugar de declarar las variables como 'ids : tipo', se cambio el orden a 'tipo : ids'


Para correr el parser:
- Abrir la terminal y navegar al folder donde se encuentra el código
- Correr el comando 'make' para generar el ejecutable 'parser'
- Insertar un documento txt al parser corriendo el comando './parser < (tuArchivo).txt'
- Si hay un error sintáctico en el código, aparecerá un mensaje de error indicando la linea donde se encuentra este

