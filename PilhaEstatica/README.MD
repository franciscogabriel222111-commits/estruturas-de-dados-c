# 📚 Entendendo Pilhas Estáticas em C

Bem-vindo! Se você está estudando Estruturas de Dados, este é o lugar certo para descomplicar o conceito de **Pilha Estática**. Vamos entender como o computador organiza informações usando um exemplo bem do nosso dia a dia.

## 📦 O que é uma Pilha Estática? (O Exemplo da Caixa de Livros)

[cite_start]Imagine uma caixa de papelão fina e funda onde você vai guardar seus livros[cite: 1548]. 
1. Se você colocar 5 livros, um em cima do outro, e quiser pegar o *primeiro* livro que guardou (o que está lá no fundo), o que precisa fazer?
2. Você é obrigado a tirar todos os livros que estão no topo primeiro!

Na programação, chamamos essa lógica de **LIFO** (*Last In, First Out* - O Último a Entrar é o Primeiro a Sair). [cite_start]As inserções e exclusões ocorrem apenas no início (ou topo) da Pilha[cite: 1559].

A palavra **Estática** significa que a nossa "caixa" tem um tamanho rígido e fixo. [cite_start]O espaço de memória é alocado no momento da compilação do código[cite: 1584]. [cite_start]Se a caixa suporta apenas o limite de 10 livros (que chamamos de `MAX`), você não pode colocar o 11º livro de jeito nenhum[cite: 1585]! [cite_start]Os elementos ocupam posições físicas vizinhas na memória, porque usamos um vetor (array) para construir isso[cite: 1593].



## ⚙️ As Regras do Jogo

Para que a pilha estática funcione sem bagunça, usamos uma variável especial chamada `qtd` (quantidade). Ela é a nossa "fita métrica":
* [cite_start]**Empilhar (Inserir):** Sempre no topo[cite: 1710]. [cite_start]A gente coloca o dado na posição livre e faz a quantidade aumentar (`qtd++`)[cite: 1733]. [cite_start]Mas atenção: não se pode inserir numa pilha que está cheia[cite: 1712]!
* [cite_start]**Desempilhar (Remover):** Sempre no topo[cite: 1744]. [cite_start]A gente simplesmente diminui a quantidade (`qtd--`), "esquecendo" o último elemento[cite: 1755]. [cite_start]Cuidado: não se pode remover de uma pilha vazia[cite: 1745].

---

## 📌 Resumo: 5 Pontos Principais

1. [cite_start]**A Regra de Ouro (LIFO):** O último elemento adicionado é obrigatoriamente o primeiro a ser removido[cite: 1559].
2. [cite_start]**Tamanho Fixo:** Exige a definição do número máximo de elementos (o `MAX`) antes do programa rodar[cite: 1585].
3. [cite_start]**Usa Vetores:** Os dados são guardados em sequência, um coladinho no outro na memória[cite: 1586].
4. [cite_start]**Variável Qtd:** O controle do topo da pilha é feito acompanhando a quantidade de elementos armazenados (`pi->qtd`)[cite: 1671].
5. [cite_start]**Limites Rígidos:** Se a quantidade for igual ao `MAX`, a pilha está cheia[cite: 1688]. [cite_start]Se for 0, a pilha está vazia[cite: 1701].

---

## 🧠 Teste o seu entendimento

1. Se você empilhar os pratos A, B e C (nesta ordem), qual prato você lavará primeiro ao desempilhar?
2. Se a sua pilha estática tem tamanho `MAX` igual a 5, o que acontece se o código tentar inserir um 6º elemento?
3. Por que precisamos da variável `qtd` se já temos o vetor criado?

*(Respostas no final do documento)*

---

## ⚠️ Erros Mais Comuns de Alunos Iniciantes

* **Furar a Pilha (Overflow):** Tentar inserir dados sem verificar se a pilha está cheia (`pi->qtd == MAX`). [cite_start]Isso faz o programa tentar acessar uma posição de memória que não pertence ao vetor, causando falhas graves[cite: 1682].
* **Remover o Vazio (Underflow):** Chamar a função de remoção sem verificar se a pilha está vazia (`pi->qtd == 0`). [cite_start]O `qtd` fica negativo e bagunça toda a lógica[cite: 1701].
* **Achar que precisa "apagar" o dado ao remover:** Na pilha estática, você não precisa apagar o valor do vetor com zeros. Basta fazer `qtd--`. O dado antigo fica lá como "lixo", e será sobrescrito naturalmente quando um novo elemento for inserido.

---
*Gabarito do Teste:*
*1. O prato C, pois foi o último a ser colocado no topo da pilha.*
*2. A função de inserção deve retornar erro (0 ou falso), pois a pilha estática não cresce além do seu limite definido na compilação.*
*3. O vetor é apenas o espaço físico (as prateleiras). A variável `qtd` nos diz exatamente quantas prateleiras estão ocupadas e onde devemos colocar o próximo item.*