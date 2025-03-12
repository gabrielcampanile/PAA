# PAA

Projeto e Análise de Algoritmos (PAA)
Este repositório reúne exemplos de implementação e estudo das principais técnicas de projeto e análise de algoritmos, cobrindo desde abordagens clássicas de força bruta (backtracking), passando por algoritmos gulosos, até soluções de programação dinâmica. Abaixo, apresentamos um resumo dos tópicos abordados:

## Descrição das Estratégias

- **Backtracking**: Técnica de força bruta que explora todas as combinações possíveis para resolver um problema, voltando atrás (backtrack) quando uma solução não é viável.
- **Programação Dinâmica (DP)**: Abordagem que resolve problemas complexos dividindo-os em subproblemas menores e armazenando os resultados para evitar cálculos repetidos.
- **Algoritmos Gulosos (Greedy)**: Estratégia que faz a escolha localmente ótima em cada etapa, esperando encontrar a solução global ótima.
- **Análise de Grafos**: Estudo de algoritmos que resolvem problemas modelados como grafos, utilizando propriedades como conexões e caminhos entre vértices.

## Tópicos Abordados

1. **Backtracking**
   1.1 Transformação de Sequências (Fold)
   Exemplo de busca exaustiva (backtracking) para transformar uma sequência através de operações de “dobra”, explorando todos os caminhos possíveis. Caso o caminho não leve a uma solução, o algoritmo “volta atrás” (backtrack) e tenta outra possibilidade.

   Pontos-chave:

   - Abordagem recursiva.
   - Explora todas as combinações de estado possíveis.
   - Poda via verificação de estados repetidos e limites de viabilidade.

2. **Programação Dinâmica**
   2.1 Troco Mínimo (Troco DP)
   Neste problema, deseja-se determinar o número mínimo de moedas necessárias para somar um valor de troco específico. A implementação utiliza um vetor dp[] onde cada posição armazena a quantidade mínima de moedas para aquele valor. Desta forma, a solução para um valor j deriva de subsoluções já calculadas para j - moedas[k].

   Pontos-chave:

   - Estrutura de subproblemas ótimos.
   - Preenchimento de uma tabela (ou vetor) de forma iterativa.
   - Complexidade geralmente O(N × M), onde N é o valor do troco e M é o número de tipos de moedas.

3. **Algoritmos Gulosos (Greedy)**
   3.1 Troco Guloso
   Difere da abordagem de programação dinâmica por sempre escolher localmente a maior moeda possível. É simples e eficiente, mas pode falhar em alguns casos onde o conjunto de moedas não é regular.

   Pontos-chave:

   - Estratégia gulosa (greedy).
   - Ordenação das moedas em ordem decrescente.
   - Funciona bem em sistemas monetários padrões, mas não garante ótimo para todos os tipos de conjuntos de moedas.

     3.2 Mochila Fracionária
     Dado um conjunto de itens com valores e pesos, e uma capacidade máxima de mochila, o algoritmo seleciona itens (ou frações deles) com base na melhor razão valor/peso primeiro. Essa abordagem gulosa encontra a solução ótima quando é permitido fracionar os itens.

   Pontos-chave:

   - Ordenação dos itens pela razão valor/peso.
   - Possibilidade de fracionar itens para preencher a capacidade exata.
   - Complexidade de ordenação O(N log N).

     3.3 Mínimo de Paradas
     Dado um conjunto de postos ao longo de uma estrada, o algoritmo guloso determina o menor número de paradas necessárias para completar a viagem, removendo de forma iterativa os postos que não são úteis. Constrói a solução escolhendo sempre o posto mais distante dentro da autonomia disponível.

   Pontos-chave:

   - Estratégia de escolher o “posto mais distante alcançável”.
   - Solução ótima para o problema de paradas em estrada.
   - Complexidade O(N), desde que os dados estejam ordenados.

4. **Análise de Grafos**
   4.1 Seleção de Usuários em Rede (Máximo Subgrupo)
   Problema modelado como grafo direcionado, onde buscamos o maior subgrupo de vértices em que cada nó (usuário) tem pelo menos uma aresta de entrada partindo de outro vértice nesse mesmo grupo. A solução utiliza remoção iterativa de nós com grau de entrada zero, restando apenas os nós que se indicam mutuamente.

   Pontos-chave:

   - Uso de “in-degree” e fila para eliminar nós sem arestas de entrada.
   - Complexidade O(N + M), onde N é o número de vértices (usuários) e M o número de arestas (indicações).
   - Implementação que garante subgrafo maximal com a propriedade desejada.

5. **Maior Subsequência Palindrômica, LCS e Outros**
   Há também exemplos de algoritmos de programação dinâmica para problemas como:
   - LCS (Longest Common Subsequence).
   - Maior subsequência palindrômica (Longest Palindromic Subsequence).
     Eles ilustram emblematicamente como a sobreposição de subproblemas e a subestrutura ótima são aplicadas na prática.

## Como Executar

Para compilar qualquer um dos códigos em C, utilize os seguintes comandos (exemplo para o arquivo “lab04.c” no Windows):

```bash
gcc lab04.c -o lab04
./lab04
```

Em outros sistemas, basta adaptar:

```bash
gcc lab04.c -o lab04
./lab04
```

## Conclusão

Este repositório serve como apoio na disciplina de Projeto e Análise de Algoritmos (PAA), mostrando implementações práticas das principais estratégias:

- Força Bruta (Backtracking)
- Algoritmos Gulosos (Greedy)
- Programação Dinâmica (DP)
- Manipulação de Grafos

O estudo comparativo dessas abordagens — bem como suas aplicações, eficiências e limitações — fornece a base para compreender como escolher a melhor estratégia para um problema específico.
