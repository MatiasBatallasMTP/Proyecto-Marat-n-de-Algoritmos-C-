// Ejercicio teórico / esquema simple
// FFT transforma una secuencia de números (señal en tiempo) a su representación en frecuencias.
// Idea: divide y vencerás
//   - Divide la secuencia en pares: índices pares e impares
//   - Calcula FFT de cada mitad recursivamente
//   - Combina usando raíces de la unidad (complejos)
// Esto permite calcular la DFT en O(n log n) en lugar de O(n^2).
