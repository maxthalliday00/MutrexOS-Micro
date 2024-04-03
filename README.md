## MutrexOS-Micro

Micro é um futuro gerenciador de pacotes, criado para o MutrexOS um sistema operacional de código aberto, baseado no kernel linux.

Os códigos ainda estão em fase de projetamento, ou seja, muito ainda estão quebrados ou instáveis.

Há dois arquivos principais, o micro.py e o micro.c, onde:

Micro.py é um programa simples, que usa requests para baixar um pacote via mirror, descrito em mirrors.txt.


# Micro.c é um programa em fase de testes, que usa comandos .configure e make para configurar para compilação, compilar e instalar o pacote. Onde ele irá receber ./configure em especifico para cada pacote e o nome da pasta onde está este pacote.

exemplo de uso:

gcc micro.c -o micro

./micro <pasta> <comando_configure> [argumentos_configure]

./micro nasm ./configure --prefix=/usr

OBS: o código ainda está em fase de testes. Ou seja, pode apresentar os mais diversos erros.
