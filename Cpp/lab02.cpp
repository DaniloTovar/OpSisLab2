#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Verifica si un carácter es alfabético (mayúscula o minúscula).
 *
 * Esta función recibe un carácter y determina si es una letra del alfabeto,
 * ya sea en su forma mayúscula o minúscula. La función devuelve `true` si el carácter
 * es una letra (de 'A' a 'Z' o de 'a' a 'z'), y `false` en caso contrario.
 *
 * @param c El carácter a verificar.
 * @return `true` si el carácter es alfabético, `false` si no lo es.
 *
 * @example
 * bool result = isAlphabetic('A');  // result será true
 * bool result = isAlphabetic('z');  // result será true
 * bool result = isAlphabetic('1');  // result será false
 * bool result = isAlphabetic('_');  // result será false
 */
bool isAlphabetic(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/**
 * @brief Elimina los caracteres no alfabéticos de una cadena.
 *
 * Esta función recorre una cadena de caracteres y elimina todos aquellos que no sean
 * alfabéticos (mayúsculas o minúsculas), guiones bajos ('_') o espacios (' '). Los
 * caracteres válidos se mueven al principio de la cadena, sobrescribiendo los caracteres no válidos.
 * Al final, la cadena resultante se termina con el carácter nulo ('\0').
 *
 * @param str La cadena de caracteres a limpiar.
 *
 * @example
 * char str[] = "Hello! World_ 123";
 * clean(str);
 * // Después de la ejecución, la cadena "str" será "Hello World_"
 */
void clean(char* str) {
    char* writePtr = str; // Puntero para escribir los caracteres válidos
    char* readPtr = str;  // Puntero para leer cada carácter
    
    while (*readPtr != '\0') {
        // Si el carácter es alfabético o un guion bajo, escríbelo en writePtr
        if (isAlphabetic(*readPtr) || *readPtr == '_' || *readPtr == ' ') {
            *writePtr = *readPtr; 
            writePtr++; // Mueve el puntero de escritura hacia adelante
        } 
        // Mueve el puntero de lectura hacia adelante
        readPtr++;
    }

    // Añade el carácter nulo para terminar la cadena
    *writePtr = '\0';
}

/**
 * @brief Reemplaza los espacios por guiones bajos en una cadena.
 *
 * Esta función recorre una cadena de caracteres y reemplaza cada espacio (' ') por un guion bajo ('_').
 * La modificación se realiza directamente sobre la cadena original, y no se crea una nueva cadena.
 *
 * @param str La cadena de caracteres en la que se van a reemplazar los espacios.
 *
 * @example
 * char str[] = "Hello World";
 * replaceSpacesWithUnderscores(str);
 * // Después de la ejecución, la cadena "str" será "Hello_World"
 */
void replaceSpacesWithUnderscores(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {  
            *str = '_';  
        }
        str++;  
    }
}



/**
 * @brief Obtiene la longitud de una cadena de caracteres.
 *
 * Esta función recorre una cadena de caracteres y cuenta cuántos caracteres hay
 * hasta encontrar el carácter nulo ('\0'), que indica el final de la cadena.
 * Devuelve la cantidad de caracteres en la cadena, excluyendo el carácter nulo.
 *
 * @param str La cadena de caracteres de la cual se desea obtener la longitud.
 * @return La longitud de la cadena, excluyendo el carácter nulo ('\0').
 *
 * @example
 * const char* str = "Hello World";
 * int length = getStringLength(str);
 * // Después de la ejecución, 'length' será 11
 */
int getStringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {  
        length++;  
    }
    return length;  
}



/**
 * @brief Invierte los caracteres de una cadena.
 *
 * Esta función toma una cadena de caracteres y la invierte en su lugar, es decir,
 * los caracteres se reordenan de tal forma que el primero pasa a ser el último,
 * el segundo pasa a ser el penúltimo, y así sucesivamente.
 * La inversión se realiza intercambiando los caracteres desde los extremos de la cadena hacia el centro.
 *
 * @param str La cadena de caracteres que se va a invertir.
 *
 * @example
 * char str[] = "Hello";
 * reverseString(str);
 * // Después de la ejecución, la cadena "str" será "olleH"
 */
void reverseString(char* str) {
    int str_size = getStringLength(str); 

    // Dividir el tamaño de la cadena para obtener el número de permutaciones
    int n_swaps = (int) str_size / 2;  

    char* first_ptr = str;
    char* last_ptr = &str[str_size - 1];

    char aux;
    while (n_swaps > 0) {
        aux = *first_ptr;
        *first_ptr = *last_ptr;
        *last_ptr = aux;
        first_ptr++;  // Mueve el puntero del primer carácter hacia adelante
        last_ptr--;   // Mueve el puntero del último carácter hacia atrás
        n_swaps--;    // Disminuye el número de permutaciones restantes
    }
}

/**
 * @brief Verifica si un carácter es una vocal.
 *
 * Esta función recibe un carácter y verifica si es una vocal (mayúscula o minúscula).
 * Utiliza una cadena estática que contiene todas las vocales y recorre la cadena con un puntero
 * para verificar si el carácter ingresado coincide con alguna de las vocales.
 *
 * @param c El carácter que se va a verificar.
 * @return `true` si el carácter es una vocal, de lo contrario, `false`.
 *
 * @example
 * char letter = 'a';
 * bool result = isVowel(&letter);
 * // En este caso, 'result' será true porque 'a' es una vocal.
 */
bool isVowel(const char* c) {
    // Cadena de caracteres que contiene las vocales
    // La keyword static hace que la variable vowels se inicialice una sola vez 
    // cada vez que se llame a esta función :)
    static const char vowels[] = "aeiouAEIOU";  
    const char* ptr = vowels;

    while (*ptr != '\0') {  
        if (*ptr == *c) {  
            return true;  
        }
        ptr++;  
    }
    
    // Si no encontró una vocal
    return false;  
}

/**
 * @brief Estructura para almacenar datos sobre una cadena de caracteres.
 *
 * Esta estructura de datos se utiliza para almacenar el conteo de las vocales (mayúsculas y minúsculas),
 * el total de vocales, el total de guiones bajos y el total de consonantes presentes en una cadena de caracteres.
 * Se utiliza un `unordered_map` para contar las vocales específicas, y también mantiene los totales generales de
 * vocales, guiones bajos y consonantes.
 */
struct CharData {
    // Un hash map para contar las vocales (tanto mayúsculas como minúsculas)
    unordered_map<char, int> vowelCount;

    // Total de vocales
    int totalVowels = 0;

    // Total de guiones bajos
    int totalUnderscores = 0;

    // Total de Consonantes
    int totalConsonants = 0;
};


/**
 * @brief Cuenta las vocales, consonantes y guiones bajos en una cadena de caracteres.
 *
 * Esta función recibe una cadena de caracteres y recorre cada uno de los caracteres para contar
 * la cantidad de vocales, consonantes y guiones bajos que contiene. Utiliza la función `isVowel`
 * para verificar si un carácter es una vocal, y un contador para llevar un registro de los
 * guiones bajos y consonantes. Los resultados se almacenan en una estructura `CharData`, que
 * contiene un mapa de frecuencias de las vocales, así como el total de vocales, guiones bajos y
 * consonantes encontrados.
 *
 * @param arr La cadena de caracteres que se va a analizar.
 * @return Devuelve una estructura `CharData` que contiene el conteo de vocales, consonantes y guiones bajos.
 *
 * @note El conteo de vocales distingue entre mayúsculas y minúsculas, ya que se cuenta cada
 * vocal individualmente.
 */
CharData countChars(char* arr) {
    CharData result;  // Estructura para almacenar los resultados

    while (*arr != '\0') {
        if (isVowel(arr)) {  // Si es una vocal, la contamos
            result.vowelCount[*arr]++;  // Aumenta el conteo de la vocal
            result.totalVowels++;  // Aumenta el total de vocales
        } 
        else if (*arr == '_') {  // Si es un guion bajo, lo contamos
            result.totalUnderscores++;
        }
        else { // Todo lo demás es una consonante
            result.totalConsonants++;
        }

        arr++;  
    }

    return result; 
}


int main(int argc, char* argv[]) {

    // Verifica si se pasa exactamente un argumento (además del nombre del programa)
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <your_string>" << endl;
        return 1;  
    }

    char* input = argv[1];
    CharData charData; // estructura para el conteo de los caracteres
    cout << "Original String: " << input << endl;

    clean(input);

    reverseString(input);
    cout << "Reversed String: " << input << endl;

    replaceSpacesWithUnderscores(input);

    // Obtenemos la información del conteo de los caracteres del string
    charData = countChars(input);
    
    cout << "Number of vowels: " << charData.totalVowels << endl;

    // Imprime el par vocal : cantidad de esa vocal en la cadena
    for (const auto& pair : charData.vowelCount) {
        cout << "Number of '" << pair.first << "': " << pair.second << endl;
    }

    cout << "Number of consonants: " << charData.totalConsonants << endl;

    cout << "Modified String: " << input << endl;

    return 0;
}
