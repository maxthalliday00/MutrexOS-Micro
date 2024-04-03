#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// Função para construir um comando com argumentos variáveis
void construir_comando(char *comando, int tamanho, const char *formato, ...) {
    va_list args;
    va_start(args, formato);
    vsnprintf(comando, tamanho, formato, args);
    va_end(args);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <pasta> <comando_configure> [argumentos_configure]\n", argv[0]);
        return 1;
    }

    char *pasta = argv[1];
    char *configure = argv[2];
    char comando_make[100];
    char comando_make_install[100];

    // Construir o comando ./configure com argumentos variáveis
    char comando_configure[200];
    construir_comando(comando_configure, sizeof(comando_configure), "%s", configure);
    for (int i = 3; i < argc; i++) {
        construir_comando(comando_configure + strlen(comando_configure), sizeof(comando_configure) - strlen(comando_configure), " %s", argv[i]);
    }

    // Comando para mudar para a pasta especificada
    snprintf(comando_make, sizeof(comando_make), "cd %s && make", pasta);
    snprintf(comando_make_install, sizeof(comando_make_install), "cd %s && make install", pasta);

    int status;

    // Executa o script de configuração
    status = system(comando_configure);
    if (status != 0) {
        printf("Erro ao configurar o programa.\n");
        return 1;
    }

    // Executa o comando make
    status = system(comando_make);
    if (status != 0) {
        printf("Erro ao compilar o programa.\n");
        return 1;
    }

    // Executa o comando make install
    status = system(comando_make_install);
    if (status != 0) {
        printf("Erro ao instalar o programa.\n");
        return 1;
    }

    printf("Programa instalado com sucesso!\n");

    return 0;
}
