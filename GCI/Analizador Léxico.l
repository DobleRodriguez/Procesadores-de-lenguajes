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

"main"                          {    yylval.lexema = strdup(yytext);   return MAIN;        }
"var"                           {    yylval.lexema = strdup(yytext);   return VAR;         }
"endvar"                        {    yylval.lexema = strdup(yytext);   return ENDVAR;      }
"{"                             {    yylval.lexema = strdup(yytext);   return OPEN_BLOCK;  }
"}"                             {    yylval.lexema = strdup(yytext);   return END_BLOCK;   }
";"                             {    yylval.lexema = strdup(yytext);   return SEMICOLON;   }
","                             {    yylval.lexema = strdup(yytext);   return COMMA;       }
":"                             {    yylval.lexema = strdup(yytext);   return COLON;       }
"("                             {    yylval.lexema = strdup(yytext);   return LEFT_PAR;    }
")"                             {    yylval.lexema = strdup(yytext);   return RIGHT_PAR;   }
"["                             {    yylval.lexema = strdup(yytext);   return LEFT_BRACK;  }
"]"                             {    yylval.lexema = strdup(yytext);   return RIGHT_BRACK; }
"="                             {    yylval.lexema = strdup(yytext);   return ASSIGN;      }
"if"                            {    yylval.lexema = strdup(yytext);   return IF;          }
"else"                          {    yylval.lexema = strdup(yytext);   return ELSE;        }
"while"                         {    yylval.lexema = strdup(yytext);   return WHILE;       }
"switch"                        {    yylval.lexema = strdup(yytext);   return SWITCH;      }  
"case"                          {    yylval.lexema = strdup(yytext);   return CASE;        }
"break"                         {    yylval.lexema = strdup(yytext);   return BREAK;       }
"default"                       {    yylval.lexema = strdup(yytext);   return DEFAULT;     }
"return"                        {    yylval.lexema = strdup(yytext);   return RETURN;      }
"int"                           {    yylval.lexema = strdup(yytext); yylval.tipo = entero;   yylval.atrib = 0;      return ELEM_TYPE;   }
"bool"                          {    yylval.lexema = strdup(yytext); yylval.tipo = booleano; yylval.atrib = 1;      return ELEM_TYPE;   }
"char"                          {    yylval.lexema = strdup(yytext); yylval.tipo = caracter; yylval.atrib = 2;      return ELEM_TYPE;   }
"float"                         {    yylval.lexema = strdup(yytext); yylval.tipo = real;     yylval.atrib = 3;      return ELEM_TYPE;   }
"read"                          {    yylval.lexema = strdup(yytext);   return READ;        }
"write"                         {    yylval.lexema = strdup(yytext);   return WRITE;       }
"++"                            {    yylval.lexema = strdup(yytext);   return INCR;        }
">>"                            {    yylval.atrib = 0;      return AHEADBACK;   }
"<<"                            {    yylval.atrib = 1;      return AHEADBACK;   }
"||"                            {    yylval.lexema = strdup(yytext);   return LOGIC_OR;    }
"&&"                            {    yylval.lexema = strdup(yytext);   return LOGIC_AND;   }
"|"                             {    yylval.lexema = strdup(yytext);   return BIT_OR;      }
"^"                             {    yylval.lexema = strdup(yytext);   return XOR;         }
"&"                             {    yylval.lexema = strdup(yytext);   return BIT_AND;     }
"=="                            {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return EQ_NEQ;  }
"!="                            {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return EQ_NEQ;  }
"<"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return VALUE_COMP;  }
">"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return VALUE_COMP;  }
"<="                            {    yylval.lexema = strdup(yytext); yylval.atrib = 2;      return VALUE_COMP;  }
">="                            {    yylval.lexema = strdup(yytext); yylval.atrib = 3;      return VALUE_COMP;  }
"+"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return ADD_SUB;  }
"-"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return ADD_SUB;  }
"*"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return MULT;  }
"/"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return MULT;  }
"!"                             {    yylval.lexema = strdup(yytext); yylval.lexema = strdup(yytext);   return NOT;         }
"#"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return LIST_UNARY;  }
"?"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return LIST_UNARY;  }
"@"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 0;      return LIST_BIN;    }
"%"                             {    yylval.lexema = strdup(yytext); yylval.atrib = 1;      return LIST_BIN;    }
"--"                            {    yylval.lexema = strdup(yytext); yylval.atrib = 2;      return DECR;        }
"**"                            {    yylval.lexema = strdup(yytext); yylval.atrib = 3;      return LIST_BIN;    }
"@@"                            {    yylval.lexema = strdup(yytext);   return TERNARY;     }
"$"                             {    yylval.lexema = strdup(yytext);   return LIST_HEAD;   }
"true"                          {    yylval.lexema = strdup("1"); yylval.atrib = 0;   yylval.tipo = booleano; yylval.longitud = -1;   return BOOL_VAR;    }
"false"                         {    yylval.lexema = strdup("0"); yylval.atrib = 1;   yylval.tipo = booleano; yylval.longitud = -1;  return BOOL_VAR;  }
{digito}+                       {    yylval.lexema = strdup(yytext); yylval.tipo = entero; yylval.longitud = -1;     return INT_VAR;     }
{digito}*"."{digito}+           {    yylval.lexema = strdup(yytext); yylval.tipo = real; yylval.longitud = -1;       return FLOAT_VAR;   }
\'[^\']\'                       {    yylval.lexema = strdup(yytext); yylval.tipo = caracter; yylval.longitud = -1;   return CHAR_VAR;    }
"list of"                       {    yylval.lexema = strdup(yytext);   return LIST;        }
\"[^\"]+\"                      {    yylval.lexema = strdup(yytext);   return STRING;      }
{letra}({letra}|{digito})*      {    yylval.lexema = strdup(yytext);    return ID;  }
[\n\t\r ]                       {                           }
[^" "\n\t\r]                    {
    printf(" \nError léxico en la línea %d: no se reconoce '%s'. \n", yylineno, yytext);
}

%%

