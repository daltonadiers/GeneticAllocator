# GeneticAllocator


## Descricao
Esse algoritmo visa simular a alocação de professores e salas de aula em um ambiente escolar, considerando professores que podem dar uma ou mais disciplinas, afim de encontrar o número mínimo de conflitos possíveis. Um conflito significa que precisaríamos de mais de 1 dia para lecionar todas as disciplinas disponíveis.

## Compilação e execução
Recomenda-se ambiente Linux para execução.
Para compilar, basta digitar make em seu terminal. É necessário que você tenha disponível o compilador g++. Em seguida a execução se dá por meio de ./output x y z c v.

## Parametros de execução 
Como mostrado acima, você deve executar com 5 parâmetros, sendo x, y, z, c e v. X representa a população inicial que você quer construir, Y representa o número total de gerações a serem executadas (valor a seu critério), Z representa a chance de um cromossomo realizar ou não Crossover na geração atual (0 a 100). C representa a chance de um cromossomo realizar ou não uma mutação na geração atual (0 a 100). Por fim, V representa a população máxima de cromossomos que podemos ter durante a execução, extrapolar esse valor pode levar a execuções exageradamente grandes e ineficientes.
#### Exemplo de compilação e execução:
make
./output 10 10 50 30 100

## Saida
A saída contém todos os cromossomos válidos encontrados, procure pelos que contém menor conflito.

## Autores
- **Dalton Oberdan Adiers**@daltonadiers