/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    num = 258,
    PID = 259,
    VAR = 260,
    T_BEGIN = 261,
    END = 262,
    IF = 263,
    ELSE = 264,
    ENDIF = 265,
    THEN = 266,
    WHILE = 267,
    DO = 268,
    ENDWHILE = 269,
    FOR = 270,
    FROM = 271,
    TO = 272,
    ENDFOR = 273,
    DOWNTO = 274,
    READ = 275,
    WRITE = 276,
    SKIP = 277,
    T_ADD = 278,
    T_MIN = 279,
    T_MUL = 280,
    T_DIV = 281,
    T_MOD = 282,
    T_EQ = 283,
    T_NEQ = 284,
    T_RGT = 285,
    T_RGE = 286,
    T_LGE = 287,
    T_LGT = 288,
    T_ASG = 289,
    T_EL = 290,
    T_LBR = 291,
    T_RBR = 292,
    ERR = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "grammar.y" /* yacc.c:1909  */

	char* string;
	int integer;
	//Identifier* identifier;
	//Command* command;

#line 100 "grammar.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
