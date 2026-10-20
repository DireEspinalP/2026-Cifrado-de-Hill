# Hill vs. Grover: del álgebra lineal a la era post-cuántica
Este repositorio contiene la implementación y análisis del Cifrado de Hill, un sistema de  `criptografía poligráfica` inventado en 1929 por el matemático **Lester S. Hill**. El proyecto desarrolla la teoría matemática detrás del cifrado, utilizando álgebra lineal, patrones conocidos, fuerza bruta y un algoritmo cuantico (Grover) para descifrar dicho mensaje.

---

## Tipos de descifrados:

-  `Know Plaintext Attack `
Con n² pares (plano, cifrado) se resuelve el sistema lineal y se recupera la llave matriz. Este proceso, especialemente para orden 2, bastan 4 pares de letras. Tiene una complejidad de O(n³)

-  `Brute Force Attack `
Este ataque intenta probar todas las matrices invertibles mod 26 con el el fin de encontrar la llave matriz. Sin embargo, su complejidad algoritmica crece exponencialmente para ordenes de matrices n>3 O(26^(n^2)).

-  `Algoritmo Grover`
Esta simulacion se requere otro tipo de lenguaje (Qiskit/ OpenQASM), reduce la cantidad de interacciones de una fuerza bruta y la complejidad algorítmica de O(N) hasta O(√N) 

Por si te interesa mas de esto, puedes darle clik a los  siguientes enlaces:

---

| Modo visual | Link |
|---|---|
|Sitio web|  https://direespinalp.github.io/2026-Cifrado-de-Hill/|
|Resumen| https://direespinalp.github.io/2026-Cifrado-de-Hill/summary_document.pdf 
|Documento completo |https://direespinalp.github.io/2026-Cifrado-de-Hill/documento_completo.pdf|

# Agradecimiento
- Leonel Mathias Puente Rojas (Matematico)
- Luis Pareja Gavilan (Ciencia de la computacion)
- Rodrigo Cordova Bedon (Ciencia de la computacion)

Los quiero muchachos :)

# Referencias

1. Hill, L. S. (1929). Cryptography in an Algebraic Alphabet. *The American Mathematical Monthly, 36*(5), 306–312. [https://doi.org/10.2307/2299749](https://doi.org/10.2307/2299749)

2. Anton, H., y Rorres, C. (2014). *Elementary Linear Algebra: Applications Version* (11th ed.). Wiley.

3. Dooley, J. (1 de enero de 2018). "10.1 The Shoulders of Giants: Friedman, Hill, and Shannon". En *History of Cryptography and Cryptanalysis: Codes, Ciphers, and Their Algorithms*. Springer. p. 167. ISBN 978-3-319-90442-9 – vía Google Books.

4. Hill, L. S. (1931). Concerning Certain Linear Transformation Apparatus of Cryptography. *The American Mathematical Monthly, 38*, 135–154.

5. Stallings, W. (2017). *Cryptography and Network Security: Principles and Practice* (7th ed.). Pearson, pp. 86–107.

6. Singh, S. (1999). *The Code Book: The Science of Secrecy from Ancient Egypt to Quantum Cryptography*. Anchor Books.

7. Ibáñez, R. (11 de enero de 2017). *Cuaderno de Cultura Científica*. [https://culturacientifica.com/2017/01/11/criptogmatrices-cifrado-hill/](https://culturacientifica.com/2017/01/11/criptogmatrices-cifrado-hill/)

8. Jacques-García, F. A., Uribe-Mejía, D., Macías-Bobadilla, G., y Chaparro-Sánchez, R. (2022). *On modular inverse matrices a computation*.

9. IBM. (s. f.). *¿Qué es un qubit?* [https://www.ibm.com/es-es/think/topics/qubit](https://www.ibm.com/es-es/think/topics/qubit)

10. Wong, T. G. (2022). *Introduction to Classical and Quantum Computing*, pp. 299–303.

11. Nielsen, M. A., y Chuang, I. L. (2010). *Quantum Computation and Quantum Information* (10th anniversary ed.), pp. 13–20.

12. Sipser, M. (2012). *Introduction to the Theory of Computation* (3rd ed.). Cengage Learning.
