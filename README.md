# Jogo War - Estácio

Este projeto implementa uma versão simplificada do jogo War utilizando a linguagem C, trabalhando com:

- Structs
- Ponteiros
- Alocação dinâmica de memória (malloc e free)
- Modularização
- Lógica de ataque entre territórios
- Sistema de missões

## Objetivos do Projeto

✔ Criar um sistema em C para cadastro de territórios usando vetor de structs  
✔ Implementar a lógica de ataque entre territórios usando ponteiros e alocação dinâmica  
✔ Implementar o sistema de missões estratégicas e verificar condições de vitória

## Territórios Implementados

O jogo utiliza 6 territórios:

- Ásia
- Sibéria
- China
- Japão
- Índia
- América do Sul

## Funcionalidade de Ataque

### O ataque funciona da seguinte maneira:
- Rolagem de dados
- Comparação entre atacante e defensor
- Transferência de território em caso de vitória
- Redução de tropas em caso de derrota

## Sistema de Missões

### O programa verifica automaticamente se o jogador:

✔ Conquistou todos os territórios da Ásia  
✔ Conquistou todos os territórios da América do Sul

## Como Rodar o Jogo

1. Clone o repositório.
2. Compile o código utilizando o comando:

   ```bash
   gcc -o war_final war_final.c
