#include <stdio.h>
#include <string.h>
int main(){
    int len = 0, val = 1, opc = 0;
    char nombres[6][30];
    char ganador_c[3][30], primero[30], segundo[30];
    int puntos[6]={0 ,0 ,0 ,0 ,0 ,0}, puntos_f[3] = {0, 0 ,0};

    for (int i = 0; i<6; i++){
        printf("Ingrese el nombre del peleador %d: ", i+1);
        fflush(stdin);
        fgets(nombres[i], 30,stdin);
        len=strlen(nombres[i]) - 1;
        nombres[i][len]='\0';
    }
    printf("\n");
    int cont = 0;
    while (1){
        printf("Elija el ganador del combate :\n1. %s\n2. %s\nElija una opcion: ", nombres[cont], nombres[cont+1]);
        do{
            fflush(stdin);
            val = scanf("%d", &opc);
            if (val != 1 || opc < 1 || opc > 2){
                printf("El valor ingresado no es correcto. \nIngrese Nuevamente: ");
            }
        } while (val != 1 || opc < 1 || opc > 2);
        if (opc == 1){
            do {
                
                printf("Ingrese con cuantos puntos gano entre 1 y 1000\n");
                fflush(stdin);
                val= scanf("%d",puntos[opc]);
                if (val<0 || val!=1 || val>1000) {
                    printf("El valor ingresado no es correcto. \nIngrese Nuevamente: ");
                }
            } while(val<0 || val!=1 || val>1000);
            

        } else if (opc == 2){
            do {
                fflush(stdin);
                printf("Ingrese con cuantos puntos gano entre 1 y 1000\n");
                val= scanf("%d",puntos[opc]);
                
            } while(val<0 || val!=1 || val>1000);
            
        }
        cont+=2;
        if (cont>=6){
            break;
        }
    }
    cont = 0;
    for (int i = 0; i<=6; i+=2){
        if (puntos[i]>puntos[i+1]){
            strcpy(ganador_c[cont], nombres[i]);
            puntos_f[cont]=puntos[i];
        } else if (puntos[i]<puntos[i+1]){
            strcpy(ganador_c[cont], nombres[i+1]);
            puntos_f[cont]=puntos[i+1];
        }
        cont++;
    }
    cont = 0;
    printf("-----GANADORES DE LA LLAVE-----\n");
    printf("C1: %s con %d puntos.\nC2: %s con %d puntos.\nC3: %s con %d puntos.\n", ganador_c[0], puntos_f[0], ganador_c[1], puntos_f[1], ganador_c[2], puntos_f[2]);
    int i= 0;

        if (puntos_f[i] >  puntos_f[i+1]){
            if (puntos_f[i] >  puntos_f[i+2]){
                strcpy(primero, ganador_c[i]);
                strcpy(segundo, ganador_c[i+1]);
            } else if (puntos_f[i+2] >  puntos_f[i]){
                strcpy(primero, ganador_c[i+1]);
                strcpy(segundo, ganador_c[i]);
            } else if (puntos_f[i+2] ==  puntos_f[i]){
                strcpy(primero, ganador_c[i]);
                strcpy(segundo, ganador_c[i+1]);
            }
        } else if (puntos_f[i] <  puntos_f[i+1]){
            if (puntos_f[i+1] >  puntos_f[i+2]){
                strcpy(primero, ganador_c[i+1]);
                strcpy(segundo, ganador_c[i+2]);
            } else if (puntos_f[i+2] >  puntos_f[i+1]){
                strcpy(primero, ganador_c[i+2]);
                strcpy(segundo, ganador_c[i+1]);
            } else if (puntos_f[i+2] ==  puntos_f[i+1]){
                strcpy(primero, ganador_c[i+1]);
                strcpy(segundo, ganador_c[i+2]);
            }
        } else if (puntos_f[i] ==  puntos_f[i+1]){
            if (puntos_f[i] >  puntos_f[i+2]){
                strcpy(primero, ganador_c[i]);
                if (puntos_f[i+1] > puntos_f[i+2]){
                    strcpy(segundo, ganador_c[i+1]);
                } else if (puntos_f[i+1] < puntos_f[i+2]){
                    strcpy(segundo, ganador_c[i+2]);
                }
            } else if (puntos_f[i+2] > puntos_f[i]){
                strcpy(primero, ganador_c[i+2]);
                strcpy(segundo, ganador_c[i]);
            } else if (puntos_f[i+2] ==  puntos_f[i]){
                strcpy(primero, ganador_c[i]);
                strcpy(segundo, ganador_c[i+1]);
            }
        }
        printf("Pasa a la final como primero: %s\n", primero);
        printf("Pasa a la final como segundo: %s\n", segundo);
        printf("Elija el ganador del combate entre:\n1. %s\n2. %s\nElija una opcion: ", primero, segundo);
        do{
            fflush(stdin);
            val = scanf("%d", &opc);
            if (val != 1 || opc < 1 || opc > 2){
                printf("El valor ingresado no es correcto. \nIngrese Nuevamente: ");
            }
        } while (val != 1 || opc < 1 || opc > 2);
        if (opc == 1){
            printf("%s es el ganador!", primero);
        } else {
            printf("%s es el ganador!", segundo);
        }

        

    return 0;
}
