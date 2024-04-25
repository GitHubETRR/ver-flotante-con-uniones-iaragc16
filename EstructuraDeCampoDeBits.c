#include <stdio.h>
#include <stdint.h> 
#include <string.h>

union numeros{
    struct{
        unsigned int mantisa: 23;
        unsigned int exponente: 8;
        unsigned int signo: 1;
    }num;
    float var;
    unsigned char vect[4];
};

union numeros NumeroCompleto (void);
union numeros NumeroPorPartes (void);
void MostrarNumero (union numeros);


int main(void){
    union numeros numero;
    int opcion;
    do{
    printf("Presione 1 si desea ingresar el numero completo, presione 2 si desea ingresarlo por partes, presione 3 si desea ver el numero y presione 4 si desea salir del programa\n");
    scanf("%d",&opcion);
    while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
        printf("El numero ingresado no es valido. Presione 1 si desea ingresar el numero completo, presione 2 si desea ingresarlo por partes, presione 3 si desea ver el numero y presione 4 si desea salir del programa\n");
        scanf("%d",&opcion);
    }
    if(opcion==1){
        numero=NumeroCompleto();
    }
    if(opcion==2){
        numero=NumeroPorPartes();
    }
    if(opcion==3){
        MostrarNumero(numero);
    }
    }while(opcion!=4);
    return(0);
}

union numeros NumeroCompleto (){
    union numeros numero;
    printf("Ingresa un numero \n");
    scanf("%f",&numero.var);
    return(numero);
}

void MostrarNumero (union numeros numero){
    printf("El numero que ingresaste es\n");
    for (int i = 3; i >= 0; i--){
        printf("%02x",numero.vect[i]);
    }
    printf(" en hexadecimal\n");
    if(numero.num.signo == 0){
        printf("El signo es positivo\n");
    }else{
        printf("El signo es negativo\n");
    }
    printf("La mantisa es %02x en hexadecimal y %d en decimal \n", numero.num.mantisa, numero.num.mantisa);
    printf("El exponente es %d en decimal \n", numero.num.exponente-127);
    printf("El numero ingresado fue %f\n", numero.var);
}

union numeros NumeroPorPartes (){
    union numeros numero;
    int temp;
    printf("Ingresa un numero para el signo. 1 si es negativo y 0 si es positivo \n");   
    scanf("%d",&temp);
    while(temp!=1 && temp!=0){
        printf("El numero ingresado no es ni 1 ni 0. Presione 1 si desea que el numero sea negativo y 0 si desea que sea positivo\n");
        scanf("%d",&temp);
    }
    numero.num.signo=temp;
    printf("Ingresa un numero para el exponente entre 0 y 128 \n");
    scanf("%d",&temp);
    while(temp <0 || temp >128){
        printf("El numero ingresado no esta entre 0 y 128. Vuelva a ingresar el valor\n");
        scanf("%d",&temp);
    }
    temp=temp+127;
    numero.num.exponente=temp;
    printf("Ingresa un numero para la mantisa\n");
    scanf("%d",&temp);
    numero.num.mantisa=temp;
    return(numero);
}
