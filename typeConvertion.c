#include<stdio.h>
int main(){
    // Number Conversion
    printf("\n\nNumber Conversion\n");
    // Select the type of conversion
    int choice;
    printf("Select the type of conversion\n");
    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Octal\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Binary to Decimal\n");
    printf("5. Octal to Decimal\n");
    printf("6. Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    // Perform the conversion
    switch(choice){
        case 1:
            decimalToBinary();
            break;
        case 2:
            decimalToOctal();
            break;
        case 3:
            decimalToHexadecimal();
            break;
        case 4:
            binaryToDecimal();
            break;
        case 5:
            octalToDecimal();
            break;
        case 6:
            hexadecimalToDecimal();
            break;
        default:
            printf("Invalid Choice\n");
    }
    return 0;
}

// Binary To Decimal
void binaryToDecimal(){
    int binaryNumber, decimalNumber = 0, base = 1, remainder;
    printf("Enter the binary number: ");
    scanf("%d", &binaryNumber);
    while(binaryNumber > 0){
        remainder = binaryNumber % 10;
        decimalNumber = decimalNumber + remainder * base;
        binaryNumber = binaryNumber / 10;
        base = base * 2;
    }
    printf("Decimal Number: %d\n", decimalNumber);
}

// Octal To Decimal
void octalToDecimal(){
    int octalNumber, decimalNumber = 0, base = 1, remainder;
    printf("Enter the octal number: ");
    scanf("%d", &octalNumber);
    while(octalNumber > 0){
        remainder = octalNumber % 10;
        decimalNumber = decimalNumber + remainder * base;
        octalNumber = octalNumber / 10;
        base = base * 8;
    }
    printf("Decimal Number: %d\n", decimalNumber);
}

// Hexadecimal To Decimal
void hexadecimalToDecimal(){
    char hexadecimalNumber[100];
    int decimalNumber = 0, base = 1, i = 0, remainder;
    printf("Enter the hexadecimal number: ");
    scanf("%s", hexadecimalNumber);
    for(i = strlen(hexadecimalNumber) - 1; i >= 0; i--){
        if(hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9'){
            decimalNumber += (hexadecimalNumber[i] - 48) * base;
            base = base * 16;
        }
        else if(hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F'){
            decimalNumber += (hexadecimalNumber[i] - 55) * base;
            base = base * 16;
        }
        else if(hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f'){
            decimalNumber += (hexadecimalNumber[i] - 87) * base;
            base = base * 16;
        }
    }
    printf("Decimal Number: %d\n", decimalNumber);
}

// Decimal To Binary
void decimalToBinary(){
    int decimalNumber, binaryNumber[100], i = 0;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    while(decimalNumber > 0){
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    printf("Binary Number: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", binaryNumber[j]);
    }
    printf("\n");
}

// Decimal To Octal
void decimalToOctal(){
    int decimalNumber, octalNumber[100], i = 0;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    while(decimalNumber > 0){
        octalNumber[i] = decimalNumber % 8;
        decimalNumber = decimalNumber / 8;
        i++;
    }
    printf("Octal Number: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", octalNumber[j]);
    }
    printf("\n");
}

// Decimal To Hexadecimal
void decimalToHexadecimal(){
    int decimalNumber, i = 0;
    char hexadecimalNumber[100];
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    while(decimalNumber > 0){
        if(decimalNumber % 16 < 10){
            hexadecimalNumber[i] = decimalNumber % 16 + 48;
            i++;
        }
        else{
            hexadecimalNumber[i] = decimalNumber % 16 + 55;
            i++;
        }
        decimalNumber = decimalNumber / 16;
    }
    printf("Hexadecimal Number: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}


