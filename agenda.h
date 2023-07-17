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

struct _arvore_evento
{
    Evento evento;
    struct _arvore_evento *direita;
    struct _arvore_evento *esquerda;
};
typedef struct _arvore_evento no;
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
Evento *CriarEvento(int *, listaEvento *, Evento *);
void printEvento(Evento);
listaEvento *inserirEvento(listaEvento *, int *);
int existeEvento(listaEvento *, Data);
int comparaDatas(Data, Data);
int comparaDataHora(Data, Data);
Evento *CriarEvento(int *, listaEvento *, Evento *);
void consultarData(listaEvento *);
void consultarDataHora(listaEvento *);
void consultar(listaEvento *);
void alterar(listaEvento *);
listaEvento *excluir(listaEvento *);
void listarTodos(listaEvento *);
void listarPorData(listaEvento *);
void listarPorCod(listaEvento *);
void limparBufferEntrada();
no *inserirNo(no *, no *);
void imprimeEmOrdem(no *);
no *limparArvore(no *);