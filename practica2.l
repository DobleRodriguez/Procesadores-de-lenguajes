%{

    // Archivos a usar

    #include <stdlib.h>
    #include <string.h>
    #include "constantes.h"


%}

%option yylineno
%option noyywrap

letra [a-zA-Z]
digito [0-9]
entero {digito}+
real {entero}.{entero}

%%

"main" { 
    ECHO;
    return(MAIN);
}

"{" {
    ECHO;
    return(BEGIN_BLOCK);
}

"}" {
    ECHO;
    return(END_BLOCK);
}

";" {
    ECHO;
    return(SEMICOLON);
}

"," {
    ECHO;
    return(COMMA);
}

"(" {
    ECHO;
    return(LEFT_PARENTHE);
}

")" {
    ECHO;
    return(RIGHT_PARENTHE);
}

"=" { 
    ECHO;
    return(ASSIGNMENT);
}

"if" {
    ECHO;
    return(IF);
}

"else" {
    ECHO;
    return(ELSE);
}

"while" {
    ECHO;
    return(WHILE);
}

"switch" {
    ECHO;
    return(SWITCH);
}

"case" {
    ECHO;
    return(CASE);
}

"return" {
    ECHO;
    return(RETURN);
}

"int" {
    ECHO;
    return(ELEM_TYPE);
}

"bool" {
    ECHO;
    return(ELEM_TYPE);
}

"char" {
    ECHO;
    return(ELEM_TYPE);
}

"float" {
    ECHO;
    return(ELEM_TYPE);
}

"const" {
    ECHO;
    return(MODIFIER);
}

"read" {
    ECHO;
    return(INPUT);
}

"write" {
    ECHO;
    return(OUTPUT);
}

"+" {
    ECHO;
    return(SIGN);
}

"-" {
    ECHO;
    return(SIGN);
}

"!" {
    ECHO;
    return(UNARY_OP);
}

"~" {
    ECHO;
    return(UNARY_OP);
}

"&" {
    ECHO;
    return(UNARY_OP);
}

"#" {
    ECHO;
    return(UNARY_OP);
}

"?" {
    ECHO;
    return(UNARY_OP);
}

"*" {
    ECHO;
    return(BINARY_OP);
}

"/" {
    ECHO;
    return(BINARY_OP);
}

"%" {
    ECHO;
    return(BINARY_OP);
}

">" {
    ECHO;
    return(BINARY_OP);
}

"<" {
    ECHO;
    return(BINARY_OP);
}

"==" {
    ECHO;
    return(BINARY_OP);
}

"!=" {
    ECHO;
    return(BINARY_OP);
}

">=" {
    ECHO;
    return(BINARY_OP);
}

"<=" {
    ECHO;
    return(BINARY_OP);
}

"&&" {
    ECHO;
    return(BINARY_OP);
}

"||" {
    ECHO;
    return(BINARY_OP);
}

"@" {
    ECHO;
    return(BINARY_OP);
}

"--" {
    ECHO;
    return(BINARY_OP);
}

"**" {
    ECHO;
    return(BINARY_OP);
}

"true" {
    ECHO;
    return(LOGIC_VAR);
}

"false" {
    ECHO;
    return(LOGIC_VAR);
}