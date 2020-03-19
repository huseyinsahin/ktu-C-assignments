/*
#Ad-Soyad = Huseyin Sahin
#E-posta = huseyin.sahin@ceng.ktu.edu.tr
#Proje = for-to-while
*/

#include <stdio.h>
#include <stdlib.h>

char *parcalama(char string[]){
    char fordan_oncesi[10000],fordan_sonrasi[10000],komple_for[10000],DegerA[10000],DegerB[10000],DegerC[10000],DegerD[10000];
    static char parcalanmis[10000];
    int i=0,forAkadar=0,fordanSonra=0,sayac=0,for_ic_uzunluk=0;

    /* Ifadedeki for döngüsü burada belirlenir. */
    while(string[i]!='\0'){
        if((string[i]=='f' && string[i+1]=='o') && string[i+2]=='r' && (string[i+3]==' ' || string[i+3]=='(')){
            forAkadar=i;
            break;
        }
        i++;
    }
    /* for'dan önceki ifade olduğu gibi kopyalanır. */
    for(i=0;i<forAkadar;i++){
        fordan_oncesi[sayac]=string[i];
        sayac++;
    }
    fordan_oncesi[sayac]='\0';
    i=0;
    int parantez=-1;
    for(i=forAkadar;string[i]!='\0';i++){
        if(string[i]=='{'){
            if(parantez==-1)
                parantez++;
            parantez++;
        }
        if(string[i]=='}'){
            parantez--;
        }
        if(parantez==0){
            fordanSonra=i;
            break;
        }
    }
    sayac=0;

    /* for'dan sonraki ifade olduğu gibi kopyalanır. */
    for(i=fordanSonra+1;string[i]!='\0';i++){
        fordan_sonrasi[sayac]=string[i];
        sayac++;
    }
    fordan_sonrasi[sayac+1]='\0';
    sayac=0;

    /* Ifadedeki for döngüsü kopyalanır. */
    for(i=forAkadar;i<=fordanSonra;i++){
        komple_for[sayac]=string[i];
        sayac++;
    }
    komple_for[sayac]='\0';
    for_ic_uzunluk=sayac;

    /* A parametresinin elde edilmesi ve ayrılması. */
    int Ailk=0,Ason=0;
    i=0;
    while(komple_for[i]!='\0'){
        if(komple_for[i]=='('){
            Ailk=i+1;
            break;
        }
        i++;
    }
    i=0;
    while(komple_for[i]!='\0'){
        if(komple_for[i]==';'){
            Ason=i;
            break;
        }
        i++;
    }
    sayac=0;
    for(i=Ailk;i<=Ason;i++){
        DegerA[sayac]=komple_for[i];
        sayac++;
    }
    DegerA[sayac]='\0';

    /* B parametresinin elde edilmesi ve ayrılması. */
    int Bilk=Ason+1,Bson=0;
    i=Ason+1;
    while(komple_for[i]!='\0'){
        if(komple_for[i]==';'){
            Bson=i;
            break;
        }
        i++;
    }
    sayac=0;
    for(i=Bilk;i<Bson;i++){
        DegerB[sayac]=komple_for[i];
        sayac++;
    }
    DegerB[sayac]='\0';

    /* C parametresinin elde edilmesi ve ayrılması. */
    int Cilk=Bson+1,Cson=0;
    i=Bson+1;
    while(komple_for[i]!='\0'){
        if(komple_for[i]==')'){
            Cson=i;
            break;
        }
        i++;
    }
    sayac=0;
    for(i=Cilk;i<Cson;i++){
        DegerC[sayac]=komple_for[i];
        sayac++;
    }
    DegerC[sayac]=';';
    DegerC[sayac+1]='\0';

    /* D parametresinin elde edilmesi ve ayrılması. */
    int Dilk=Cson+1,Dson=(for_ic_uzunluk-2);
    sayac=0;
    for(i=Dilk;i<=Dson;i++){
        DegerD[sayac]=komple_for[i];
        sayac++;
    }
    DegerD[sayac]='\0';

    /* While'a uygun olarak string parçaları birleştirilerek main'e gönderilir. */
    sprintf(parcalanmis,"%s%s\n\twhile(%s)%s\t%s\n\t}%s",fordan_oncesi,DegerA,DegerB,DegerD,DegerC,fordan_sonrasi);
    return parcalanmis;
}

int main()
{
    FILE *ptr1=fopen("input.txt","r");
    FILE *ptr2=fopen("output.txt","w");
    char string[10000],parcalanmis[10000];
    int i=0;
    while(!feof(ptr1)){
        string[i]=fgetc(ptr1);
        if(string[i]== EOF)
            break;
        i++;
    }
    string[i]='\0';
    fclose(ptr1);
    i=0;
    int forSayisi=0;
    while(string[i]!='\0'){
        if((string[i]=='f' && string[i+1]=='o') && string[i+2]=='r' && (string[i+3]==' ' || string[i+3]=='(')){
            forSayisi++;
        }
        i++;
    }
    sprintf(parcalanmis,"%s",parcalama(string));
    for(i=1;i<forSayisi;i++){
        sprintf(parcalanmis,"%s",parcalama(parcalanmis));
    }
    fprintf(ptr2,"%s",parcalanmis);
    fclose(ptr2);
    return 0;
}
