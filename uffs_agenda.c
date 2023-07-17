// RUAN PABLO VITKOSKI DE SOUZA
// 2221101033
//  -armazenar os eventos em uma estrutura de lista encadeada simples.
//  exempo de evento
//  Exemplo:
//   Código: 1   (codigo pra que se não vai ser usado )
//   Data: 24/12/2022
//   Hora: 19:00
//   Duração: 3.5
//   Descrição: Jantar de Natal no Palácio do Alvorada
//  -A consulta deverá ser
//        por data
//        por data e hora
//  menu
//  1-Incluir
//       Verificar se já existe um compromisso agendado para a mesma data e horário.
//  2-Consultar
//       por data - todos no dia
//       por data e hora -  o no dia e horario
//       “Agenda Vazia” caso não existam
//
//  3-Alterar
//       alterar a descrição e a duração de um compromisso.
//       alterar com base na data e hora (pra que usar codigo então ?)
//       “Compromisso não encontrado” caso não exista compromisso para a data e hora
//
//  4-Excluir
//       excluir comn consulta de data e hora
//  5-Listar todos
//       lista todos
//           ordenados (opcional)
//  6-Sair
//       sair do programa
//       limpar memoria
//  OPICIONAL
//       BST (binary search tree)
//       TAD (.h e .c)
//       ordena os compromissos da agenda por data e hora.

#include <stdio.h>
// #include <stdlib.h>
#include "agenda.h"
int main()
{
    int ops, True = 1;
    int count = 0;
    listaEvento *first = NULL;
    while (True)
    {
        printf("\no que deseja fazer:\n\t1-Incluir\n\t2-Consultar\n\t3-Alterar\n\t4-Excluir\n\t5-Listar todos\n\t6-Sair\n");
        scanf("%d", &ops);
        switch (ops)
        {
        case 6: // Sair do programa | limpar
            /* code */
            // goto EndWhile;
            freeMemory(first);
            True = 0;
            break;
        case 1: // Incluir
            first = inserirEvento(first, &count);
            break;
        case 2: // Consultar
            /* code */
            consultar(first);
            break;
        case 3: // Alterar
            /* code */
            alterar(first);
            break;
        case 4: // Excluir
            /* code */
            first = excluir(first);
            break;
        case 5: // Listar todos
            /* code */
            listarTodos(first);
            break;
        default:
            printf("opção invalida\n");
            // break;
        }
    }

    return 0;
}
