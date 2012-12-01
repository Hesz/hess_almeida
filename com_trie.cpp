#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct lista_usuario
{
    char usuario[50];
    struct lista_usuario *prox;
};typedef struct lista_usuario Lista_usuario;

struct lista_hashtags
{
    char tag[140]; //Hashtag utilizada pelo usuário.
    int ocorrencias;
    struct lista_hashtags *prox;
};typedef struct lista_hashtags Lista_hashtags;

struct lista_amigos
{//Armazena uma lista com o nome dos amigos que foram retweetados
    char nome[50]; //Nome do amigo
    int ocorrencias;
    struct lista_amigos *prox; //Aponta para o próximo amigo.
};typedef struct lista_amigos Lista_amigos;

struct lista_mentions
{//Armazena uma lista com o nome dos amigos que foram retwetados
    char nome[50]; //Nome do user que foi mencionado.
    int ocorrencias;
    struct lista_mentions *prox; //Aponta para o próximo nodo.
};typedef struct lista_mentions Lista_mentions;

struct local
{//Todos os locais de todos os usuários.
    char nome[50]; //Nome da cidade/local.
    int ocorrencias;
    local *prox; //Lista de locais.
};typedef struct local Local;

struct inf_tweet
{
    char palavras[800];  //Todas as palavras uteis são armazenadas aqui (separadas por ' ')
    char data[10]; //IMPORTANTE! Converter para int, ou não.
    char horario[8]; //IMPORTANTE! Converter para int, ou não.
    int num_palavras;  //Número de palavras úteis armazenadas.
};typedef struct inf_tweet Inf_tweet;

struct horarios
{
    int hora_00;
    int hora_01;
    int hora_02;
    int hora_03;
    int hora_04;
    int hora_05;
    int hora_06;
    int hora_07;
    int hora_08;
    int hora_09;
    int hora_10;
    int hora_11;
    int hora_12;
    int hora_13;
    int hora_14;
    int hora_15;
    int hora_16;
    int hora_17;
    int hora_18;
    int hora_19;
    int hora_20;
    int hora_21;
    int hora_22;
    int hora_23;
};typedef struct horarios Horas;

struct user
{//Informações de um usuário;
    char nome[50]; //Nome do usuário.
    char local[50]; //Local do usuário.
    Lista_amigos *amigos; //List que contem os amigos que foram retwetados.
    Lista_mentions *mentions; //Lista com todos os usuários que receberam mentions.
            //Ponteiro para a árvore TRIE com as palavras do usuário.
    Lista_hashtags *hashtags; //Lista com todas as hashtags utilizadas pelo usuário.
    Horas *horarios_user;
    char palavras[28000];
    struct user *prox;
};typedef struct user User;

struct inf_geral
{
    Local *lis_local;
    Lista_mentions *lis_mentions;
    Lista_hashtags *lis_hashtags;
    Lista_amigos *lis_amigos;
    Horas *tab_horarios;
    User *usuarios;
    Lista_usuario *lis_usuario;
};typedef struct inf_geral GERAL;

int risos(char palavra[140])
{
    int carac=0,cont_k=0,cont_h=0,cont_rs=0,cont_kop=0,cont_ha=0;
    while(palavra[carac]!=0)
    {
        if(palavra[carac]=='k')
            cont_k++;
        if(palavra[carac]=='h' || palavra[carac]=='a' || palavra[carac]=='s' || palavra[carac]=='u' || palavra[carac]=='e' || palavra[carac]=='i' || palavra[carac]=='d' || palavra[carac]=='j')
            cont_h++;
        if(palavra[carac]=='r' || palavra[carac]=='s')
            cont_rs++;
        if(palavra[carac]=='k' || palavra[carac]=='o' || palavra[carac]=='p' || palavra[carac]=='s' || palavra[carac]=='a')
            cont_kop++;
        if(palavra[carac]=='h' || palavra[carac]=='a')
            cont_ha++;
        carac++;
    }
    if((float)cont_k/(float)carac > 0.85 || (carac>9 && (float)cont_h/(float)carac > 0.74) || (float)cont_rs/(float)carac > 0.8 || (float)cont_kop/(float)carac > 0.9 || (float)cont_ha/(float)carac >0.95 || carac<4)
        return 1;
    else
        return 0;
}

void trata_pal(char palavra[140])
{
    int cont=0;
    while(palavra[cont]!=0)
    {
        if(palavra[cont]==-30 || palavra[cont]==-31 || palavra[cont]==-63 || palavra[cont]==-32 || palavra[cont]==-64 || palavra[cont]==-28 || palavra[cont]==-60 || palavra[cont]==-29 || palavra[cont]==-61 || palavra[cont]==-62)
            palavra[cont]='a';
        else
        {
            if(palavra[cont]==-6 || palavra[cont]==-38 || palavra[cont]==-7 || palavra[cont]==-39 || palavra[cont]==-5 || palavra[cont]==-37 || palavra[cont]==-4 || palavra[cont]==-36)
                palavra[cont]='u';
            else
            {
                if(palavra[cont]==-22 || palavra[cont]==-54 || palavra[cont]==-23 || palavra[cont]==-55 || palavra[cont]==-24 || palavra[cont]==-56 || palavra[cont]==-21 || palavra[cont]==-53)
                    palavra[cont]='e';
                else
                {
                    if(palavra[cont]==-19 || palavra[cont]==-51 || palavra[cont]==-20 || palavra[cont]==-52 || palavra[cont]==-18 || palavra[cont]==-50 || palavra[cont]==-17 || palavra[cont]==-49)
                        palavra[cont]='i';
                    else
                    {
                        if(palavra[cont]==-13 || palavra[cont]==-45 || palavra[cont]==-14 || palavra[cont]==-46 || palavra[cont]==-12 ||    palavra[cont]==-44 || palavra[cont]==-11 || palavra[cont]==-43 || palavra[cont]==-10 || palavra[cont]==-42)
                            palavra[cont]='o';
                        else
                        {
                            if(palavra[cont]==-25 || palavra[cont]==-57)
                                palavra[cont]='c';
                            else
                                if(palavra[cont]==-15 || palavra[cont]==-47)
                                    palavra[cont]='n';
                        }
                    }
                }
            }
        }
        palavra[cont]=tolower(palavra[cont]);
        cont++;
    }
}

struct trie{                //ÁRVORE COM TODOS OS PONTEIROS, IDENTIFICADOR DE CARACTERE E CONTADOR DE OCORRÊNCIAS
    char carac;
    int ocorr;
    struct trie *l_a;
    struct trie *l_b;
    struct trie *l_c;
    struct trie *l_d;
    struct trie *l_e;
    struct trie *l_f;
    struct trie *l_g;
    struct trie *l_h;
    struct trie *l_i;
    struct trie *l_j;
    struct trie *l_k;
    struct trie *l_l;
    struct trie *l_m;
    struct trie *l_n;
    struct trie *l_o;
    struct trie *l_p;
    struct trie *l_q;
    struct trie *l_r;
    struct trie *l_s;
    struct trie *l_t;
    struct trie *l_u;
    struct trie *l_v;
    struct trie *l_w;
    struct trie *l_x;
    struct trie *l_y;
    struct trie *l_z;
};
typedef struct trie trai;

trai* insere_u(char str[140],int index, trai *a);

trai* seta_carac(char let,trai *a)              //SE É ENTRADO UM NOVO NODO, TUDO SETADO PRA NULL E PRA 0
{
    a->carac=let;
    a->l_a=NULL;
    a->l_b=NULL;
    a->l_c=NULL;
    a->l_d=NULL;
    a->l_e=NULL;
    a->l_f=NULL;
    a->l_g=NULL;
    a->l_h=NULL;
    a->l_i=NULL;
    a->l_j=NULL;
    a->l_k=NULL;
    a->l_l=NULL;
    a->l_m=NULL;
    a->l_n=NULL;
    a->l_o=NULL;
    a->l_p=NULL;
    a->l_q=NULL;
    a->l_r=NULL;
    a->l_s=NULL;
    a->l_t=NULL;
    a->l_u=NULL;
    a->l_v=NULL;
    a->l_w=NULL;
    a->l_x=NULL;
    a->l_y=NULL;
    a->l_z=NULL;
    a->ocorr=0;
    return a;
}

void imprime_pal (trai *a, char str[140], int i)
{
    if(i!=-1)
    {
        str[i]=a->carac;
        str[i+1]=0;
        if(a->ocorr!=0)
            printf("%s - %d\n",str,a->ocorr);
    }
    if (a->l_a!=NULL)
        imprime_pal(a->l_a,str,i+1);
    if (a->l_b!=NULL)
        imprime_pal(a->l_b,str,i+1);
    if (a->l_c!=NULL)
        imprime_pal(a->l_c,str,i+1);
    if (a->l_d!=NULL)
        imprime_pal(a->l_d,str,i+1);
    if (a->l_e!=NULL)
        imprime_pal(a->l_e,str,i+1);
    if (a->l_f!=NULL)
        imprime_pal(a->l_f,str,i+1);
    if (a->l_g!=NULL)
        imprime_pal(a->l_g,str,i+1);
    if (a->l_h!=NULL)
        imprime_pal(a->l_h,str,i+1);
    if (a->l_i!=NULL)
        imprime_pal(a->l_i,str,i+1);
    if (a->l_j!=NULL)
        imprime_pal(a->l_j,str,i+1);
    if (a->l_k!=NULL)
        imprime_pal(a->l_k,str,i+1);
    if (a->l_l!=NULL)
        imprime_pal(a->l_l,str,i+1);
    if (a->l_m!=NULL)
        imprime_pal(a->l_m,str,i+1);
    if (a->l_n!=NULL)
        imprime_pal(a->l_n,str,i+1);
    if (a->l_o!=NULL)
        imprime_pal(a->l_o,str,i+1);
    if (a->l_p!=NULL)
        imprime_pal(a->l_p,str,i+1);
    if (a->l_q!=NULL)
        imprime_pal(a->l_q,str,i+1);
    if (a->l_r!=NULL)
        imprime_pal(a->l_r,str,i+1);
    if (a->l_s!=NULL)
        imprime_pal(a->l_s,str,i+1);
    if (a->l_t!=NULL)
        imprime_pal(a->l_t,str,i+1);
    if (a->l_u!=NULL)
        imprime_pal(a->l_u,str,i+1);
    if (a->l_v!=NULL)
        imprime_pal(a->l_v,str,i+1);
    if (a->l_w!=NULL)
        imprime_pal(a->l_w,str,i+1);
    if (a->l_x!=NULL)
        imprime_pal(a->l_x,str,i+1);
    if (a->l_y!=NULL)
        imprime_pal(a->l_y,str,i+1);
    if (a->l_z!=NULL)
        imprime_pal(a->l_z,str,i+1);
}

trai* sw_ca(char str[140],int index, trai *a)
{
    if(str[index+1]==0) //TESTA SE A STRING ACABOU. SE SIM, RETORNA A ÁRVORE RECURSIVAMENTE
        return a;
    else
    {
        switch(str[index+1])                //SE NÃO ACABOU, VAI PRA FUNÇÃO INSERE DA PRÓXIMA LETRA
        {
            case 97:
                a->l_a=insere_u(str,index+1,a->l_a);
                break;
            case 98:
                a->l_b=insere_u(str,index+1,a->l_b);
                break;
            case 99:
                a->l_c=insere_u(str,index+1,a->l_c);
                break;
            case 100:
                a->l_d=insere_u(str,index+1,a->l_d);
                break;
            case 101:
                a->l_e=insere_u(str,index+1,a->l_e);
                break;
            case 102:
                a->l_f=insere_u(str,index+1,a->l_f);
                break;
            case 103:
                a->l_g=insere_u(str,index+1,a->l_g);
                break;
            case 104:
                a->l_h=insere_u(str,index+1,a->l_h);
                break;
            case 105:
                a->l_i=insere_u(str,index+1,a->l_i);
                break;
            case 106:
                a->l_j=insere_u(str,index+1,a->l_j);
                break;
            case 107:
                a->l_k=insere_u(str,index+1,a->l_k);
                break;
            case 108:
                a->l_l=insere_u(str,index+1,a->l_l);
                break;
            case 109:
                a->l_m=insere_u(str,index+1,a->l_m);
                break;
            case 110:
                a->l_n=insere_u(str,index+1,a->l_n);
                break;
            case 111:
                a->l_o=insere_u(str,index+1,a->l_o);
                break;
            case 112:
                a->l_p=insere_u(str,index+1,a->l_p);
                break;
            case 113:
                a->l_q=insere_u(str,index+1,a->l_q);
                break;
            case 114:
                a->l_r=insere_u(str,index+1,a->l_r);
                break;
            case 115:
                a->l_s=insere_u(str,index+1,a->l_s);
                break;
            case 116:
                a->l_t=insere_u(str,index+1,a->l_t);
                break;
            case 117:
                a->l_u=insere_u(str,index+1,a->l_u);
                break;
            case 118:
                a->l_v=insere_u(str,index+1,a->l_v);
                break;
            case 119:
                a->l_w=insere_u(str,index+1,a->l_w);
                break;
            case 120:
                a->l_x=insere_u(str,index+1,a->l_x);
                break;
            case 121:
                a->l_y=insere_u(str,index+1,a->l_y);
                break;
            case 122:
                a->l_z=insere_u(str,index+1,a->l_z);
                break;
        }
        return a;
    }
}

GERAL *case_1(GERAL *novo);

void menu(GERAL *novo)
{   //FUNÇÃO QUE ABRE O MENU E FAZ COM QUE O USUÁRIO ESCOLHA SUA OPÇÃO
    int op;
    Lista_mentions *teste, *teste2;
    while(op!=6)
    {
        printf("Entre com sua opcao: ");
        printf("\n1 - Inserir novo usuario");
        printf("\n2 - Listar informacoes por localidade");
        printf("\n3 - Listar informacoes por hashtag");
        printf("\n4 - Listar informacoes por usuario");
        printf("\n5 - Listar informacoes gerais");
        printf("\n6 - Salvar dados e encerrar programa\n");
        scanf("%d", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                case_1(novo);
                break;
            case 2: //CHAMA INFORMAÇÕES POR LOCALIDADE;
                break;
            case 3: //CHAMA INFORMAÇÕES POR HASHTAG;
                break;
            case 4: //CHAMA INFORMAÇÕES POR USUÁRIO;
                break;
            case 5: //CHAMA INFORMAÇÕES GERAIS;
                break;
            case 6: //ENCERRA PROGRAMA;
                break;
            default:
                printf("\n\nOpcao invalida, entre novamente\n");
                system("pause");
                break;
        }
        system("cls");
    }
}

trai* insere_u(char str[140],int index, trai *a)
{
    if(a==NULL) //SE O NODO NÃO EXISTE, ELE É ACRESCENTADO
    {
        a = (trai*) malloc(sizeof(trai));
        a = seta_carac(str[index],a);
    }
    a=sw_ca(str,index,a);   //SE EXISTE OU NÃO, O PRÓXIMO É TESTADO.
    if(str[index+1]==0)
        a->ocorr++;         //SE É O ÚLTIMO ELEMENTO DA STRING, OCORRÊNCIAS É INCREMENTADO
    return a;
}

User *insere_usuar(User *novo_user, char nome_u[50])
{
    if(novo_user==NULL)
    {
        novo_user = (User*) malloc(sizeof(User));
        strcpy(novo_user->nome,nome_u);
        novo_user->hashtags = NULL;
        novo_user->mentions = NULL;
        novo_user->amigos = NULL;
        novo_user->horarios_user = NULL;
        novo_user->prox = NULL;
    }
    else
        novo_user->prox = insere_usuar(novo_user->prox, nome_u);
    return novo_user;
}

Local *insere_local(Local *novo_local, char nome_local[50])
{
    if(novo_local==NULL)
    {
        novo_local = (Local*) malloc(sizeof(Local));
        strcpy(novo_local->nome,nome_local);
        novo_local->ocorrencias = 1;
        novo_local->prox = NULL;
    }
    else
    {
        if(strcmp(novo_local->nome,nome_local)==0)
            novo_local->ocorrencias++;
        else
            novo_local->prox = insere_local(novo_local->prox, nome_local);
    }
    return novo_local;
}

Lista_amigos *insere_amigo(Lista_amigos *novo_amigo, char nome_amigo[50])
{
    if(novo_amigo == NULL)
    {
        novo_amigo = (Lista_amigos*) malloc(sizeof(Lista_amigos));
        strcpy(novo_amigo->nome,nome_amigo);
        novo_amigo->ocorrencias = 1;
        novo_amigo->prox = NULL;
    }
    else
    {
        if(strcmp(novo_amigo->nome,nome_amigo)==0)
            novo_amigo->ocorrencias++;
        else
            novo_amigo->prox = insere_amigo(novo_amigo->prox, nome_amigo);
    }
    return novo_amigo;
}

Lista_hashtags *insere_hashtag(Lista_hashtags *nova_hash, char nome_hash[140])
{
    if(nova_hash==NULL)
    {
        nova_hash = (Lista_hashtags*) malloc(sizeof(Lista_hashtags));
        strcpy(nova_hash->tag,nome_hash);
        nova_hash->ocorrencias = 1;
        nova_hash->prox = NULL;
    }
    else
    {
        if(strcmp(nome_hash,nova_hash->tag)==0)
            nova_hash->ocorrencias++;
        else
            nova_hash->prox = insere_hashtag(nova_hash->prox, nome_hash);
    }
    return nova_hash;
}

Lista_mentions *insere_mention(Lista_mentions *nova_mention, char nome_mention[50])
{
    if(nova_mention==NULL)
    {
        nova_mention = (Lista_mentions*) malloc(sizeof(Lista_mentions));
        strcpy(nova_mention->nome,nome_mention);
        nova_mention->ocorrencias = 1;
        nova_mention->prox = NULL;
    }
    else
    {
        if(strcmp(nome_mention,nova_mention->nome)==0)
            nova_mention->ocorrencias++;
        else
            nova_mention->prox = insere_mention(nova_mention->prox, nome_mention);    //SE NÃO ACHOU O USUÁRIO DA MENTION, SEGUE RODANDO A LISTA
    }
    return nova_mention;
}

void atualiza_hora(Horas *geral,char hora[8])
{   //FUNÇÃO QUE ATUALIZA AS HORAS, SE NÃO EXISTE PONTEIRO, ALOCA LOCAL E JÁ ATUALIZA, COM SWITCH CASE DO PRIMEIRO CARACTERE E DO SEGUNDO
    if(geral==NULL)
    {
        geral = (Horas*) malloc(sizeof(Horas));
        geral->hora_00=0;
        geral->hora_01=0;
        geral->hora_02=0;
        geral->hora_03=0;
        geral->hora_04=0;
        geral->hora_05=0;
        geral->hora_06=0;
        geral->hora_07=0;
        geral->hora_08=0;
        geral->hora_09=0;
        geral->hora_10=0;
        geral->hora_11=0;
        geral->hora_12=0;
        geral->hora_13=0;
        geral->hora_14=0;
        geral->hora_15=0;
        geral->hora_16=0;
        geral->hora_17=0;
        geral->hora_18=0;
        geral->hora_19=0;
        geral->hora_20=0;
        geral->hora_21=0;
        geral->hora_22=0;
        geral->hora_23=0;
    }
    switch(hora[0])
    {
        case '2':
            switch(hora[1])
            {
                case '3':
                    geral->hora_23++;
                    break;
                case '2':
                    geral->hora_22++;
                    break;
                case '1':
                    geral->hora_21++;
                    break;
                case '0':
                    geral->hora_20++;
                    break;
            }
            break;
        case '1':
            switch(hora[1])
            {
                case '9':
                    geral->hora_19++;
                    break;
                case '8':
                    geral->hora_18++;
                    break;
                case '7':
                    geral->hora_17++;
                    break;
                case '6':
                    geral->hora_16++;
                    break;
                case '5':
                    geral->hora_15++;
                    break;
                case '4':
                    geral->hora_14++;
                    break;
                case '3':
                    geral->hora_13++;
                    break;
                case '2':
                    geral->hora_12++;
                    break;
                case '1':
                    geral->hora_11++;
                    break;
                case '0':
                    geral->hora_10++;
                    break;
            }
            break;
        case '0':
            switch(hora[1])
            {
                case '9':
                    geral->hora_09++;
                    break;
                case '8':
                    geral->hora_08++;
                    break;
                case '7':
                    geral->hora_07++;
                    break;
                case '6':
                    geral->hora_06++;
                    break;
                case '5':
                    geral->hora_05++;
                    break;
                case '4':
                    geral->hora_04++;
                    break;
                case '3':
                    geral->hora_03++;
                    break;
                case '2':
                    geral->hora_02++;
                    break;
                case '1':
                    geral->hora_01++;
                    break;
                case '0':
                    geral->hora_00++;
                    break;
            }
            break;
    }
}

User *atualiza_geral(User *do_geral, User *aux)
{
    if(do_geral==NULL)
    {
        do_geral = (User*) malloc(sizeof(User));
        strcpy(do_geral->nome,aux->nome);
        strcpy(do_geral->local,aux->local);
        do_geral->hashtags = aux->hashtags;
        do_geral->amigos = aux->amigos;
        do_geral->horarios_user = aux->horarios_user;
        do_geral->mentions = aux->mentions;
        strcpy(do_geral->palavras,aux->palavras);
        do_geral->prox = NULL;
    }
    else
        do_geral->prox = atualiza_geral(do_geral->prox,aux);
    return do_geral;
}

GERAL *case_1(GERAL *novo)
{
    FILE *arq;
    User *aux_user = novo->usuarios;
    char nome_usuario[50], palavra[140], nome_hashtag[140], nome_RT[140], nome_mention[140], local[140], auxiliar[140],string[140];
    Inf_tweet ult_tweet;
    int i=0,sair=0,pos_atual=0,pos_fim=0, diferente=0,riso,acabou=0,j=0, option, total_tweets=0,cont;
    system("cls");
    puts("Informe o nome do usuario: ");
    gets(nome_usuario);
    strcat(nome_usuario,".txt");
    if(arq = fopen(nome_usuario,"r+"))
    {
        fscanf(arq,"%s",palavra); //Lê nome user.
        strcpy(nome_usuario,palavra);
        aux_user = insere_usuar(aux_user,nome_usuario); //INSERE NOVO USUÁRIO, PRECISA FAZER CONSISTÊNCIA PARA TESTAR SE NÃO EXISTE
        while(strcmp(aux_user->nome,nome_usuario))   //CARREGA A STRUCT DO USUÁRIO A TER INFORMAÇÕES PREENCHIDAS
            aux_user = aux_user->prox;
        fscanf(arq,"%s",palavra); //Lê local;
        strcpy(local,palavra);
        strcpy(aux_user->local,local);          //COLOCA LOCAL NA STRUCT DO USUÁRIO
        novo->lis_local = insere_local(novo->lis_local,local);    //ATUALIZA A LISTA DOS LOCAIS COM O NOVO LOCAL
        total_tweets=0;
        while(total_tweets<200)
        {
            acabou=0;
            for(j=0;j<800;j++)
                ult_tweet.palavras[j]=0;
            while(acabou==0)
            {
                fscanf(arq,"%s",auxiliar);
                option=0;
                if(strcmp(auxiliar,"|*|")==0)
                    option=1;
                    else if(strcmp(auxiliar,"RT")==0)
                        option=2;
                        else if(auxiliar[0]=='@')
                                option=3;
                                else if(auxiliar[0]=='#')
                                        option=4;
                switch(option)
                {
                    case 1://Deve ler a data e salvar e o horario e mandar pro arquivo o resto.
                            acabou=1; //Pra começar a ler um novo tweet depois do ciclo.
                            total_tweets++; //Leu todos os tweets.
                            fscanf(arq,"%s",auxiliar); //Lê a data.
                            strcpy(ult_tweet.data,auxiliar);
                            fscanf(arq,"%s",auxiliar); //Lê horário.
                            strcpy(ult_tweet.horario,auxiliar);
                            atualiza_hora(novo->tab_horarios,ult_tweet.horario);     //ATUALIZA O HORÁRIO NA TABELA GERAL DE HORÁRIOS
                            atualiza_hora(aux_user->horarios_user,ult_tweet.horario);   //ATUALIZA AS HORAS DOS TWEETS DO USUÁRIO
                            break;
                     case 2://É RT
                            fscanf(arq,"%s",auxiliar); //Lê a proxima palavra do texto, que é o nome do amigo.
                            strcpy(nome_RT,auxiliar);
                            aux_user->amigos = insere_amigo(aux_user->amigos,nome_RT);  //ATUALIZA A LISTA DOS RETWEETS FEITOS PELO USUÁRIO
                            novo->lis_amigos = insere_amigo(novo->lis_amigos,nome_RT);                  //ATUALIZA A LISTA DOS RETWEETS GERAIS
                            //Deve criar a lista com os amigos.
                            break;
                     case 3://É Mention
                            strcpy(nome_mention,auxiliar); //Copia o nome do amigo mencionado pra inserir na lista.
                            aux_user->mentions = insere_mention(aux_user->mentions,nome_mention);   //ATUALIZA A LISTA DE MENTIONS DO USUÁRIO
                            novo->lis_mentions = insere_mention(novo->lis_mentions,nome_mention);                   //ATUALIZA A LISTA DE MENTIONS GERAL
                            //Criar a lista de mentions.
                            break;
                     case 4://É hashtag
                            strcpy(nome_hashtag,auxiliar);
                            aux_user->hashtags = insere_hashtag(aux_user->hashtags,nome_hashtag);   //ATUALIZA A LISTA DE HASHTAGS DO USUÁRIO
                            novo->lis_hashtags = insere_hashtag(novo->lis_hashtags,nome_hashtag);                   //ATUALIZA A LISTA DE HASHTAGS GERAL
                            //Criar a lista de tags.
                            break;
                     default://Se não é nenhum dos casos, trata a palavra e vê se ela é válida para ser inserida.
                            trata_pal(auxiliar);//Elimina acentos e coloca tudo em minusculo.
                            pos_atual=0; //Seta o valor para 0.
                            cont=0;
                            while(auxiliar[cont]!=0)
                            {
                                if(auxiliar[cont]>= 'a' && auxiliar[cont]<= 'z')
                                {
                                    if(auxiliar[cont]=='h' && auxiliar[cont+1]=='t' && auxiliar[cont+2]=='t' && auxiliar[cont+3]=='p')  //TESTA SE É LINK
                                        auxiliar[cont]=0;
                                    palavra[pos_atual]=auxiliar[cont];
                                    pos_atual++;
                                }
                                cont++;
                            }
                            palavra[pos_atual]=0;
                            riso=risos(palavra);
                            if(riso==0)//Não é risada! Salva a palavra na struct.
                            {
                                strcat(ult_tweet.palavras,palavra); //Se for útil manda pro array.
                                strcat(ult_tweet.palavras," ");  //Insere o separador.
                                ult_tweet.num_palavras++;
                            }
                            break;
                }
            }
            strcat(aux_user->palavras,ult_tweet.palavras);  //COLOCA AS PALAVRAS RELEVANTES NA STRING DO USUÁRIO
        }
        fclose(arq);
        puts("\n\nUsuario inserido com sucesso!");
    }
     else
    {
        //atualizar log de eventos com erro.
        puts("\n\nNao foi possivel encontrar o usuario.");
    }
    system("pause");
    novo->usuarios = atualiza_geral(novo->usuarios,aux_user);
    return novo;
}

int main()
{
    GERAL *novo;
    novo = (GERAL*) malloc(sizeof(GERAL));
    novo->lis_local=NULL;
    novo->lis_mentions=NULL;
    novo->lis_hashtags=NULL;
    novo->lis_amigos=NULL;
    novo->tab_horarios=NULL;
    novo->usuarios=NULL;
    novo->lis_usuario=NULL;
    menu(novo);  //CHAMA O MENU
    return 0;
}

    /*
    FILE *arq, *tst;
    char nome_usuario[50], palavra[140], nome_hashtag[140], nome_RT[140], nome_mention[140], local[140], auxiliar[140],string[140];
    Inf_tweet ult_tweet;
    int i=0,sair=0,pos_atual=0,pos_fim=0, diferente=0,riso,acabou=0,j=0, option, total_tweets=0,cont;
    trai* alvore=(trai*) malloc(sizeof(trai));
    alvore=seta_carac(0,alvore);
    User info_usuario;

    puts("Informe o nome do usuario: ");
    gets(nome_usuario);
    strcat(nome_usuario,".txt");
    for(j=0;j<240;j++)
        ult_tweet.palavras[j]=0;
    tst=fopen("teste2.txt","w+");//COMETNAR DEPOIS QUE NÃO USAR MAIS O ARQUIVO DE TESTE.
    if(arq=fopen(nome_usuario,"r+"))
    {
        //Atualizar log de eventos com informação que abriu o arquivo.
        fscanf(arq,"%s",palavra); //Lê nome user.
        strcpy(nome_usuario,palavra);
        fscanf(arq,"%s",palavra); //Lê local;
        strcpy(local,palavra);
        total_tweets=0;
        while((total_tweets==0) || total_tweets<200)
        {
            acabou=0;
            for(j=0;j<260;j++)
                ult_tweet.palavras[j]=0;
            //puts(ult_tweet.palavras);
            while(acabou==0)
            {
                fscanf(arq,"%s",auxiliar);
                option=0;
                if(strcmp(auxiliar,"|*|")==0)
                    option=1;
                    else if(strcmp(auxiliar,"RT")==0)
                        option=2;
                        else if(auxiliar[0]=='@')
                                option=3;
                                else if(auxiliar[0]=='#')
                                        option=4;
                switch(option)
                {
                    case 1://Deve ler a data e salvar e o horario e mandar pro arquivo o resto.
                            acabou=1; //Pra começar a ler um novo tweet depois do ciclo.
                            total_tweets++; //Leu todos os tweets.
                            fscanf(arq,"%s",auxiliar); //Lê a data.
                            strcpy(ult_tweet.data,auxiliar);
                            //puts(ult_tweet.data);
                            fscanf(arq,"%s",auxiliar); //Lê horário.
                            strcpy(ult_tweet.horario,auxiliar);
                            //puts(ult_tweet.horario);
                          //  system("pause");
                            fputs(ult_tweet.palavras,tst);
                            fflush(tst);
                            //puts(ult_tweet.palavras);
                           // system("pause");
                            //system("pause");
                            putc('-',tst);
                            fputs(ult_tweet.data,tst);
                            fflush(tst);
                            //puts(ult_tweet.data);
                       //     system("pause");
                            putc('-',tst);
                           // fputs(ult_tweet.horario,tst);
                           // puts("   ");
                            //system("pause");
                            putc('\n',tst);
                            fflush(tst);
                            //puts(ult_tweet.palavras);
                            //system("pause");
                            break;
                     case 2://É RT
                            fscanf(arq,"%s",auxiliar); //Lê a proxima palavra do texto, que é o nome do amigo.
                            strcpy(nome_RT,auxiliar);
                            //Deve criar a lista com os amigos.
                            break;
                     case 3://É Mention
                            strcpy(nome_mention,auxiliar); //Copia o nome do amigo mencionado pra inserir na lista.
                            //Criar a lista de mentions.
                            break;
                     case 4://É hashtag
                            strcpy(nome_hashtag,auxiliar);
                            //Criar a lista de tags.
                            break;
                     default://Se não é nenhum dos casos, trata a palavra e vê se ela é válida para ser inserida.
                            trata_pal(auxiliar);//Elimina acentos e coloca tudo em minusculo.
                            pos_atual=0; //Seta o valor para 0.
                            cont=0;
                            while(auxiliar[cont]!=0)
                            {
                                if(auxiliar[cont]>= 'a' && auxiliar[cont]<= 'z')
                                {
                                    if(auxiliar[cont]=='h' && auxiliar[cont+1]=='t' && auxiliar[cont+2]=='t' && auxiliar[cont+3]=='p')
                                        auxiliar[cont]=0;
                                    palavra[pos_atual]=auxiliar[cont];
                                    pos_atual++;
                                }
                                cont++;
                            }
                            palavra[pos_atual]=0;
                            riso=risos(palavra);
                            if(riso==0)//Não é risada! Salva a palavra na struct.
                            {
                                strcat(ult_tweet.palavras,palavra); //Se for útil manda pro array.
                                strcat(ult_tweet.palavras,"|");  //Insere o separador.
                                ult_tweet.num_palavras++;
                            }
                            break;
                }
            }
            cont=0;
            while(ult_tweet.palavras[cont]!=0)
            {
                i=0;
                while(ult_tweet.palavras[cont]!='|')
                {
                    auxiliar[i]=ult_tweet.palavras[cont];
                    i++;
                    cont++;
                }
                auxiliar[i]=0;
                alvore=insere_u(auxiliar,-1,alvore);
                cont++;
            }
        }
        fclose(arq);
    }
     else
    {
        //atualizar log de eventos com erro.
        puts("Nao foi possivel encontrar o arquivo.");
    }
    fclose(tst);
    imprime_pal(alvore,string,-1);
    return 0; */
