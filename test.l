%{
    #include<stdio.h>
    int int_num=0;
    int float_num=0;
    int id_num=0;
    int error_num=0;
%}
%option noyywrap
%%
[-]*[0-9]+; {
    printf("Integer (%s)\n",yytext);
    int_num++;
}
[-]*[0-9]*\.[0-9]+; {
    printf("Float (%s)\n",yytext);
    float_num++;
}
[a-zA-Z][a-zA-Z0-9_]*; {
    printf("ID (%s)\n",yytext);
    id_num++;
}
[\n] {}
[0-9a-zA-Z_!@#$%.^*()_+=-{};]+    {
        printf("ERROR (%s)\n",yytext);
    }
%%
int main(){
    yylex();
    printf("num:%d   float:%d   id:%d\n",int_num,float_num,id_num);
    return 0;
}
