# Cifrado-de-Hill
Este repositorio contiene la implementación y análisis del Cifrado de Hill, un sistema de criptografía poligráfica inventado en 1929 por el matemático Lester S. Hill. El proyecto desarrolla la teoría matemática detrás del cifrado, utilizando álgebra lineal, aritmética modular y matrices para la codificación y decodificación de mensajes.

Tipos de descifrados:

-Know Plaintext Attack:
Con n² pares (plano, cifrado) se resuelve el sistema lineal y se recupera la llave matriz. Este proceso, especialemente para orden 2, bastan 4 pares de letras. Tiene una complejidad de O(n³)
-Brute Force Attack:
Este ataque intenta probar todas las matrices invertibles mod 26 con el el fin de encontrar la llave matriz. Sin embargo, su complejidad algoritmica crece exponencialmente para ordenes de matrices n>3 O(26^(n^2)).

-Quatium computer:
Esta simulacion se requere otro tipo de lenguaje, ademas hay una manera sencilla de hacerlo graficamente y es con el simulacion de IBM composer. 

Por si te interesa mas de esto, puedes darle clik al siguiente enlace:
.........................