package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

// invierte la cadena como hola en aloh
func invertirCadena(s string) string {
	runes := []rune(s)
	i, j := 0, len(runes)-1
	for i < j {
		runes[i], runes[j] = runes[j], runes[i]
		i++
		j--
	}
	return string(runes)
}

// contar vocales y consonantes
// recibe s y devuelve total de vocales, un map con el total de veces que aparece cada vocal y el total de consonantes
func vocalesYconsonantes(s string) (int, map[rune]int, int) {
	vocales := "aeiouAEIOU"
	contadorVocales := 0
	contadorConsonantes := 0
	mapaVocales := map[rune]int{}

	//la r representa cada caracter en en la cadena s
	for _, r := range s {
		if !unicode.IsLetter(r) {
			continue
		}

		if strings.ContainsRune(vocales, r) {
			contadorVocales++
			mapaVocales[unicode.ToLower(r)]++
		} else {
			contadorConsonantes++
		}
	}
	return contadorVocales, mapaVocales, contadorConsonantes
}

func quitarGuiones(s string) string {
	runes := []rune(s)
	for i := 0; i < len(runes); i++ {
		if runes[i] == ' ' {
			runes[i] = '_'
		}
	}
	return string(runes)
}

func main() {
	var input string

	// Si se pasa un argumento (argv[1]), lo usamos; de lo contrario, leemos desde el teclado.
	if len(os.Args) > 1 {
		input = os.Args[1]
	} else {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print("Ingresa una cadena (máx. 100 caracteres): ")
		tmp, _ := reader.ReadString('\n')
		input = strings.TrimSpace(tmp)
	}

	// Si la cadena es mayor a 100 caracteres, se trunca.
	if len(input) > 100 {
		input = input[:100]
	}

	// Obtener resultados
	invertida := invertirCadena(input)
	vocalesTotales, mapaVocales, consonantesTotales := vocalesYconsonantes(input)
	modificada := quitarGuiones(input)

	// Construir una salida en una sola línea.
	salida := fmt.Sprintf("Cadena invertida: %s | ", invertida)
	salida += fmt.Sprintf("Vocales totales: %d (", vocalesTotales)
	for k, val := range mapaVocales {
		salida += fmt.Sprintf("'%c': %d, ", k, val)
	}
	// Eliminar la coma y espacio de más, si existe.
	salida = strings.TrimRight(salida, ", ")
	salida += fmt.Sprintf(") | Consonantes totales: %d | ", consonantesTotales)
	salida += fmt.Sprintf("Cadena con espacios reemplazados: %s", modificada)

	fmt.Println(salida)
}
