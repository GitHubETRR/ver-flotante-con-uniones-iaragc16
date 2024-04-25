#include <stdio.h>

union numero{
    float var;
    unsigned char caracter;
};

int main(void){
    union numero num;
    printf("\nIngresa el valor del numero: ");
    scanf("%f", &num.var);

    unsigned char *caracter_ptr = &num.caracter; //porque apuntar a un flotante a veces da error

    printf("var vale \n");

    for(int i = 3; i>=0; i--){ //apunta a caracter y disminuye el valor de la direccion a la que apunta para apuntar al otro byte de var
        printf("%02X \n", *(caracter_ptr+i)); // uso el * para indicar que se imprime el valor dentro de la direccion del puntero
    }
}