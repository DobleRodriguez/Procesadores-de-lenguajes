%{
#include "Analizador Semántico.h"
#include "Analizador Semántico.tab.h"
#include <stdio.h>
%}

%option yylineno
%option noyywrap

letra [a-zA-Z_]
digito [0-9]

%%

"main"                          {       return MAIN;        }
"var"                           {       return VAR;         }
"endvar"                        {       return ENDVAR;      }
"{"                             {       return OPEN_BLOCK;  }
"}"                             {       return END_BLOCK;   }
";"                             {       return SEMICOLON;   }
","                             {       return COMMA;       }
":"                             {       return COLON;       }
"("                             {       return LEFT_PAR;    }
")"                             {       return RIGHT_PAR;   }
"["                             {       return LEFT_BRACK;  }
"]"                             {       return RIGHT_BRACK; }
"="                             {       return ASSIGN;      }
"if"                            {       return IF;          }
"else"                          {       return ELSE;        }
"while"                         {       return WHILE;       }
"switch"                        {       return SWITCH;      }  
"case"                          {       return CASE;        }
"break"                         {       return BREAK;       }
"default"                       {       return DEFAULT;     }
"return"                        {       return RETURN;      }
"int"                           {    yylval.tipo = entero;   yylval.atrib = 0;      return ELEM_TYPE;   }
"bool"                          {    yylval.tipo = booleano; yylval.atrib = 1;      return ELEM_TYPE;   }
"char"                          {    yylval.tipo = caracter; yylval.atrib = 2;      return ELEM_TYPE;   }
"float"                         {    yylval.tipo = real;     yylval.atrib = 3;      return ELEM_TYPE;   }
"read"                          {       return READ;        }
"write"                         {       return WRITE;       }
"++"                            {       return INCR;        }
"--"                            {       return DECR;        }
">>"                            {    yylval.atrib = 0;      return AHEADBACK;   }
"<<"                            {    yylval.atrib = 1;      return AHEADBACK;   }
"||"                            {       return LOGIC_OR;    }
"&&"                            {       return LOGIC_AND;   }
"|"                             {       return BIT_OR;      }
"^"                             {       return XOR;         }
"&"                             {       return BIT_AND;     }
"=="                            {    yylval.atrib = 0;      return EQ_NEQ;  }
"!="                            {    yylval.atrib = 1;      return EQ_NEQ;  }
"<"                             {    yylval.atrib = 0;      return VALUE_COMP;  }
">"                             {    yylval.atrib = 1;      return VALUE_COMP;  }
"<="                            {    yylval.atrib = 2;      return VALUE_COMP;  }
">="                            {    yylval.atrib = 3;      return VALUE_COMP;  }
"+"                             {    yylval.atrib = 0;      return ADD_SUB;  }
"-"                             {    yylval.atrib = 1;      return ADD_SUB;  }
"*"                             {       return MULT;        }
"/"                             {    yylval.atrib = 0;      return MULT_OPS;  }
"%"                             {    yylval.atrib = 1;      return MULT_OPS;  }
"!"                             {    yylval.atrib = 0;      return UNARY_OP;  }
"#"                             {    yylval.atrib = 1;      return UNARY_OP;  }
"?"                             {    yylval.atrib = 2;      return UNARY_OP;  }
"@"                             {       return BIN_TER;     }
"@@"                            {       return TERNARY;     }
"$"                             {       return LIST_HEAD;   }
"true"                          {    yylval.atrib = 0;   yylval.tipo = booleano;    return BOOL_VAR;    }
"false"                         {    yylval.atrib = 1;   yylval.tipo = booleano;    return BOOL_VAR;  }
{digito}+                       {    yylval.tipo = entero;      return INT_VAR;     }
{digito}*"."{digito}+           {    yylval.tipo = real;        return FLOAT_VAR;   }
\'[^\']\'                       {    yylval.tipo = caracter;    return CHAR_VAR;    }
"list of"                       {    yylval.tipo = lista;       return LIST;        }
\"[^\"]+\"                      {       return STRING;      }
{letra}({letra}|{digito})*      {    yylval.lexema = strdup(yytext);    return ID;  }
[\n\t\r ]                       {                           }
[^" "\n\t\r]                    {
    printf(" \nError léxico en la línea %d: no se reconoce '%s'. \n", yylineno, yytext);
}

%%

