#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 32

// ================= SHOWCASE DE COMPLEJIDAD CICLOMÁTICA =================

// Ejemplo trivial: Complejidad ciclomática = 1
// ...existing code...

// Ejemplo de función lineal: Complejidad ciclomática = 2
int isEven(int n) {
    return n % 2 == 0 ? 1 : 0;
}

// Ejemplo con bucle y decisión: Complejidad ciclomática = 3
int countSpaces(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') count++;
    }
    return count;
}

// Ejemplo con múltiples decisiones y bucles anidados: Complejidad ciclomática = 7
int matrixSum(int mat[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] > 0) sum += mat[i][j];
            else if (mat[i][j] < 0) sum -= mat[i][j];
            else sum += 0;
        }
    }
    return sum;
}

// Ejemplo extremo: Complejidad ciclomática = 12
// ...existing code...

// ================= SHOWCASE DE COMPLEJIDAD CICLOMÁTICA =================

void printHello() {
    printf("Hola mundo!\n");
}

// Ejemplo extremo:
int extremeDecision(int x, int y) {
    // Cada decisión suma 1 a la complejidad
    if (x > 0) {
        if (y > 0) {
            if (x == y) return 1;
            else if (x > y) return 2;
            else return 3;
        } else if (y < 0) {
            return 4;
        } else {
            return 5;
        }
    } else if (x < 0) {
        switch (y) {
            case 0: return 6;
            case 1: return 7;
            case 2: return 8;
            default: return 9;
        }
    } else {
        for (int i = 0; i < y; i++) {
            if (i % 2 == 0) return 10;
        }
        return 11;
    }
    return 0;
}

// ============ CÓDIGO VULNERABLE: Complejidad ciclomática = 4 ============

void validatePassword(char* inputPassword) {
    char password[MAX_PASSWORD_LEN];
    // Vulnerabilidad: no se valida el tamaño de inputPassword
    strcpy(password, inputPassword);  // BUFFER OVERFLOW
    if (strlen(password) < 8) {
        printf("Password too short\n");
        return;
    }
    printf("Password accepted\n");
}

// Ejemplo de función con ALTA complejidad ciclomática
int checkPasswordStrength(char* password) {
    // COMPLEJIDAD CICLOMÁTICA = 18
    if (password == NULL) return 0; // 1
    if (strlen(password) < 8) return 0; // 2

    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; password[i] != '\0'; i++) { // 3
        char c = password[i];
        if (c >= 'A' && c <= 'Z') hasUpper = 1; // 4
        else if (c >= 'a' && c <= 'z') hasLower = 1; // 5
        else if (c >= '0' && c <= '9') hasDigit = 1; // 6
        else if (c == '!' || c == '@' || c == '#' || c == '$') hasSpecial = 1; // 7
        if (c == ' ') return 0; // 8
    }

    if (!hasUpper) return 0; // 9
    if (!hasLower) return 0; // 10
    if (!hasDigit) return 0; // 11
    if (!hasSpecial) return 0; // 12
    if (strcmp(password, "Password1!") == 0) return 0; // 13
    if (strcmp(password, "Admin@1234") == 0) return 0; // 14
    if (strcmp(password, "Test#1234") == 0) return 0; // 15

    return 1; // 16
}

// ============ CÓDIGO REFACTORIZADO: Complejidad ciclomática = 4 ============

void validatePasswordSecure(char* inputPassword) {
    if (inputPassword == NULL || strlen(inputPassword) > 31) {
        printf("Invalid password length\n");
        return;
    }

    char password[32];
    strncpy(password, inputPassword, 31);
    password[31] = '\0';
    printf("Password accepted\n");
}

int hasValidCharacters(char* password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        char c = password[i];
        if (c == ' ') return 0;
        if (c >= 'A' && c <= 'Z') hasUpper = 1;
        else if (c >= 'a' && c <= 'z') hasLower = 1;
        else if (c >= '0' && c <= '9') hasDigit = 1;
        else if (c == '!' || c == '@' || c == '#' || c == '$') hasSpecial = 1;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int isCommonPassword(char* password) {
    if (strcmp(password, "Password1!") == 0) return 1;
    if (strcmp(password, "Admin@1234") == 0) return 1;
    if (strcmp(password, "Test#1234") == 0) return 1;
    return 0;
}

// Ejemplo de función refactorizada: Complejidad ciclomática = 4
int checkPasswordStrengthRefactored(char* password) {
    // COMPLEJIDAD CICLOMÁTICA = 4 (ACEPTABLE)
    if (password == NULL) return 0; // 1
    if (strlen(password) < 8) return 0; // 2
    if (!hasValidCharacters(password)) return 0; // 3
    if (isCommonPassword(password)) return 0; // 4
    return 1;
}

int main() {
    printf("\n--- Ejemplo trivial ---\n");
    printHello();

    printf("\n--- Ejemplo lineal ---\n");
    printf("isEven(4): %d\n", isEven(4));
    printf("isEven(5): %d\n", isEven(5));

    printf("\n--- Ejemplo con bucle y decisión ---\n");
    printf("countSpaces('Hola mundo!'): %d\n", countSpaces("Hola mundo!"));
    printf("countSpaces('Sin espacios'): %d\n", countSpaces("Sin espacios"));

    printf("\n--- Ejemplo con bucles anidados y decisiones ---\n");
    int mat[3][3] = {{1, -2, 0}, {3, 0, -1}, {0, 2, -3}};
    printf("matrixSum: %d\n", matrixSum(mat));

    printf("\n--- Ejemplo extremo ---\n");
    int res = extremeDecision(1, 2);
    printf("Resultado extremeDecision(1,2): %d\n", res);

    printf("\n--- Prueba código vulnerable (complejidad 18) ---\n");
    int v = checkPasswordStrength("Valid@Pass1");
    printf("Resultado: %d\n", v);

    printf("\n--- Prueba código refactorizado (complejidad 4) ---\n");
    int r = checkPasswordStrengthRefactored("Valid@Pass1");
    printf("Resultado: %d\n", r);

    printf("\n--- Prueba código seguro ---\n");
    validatePasswordSecure("Secure@1234");

    // Pruebas extra de robustez
    printf("\n--- Robustez: validaciones de password ---\n");
    validatePasswordSecure(NULL);
    validatePasswordSecure("123");
    validatePasswordSecure("EstePasswordEsDemasiadoLargoParaElBuffer1234567890");

    printf("\n--- Robustez: checkPasswordStrength con casos límite ---\n");
    printf("Empty: %d\n", checkPasswordStrength(""));
    printf("Solo letras: %d\n", checkPasswordStrength("abcdefgh"));
    printf("Solo números: %d\n", checkPasswordStrength("12345678"));
    printf("Común: %d\n", checkPasswordStrength("Password1!"));

    return 0;
}
