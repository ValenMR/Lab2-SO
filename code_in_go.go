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
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Ingresa una cadena (máx. 100 caracteres): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	if len(input) > 100 {
		input = input[:100]
	}

	//resultados de cadena invertida
	invertida := invertirCadena(input)
	fmt.Println("Cadena invertida:", invertida)

	//resultados del conteo de vocales y consonantes
	v, mapaVocales, c := vocalesYconsonantes(input)
	fmt.Printf("Vocales: %d\n", v)
	for k, val := range mapaVocales {
		fmt.Printf("'%c': %d veces\n", k, val)
	}
	fmt.Printf("Consonantes: %d\n", c)

	//resultado de quitar los guiones
	modificada := quitarGuiones(input)
	fmt.Println("Cadena con espacios reemplazados:", modificada)
}
