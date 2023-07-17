struct _data
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};
typedef struct _data Data;

struct _evento
{
    int codigo;
    Data dataEvento;
    float duracao;
    char descricao[100];
};
typedef struct _evento Evento;

struct _lista_evento
{
    Evento evento;
    struct _lista_evento *next;
};
typedef struct _lista_evento listaEvento;

Data atribuiData();

void printData(Data);
void printDataHora(Data);

void freeMemory(listaEvento *);

Evento *CriarEvento(int *count, listaEvento *first, Evento *e);
void printEvento(Evento);
listaEvento *inserirEvento(listaEvento *first, int *count);
int existeEvento(listaEvento *first, Data data);
int comparaDatas(Data data1, Data data2);
int comparaDataHora(Data data1, Data data2);
Evento *CriarEvento(int *count, listaEvento *first, Evento *e);
void consultarData(listaEvento *first);
void consultarDataHora(listaEvento *first);
void consultar(listaEvento *first);
void alterar(listaEvento *first);
listaEvento *excluir(listaEvento *first);
void listarTodos(listaEvento *);
void listarPorData(listaEvento *);
void listarPorCod(listaEvento *);
void limparBufferEntrada();