*Esta atividade foi criada como parte do currículo 42 por jamsilva, luafranc*

# push_swap

## Description

**push_swap** ordena uma pilha de inteiros usando duas pilhas (`a` e `b`) e um
conjunto restrito de operacoes (`sa`, `pb`, `ra`, `rra`, etc.), gerando a
menor sequencia possivel de movimentos.

O programa oferece **quatro estrategias** selecionaveis por flag, ou
automaticamente via `--adaptive` (padrao):

| Estrategia | Flag | Complexidade | Melhor para |
|---|---|---|---|
| Simple | `--simple` | O(n²) | Listas pequenas |
| Medium | `--medium` | O(n√n) | Listas medias / grandes |
| Complex | `--complex` | O(n log n) | Listas aleatorias medias |
| Adaptive | `--adaptive` *(padrao)* | Escolhe uma das acima | Qualquer entrada |

### Metrica de desordem (disorder)

Antes de ordenar (e no modo `--bench`), o programa calcula um score de
desordem (Kendall-tau):

```
disorder = (pares invertidos) / (total de pares)
```

`0.0` = ja ordenado; `1.0` = ordem inversa (pior caso).

### Como o Adaptive escolhe

1. Se `n <= 5`: usa **Simple** (casos otimizados 2/3/5).
2. Se `disorder < 0.2` e `n <= 25`: usa **Simple** O(n²)
   (quase ordenado e ainda pequeno).
3. Se `disorder >= 0.5` e `25 < n < 80`: usa **Complex** O(n log n)
   (radix) — boa em listas medias bem baguncadas.
4. Nos demais casos: usa **Medium** O(n√n) (chunks) — inclui 100 e 500,
   onde chunks performam melhor que radix com as operacoes do push_swap.

### Algoritmos

**Simple (O(n²)) — selection sort adaptado**

Para n=2/3/5 usa caminhos hardcoded. Para n maior: encontra o minimo em `a`,
traz ao topo pelo caminho mais curto (`ra`/`rra`), faz `pb`. Repete ate
esvaziar `a`, depois `pa` tudo de volta. Custo tipico ~O(n²).

**Medium (O(n√n)) — chunk sort**

Indexa os valores em ranks `0..n-1`. Empurra para `b` em janelas (chunks)
de tamanho ~√n (15 se n≤100, 35 se n>100): valores menores vao ao fundo de
`b` com `rb`. Deixa os 3 maiores em `a`, ordena com `sort_three`, depois
puxa de `b` do maior indice para o menor. Passes ~√n sobre n elementos →
O(n√n).

**Complex (O(n log n)) — radix sort binario (LSD)**

Indexa ranks `0..n-1`. Para cada bit (LSB→MSB): bit 0 vai para `b` (`pb`),
bit 1 rota em `a` (`ra`). Ao fim do bit, devolve `b` com `pa`.
Passes: log₂(n). Movimentos por passe: ~n → O(n log n).

---

## Instructions

### Compilacao

```bash
make          # gera o binario push_swap
make clean    # remove objetos
make fclean   # remove objetos + binario
make re       # fclean + all
```

Flags de compilacao: `-Wall -Wextra -Werror`.

### Uso

```bash
# Padrao = --adaptive
./push_swap 4 67 3 87 23

# Forcar estrategia
./push_swap --simple  5 4 3 2 1
./push_swap --medium  $(shuf -i 0-99  -n 50 | tr '\n' ' ')
./push_swap --complex $(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap --adaptive 5 4 3 2 1

# Benchmark (metricas em stderr; instrucoes em stdout)
./push_swap --bench --simple 5 4 3 2 1

# Contar operacoes / validar com checker oficial
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Tratamento de erros

```bash
./push_swap 0 one 2 3     # Error (nao numerico)
./push_swap 3 2 3         # Error (duplicata)
./push_swap 2147483648    # Error (> INT_MAX)
./push_swap               # (sem saida)
```

---

## Resources

Referencias:
- Think Like a Programmer (V. Anton Spraul)
- The Programmer’s Brain (Felienne Hermans)
- Sorting algorithms — Wikipedia
- Radix sort — Wikipedia
- Big-O notation — Wikipedia
- 42 push_swap visualizer

### Uso de IA

AI (Replit Agent / Cursor) auxiliou em:
- Scaffolding: estrutura de diretorios e regras iniciais do Makefile
- Estruturas: esbocos de `t_number` e `t_bench` em `include/push_swap.h`
- Parsing: logica auxiliar de `ft_atol.c` e `compute_disorder`
- Esqueletos: fluxo basico das quatro estrategias

Todo o codigo gerado foi revisado, adaptado a Norm e depurado pelos dois
integrantes, com ownership total da implementacao final.

---

## Contribuicoes

| Aluno | Principais contribuicoes |
|---|---|
| **luafranc** | Operacoes (`operations/`), parsing inicial, validators, free_utils, estrutura base do Makefile/libft, primeiros esqueletos |
| **jamsilva** | Algoritmos (`simple`/`medium`/`complex`), adaptive + disorder, benchmark (`--bench`), indices/chunks, integracao final e README |

Ambos revisaram e conseguem defender qualquer parte do codigo.
