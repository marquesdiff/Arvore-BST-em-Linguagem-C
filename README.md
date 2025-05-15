*pt-BR*

# Árvore BST ⤵

Este repositório contém uma implementação em C de uma **Árvore Binária de Busca (sigla 'BST' em inglês)**. Uma BST é uma estrutura de dados de árvore que organiza os elementos de forma hierárquica, permitindo operações eficientes de busca, inserção e remoção. Para cada nó na árvore, todos os valores na subárvore esquerda são menores que o valor do nó, e todos os valores na subárvore direita são maiores.

O código `bst.c` oferece as seguintes funcionalidades principais para manipulação e visualização da BST:

* **Inserir**: Adiciona novos elementos à árvore, mantendo a propriedade da BST.
* **Percursos (Pré-order, In-order, Pós-order, Reverso)**: Permite visualizar os elementos da árvore em diferentes ordens, fundamentais para entender a estrutura e o conteúdo da BST.
* **Altura**: Calcula a altura da árvore, indicando seu nível de aninhamento.
* **Quantidade de Folhas**: Conta o número de nós sem filhos na árvore.
* **Caminho**: Traça o percurso da raiz até um nó específico.
* **Remover**: Remove um elemento da árvore, ajustando a estrutura para manter a validade da BST.

---

### Funções Disponíveis

#### A tabela a seguir detalha cada função, seus parâmetros, o que ela realiza e o formato de saída esperado:
     __________________________________________________________________________________________________
    | opção |  função   |  detalhes                                                                     |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetros um número inteiro e um ponteiro para raiz de uma      |
    |   1   |  inserir  |  árvore BST, retorna o ponteiro para árvore após a inclusão do valor passado  |
    |       |           |  como primeiro parâmetro.                                                     |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela       |
    |       |           |  todos seus elementos, seguindo a ordem pré-order. Os valores dos elementos   |
    |   2   | pré-order |  são impressos entre colchetes, sem espaço entre dois elementos.              |
    |       |           |  Acrescenta um ‘\n’ após imprimir todos os elementos.                         |
    |       |           |  Ex:                                                                          |
    |       |           |  [20][10][30]                                                                 |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela       |
    |       |           |  todos seus elementos, seguindo a ordem in-order. Os valores dos elementos    |
    |   3   | in-order  |  são impressos entre colchetes, sem espaço entre dois elementos.              |
    |       |           |  Acrescenta um ‘\n’ após imprimir todos os elementos.                         |
    |       |           |  Ex:                                                                          |
    |       |           |  [10][20][30]                                                                 |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela       |
    |       |           |  todos seus elementos, seguindo a ordem pós-order. Os valores dos elementos   |
    |   4   | pós-order |  são impressos entre colchetes, sem espaço entre dois elementos.              |
    |       |           |  Acrescenta um ‘\n’ após imprimir todos os elementos.                         |
    |       |           |  Ex:                                                                          |
    |       |           |  [10][30][20]                                                                 |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela       |
    |       |           |  todos seus elementos, ordenados de forma decrescente. Os valores dos         |
    |   5   |  reverso  |  elementos são impressos entre colchetes, sem espaço entre dois               |
    |       |           |  elementos. Acrescenta um ‘\n’ após imprimir todos os elementos.              |
    |       |           |  Ex:                                                                          |
    |       |           |  [30][20][10]                                                                 |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e retorna a altura da   |
    |       |           |  árvore. Na função main, é impresso apenas o número inteiro seguido           |
    |   6   |  altura   |  por ‘\n’.                                                                    |
    |       |           |  Ex:                                                                          |
    |       |           |  2                                                                            |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |   7   | qtdFolhas |  Recebe como parâmetro o ponteiro para uma árvore BST e retorna a quantidade  |
    |       |           |  de folhas existentes na árvore.                                              |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetro o ponteiro para uma árvore BST e o valor de uma        |
    |       |           |  chave de procura. A função imprime o caminho do nó raiz até o nó             |
    |   8   |  caminho  |  específico passado como parâmetro, caso a chave não exista, imprime apenas   |
    |       |           |  ‘\n’.                                                                        |
    |       |           |  Ex (Caminho da raiz 2 até o nó 1):                                           |
    |       |           |  [2][1]                                                                       |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |       |           |  Recebe como parâmetros um número inteiro e a ponteiro para raiz de uma       |
    |   9   |  remover  |  árvore BST, retorna o ponteiro para árvore após a remoção do valor passado   |
    |       |           |  como primeiro parâmetro.                                                     |
    |       |           |                                                                               |
    |-------------------------------------------------------------------------------------------------- |
    |       |           |                                                                               |
    |  99   |   sair    |  Fecha o programa.                                                            |
    |       |           |                                                                               |
     ___________________________________________________________________________________________________

