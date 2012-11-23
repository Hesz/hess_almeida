//teste
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct lista_hashtags
{
    char tag[140]; //Hashtag utilizada pelo usuário.
    struct lista_hashtags *prox;
};typedef struct lista_hashtags Lista_hashtags;

struct lista_amigos
{//Armazena uma lista (árvore) com o nome dos amigos que foram retweetados
    char nome[50]; //Nome do amigo
    struct lista_amigos *prox; //Aponta para o próximo amigo.
};typedef struct lista_amigos Lista_amigos;

struct lista_mentions
{//Armazena uma lista com o nome dos amigos que foram retwetados
    char nome[50]; //Nome do user que foi mencionado.
    struct lista_mentions *prox; //Aponta para o próximo nodo.
};typedef struct lista_mentions Lista_mentions;

struct inf_tweet
{
     char palavras[800];  //Todas as palavras uteis são armazenadas aqui (separadas por ',')
     char data[10]; //IMPORTANTE! Converter para int, ou não.
     char horario[8]; //IMPORTANTE! Converter para int, ou não.
     int num_palavras;  //Número de palavras úteis armazenadas.

};typedef struct inf_tweet Inf_tweet;

struct user
{//Informações de um usuário;
    char nome[50]; //Nome do usuário.
    char local[50]; //Local do usuário.
    Lista_amigos amigos; //List que contem os amigos que foram retwetados.
    Lista_mentions mentions; //Lista com todos os usuários que receberam mentions.
            //Ponteiro para a árvore TRIE com as palavras do usuário.
    Lista_hashtags hashtags; //Lista com todas as hashtags utilizadas pelo usuário.
};typedef struct user User;

struct local
{//Todos os locais de todos os usuários.
    char nome[50]; //Nome da cidade/local.
    local *prox; //Lista de locais.
};typedef struct local Local;

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


int main()
{
    FILE *arq, *tst;
    char nome_usuario[50], palavra[140], nome_hashtag[140], nome_RT[140], nome_mention[140], local[140], auxiliar[140],string[140];
    Inf_tweet ult_tweet;
    int i=0,sair=0,pos_atual=0,pos_fim=0, diferente=0,riso,acabou=0,j=0, option, total_tweets=0,cont;
    trai* alvore=(trai*) malloc(sizeof(trai));
    alvore=seta_carac(0,alvore);
    puts("Informe o nome do usuario: ");
    gets(nome_usuario);
    strcat(nome_usuario,".txt");
    for(j=0;j<240;j++)
        ult_tweet.palavras[j]=0;
    //puts(ult_tweet.palavras);
    //puts(ult_tweet.palavras);
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
    return 0;
}

                /*
                if(strcmp(palavra,"|*|")==0)//PRÓXIMA INFORMAÇÃO QUE SERÁ LIDA É A DATA E O HORÁRIO.
                {
                    fscanf(arq,"%s",palavra); //Lê a data.
                    strcpy(ult_tweet.data,palavra); //Copia a data pra struct do tweet.
                    fscanf(arq,"%s",palavra); //Lê o horário.
                    strcpy(ult_tweet.horario,palavra); //Copia o horário para a struct do tweet.
                    acabou=1; //SAI DO LAÇO! ACABOU DE LER ESSE TWEET, NO PRÓXIMO LAÇO, IRÁ LER O PRÓXIMO, ATÉ QUE CHEGA NO FIM DO ARQUIVO.
                    //AQUI DEVE SER INSERIDO O TRATAMENTO DA TRIE E OUTRAS, POIS NOS PRÓXIMOS PASSOS AS INFORMAÇÕES DA STRUCT TWEET SERÃO
                    //APAGADAS!
                    tst=fopen("teste1.txt","w+");
                    fputs(ult_tweet.palavras,tst);
                    putc('\n',tst);
                    fputs(ult_tweet.data,tst);
                    putc('\n',tst);
                    fputs(ult_tweet.horario,tst);
                }
                puts(palavra);
                system("pause");
                if(strcmp(palavra,"RT")==0)
                {//É retweet, próximo passo é pegar o nome do usuário que foi RT.
                    fscanf(arq,"%s",palavra);
                    (palavra);
                system("pause");
                    strcpy(nome_RT,palavra); //Copia o nome pra string.
                    //INSERE NA LISTA DOS AMIGOS!
                }

                else //Se não for RT
                {
                    if(palavra[0]=='@')// É MENTION!
                    {
                        strcpy(nome_mention,palavra); //Copia o nome do amigo que foi mencionado.
                        //INSERE NA LISTA DE MENTIONS!
                    }
                    else //Se não for mention.
                    {
                        if(palavra[0]=='#')//É HASHTAG
                        {
                            strcpy(nome_hashtag,palavra); //Copia o nome da tag.
                            // INSERE NA LISTA DE DE TAG!
                        }
                    }
                }
                trata_pal(palavra); //Elimina acentos e coloca tudo como minusculo.
                pos_atual=0; //Seta o valor para 0.
                pos_fim=strlen(palavra); //Tamanho da palavra
                diferente=0;
                while((pos_atual!=pos_fim) && (diferente==0))
                {
                    if(!(palavra[pos_atual] >= 'a') && (palavra[pos_atual] <= 'z'))
                        diferente=1; //Se não estiver no padrão, cai fora.
                    else
                        pos_atual++; //Se estiver, será usada.
                }
                if(diferente==0)//Testa se é risada.
                {
                    riso=risos(palavra);
                    if(riso==0)//Não é risada! Salva a palavra na struct.
                    {
                        strcat(ult_tweet.palavras,palavra); //Se for útil manda pro array.
                        strcat(ult_tweet.palavras,"|");  //Insere o separador.
                        ult_tweet.num_palavras++;
                    }
                }*/

