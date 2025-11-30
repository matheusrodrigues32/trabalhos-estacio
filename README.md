Este projeto implementa uma versão simplificada do jogo War utilizando a linguagem C, trabalhando com:

Structs

Ponteiros

Alocação dinâmica de memória (malloc e free)

Modularização

Simulação de ataque entre territórios

Verificação de missões (vitória)

Este trabalho atende aos requisitos das atividades propostas pela Estácio.

🎯 Objetivos do Projeto

✔ Criar um sistema em C para cadastro de territórios usando vetor de structs
✔ Implementar a lógica de ataque entre territórios usando ponteiros e alocação dinâmica
✔ Implementar o sistema de missões estratégicas e verificar condições de vitória

🗺️ Territórios Implementados

O jogo utiliza 8 territórios:

Ásia:

Sibéria

China

Japão

Índia

América do Sul:

Brasil

Argentina

Peru

Venezuela

Cada território possui:

Nome

Cor do jogador que controla

Tropas

⚔️ Funcionalidade de Ataque

O ataque funciona através de:

Rolagem de dados (1 a 6)

Comparação entre atacante e defensor

Transferência de território em caso de vitória

Redução de tropas em caso de derrota

🏆 Sistema de Missões

O programa verifica automaticamente se o jogador:

Conquistou toda a Ásia

Conquistou toda a América do Sul
