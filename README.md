# Disk Scheduling
Repositório que tem por objetivo simular o acesso a blocos/setores em discos rígidos utilizando algoritmos de escalonamento de requisições.

## Algoritmos
+ **First-Come, First Served** - [**FCFS**](/algorithms/fcfs/fcfs.c)
+ **Shortest Seek Time First** - [**SSTF**](/algorithms/sstf/sstf.c)

## Execução
Para compilar o projeto, entre na pasta raíz do repositório e digite o comando (usando o GCC):

```
gcc main.c numbers.c algorithms/sstf/sstf.c algorithms/fcfs/fcfs.c operations/operations.c -o main
```

Em seguida o execute com o comando **`./main`** em sistemas *Linux* ou **`main.exe`** no *Windows*.

## Resultados
Para conferir os resultados, basta analisar os arquivos **`.csv`** na pasta [**_reports_**](/reports/).

Os arquivos **`.csv`** possuem as seguintes colunas:

| Coluna | Descrição |
| :----: | :---- |
| *index* | índice da iteração |
| *sector* | setor da iteração atual |
| *track* | trilha da iteração atual |
| *seek* | tempo de seek |
| *rotation* | tempo de rotação |
| *transfer* | tempo de transferência |
| *total* | seek + rotation + transfer |
