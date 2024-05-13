# Disk Scheduling
Repositório que tem por objetivo simular o acesso de blocos/setores utilizando algoritmos de escalonamento de discos rígidos.

## Algoritmos
+ **First-Come, First Served** - [**FCFS**](/algorithms/fcfs/fcfs.c)
+ **Shortest Seek Time First** - [**SSTF**](/algorithms/sstf/sstf.c)

## Execução
Para executar basta estar na pasta raíz do repositório e digitar o comando de compilação (usando o GCC):

**`gcc main.c numbers.c algorithms/sstf/sstf.c algorithms/fcfs/fcfs.c operations/operations.c -o main`**

Em seguida basta executá-lo.

## Resultados
Para conferir os resultados, basta buscar os arquivos **`.csv`** na pasta [**_reports_**](/reports/).
