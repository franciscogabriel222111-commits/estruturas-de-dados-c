# 🥞 Entendendo Pilhas Dinâmicas em C

Bem-vindo! Depois de entender a Pilha Estática, é hora de dar um passo além. Vamos descobrir como construir uma pilha que cresce e encolhe como mágica, usando a **Pilha Dinâmica**.

## 🧱 O que é uma Pilha Dinâmica? (O Exemplo dos Blocos de Montar)

Imagine que você está brincando com blocos de montar (tipo LEGO). 
1. Você coloca uma peça na mesa. 
2. Depois, encaixa outra peça *em cima* da primeira. E outra em cima dessa.
3. Não existe uma caixa limitando a altura da sua torre. Você pode continuar empilhando blocos enquanto tiver peças na sua caixa de brinquedos!

Na programação, uma **Pilha Dinâmica** funciona da mesma maneira. [cite_start]O espaço de memória é alocado em tempo de execução[cite: 1588]. [cite_start]A pilha cresce à medida que novos elementos são armazenados, e diminui à medida que elementos são removidos[cite: 1589].

[cite_start]Como os blocos não estão grudados fixamente numa caixa de papelão (vetor), cada elemento é alocado em uma área distinta da memória[cite: 1590]. [cite_start]Para a torre não desmoronar, cada elemento aponta para o seu sucessor na pilha (a peça de baixo)[cite: 1292].



## 🎩 O "Gerente" do Topo

[cite_start]Para não perdermos a nossa torre de vista, usamos um ponteiro especial para o primeiro elemento da pilha (o bloco mais alto)[cite: 1293]. [cite_start]Nós chamamos ele de **Topo**[cite: 1295].
* [cite_start]**Empilhar:** Nós criamos um bloco novo, dizemos que a parte de baixo dele aponta para o antigo Topo, e avisamos ao sistema: "Ei, o Topo agora é esse bloco novo!"[cite: 1448, 1449]. [cite_start]A inserção é sempre feita no seu topo[cite: 1434].
* **Desempilhar:** Nós olhamos para o Topo atual, vemos quem está embaixo dele, e dizemos: "O novo Topo agora é a peça de baixo". [cite_start]Depois, jogamos a peça antiga fora (liberamos a memória)[cite: 1479, 1480]. [cite_start]A remoção é sempre no seu topo[cite: 1744].

---

## 📌 Resumo: 5 Pontos Principais

1. [cite_start]**A Mesma Regra LIFO:** O comportamento é o mesmo da pilha estática: o último elemento a entrar é sempre o primeiro a sair[cite: 1434, 1744].
2. **Crescimento Livre:** A memória é alocada sob demanda (durante a execução). [cite_start]A pilha não tem um limite `MAX` definido[cite: 1588, 1589].
3. [cite_start]**Elos da Corrente:** Cada elemento guarda a sua informação e um "gancho" (ponteiro) que segura o elemento de baixo[cite: 1292].
4. [cite_start]**O Ponteiro Topo:** O controle de toda a estrutura é feito exclusivamente pelo ponteiro que marca quem está no topo da pilha[cite: 1295].
5. [cite_start]**Memória Limpa:** Toda vez que removemos um elemento, precisamos usar a função `free()` para devolver o espaço daquele bloco para o computador[cite: 1480].

---

## 🧠 Teste o seu entendimento

1. Qual é a principal diferença de construção entre uma Pilha Estática e uma Pilha Dinâmica?
2. Por que não faz sentido criar uma função para verificar se a Pilha Dinâmica está cheia?
3. Se o ponteiro que indica o Topo da pilha for igual a `NULL` (vazio), o que isso significa sobre a nossa torre de blocos?

*(Respostas no final do documento)*

---

## ⚠️ Erros Mais Comuns de Alunos Iniciantes

* **Perder o Topo (Memory Leak):** Na hora de remover, o aluno muda o Topo direto para a peça de baixo, mas esquece de usar o `free()` na peça que foi removida. O dado fica "flutuando" na memória do computador gastando espaço à toa.
* **Quebrar a Torre:** Na hora de inserir, o aluno diz que o novo bloco é o Topo *antes* de fazer o novo bloco apontar para o Topo antigo. Resultado: a ligação com o resto da pilha se perde para sempre! A ordem importa.
* [cite_start]**Tentar remover do infinito:** Esquecer de programar a verificação de pilha vazia (`*pi == NULL`) na hora de desempilhar[cite: 1425]. Se a pilha estiver vazia e o código tentar olhar quem está "embaixo" do nada, o programa quebra.

---
*Gabarito do Teste:*
*1. A Estática usa um vetor de tamanho fixo criado na compilação. A Dinâmica cria nós separados na memória sob demanda durante a execução.*
*2. Porque ela não tem um limite `MAX` programado. Ela só "enche" se a memória RAM do computador inteiro se esgotar.*
*3. [cite_start]Significa que a pilha está completamente vazia[cite: 1425]. Não há nenhuma peça na mesa.*