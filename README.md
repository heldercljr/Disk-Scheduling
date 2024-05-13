# Disk Scheduling
Repositório que tem por objetivo simular o acesso de blocos/setores utilizando algoritmos de escalonamento de discos rígidos.

## Algoritmos
+ **First-Come, First Served** - [**FCFS**](/algorithms/fcfs/fcfs.c)
+ **Shortest Seek Time First** - [**SSTF**](/algorithms/sstf/sstf.c)

## Execução
Para compilar o projeto, entre na pasta raíz do repositório e digitar o comando (usando o GCC):

**`gcc main.c numbers.c algorithms/sstf/sstf.c algorithms/fcfs/fcfs.c operations/operations.c -o main`**

Em seguida o execute com o comando **`./main`** em sistemas *Linux* ou **`main.exe`** no *Windows*.

## Resultados
Para conferir os resultados, basta buscar os arquivos **`.csv`** na pasta [**_reports_**](/reports/).
