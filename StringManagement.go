package main

import (
    "fmt"
    "os"
    "io/ioutil"
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
	    case 'A', 'Á', 'á':
		char = 'a'
	    case 'I', 'Í', 'í':
		char = 'i'
	    case 'U', 'Ú', 'ú':
		char = 'u'
	    case 'E', 'É', 'é':
		char = 'e'
	    case 'O', 'Ó', 'ó':
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

func main(){
    // Verificar que se ingresen la cantidad correcta de argumentos
    if (len(os.Args) > 2){
	fmt.Println("Error: Se ingresaron mas argumentos de los requeridos")
	os.Exit(1)
    }

    // Obtener el input del usuario
    varg := os.Args[1]

    // If argument its a file, read the file content
    var input string
    content, err := ioutil.ReadFile(varg)
    if (err == nil) {
	input = string(content)
    } else{
	input = varg
    }

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
	fmt.Printf("Error: La longitud de la entrada ingresada (%d) supera el limite de caracteres.",length)
    } else if (length <= 0){
	fmt.Println("Error: La entrada ingresada no puede estar vacia.")
    } else{


    // Ejecutar las funciones
    // Invertir la cadena en su lugar
    flipStringWithPointer(&processedInput)
    fmt.Print(string(processedInput))

    // Contar el numero de vocales y consonantes
    vowels, numPerVow, consonants := getVowelsAndConsonants(processedInput)
    fmt.Print(" ", vowels)

    orderedVowels := []rune{'a','e','i','o','u'}
    for _,char := range(orderedVowels) {
	value := numPerVow[char]
	if (value != 0){
	    fmt.Print(" ", value)
	}
    }

    fmt.Print(" ", consonants)


    // Reemplazar espacios por barra baja
    replaceSpacesInPlace(&processedInput)
    fmt.Print(" ", string(processedInput))
    }
}
