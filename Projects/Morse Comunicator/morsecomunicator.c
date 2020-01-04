#include <stdio.h>
#include <string.h>

char* getMorseCodeFromCharacter(char character);
char* getMorseCodeFromSymbol(char *symbol);
void transmitMorseCode(int prependCharSeparationFlag, char *morseCode);
void transmitMorseWordSeparation();

int main() {

    char *message = "Hello World!";
    char *currentCharacter;
    char *morseCode;

    currentCharacter = message;
    printf("\n%s\n", message);

    int prependCharSeparation = 0;
    while (*currentCharacter)
    {
        if(*currentCharacter != ' ') {
            morseCode = getMorseCodeFromCharacter(*currentCharacter);
            transmitMorseCode(prependCharSeparation, morseCode);
            prependCharSeparation = 1;
        } else {
            transmitMorseWordSeparation();
            prependCharSeparation = 0;
        }

        currentCharacter++;
    }

}

char* getMorseCodeFromCharacter(char character) {
    char symbol[2] = "\0";
    symbol[0] = character;
    return getMorseCodeFromSymbol(symbol);
}

char* getMorseCodeFromSymbol(char *symbol) {

    const int MORSE_TABLE_LEN = 50;
    char *morseTable[][2] = {
        {"A", ".-"},
        {"B", "-..."},
        {"C", "-.-."},
        {"D", "-.."},
        {"E", "."},
        {"F", "..-."},
        {"G", "--."},
        {"H", "...."},
        {"I", ".."},
        {"J", ".---"},
        {"K", "-.-"},
        {"L", ".-.."},
        {"M", "--"},
        {"N", "-."},
        {"O", "---"},
        {"P", ".--."},
        {"Q", "--.-"},
        {"R", ".-."},
        {"S", "..."},
        {"T", "-"},
        {"U", "..-"},
        {"V", "...-"},
        {"W", ".--"},
        {"X", "-..-"},
        {"Y", "-.--"},
        {"Z", "--.."},
        {"0", "-----"},
        {"1", ".----"},
        {"2", "..---"},
        {"3", "...--"},
        {"4", "....-"},
        {"5", "....."},
        {"6", "-...."},
        {"7", "--..."},
        {"8", "---.."},
        {"9", "----."},
        {".", ".-.-.-"},
        {",", "--..--"},
        {":", "---..."},
        {"?", "..--.."},
        {"=", "-...-"},
        {"-", "-....-"},
        {"(", "-.--."},
        {")", "-.--.-"},
        {"DOUBLEQUOTE", ".-..-."},
        {"'", ".----."},
        {"/", "-..-."},
        {"_", "..--.-"},
        {"@", ".--.-."},
        {"!", "-.-.--"}
    };

    static char *result;

    // Convert symbol to upper
    int i;
    for (i = 0; symbol[i]!='\0'; i++){
        if(symbol[i] >= 'a' && symbol[i] <= 'z') {
         symbol[i] = symbol[i] -32;
        }
    }

    // Find symbol in the Morse table
    int foundIndex = 0;
    for (int i = 0; i < MORSE_TABLE_LEN && !foundIndex; i++) {
        if (strcmp(morseTable[i][0], symbol) == 0) {
            foundIndex = i;
        }
    }
    
    result = foundIndex ? morseTable[foundIndex][1] : NULL;
    return result;
}

void transmitMorseCode(int prependCharSeparationFlag, char *morseCode) {

    if (prependCharSeparationFlag) {
        printf("|");
    }

    printf("%s", morseCode);

}

void transmitMorseWordSeparation() {

    printf("|||||||");

}