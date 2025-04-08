package main

import (
    "fmt"
    "bufio"
    "os"
)

// Funcion para invertir un string in-place
func flipStringWithPointer(s *[]rune) {
    for i, j := 0, len(*s)-1; i < j; i, j = i+1, j-1 {
        (*s)[i], (*s)[j] = (*s)[j], (*s)[i]
    }
}

// Funcion para obtener las vocales y las consonantes
func getVowelsAndConsonants(s []rune) (int, map[rune]int, int){
    numPerVowel := make(map[rune]int)
    vowels, consonants := 0, 0

    for _, char := range s {
	switch char{
	    case 'A':
		char = 'a'
	    case 'I':
		char = 'i'
	    case 'U':
		char = 'u'
	    case 'E':
		char = 'e'
	    case 'O':
		char = 'o'
	}
	switch char{
	    case 'a','i','u','e','o':
		vowels++
		numPerVowel[char]++
	    case ' ':
		continue
	    default:
		consonants++
	}
    }

    return vowels, numPerVowel, consonants
}

// Funcion para saber si un caracter es una vocal
func isAlphabet(c rune) bool{
    alphabetMayus := rune(65)
    alphabetMinus := rune(97)
    mayus := c - alphabetMayus
    minus := c - alphabetMinus
    space := c - rune(32)
    if (mayus <= 25 && mayus >= 0) || (minus <= 25 && minus >= 0) || (space == 0){
	return true
    }
    return false
}

// Funcion para reemplazar los espacios
func replaceSpacesInPlace(s *[]rune) {
    for i := range *s{
	if (*s)[i] == ' ' {
	    (*s)[i] = '_'
	}
    }
}

func main() {
    // Obtener el input del usuario
    var reader = bufio.NewReader(os.Stdin)
    fmt.Print("Ingresa una palabra o frase (No superar 100 caracteres): ")
    input, _ := reader.ReadString('\n')

    // Procesar el input para eliminar numeros y caracteres especiales
    processedInput := []rune{}
    for _, char := range input{
	if isAlphabet(char){
	    processedInput = append(processedInput, char)
	}
    }

    // Verificar que el input cumpla con la logitud maxima
    var length = len(processedInput)
    if (length > 100){
	fmt.Printf("La longitud de la entrada ingresada (%d) supera el limite de caracteres.",length)
    } else if (length <= 0){
	fmt.Println("La entrada ingresada no puede estar vacia.")
    } else{


    // Ejecutar las funciones
    // Invertir la cadena en su lugar
    flipStringWithPointer(&processedInput)
    fmt.Println("\nString invertido:")
    fmt.Println(string(processedInput))

    // Contar el numero de vocales y consonantes
    vowels, numPerVow, consonants := getVowelsAndConsonants(processedInput)
    fmt.Println("\nNumero de vocales:", vowels)
    for vowel, num := range numPerVow {
	fmt.Printf("Numero de '%c': %d\n", vowel, num)
    }
    fmt.Println("\nNumero de consonantes:", consonants)


    // Reemplazar espacios por barra baja
    replaceSpacesInPlace(&processedInput)
    fmt.Println("\nString modificado:")
    fmt.Println(string(processedInput),"\n")
    }
}
