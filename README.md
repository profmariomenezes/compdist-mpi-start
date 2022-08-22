# compdist-mpi-start

## Execução dos arquivos MPI exemplo

Execute um ou mais dos arquivos de exemplo do MPI no Google Colab, seguindo o exemplo do notebook; pode ser em uma máquina da AWS ou Azzure também (ou no cluster virtual).

Siga as orientações do slide "05 - Programação Paralela usando MPI - ch03" para compilar o seu código.

Para executar, vc precisa que o arquivo rand.txt esteja no mesmo diretório do executável que compilou. Se estiver usando o Colab, faça o upload do arquivo diretamente pela interface do Colab, no mesmo diretório do executável.

Experimente as funções `mpiexec` e também a `mpirun`; ambas podem funcionar.

No Colab, rodaremos apenas na máquina local, então informe apenas o número de processos (2, 4 e 8). Se estiver em um cluster, então pode ser necessário informar os nomes das máquinas (localhost) para executar; veja o exemplo:

$ mpirun -n 4 -H localhost,localhost,localhost,localhost ./teste-mpi

SUBMETA:

- Prints da tela mostrando a execução do MPI com 4 processos.
