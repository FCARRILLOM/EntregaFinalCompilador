%{
#include <iostream>
#include <string>

extern int yylex();
extern int lineno;
void yyerror(char*s);

#include "TablaSimbolos.h"
#include "Quad.h"
#include "MapaMemoria.h"
#include "TablasDatos.h"
 
TablasDatos tablasDatos;
MapaMemoria mapa;

Quad quad(tablasDatos, mapa);
TablaSimbolos tabla(tablasDatos, tablasDatos.funcDir, tablasDatos.clasesDir, quad, mapa);

%}

%union {
  int intval;
  char charval;
  float floatval;
  char* strval;
}

%token programa principal
%token si entonces sino mientras hacer desde hasta
%token clase hereda atributos metodos
%token variables funcion lee escribe regresa
%token <strval>n_void <strval>n_int <strval>n_float <strval>n_char
%token <strval>asignador <strval>mas <strval>menos <strval>divi <strval>mult <strval>op_and <strval>op_or <strval>op_rel
%token punto_coma dos_puntos coma punto flecha
%token l_paren r_paren l_brace r_brace l_bracket r_bracket
%token <intval>cte_int <floatval>cte_float <strval>cte_char <strval>cte_string <strval>id_

%type <strval>TIPO_RET TIPO_SIMPLE TIPO_VAR


%%
PROGRAMA		:	programa id_ { quad.savePrincipalLoc(); tabla.addPrincipalFunc($2); } punto_coma DECLARACIONES principal 
					l_paren r_paren { quad.addGotoPrincipalLoc(); } l_brace ESTATUTOS r_brace 
					{ tabla.saveTempsUsed(); quad.clearQuad(); }
				;
DECLARACIONES	:	 DECLARACION DECLARACIONES
				|	/*epsilon*/
				;
DECLARACION		:	CLASE
				|	VARIABLES { tabla.saveGlobalVars(); }
				|	FUNCIONES
				;
CLASE			:	clase id_ { tabla.addClass($2) } HEREDA punto_coma l_brace ATRIBUTOS METODOS r_brace { tabla.endCurrentClassDeclaration(); } punto_coma
				;
HEREDA			:	hereda id_
				|	/*epsilon*/
				;
ATRIBUTOS		:	atributos VARS { tabla.addVarsToClass(); }
				|	/*epsilon*/
				;
METODOS			:	metodos FUNCIONES
				|	/*epsilon*/
				;
VARIABLES		:	variables VARS
				;
VARS			:	VAR VARS_
				;
VARS_			:	VARS
				|	/*epsilon*/
				;
VAR				:	TIPO_VAR { tabla.saveCurrentVarType($1); } dos_puntos VAR_IDS punto_coma
				;
VAR_IDS			:	id_ { tabla.addVarToList($1); } ARR VAR_IDS_
				;
ARR				:	l_bracket { tabla.addFirstArrNode(); } cte_int { tabla.storeDimSize($3); } ARR_ r_bracket { tabla.endArrNode(); }
				|	/*epsilon*/
				;
ARR_			:	 coma { tabla.addArrNode(); } cte_int { tabla.storeDimSize($3); }
				| 	/*epsilon*/
				;
VAR_IDS_		:	coma VAR_IDS
				|	/*epsilon*/
				;
TIPO_SIMPLE		:	n_int
				|	n_float
				|	n_char
				;
TIPO_VAR		:	TIPO_SIMPLE
				| 	id_
				;
FUNCIONES		: 	FUNCION FUNCIONES_
				;
FUNCIONES_		: 	FUNCIONES
				| 	/*epsilon*/
				;
FUNCION			:	funcion TIPO_RET id_ { tabla.createFunc($3, $2); tabla.addFuncGlobalVar(); } l_paren { tabla.initParameterVars(); } PARAMETROS 
					{ tabla.addParameterVarsToDir(); } r_paren punto_coma FUNC_VARIABLES 
					{ tabla.addCurrLVarsToDir(); tabla.addFuncCont(); } l_brace ESTATUTOS r_brace { tabla.addEndFunc(); }
				;
FUNC_VARIABLES	:	VARIABLES
				|	/*epsilon*/
				;
TIPO_RET		: 	TIPO_SIMPLE
				|	n_void
				;
PARAMETROS		:	TIPO_SIMPLE dos_puntos id_ { tabla.addParameterVar($3, $1); } PARAMETROS_
				|	/*epsilon*/
				;
PARAMETROS_		:	coma PARAMETROS
				|	/*epsilon*/
				;
ASIGNACION		:	id_ { quad.addOperand($1); } ASIG asignador { quad.addOperatorAsig($4); } 
					EXP { quad.removeFromStackAssign(); } punto_coma
				;
ASIG			:	punto id_ { quad.checkValidAttribute($2); }
				|	l_bracket { quad.verifyArrayDimensions(); } EXP { quad.getArrayDimensionResult(); } 
					ASIG_ r_bracket { quad.addArrayQuads(); }
				|	/*epsilon*/
				;
ASIG_			:	coma EXP { quad.getArrayDimensionResult(); }
				|	/*epsilon*/
				;
LLAMADA_VOID 	:	id_ { quad.addOperand($1); } VOID_ATTR l_paren { tabla.verifyVoidFunction(); tabla.generateEra(); }
					FUNC_PARAM r_paren { tabla.verifyLastParam(); tabla.addGoSub(); } punto_coma
				;
VOID_ATTR		:	flecha id_ { quad.checkValidVoidMethod($2); }
				|	/*epsilon*/
				;
FUNC_PARAM		:	EXP { tabla.verifyParameterType(); tabla.moveToNextParam(); } FUNC_PARAM_
				|	/*epsilon*/
				;
FUNC_PARAM_		:	coma FUNC_PARAM
				|	/*epsilon*/
				;
DECISION		:	si l_paren EXP r_paren { quad.addGotoIf(); } entonces l_brace ESTATUTOS r_brace DECISION_ { quad.addDecisionEnd(); }
				;
DECISION_		:	sino { quad.addGotoElse(); } l_brace ESTATUTOS r_brace
				|	/*epsilon*/
				;
CONDICIONAL		:	mientras { quad.addWhileCheckpoint(); } l_paren EXP r_paren { quad.addGotoWhile(); } hacer l_brace ESTATUTOS 
					r_brace { quad.addConditionalEnd(); }
				;
NOCONDICIONAL	:	desde id_ asignador EXP { quad.addLoopCounter($2); } hasta EXP { quad.addLoopLimit(); } hacer { quad.addGotoFor(); } 
					l_brace ESTATUTOS r_brace { quad.addNonConditionalEnd($2); }
				;
ESCRITURA		:	escribe l_paren PRINTABLE r_paren punto_coma
				;
PRINTABLE		:	E PRINTABLE_
				;
PRINTABLE_		:	coma PRINTABLE
				|	/*epsilon*/
				;
E				:	cte_string { quad.addWriteStr($1); }
				|	EXP { quad.addWriteExp(); }
				;
LECTURA			:	lee l_paren READABLE r_paren punto_coma
				;
READABLE		:	id_ { quad.addRead($1); } READABLE_
				;
READABLE_		:	coma READABLE 
				|	/*epsilon*/
				;
RETORNO			:	regresa l_paren EXP r_paren { tabla.saveReturnValue(); } punto_coma
				;
EXP				:	EXP_Q
				;
EXP_Q			:	T_EXP { quad.removeFromStackOr(); } EXP_
				;
EXP_			:	op_or { quad.addOperatorOr($1); } EXP
				|	/*epsilon*/
				;
T_EXP			:	G_EXP { quad.removeFromStackAnd(); } T_EXP_
				;
T_EXP_			:	op_and { quad.addOperatorAnd($1); } T_EXP
				|	/*epsilon*/
				;
G_EXP			:	M_EXP G_EXP_
				;
G_EXP_			:	OPER_REL M_EXP { quad.removeFromStackRel(); }
				|	/*epsilon*/
				;
OPER_REL		:	op_rel { quad.addOperatorRel($1); }
				;
M_EXP			:	T { quad.removeFromStackPlusMinus(); } M_EXP_
				;
M_EXP_			:	mas { quad.addOperatorPlusMinus($1); } M_EXP
				| 	menos { quad.addOperatorPlusMinus($1); } M_EXP
				|	/*epsilon*/
				;
T				:	F { quad.removeFromStackMultDiv(); } T_
				;
T_				:	mult { quad.addOperatorMultDiv($1); } T
				|	divi { quad.addOperatorMultDiv($1); } T
				|	/*epsilon*/
				;
F				:	l_paren { quad.addFalseBottom(); } EXP_Q r_paren { quad.removeFalseBottom(); }
				|	CTE
				|	id_ { quad.addOperand($1); } ID_A
				;
ID_A			: 	ID_ATTR
				| 	ID_METHOD
				|	l_bracket { quad.verifyArrayDimensions(); } EXP { quad.getArrayDimensionResult(); } 
					ID_ARR r_bracket { quad.addArrayQuads(); }
				| 	/*epsilon*/
				;
ID_ARR			:	coma EXP { quad.getArrayDimensionResult(); }
				|	/*epsilon*/
				;
ID_ATTR			: 	punto id_ { quad.checkValidAttribute($2); }
				|	/*epsilon*/
				;
ID_METHOD		:	FLECHA LLAMADA_RET
				;
FLECHA			:	flecha id_ { quad.checkValidMethod($2); }
				|	/*epsilon*/
				;
LLAMADA_RET 	:	l_paren { tabla.verifyFunction(); tabla.generateEra(); }
					FUNC_PARAM r_paren { tabla.verifyLastParam(); tabla.addGoSub(); tabla.addReturnValue(); }
				|   /*epsilon*/
				;
CTE				:	cte_int { quad.addConstOperand(std::to_string($1), "int"); }
				|	cte_float { quad.addConstOperand(std::to_string($1), "float"); }
				|	cte_char { quad.addConstOperand($1, "char"); }
				;
ESTATUTOS		:	ESTATUTO ESTATUTOS
				|	/*epsilon*/
				;
ESTATUTO		:   ASIGNACION 
				|	LLAMADA_VOID
				|	LECTURA 
				|	ESCRITURA 
				|	DECISION
				|	CONDICIONAL
				|	NOCONDICIONAL
				|	RETORNO
				;

%% 

int main() {
	yyparse();
}

void yyerror(char* s) {
	std::cout << "Syntax error on line " << lineno << std::endl;
}
