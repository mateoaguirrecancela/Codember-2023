//CHALLENGE_02

#include <stdio.h>
#include <string.h>

int analizar(char m, int resultado){
    switch (m)
    {
    case '#':
        resultado++;
        break;
    
    case '@':
        resultado--;
        break;

    case '*':
        resultado=resultado*resultado;
        break;

    case '&':
        printf("%d", resultado);
        break;

    default:
        break;
    }

    return resultado;
}

int main(){
    char *mensaje="&###@&*&###@@##@##&######@@#####@#@#@#@##@@@@@@@@@@@@@@@*&&@@@@@@@@@####@@@@@@@@@#########&#&##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@&";
    int resultado=0;

    for (int i = 0; i < strlen(mensaje); i++){
        resultado=analizar(mensaje[i], resultado);
    }

    printf("\n");
    
    return 0;
}