#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"

void limparBufferEntrada()
{
    int c;
    // EOF fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void freeMemory(listaEvento *e)
{
    if (e == NULL)
    {
        printf("-");
        return;
    }
    freeMemory(e->next);
    free(e);
}

void printDataHora(Data d)
{
    printf("\n\tData-Hora: %02d/%02d/%4d | %2d:%02d", d.dia, d.mes, d.ano, d.hora, d.minuto);
};
void printEvento(Evento e)
{
    printf("\nEvento");
    printf("\n\tCódigo: %d", e.codigo);
    printDataHora(e.dataEvento);
    printf("\n\tDuração: %f", e.duracao);
    printf("\n\tdescrição: %s", e.descricao);
};

Data atribuiData()
{
    Data d;
    while (1)
    {
        // dia 1-31
        // mes 1-12
        printf("Informe a data do evento (DD/MM/AAAA):");
        scanf("%2d/%2d/%4d", &d.dia, &d.mes, &d.ano);
        if (((d.dia >= 1) && (d.dia <= 31)) && ((d.mes >= 1) && (d.mes <= 12)))
        {
            break;
        }
        printf("\ndata invalida!\n");
    }
    while (1)
    {
        // hora 0-23
        // 0-59
        printf("Informe a hora do evento (HH:MM):");
        scanf("%2d:%2d", &d.hora, &d.minuto);
        if (((d.hora >= 0) && (d.hora <= 23)) && ((d.minuto >= 0) && (d.minuto <= 59)))
        {
            break;
        }
        printf("\nhorario invalido!\n");
    }

    return d;
};

int comparaDataHora(Data data1, Data data2)
{
    if (data1.ano != data2.ano)
    {
        return 0;
    }
    if (data1.mes != data2.mes)
    {
        return 0;
    }
    if (data1.dia != data2.dia)
    {
        return 0;
    }
    if (data1.hora != data2.hora)
    {
        return 0;
    }
    if (data1.minuto != data2.minuto)
    {
        return 0;
    }
    return 1;
}
int comparaDatas(Data data1, Data data2)
{
    if (data1.ano != data2.ano)
    {
        return 0;
    }
    if (data1.mes != data2.mes)
    {
        return 0;
    }
    if (data1.dia != data2.dia)
    {
        return 0;
    }
    return 1;
}

int existeEvento(listaEvento *first, Data data)
{
    if (first == NULL)
    {
        return 0;
    }
    for (listaEvento *i = first; i != NULL; i = i->next)
    {
        if (comparaDataHora(data, i->evento.dataEvento) == 1)
        {
            return 1;
        }
    }
    return 0;
};

Evento *CriarEvento(int *count, listaEvento *first, Evento *e)
{
    e->dataEvento = atribuiData();
    if (existeEvento(first, e->dataEvento) == 1)
    {
        printf("já existe um compromisso agendado para a mesma data e horário.");
        return NULL;
    }
    printf("Informe a durção do evento:");
    scanf("%f", &e->duracao);
    printf("Informe a descrição do evento (maximo 100 caracter):");
    limparBufferEntrada();
    fgets(e->descricao, 100, stdin);

    *count = *count + 1;
    e->codigo = *count;
    return e;
};

listaEvento *inserirEvento(listaEvento *first, int *count)
{
    listaEvento *aux;
    aux = (listaEvento *)malloc(sizeof(listaEvento));
    Evento *e = (Evento *)malloc(sizeof(Evento));
    e = CriarEvento(count, first, e);
    if (e == NULL)
    {
        free(e);
        return first;
    }
    aux->evento = *e;
    aux->next = NULL;
    printf("\nEvento Criado com Sucesso");
    printEvento(aux->evento);
    free(e);
    if (first == NULL)
    {
        first = aux;
    }
    else
    {
        for (listaEvento *i = first; i != NULL; i = i->next)
        {
            if (i->next == NULL)
            {
                i->next = aux;
                break;
            }
        }
    }
    printf("\nEvento adicionado na Agenda com Sucesso");
    return first;
}

void consultarData(listaEvento *first)
{
    if (first == NULL)
    {
        printf("\nAgenda Fazia\n");
        return;
    }
    Data d;
    printf("Informe a data do evento:");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    listaEvento *i;
    printf("\nEventos:");
    for (i = first; i != NULL; i = i->next)
    {
        if (comparaDatas(d, i->evento.dataEvento) == 1)
        {
            printEvento(i->evento);
        }
    }
    if (i == NULL)
    {
        printf("\n\tAgenda Fazia\n");
    }
};
void consultarDataHora(listaEvento *first)
{
    if (first == NULL)
    {
        printf("\nAgenda Fazia\n");
        return;
    }
    Data d;
    printf("Informe a data do evento:");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    printf("Informe a hora do evento:");
    scanf("%d:%d", &d.hora, &d.minuto);
    printf("Eventos:");
    listaEvento *i;

    for (i = first; i != NULL; i = i->next)
    {
        if (comparaDatas(d, i->evento.dataEvento) == 1)
        {
            printEvento(i->evento);
            break;
        }
    }
    if (i == NULL)
    {
        printf("\n\tAgenda Fazia\n");
    }
};

void consultar(listaEvento *first)
{
    int ops, True = 1;
    while (True)
    {
        printf("\nconsultar por:\n\t1-Data\n\t2-Data e Hora\n\t3-Voltar\n");
        scanf("%d", &ops);
        switch (ops)
        {
        case 1:
            consultarData(first);
            // True = 0;
            break;
        case 2:
            consultarDataHora(first);
            // True = 0;
            break;
        case 3:
            True = 0;
            break;
        default:
            printf("opção invalida\n");
            break;
        }
    }
}

void alterar(listaEvento *first)
{
    if (first == NULL)
    {
        printf("Agenda Fazia\n");
        return;
    }
    Data d;
    printf("Informe a data do evento:");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    printf("Informe a hora do evento:");
    scanf("%d:%d", &d.hora, &d.minuto);
    listaEvento *aux = NULL;
    for (listaEvento *i = first; i != NULL; i = i->next)
    {
        if (comparaDataHora(d, i->evento.dataEvento) == 1)
        {
            printEvento(i->evento);
            aux = i;
            break;
        }
    }
    if (aux == NULL)
    {
        printf("\tCompromisso não encontrado");
    }
    else
    {
        int ops, True = 1;
        while (True)
        {
            printf("\nAlterar :\n\t1-descrição\n\t2-duração \n\t3-descrição e duração \n");
            scanf("%d", &ops);
            switch (ops)
            {
            case 1:
                printf("Informe a descrição do evento para alterar (maximo 100 caracter):");
                limparBufferEntrada();
                fgets(aux->evento.descricao, 100, stdin);
                True = 0;
                break;
            case 2:
                printf("Informe a durção do evento para alterar:");
                scanf("%f", &aux->evento.duracao);
                True = 0;
                break;
            case 3:
                printf("Informe a durção do evento para alterar:");
                scanf("%f", &aux->evento.duracao);
                printf("Informe a descrição do evento para alterar (maximo 100 caracter):");
                limparBufferEntrada();
                fgets(aux->evento.descricao, 100, stdin);
                True = 0;
                break;
            default:
                printf("opção invalida\n");
                break;
            }
        }
    }
}

listaEvento *excluir(listaEvento *first)
{
    if (first == NULL)
    {
        printf("Agenda Fazia\n");
        return first;
    }
    Data d;
    printf("Informe a data do evento:");
    scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
    printf("Informe a hora do evento:");
    scanf("%d:%d", &d.hora, &d.minuto);
    printf("Eventos:");
    listaEvento *aux, *i;
    for (i = first; i != NULL; i = i->next)
    {
        if (comparaDatas(d, i->evento.dataEvento) == 1)
        {
            printEvento(i->evento);
            break;
        }
        aux = i;
    }
    if (i == NULL)
    {
        printf("\tCompromisso não encontrado");
    }
    else
    {
        if (first == i)
        {
            first = i->next;
            free(i);
        }
        else
        {
            aux->next = i->next;
            free(i);
        }
    }
    return first;
}

void listarPorData(listaEvento *first)
{
}
void listarPorCod(listaEvento *first)
{
    printf("Eventos:");
    listaEvento *i;
    for (i = first; i != NULL; i = i->next)
    {
        printEvento(i->evento);
    }
}
void listarTodos(listaEvento *first)
{
    if (first == NULL)
    {
        printf("\nAgenda Fazia\n");
        return;
    }
    int ops, True = 1;
    while (True)
    {
        printf("\nListar por:\n\t1-Ordem de criação\n\t2-Ordem de Data Hora\n\t3-Voltar\n");
        scanf("%d", &ops);
        switch (ops)
        {
        case 1:
            listarPorCod(first);
            True = 0;
            break;
        case 2:
            listarPorData(first);
            True = 0;
            break;
        case 3:
            True = 0;
            break;
        default:
            printf("opção invalida\n");
            break;
        }
    }
};