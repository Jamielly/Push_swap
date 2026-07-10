*Esta atividade foi criada como parte do currículo 42 por <login1>, <login2>*

# push_swap

## 📖 Descrição

`push_swap` é um algoritmo de ordenação com pilhas (*stacks*) restrito a um
conjunto limitado de operações. O programa recebe uma lista de números
inteiros como argumentos, os empilha em uma pilha `A` e deve produzir, na
saída padrão, a menor sequência possível de instruções capaz de ordenar essa
pilha em ordem crescente utilizando apenas uma segunda pilha `B` auxiliar.

O objetivo do projeto vai além de apenas ordenar: é necessário **projetar,
justificar e comparar diferentes estratégias de complexidade** para o mesmo
problema, expondo-as através de flags de linha de comando (`--simple`,
`--medium`, `--complex`, `--adaptive`), além de fornecer um modo de
*benchmark* que mede o percentual de desordem da entrada e a performance de
cada estratégia.

O repositório também contém um segundo programa, o `checker`, responsável por
validar se uma sequência de instruções realmente ordena a pilha fornecida.

## ⚙️ Instruções

### Pré-requisitos

- `gcc` ou `clang`
- `make`
- Sistema Unix-like (Linux / macOS)

### Compilação

```bash
git clone <url_do_repositorio>
cd push_swap
make
```

Isso irá gerar o executável `push_swap` na raiz do projeto.

Regras disponíveis no `Makefile`:

| Regra     | Descrição                                              |
|-----------|---------------------------------------------------------|
| `make`    | Compila o projeto (equivalente a `make all`)             |
| `make all`| Compila `push_swap` com as flags `-Wall -Wextra -Werror`|
| `make clean` | Remove os arquivos objeto (`.o`)                      |
| `make fclean`| Remove os `.o` e o executável                        |
| `make re`    | Executa `fclean` seguido de `all`                     |

### Execução básica

```bash
./push_swap 2 1 3 6 5 8
```

O programa imprime, uma instrução por linha, a sequência de operações que
ordena a pilha (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`,
`rrr`). Se a pilha já estiver ordenada, nada é impresso.

### Flags de estratégia

```bash
./push_swap --simple   3 1 2       # força a estratégia O(n²)
./push_swap --medium   3 1 2       # força a estratégia O(n√n)
./push_swap --complex  3 1 2       # força a estratégia O(n log n)
./push_swap --adaptive 3 1 2       # escolhe a estratégia automaticamente (padrão)
```

Se nenhuma flag for informada, o comportamento padrão é `--adaptive`.

### Modo benchmark

```bash
./push_swap --bench --complex 5 4 3 2 1 2>bench.txt >/dev/null
cat bench.txt
```

O modo `--bench` envia para a saída padrão as instruções de ordenação
normalmente, e para a saída de erro um relatório contendo:

- Percentual de desordem da entrada
- Estratégia utilizada e sua classe de complexidade
- Número total de operações
- Contagem individual por tipo de operação (`sa`, `pa`, `ra`, etc.)

### Flag extra: `--count-only`

```bash
./push_swap --count-only 3 2 1
# saída: 3
```

Exibe apenas o número total de operações necessárias, sem listar as
instruções individualmente.

### Verificando o resultado com o checker

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_linux $ARG
# saída esperada: OK
```

O checker também pode ser usado de forma interativa, lendo instruções pela
entrada padrão até `Ctrl+D`:

```bash
./checker_linux 0 1 2
sa
rrr
# Ctrl+D -> imprime OK ou KO
```

### Testes automatizados

O repositório inclui um script de testes (`push_swap_tester.sh`) que cobre
gerenciamento de erros, seleção de estratégia, entradas de diferentes
tamanhos, modo benchmark e vazamento de memória:

```bash
chmod +x push_swap_tester.sh
./push_swap_tester.sh .
```

## 📚 Recursos

### Referências utilizadas

- Assunto oficial do projeto (`assunto.pdf`) fornecido pela 42
- Documentação da linguagem C — [cppreference.com](https://en.cppreference.com/w/c)
- Artigos sobre algoritmos de ordenação clássicos (Selection Sort, Insertion
  Sort) para a estratégia `--simple`
- Material sobre o algoritmo **Turk / chunks** (divisão em `√n` grupos),
  amplamente documentado pela comunidade 42, para a estratégia `--medium`
- Conceitos de ordenação eficiente (Merge Insertion Sort / Ford-Johnson) para
  a estratégia `--complex`
- Documentação do `valgrind` para verificação de vazamentos de memória —
  [valgrind.org](https://valgrind.org/docs/manual/quick-start.html)

### Uso de Inteligência Artificial

A IA (assistente de programação) foi utilizada como apoio pontual nas
seguintes tarefas, sempre com revisão manual e compreensão integral do código
gerado por parte de ambos os alunos:

- Esclarecimento de dúvidas conceituais sobre complexidade assintótica
  (O(n²), O(n√n), O(n log n)) e sobre o funcionamento do algoritmo de
  Ford-Johnson (merge-insertion sort).
- Sugestões de organização/estrutura de arquivos e nomes de funções para
  manter aderência à Norma 42.
- Auxílio na escrita deste `README.md` (estrutura das seções e formatação
  Markdown).
- Revisão e sugestões de casos de teste extras (valores limite, `INT_MAX`,
  duplicados) para o script `push_swap_tester.sh`.
- Depuração de vazamentos de memória: interpretação de saídas do `valgrind`
  e sugestão de pontos do código onde `free()` estava faltando.

A IA **não** foi utilizada para gerar a lógica final dos algoritmos de
ordenação nem a implementação das estruturas de pilha — essas partes foram
escritas, testadas e são de plena compreensão dos dois autores, conforme
exigido pela avaliação por pares.

## 🧠 Algoritmos e justificativa de escolha

O projeto implementa quatro estratégias, selecionáveis via flag, cada uma
representando uma classe de complexidade distinta exigida pelo enunciado.

### `--simple` — O(n²)

**Abordagem:** Selection Sort adaptado às operações de pilha. Repetidamente
localiza o menor elemento restante em `A`, gira a pilha (`ra`/`rra`) até
trazê-lo ao topo e o empilha na posição correta de `B` (ou o mantém em `A`
já ordenado), repetindo o processo até que todos os elementos estejam
ordenados.

**Por que O(n²):** para cada um dos `n` elementos é necessário, no pior
caso, percorrer o restante da pilha (`O(n)`) para encontrar o próximo menor
valor, resultando em `O(n) × O(n) = O(n²)` operações. É a estratégia mais
simples de implementar e serve como *baseline* de corretude para validar as
demais.

**Quando é escolhida pela `--adaptive`:** para conjuntos muito pequenos
(tipicamente `n ≤ 3`), onde a simplicidade supera qualquer ganho teórico de
algoritmos mais complexos.

### `--medium` — O(n√n)

**Abordagem:** algoritmo de **divisão em blocos** (*chunks*). A pilha `A` é
dividida em aproximadamente `√n` grupos de tamanho `√n`, definidos por
faixas de valor (ex.: os `√n` menores valores formam o primeiro grupo, e
assim por diante). Os elementos são empurrados para `B` grupo a grupo,
sempre inserindo cada elemento na posição correta dentro de `B` usando o
menor número de rotações (`ra`/`rra`/`rb`/`rrb`) — cálculo de distância
circular para decidir a direção mais curta. Ao final, os elementos são
devolvidos a `A` na ordem correta.

**Por que O(n√n):** cada um dos `n` elementos exige, em média, uma busca de
posição custando `O(√n)` (proporcional ao tamanho de cada bloco/à posição
dentro de `B`), resultando em `O(n) × O(√n) = O(n√n)`.

**Quando é escolhida pela `--adaptive`:** para conjuntos de tamanho
intermediário (ex.: dezenas a poucas centenas de elementos), quando o custo
de implementar/rodar o algoritmo `O(n log n)` completo não compensa o ganho
de performance.

### `--complex` — O(n log n)

**Abordagem:** implementação do algoritmo **Ford-Johnson (merge insertion
sort)** adaptado a pilhas. Os elementos de `A` são agrupados em pares e
ordenados internamente; o maior de cada par forma uma "cadeia principal"
que é recursivamente ordenada por *merge*; o menor de cada par é então
inserido na cadeia principal na posição correta usando busca binária
(sequência de Jacobsthal para minimizar o número de comparações). A
sequência final de inserções é convertida em uma sequência mínima de
movimentos de pilha.

**Por que O(n log n):** a fase de ordenação da cadeia principal é feita por
divisão recursiva (`O(log n)` níveis), e cada inserção usa busca binária
(`O(log n)`), resultando na complexidade ótima conhecida para algoritmos de
ordenação por comparação: `O(n log n)`.

**Quando é escolhida pela `--adaptive`:** para conjuntos grandes (centenas a
milhares de elementos), onde o ganho assintótico se traduz em uma redução
significativa e mensurável do número de operações em relação a
`--simple`/`--medium`.

### `--adaptive` (padrão)

**Abordagem:** a estratégia adaptativa mede o tamanho `n` da entrada (e,
opcionalmente, seu percentual de desordem calculado no modo benchmark) e
seleciona automaticamente entre `--simple`, `--medium` e `--complex` segundo
limiares definidos empiricamente através de testes de performance:

| Tamanho da entrada | Estratégia escolhida |
|---------------------|-----------------------|
| `n ≤ 3`              | `--simple`            |
| `3 < n ≤ 100`        | `--medium`             |
| `n > 100`            | `--complex`            |

Esses limiares foram calibrados testando cada estratégia em diferentes
tamanhos de entrada e comparando o número médio de operações geradas (ver
seção de testes do `push_swap_tester.sh`), priorizando sempre a estratégia
que oferece o melhor equilíbrio entre número de operações e tempo de
execução para a faixa de tamanho observada.

## 👥 Contribuições

| Aluno       | Login  | Contribuições principais |
|-------------|--------|---------------------------|
| <Nome 1>    | <login1> | - Estrutura de dados da pilha (`t_stack`) e operações básicas (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)<br>- Parsing e validação dos argumentos (gerenciamento de erros)<br>- Implementação da estratégia `--simple` (O(n²))<br>- Implementação do `checker` |
| <Nome 2>    | <login2> | - Implementação da estratégia `--medium` (O(n√n))<br>- Implementação da estratégia `--complex` (O(n log n) — Ford-Johnson)<br>- Lógica da estratégia `--adaptive` e seleção automática<br>- Modo `--bench`, cálculo de percentual de desordem e flag `--count-only` |

> **Observação:** apesar da divisão de tarefas acima, ambos os alunos
> revisaram em conjunto a totalidade do código, participaram de sessões de
> *pair programming* para as partes mais críticas (Ford-Johnson e cálculo de
> rotações mínimas) e são capazes de explicar e defender qualquer trecho do
> projeto, conforme exigido pela avaliação em grupo.

## 🧪 Testes

Consulte o script `push_swap_tester.sh` incluído neste repositório para uma
suíte completa de testes automatizados (gerenciamento de erros, seleção de
estratégia, entradas de 3 a 500 números, benchmark, vazamento de memória e
robustez contra crashes), alinhada à régua de avaliação do projeto.
