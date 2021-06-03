%{
#include "mylang.tab.h"
int lineno = 1;
%}

DIGIT [0-9]
CHAR [a-zA-Z]

%%
"si"	        	{return(si);}
"entonces"		    {return(entonces);}
"sino"		    	{return(sino);}
"mientras"		    {return(mientras);}
"hacer"		    	{return(hacer);}
"desde"		    	{return(desde);}
"hasta"		    	{return(hasta);}
"programa"		    {return(programa);}
"principal"		    {return(principal);}
"Clase"			    {return(clase);}
"hereda"			{return(hereda);}
"variables"		    {return(variables);}
"funcion"		    {return(funcion);}
"int"		    	{yylval.strval=strdup(yytext); return(n_int);}
"float"		    	{yylval.strval=strdup(yytext); return(n_float);}
"char"		    	{yylval.strval=strdup(yytext); return(n_char);}
"void"		    	{yylval.strval=strdup(yytext); return(n_void);}
"regresa"		    {return(regresa);}
"lee"		    	{return(lee);}
"escribe"		    {return(escribe);}
"atributos"		    {return(atributos);}
"metodos"		    {return(metodos);}

"="		            {yylval.strval=strdup(yytext); return(asignador);}
"+"		            {yylval.strval=strdup(yytext); return(mas);}
"-"		            {yylval.strval=strdup(yytext); return(menos);}
"/"		            {yylval.strval=strdup(yytext); return(divi);}
"*"		            {yylval.strval=strdup(yytext); return(mult);}
"&"			        {yylval.strval=strdup(yytext); return(op_and);}
"|"			        {yylval.strval=strdup(yytext); return(op_or);}
"<"|">"|"=="|"<>"|">="|"<="		{yylval.strval=strdup(yytext); return(op_rel);}
";"		            {return(punto_coma);}
":"		            {return(dos_puntos);}
","		            {return(coma);}
"."		            {return(punto);}
"->"                {return(flecha);}
"("		            {return(l_paren);}
")"		            {return(r_paren);}
"{"		            {return(l_brace);}
"}"		            {return(r_brace);}
"["		            {return(l_bracket);}
"]"		            {return(r_bracket);}

\'{CHAR}\'						        {yylval.strval=yytext; return(cte_char);}
("-")?{DIGIT}+			    			{yylval.intval=atoi(yytext); return(cte_int);}
("-")?{DIGIT}*("."{DIGIT}+)?("E"("+"|"-")?{DIGIT}+)?	{yylval.floatval=atof(yytext); return(cte_float);}
"%%".*   						        ;
\"[^"]*\"    						    {yylval.strval=yytext; return(cte_string);}
{CHAR}({CHAR}*{DIGIT}*_*)*	    		{yylval.strval=strdup(yytext); return(id_);}
[\t ]				    		        ;
[\n]						            {lineno++;}

%%
