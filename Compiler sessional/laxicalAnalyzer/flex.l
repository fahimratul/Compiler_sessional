%option noyywrap

%{
	#include<stdio.h>
%}
space		[ \t\n]
digit		[0-9]
number 		{digit}*(.{digit}{digit}*)?(E[-+]?{digit}{digit}*)?
letter		[A-za-z_]
variables	{letter}({letter}|{digit})*
bitops		[{>>}{<<}&^|] 
assignops	[=<{<=}{>=}>{&=}{^=}{|=}]
function	[{variables}(]
keyword		("if"|"int"|"double")
partentisis	[()]

%% 
{space}+		{}
{digit}			{printf("<%s,digit>\n", yytext);}
{number}		{printf("<%s,number>\n", yytext);}
{keyword}		{printf("<%s,KEYWORD>\n", yytext);}
{function}		{printf("<%s,function>\n", yytext);}
{variables}		{printf("<%s,variables>\n", yytext);}
{bitops}		{printf("<%s,bitops>\n", yytext);}
{assignops}		{printf("<%s,assignops>\n", yytext);}
{partentisis}	{printf("<%s,partentisis>\n", yytext);}
%%

int main() {
	yylex();
}