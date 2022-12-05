# Practicas_Arquitectura_De_Computadores

Práctica 1 - Ejercicio 1

Implementar un programa usando MPI, que imprima por salida estándar:
  “Hola mundo, soy el proceso X de un total de Y.”
cuando el número total de tareas es Y y X un rango de 0 a Y-1.

Calcular el tiempo de ejecución de cada proceso (desde que se inicia hasta que termina de
imprimir “Hola mundo…”) cuando hay 1, 20 y 50 procesos.

Práctica 3 - Ejercicio 2

Implementar un programa donde el nodo 0 inicializa un array unidimensional asignando a cada
valor su índice. Este array es dividido en partes, donde cada una de ellas será mandada a un
proceso/nodo diferente. Después de que cada nodo haya recibido su porción de datos, los
actualiza sumando a cada valor su rank. Por último, cada proceso envía su porción modificada
al proceso root.
(Hacerlo para que el número de datos total (N) sea múltiplo del número de procesos).
