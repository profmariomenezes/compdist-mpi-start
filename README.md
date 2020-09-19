# compdist-mpi-start

## Execução dos arquivos MPI exemplo

Execute um ou mais dos arquivos de exemplo do MPI em uma máquina da AWS (ou no cluster virtual).

Siga as orientações do slide "05 - Programação Paralela usando MPI - ch03" para compilar o seu código.

Para executar, vc precisa que o arquivo rand.txt esteja no mesmo diretório do executável que compilou.

Utilize a função mpirun ao invés da mpiexec que mostra no slide.

Pode ser necessário informar os nomes das máquinas (localhost) para executar; veja o exemplo:

$ mpirun -n 4 -H localhost,localhost,localhost,localhost ./teste-mpi

SUBMETA:

- Prints da tela mostrando a execução do MPI com 4 processos.
