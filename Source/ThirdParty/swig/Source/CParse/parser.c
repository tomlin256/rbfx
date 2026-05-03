/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     HBLOCK = 259,
     POUND = 260,
     STRING = 261,
     WSTRING = 262,
     INCLUDE = 263,
     IMPORT = 264,
     INSERT = 265,
     CHARCONST = 266,
     WCHARCONST = 267,
     NUM_INT = 268,
     NUM_FLOAT = 269,
     NUM_UNSIGNED = 270,
     NUM_LONG = 271,
     NUM_ULONG = 272,
     NUM_LONGLONG = 273,
     NUM_ULONGLONG = 274,
     NUM_BOOL = 275,
     TYPEDEF = 276,
     TYPE_INT = 277,
     TYPE_UNSIGNED = 278,
     TYPE_SHORT = 279,
     TYPE_LONG = 280,
     TYPE_FLOAT = 281,
     TYPE_DOUBLE = 282,
     TYPE_CHAR = 283,
     TYPE_WCHAR = 284,
     TYPE_VOID = 285,
     TYPE_SIGNED = 286,
     TYPE_BOOL = 287,
     TYPE_COMPLEX = 288,
     TYPE_TYPEDEF = 289,
     TYPE_RAW = 290,
     TYPE_NON_ISO_INT8 = 291,
     TYPE_NON_ISO_INT16 = 292,
     TYPE_NON_ISO_INT32 = 293,
     TYPE_NON_ISO_INT64 = 294,
     LPAREN = 295,
     RPAREN = 296,
     COMMA = 297,
     SEMI = 298,
     EXTERN = 299,
     INIT = 300,
     LBRACE = 301,
     RBRACE = 302,
     PERIOD = 303,
     CONST_QUAL = 304,
     VOLATILE = 305,
     REGISTER = 306,
     STRUCT = 307,
     UNION = 308,
     EQUAL = 309,
     SIZEOF = 310,
     MODULE = 311,
     LBRACKET = 312,
     RBRACKET = 313,
     BEGINFILE = 314,
     ENDOFFILE = 315,
     ILLEGAL = 316,
     CONSTANT = 317,
     NAME = 318,
     RENAME = 319,
     NAMEWARN = 320,
     EXTEND = 321,
     PRAGMA = 322,
     FEATURE = 323,
     VARARGS = 324,
     ENUM = 325,
     CLASS = 326,
     TYPENAME = 327,
     PRIVATE = 328,
     PUBLIC = 329,
     PROTECTED = 330,
     COLON = 331,
     STATIC = 332,
     VIRTUAL = 333,
     FRIEND = 334,
     THROW = 335,
     CATCH = 336,
     EXPLICIT = 337,
     STATIC_ASSERT = 338,
     CONSTEXPR = 339,
     THREAD_LOCAL = 340,
     DECLTYPE = 341,
     AUTO = 342,
     NOEXCEPT = 343,
     OVERRIDE = 344,
     FINAL = 345,
     USING = 346,
     NAMESPACE = 347,
     NATIVE = 348,
     INLINE = 349,
     TYPEMAP = 350,
     EXCEPT = 351,
     ECHO = 352,
     APPLY = 353,
     CLEAR = 354,
     SWIGTEMPLATE = 355,
     FRAGMENT = 356,
     WARN = 357,
     LESSTHAN = 358,
     GREATERTHAN = 359,
     DELETE_KW = 360,
     DEFAULT = 361,
     LESSTHANOREQUALTO = 362,
     GREATERTHANOREQUALTO = 363,
     EQUALTO = 364,
     NOTEQUALTO = 365,
     ARROW = 366,
     QUESTIONMARK = 367,
     TYPES = 368,
     PARMS = 369,
     NONID = 370,
     DSTAR = 371,
     DCNOT = 372,
     TEMPLATE = 373,
     OPERATOR = 374,
     CONVERSIONOPERATOR = 375,
     PARSETYPE = 376,
     PARSEPARM = 377,
     PARSEPARMS = 378,
     DOXYGENSTRING = 379,
     DOXYGENPOSTSTRING = 380,
     CAST = 381,
     LOR = 382,
     LAND = 383,
     OR = 384,
     XOR = 385,
     AND = 386,
     RSHIFT = 387,
     LSHIFT = 388,
     MINUS = 389,
     PLUS = 390,
     MODULO = 391,
     SLASH = 392,
     STAR = 393,
     LNOT = 394,
     NOT = 395,
     UMINUS = 396,
     DCOLON = 397
   };
#endif
/* Tokens.  */
#define ID 258
#define HBLOCK 259
#define POUND 260
#define STRING 261
#define WSTRING 262
#define INCLUDE 263
#define IMPORT 264
#define INSERT 265
#define CHARCONST 266
#define WCHARCONST 267
#define NUM_INT 268
#define NUM_FLOAT 269
#define NUM_UNSIGNED 270
#define NUM_LONG 271
#define NUM_ULONG 272
#define NUM_LONGLONG 273
#define NUM_ULONGLONG 274
#define NUM_BOOL 275
#define TYPEDEF 276
#define TYPE_INT 277
#define TYPE_UNSIGNED 278
#define TYPE_SHORT 279
#define TYPE_LONG 280
#define TYPE_FLOAT 281
#define TYPE_DOUBLE 282
#define TYPE_CHAR 283
#define TYPE_WCHAR 284
#define TYPE_VOID 285
#define TYPE_SIGNED 286
#define TYPE_BOOL 287
#define TYPE_COMPLEX 288
#define TYPE_TYPEDEF 289
#define TYPE_RAW 290
#define TYPE_NON_ISO_INT8 291
#define TYPE_NON_ISO_INT16 292
#define TYPE_NON_ISO_INT32 293
#define TYPE_NON_ISO_INT64 294
#define LPAREN 295
#define RPAREN 296
#define COMMA 297
#define SEMI 298
#define EXTERN 299
#define INIT 300
#define LBRACE 301
#define RBRACE 302
#define PERIOD 303
#define CONST_QUAL 304
#define VOLATILE 305
#define REGISTER 306
#define STRUCT 307
#define UNION 308
#define EQUAL 309
#define SIZEOF 310
#define MODULE 311
#define LBRACKET 312
#define RBRACKET 313
#define BEGINFILE 314
#define ENDOFFILE 315
#define ILLEGAL 316
#define CONSTANT 317
#define NAME 318
#define RENAME 319
#define NAMEWARN 320
#define EXTEND 321
#define PRAGMA 322
#define FEATURE 323
#define VARARGS 324
#define ENUM 325
#define CLASS 326
#define TYPENAME 327
#define PRIVATE 328
#define PUBLIC 329
#define PROTECTED 330
#define COLON 331
#define STATIC 332
#define VIRTUAL 333
#define FRIEND 334
#define THROW 335
#define CATCH 336
#define EXPLICIT 337
#define STATIC_ASSERT 338
#define CONSTEXPR 339
#define THREAD_LOCAL 340
#define DECLTYPE 341
#define AUTO 342
#define NOEXCEPT 343
#define OVERRIDE 344
#define FINAL 345
#define USING 346
#define NAMESPACE 347
#define NATIVE 348
#define INLINE 349
#define TYPEMAP 350
#define EXCEPT 351
#define ECHO 352
#define APPLY 353
#define CLEAR 354
#define SWIGTEMPLATE 355
#define FRAGMENT 356
#define WARN 357
#define LESSTHAN 358
#define GREATERTHAN 359
#define DELETE_KW 360
#define DEFAULT 361
#define LESSTHANOREQUALTO 362
#define GREATERTHANOREQUALTO 363
#define EQUALTO 364
#define NOTEQUALTO 365
#define ARROW 366
#define QUESTIONMARK 367
#define TYPES 368
#define PARMS 369
#define NONID 370
#define DSTAR 371
#define DCNOT 372
#define TEMPLATE 373
#define OPERATOR 374
#define CONVERSIONOPERATOR 375
#define PARSETYPE 376
#define PARSEPARM 377
#define PARSEPARMS 378
#define DOXYGENSTRING 379
#define DOXYGENPOSTSTRING 380
#define CAST 381
#define LOR 382
#define LAND 383
#define OR 384
#define XOR 385
#define AND 386
#define RSHIFT 387
#define LSHIFT 388
#define MINUS 389
#define PLUS 390
#define MODULO 391
#define SLASH 392
#define STAR 393
#define LNOT 394
#define NOT 395
#define UMINUS 396
#define DCOLON 397




/* Copy the first part of user declarations.  */


#define yylex yylex

#include "swig.h"
#include "cparse.h"
#include "preprocessor.h"
#include <ctype.h>

/* We do this for portability */
#undef alloca
#define alloca malloc

/* -----------------------------------------------------------------------------
 *                               Externals
 * ----------------------------------------------------------------------------- */

int  yyparse();

/* NEW Variables */

static Node    *top = 0;      /* Top of the generated parse tree */
static int      unnamed = 0;  /* Unnamed datatype counter */
static Hash    *classes = 0;        /* Hash table of classes */
static Hash    *classes_typedefs = 0; /* Hash table of typedef classes: typedef struct X {...} Y; */
static Symtab  *prev_symtab = 0;
static Node    *current_class = 0;
String  *ModuleName = 0;
static Node    *module_node = 0;
static String  *Classprefix = 0;  
static String  *Namespaceprefix = 0;
static int      inclass = 0;
static Node    *currentOuterClass = 0; /* for nested classes */
static const char *last_cpptype = 0;
static int      inherit_list = 0;
static Parm    *template_parameters = 0;
static int      parsing_template_declaration = 0;
static int      extendmode   = 0;
static int      compact_default_args = 0;
static int      template_reduce = 0;
static int      cparse_externc = 0;
int		ignore_nested_classes = 0;
int		kwargs_supported = 0;
/* -----------------------------------------------------------------------------
 *                            Doxygen Comment Globals
 * ----------------------------------------------------------------------------- */
static String *currentDeclComment = NULL; /* Comment of C/C++ declaration. */
static Node *previousNode = NULL; /* Pointer to the previous node (for post comments) */
static Node *currentNode = NULL; /* Pointer to the current node (for post comments) */

/* -----------------------------------------------------------------------------
 *                            Assist Functions
 * ----------------------------------------------------------------------------- */


 
/* Called by the parser (yyparse) when an error is found.*/
static void yyerror (const char *e) {
  (void)e;
}

static Node *new_node(const_String_or_char_ptr tag) {
  Node *n = Swig_cparse_new_node(tag);
  /* Remember the previous node in case it will need a post-comment */
  previousNode = currentNode;
  currentNode = n;
  return n;
}

/* Copies a node.  Does not copy tree links or symbol table data (except for
   sym:name) */

static Node *copy_node(Node *n) {
  Node *nn;
  Iterator k;
  nn = NewHash();
  Setfile(nn,Getfile(n));
  Setline(nn,Getline(n));
  for (k = First(n); k.key; k = Next(k)) {
    String *ci;
    String *key = k.key;
    char *ckey = Char(key);
    if ((strcmp(ckey,"nextSibling") == 0) ||
	(strcmp(ckey,"previousSibling") == 0) ||
	(strcmp(ckey,"parentNode") == 0) ||
	(strcmp(ckey,"lastChild") == 0)) {
      continue;
    }
    if (Strncmp(key,"csym:",5) == 0) continue;
    /* We do copy sym:name.  For templates */
    if ((strcmp(ckey,"sym:name") == 0) || 
	(strcmp(ckey,"sym:weak") == 0) ||
	(strcmp(ckey,"sym:typename") == 0)) {
      String *ci = Copy(k.item);
      Setattr(nn,key, ci);
      Delete(ci);
      continue;
    }
    if (strcmp(ckey,"sym:symtab") == 0) {
      Setattr(nn,"sym:needs_symtab", "1");
    }
    /* We don't copy any other symbol table attributes */
    if (strncmp(ckey,"sym:",4) == 0) {
      continue;
    }
    /* If children.  We copy them recursively using this function */
    if (strcmp(ckey,"firstChild") == 0) {
      /* Copy children */
      Node *cn = k.item;
      while (cn) {
	Node *copy = copy_node(cn);
	appendChild(nn,copy);
	Delete(copy);
	cn = nextSibling(cn);
      }
      continue;
    }
    /* We don't copy the symbol table.  But we drop an attribute 
       requires_symtab so that functions know it needs to be built */

    if (strcmp(ckey,"symtab") == 0) {
      /* Node defined a symbol table. */
      Setattr(nn,"requires_symtab","1");
      continue;
    }
    /* Can't copy nodes */
    if (strcmp(ckey,"node") == 0) {
      continue;
    }
    if ((strcmp(ckey,"parms") == 0) || (strcmp(ckey,"pattern") == 0) || (strcmp(ckey,"throws") == 0)
	|| (strcmp(ckey,"kwargs") == 0)) {
      ParmList *pl = CopyParmList(k.item);
      Setattr(nn,key,pl);
      Delete(pl);
      continue;
    }
    if (strcmp(ckey,"nested:outer") == 0) { /* don't copy outer classes links, they will be updated later */
      Setattr(nn, key, k.item);
      continue;
    }
    /* defaultargs will be patched back in later in update_defaultargs() */
    if (strcmp(ckey,"defaultargs") == 0) {
      Setattr(nn, "needs_defaultargs", "1");
      continue;
    }
    /* same for abstracts, which contains pointers to the source node children, and so will need to be patch too */
    if (strcmp(ckey,"abstracts") == 0) {
      SetFlag(nn, "needs_abstracts");
      continue;
    }
    /* Looks okay.  Just copy the data using Copy */
    ci = Copy(k.item);
    Setattr(nn, key, ci);
    Delete(ci);
  }
  return nn;
}

static void set_comment(Node *n, String *comment) {
  String *name;
  Parm *p;
  if (!n || !comment)
    return;

  if (Getattr(n, "doxygen"))
    Append(Getattr(n, "doxygen"), comment);
  else {
    Setattr(n, "doxygen", comment);
    /* This is the first comment, populate it with @params, if any */
    p = Getattr(n, "parms");
    while (p) {
      if (Getattr(p, "doxygen"))
	Printv(comment, "\n@param ", Getattr(p, "name"), Getattr(p, "doxygen"), NIL);
      p=nextSibling(p);
    }
  }
  
  /* Append same comment to every generated overload */
  name = Getattr(n, "name");
  if (!name)
    return;
  n = nextSibling(n);
  while (n && Getattr(n, "name") && Strcmp(Getattr(n, "name"), name) == 0) {
    Setattr(n, "doxygen", comment);
    n = nextSibling(n);
  }
}

/* -----------------------------------------------------------------------------
 *                              Variables
 * ----------------------------------------------------------------------------- */

static char  *typemap_lang = 0;    /* Current language setting */

static int cplus_mode  = 0;

/* C++ modes */

#define  CPLUS_PUBLIC    1
#define  CPLUS_PRIVATE   2
#define  CPLUS_PROTECTED 3

/* include types */
static int   import_mode = 0;

void SWIG_typemap_lang(const char *tm_lang) {
  typemap_lang = Swig_copy_string(tm_lang);
}

void SWIG_cparse_set_compact_default_args(int defargs) {
  compact_default_args = defargs;
}

int SWIG_cparse_template_reduce(int treduce) {
  template_reduce = treduce;
  return treduce;  
}

/* -----------------------------------------------------------------------------
 *                           Assist functions
 * ----------------------------------------------------------------------------- */

static int promote_type(int t) {
  if (t <= T_UCHAR || t == T_CHAR || t == T_WCHAR) return T_INT;
  return t;
}

/* Perform type-promotion for binary operators */
static int promote(int t1, int t2) {
  t1 = promote_type(t1);
  t2 = promote_type(t2);
  return t1 > t2 ? t1 : t2;
}

static String *yyrename = 0;

/* Forward renaming operator */

static String *resolve_create_node_scope(String *cname, int is_class_definition);


Hash *Swig_cparse_features(void) {
  static Hash   *features_hash = 0;
  if (!features_hash) features_hash = NewHash();
  return features_hash;
}

/* Fully qualify any template parameters */
static String *feature_identifier_fix(String *s) {
  String *tp = SwigType_istemplate_templateprefix(s);
  if (tp) {
    String *ts, *ta, *tq;
    ts = SwigType_templatesuffix(s);
    ta = SwigType_templateargs(s);
    tq = Swig_symbol_type_qualify(ta,0);
    Append(tp,tq);
    Append(tp,ts);
    Delete(ts);
    Delete(ta);
    Delete(tq);
    return tp;
  } else {
    return NewString(s);
  }
}

static void set_access_mode(Node *n) {
  if (cplus_mode == CPLUS_PUBLIC)
    Setattr(n, "access", "public");
  else if (cplus_mode == CPLUS_PROTECTED)
    Setattr(n, "access", "protected");
  else
    Setattr(n, "access", "private");
}

static void restore_access_mode(Node *n) {
  String *mode = Getattr(n, "access");
  if (Strcmp(mode, "private") == 0)
    cplus_mode = CPLUS_PRIVATE;
  else if (Strcmp(mode, "protected") == 0)
    cplus_mode = CPLUS_PROTECTED;
  else
    cplus_mode = CPLUS_PUBLIC;
}

/* Generate the symbol table name for an object */
/* This is a bit of a mess. Need to clean up */
static String *add_oldname = 0;



static String *make_name(Node *n, String *name,SwigType *decl) {
  String *made_name = 0;
  int destructor = name && (*(Char(name)) == '~');

  if (yyrename) {
    String *s = NewString(yyrename);
    Delete(yyrename);
    yyrename = 0;
    if (destructor  && (*(Char(s)) != '~')) {
      Insert(s,0,"~");
    }
    return s;
  }

  if (!name) return 0;

  if (parsing_template_declaration)
    SetFlag(n, "parsing_template_declaration");
  made_name = Swig_name_make(n, Namespaceprefix, name, decl, add_oldname);
  Delattr(n, "parsing_template_declaration");

  return made_name;
}

/* Generate an unnamed identifier */
static String *make_unnamed() {
  unnamed++;
  return NewStringf("$unnamed%d$",unnamed);
}

/* Return if the node is a friend declaration */
static int is_friend(Node *n) {
  return Cmp(Getattr(n,"storage"),"friend") == 0;
}

static int is_operator(String *name) {
  return Strncmp(name,"operator ", 9) == 0;
}


/* Add declaration list to symbol table */
static int  add_only_one = 0;

static void add_symbols(Node *n) {
  String *decl;
  String *wrn = 0;

  if (inclass && n) {
    cparse_normalize_void(n);
  }
  while (n) {
    String *symname = 0;
    /* for friends, we need to pop the scope once */
    String *old_prefix = 0;
    Symtab *old_scope = 0;
    int isfriend = inclass && is_friend(n);
    int iscdecl = Cmp(nodeType(n),"cdecl") == 0;
    int only_csymbol = 0;
    
    if (inclass) {
      String *name = Getattr(n, "name");
      if (isfriend) {
	/* for friends, we need to add the scopename if needed */
	String *prefix = name ? Swig_scopename_prefix(name) : 0;
	old_prefix = Namespaceprefix;
	old_scope = Swig_symbol_popscope();
	Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	if (!prefix) {
	  if (name && !is_operator(name) && Namespaceprefix) {
	    String *nname = NewStringf("%s::%s", Namespaceprefix, name);
	    Setattr(n,"name",nname);
	    Delete(nname);
	  }
	} else {
	  Symtab *st = Swig_symbol_getscope(prefix);
	  String *ns = st ? Getattr(st,"name") : prefix;
	  String *base  = Swig_scopename_last(name);
	  String *nname = NewStringf("%s::%s", ns, base);
	  Setattr(n,"name",nname);
	  Delete(nname);
	  Delete(base);
	  Delete(prefix);
	}
	Namespaceprefix = 0;
      } else {
	/* for member functions, we need to remove the redundant
	   class scope if provided, as in
	   
	   struct Foo {
	   int Foo::method(int a);
	   };
	   
	*/
	String *prefix = name ? Swig_scopename_prefix(name) : 0;
	if (prefix) {
	  if (Classprefix && (Equal(prefix,Classprefix))) {
	    String *base = Swig_scopename_last(name);
	    Setattr(n,"name",base);
	    Delete(base);
	  }
	  Delete(prefix);
	}
      }
    }

    if (!isfriend && (inclass || extendmode)) {
      Setattr(n,"ismember","1");
    }

    if (extendmode) {
      if (!Getattr(n, "template"))
        SetFlag(n,"isextendmember");
    }

    if (!isfriend && inclass) {
      if ((cplus_mode != CPLUS_PUBLIC)) {
	only_csymbol = 1;
	if (cplus_mode == CPLUS_PROTECTED) {
	  Setattr(n,"access", "protected");
	  only_csymbol = !Swig_need_protected(n);
	} else {
	  Setattr(n,"access", "private");
	  /* private are needed only when they are pure virtuals - why? */
	  if ((Cmp(Getattr(n,"storage"),"virtual") == 0) && (Cmp(Getattr(n,"value"),"0") == 0)) {
	    only_csymbol = 0;
	  }
	  if (Cmp(nodeType(n),"destructor") == 0) {
	    /* Needed for "unref" feature */
	    only_csymbol = 0;
	  }
	}
      } else {
	  Setattr(n,"access", "public");
      }
    }
    if (Getattr(n,"sym:name")) {
      n = nextSibling(n);
      continue;
    }
    decl = Getattr(n,"decl");
    if (!SwigType_isfunction(decl)) {
      String *name = Getattr(n,"name");
      String *makename = Getattr(n,"parser:makename");
      if (iscdecl) {	
	String *storage = Getattr(n, "storage");
	if (Cmp(storage,"typedef") == 0) {
	  Setattr(n,"kind","typedef");
	} else {
	  SwigType *type = Getattr(n,"type");
	  String *value = Getattr(n,"value");
	  Setattr(n,"kind","variable");
	  if (value && Len(value)) {
	    Setattr(n,"hasvalue","1");
	  }
	  if (type) {
	    SwigType *ty;
	    SwigType *tmp = 0;
	    if (decl) {
	      ty = tmp = Copy(type);
	      SwigType_push(ty,decl);
	    } else {
	      ty = type;
	    }
	    if (!SwigType_ismutable(ty) || (storage && Strstr(storage, "constexpr"))) {
	      SetFlag(n,"hasconsttype");
	      SetFlag(n,"feature:immutable");
	    }
	    if (tmp) Delete(tmp);
	  }
	  if (!type) {
	    Printf(stderr,"notype name %s\n", name);
	  }
	}
      }
      Swig_features_get(Swig_cparse_features(), Namespaceprefix, name, 0, n);
      if (makename) {
	symname = make_name(n, makename,0);
        Delattr(n,"parser:makename"); /* temporary information, don't leave it hanging around */
      } else {
        makename = name;
	symname = make_name(n, makename,0);
      }
      
      if (!symname) {
	symname = Copy(Getattr(n,"unnamed"));
      }
      if (symname) {
	if (parsing_template_declaration)
	  SetFlag(n, "parsing_template_declaration");
	wrn = Swig_name_warning(n, Namespaceprefix, symname,0);
	Delattr(n, "parsing_template_declaration");
      }
    } else {
      String *name = Getattr(n,"name");
      SwigType *fdecl = Copy(decl);
      SwigType *fun = SwigType_pop_function(fdecl);
      if (iscdecl) {	
	Setattr(n,"kind","function");
      }
      
      Swig_features_get(Swig_cparse_features(),Namespaceprefix,name,fun,n);

      symname = make_name(n, name,fun);
      if (parsing_template_declaration)
	SetFlag(n, "parsing_template_declaration");
      wrn = Swig_name_warning(n, Namespaceprefix,symname,fun);
      Delattr(n, "parsing_template_declaration");
      
      Delete(fdecl);
      Delete(fun);
      
    }
    if (!symname) {
      n = nextSibling(n);
      continue;
    }
    if (cparse_cplusplus) {
      String *value = Getattr(n, "value");
      if (value && Strcmp(value, "delete") == 0) {
	/* C++11 deleted definition / deleted function */
        SetFlag(n,"deleted");
        SetFlag(n,"feature:ignore");
      }
      if (SwigType_isrvalue_reference(Getattr(n, "refqualifier"))) {
	/* Ignore rvalue ref-qualifiers by default
	 * Use Getattr instead of GetFlag to handle explicit ignore and explicit not ignore */
	if (!(Getattr(n, "feature:ignore") || Strncmp(symname, "$ignore", 7) == 0)) {
	  SWIG_WARN_NODE_BEGIN(n);
	  Swig_warning(WARN_TYPE_RVALUE_REF_QUALIFIER_IGNORED, Getfile(n), Getline(n),
	      "Method with rvalue ref-qualifier %s ignored.\n", Swig_name_decl(n));
	  SWIG_WARN_NODE_END(n);
	  SetFlag(n, "feature:ignore");
	}
      }
    }
    if (only_csymbol || GetFlag(n, "feature:ignore") || Strncmp(symname, "$ignore", 7) == 0) {
      /* Only add to C symbol table and continue */
      Swig_symbol_add(0, n);
      if (!only_csymbol && !GetFlag(n, "feature:ignore")) {
	/* Print the warning attached to $ignore name, if any */
        char *c = Char(symname) + 7;
	if (strlen(c)) {
	  SWIG_WARN_NODE_BEGIN(n);
	  Swig_warning(0,Getfile(n), Getline(n), "%s\n",c+1);
	  SWIG_WARN_NODE_END(n);
	}
	/* If the symbol was ignored via "rename" and is visible, set also feature:ignore*/
	SetFlag(n, "feature:ignore");
      }
      if (!GetFlag(n, "feature:ignore") && Strcmp(symname,"$ignore") == 0) {
	/* Add feature:ignore if the symbol was explicitly ignored, regardless of visibility */
	SetFlag(n, "feature:ignore");
      }
    } else {
      Node *c;
      if ((wrn) && (Len(wrn))) {
	String *metaname = symname;
	if (!Getmeta(metaname,"already_warned")) {
	  SWIG_WARN_NODE_BEGIN(n);
	  Swig_warning(0,Getfile(n),Getline(n), "%s\n", wrn);
	  SWIG_WARN_NODE_END(n);
	  Setmeta(metaname,"already_warned","1");
	}
      }
      c = Swig_symbol_add(symname,n);

      if (c != n) {
        /* symbol conflict attempting to add in the new symbol */
        if (Getattr(n,"sym:weak")) {
          Setattr(n,"sym:name",symname);
        } else {
          String *e = NewStringEmpty();
          String *en = NewStringEmpty();
          String *ec = NewStringEmpty();
          int redefined = Swig_need_redefined_warn(n,c,inclass);
          if (redefined) {
            Printf(en,"Identifier '%s' redefined (ignored)",symname);
            Printf(ec,"previous definition of '%s'",symname);
          } else {
            Printf(en,"Redundant redeclaration of '%s'",symname);
            Printf(ec,"previous declaration of '%s'",symname);
          }
          if (Cmp(symname,Getattr(n,"name"))) {
            Printf(en," (Renamed from '%s')", SwigType_namestr(Getattr(n,"name")));
          }
          Printf(en,",");
          if (Cmp(symname,Getattr(c,"name"))) {
            Printf(ec," (Renamed from '%s')", SwigType_namestr(Getattr(c,"name")));
          }
          Printf(ec,".");
	  SWIG_WARN_NODE_BEGIN(n);
          if (redefined) {
            Swig_warning(WARN_PARSE_REDEFINED,Getfile(n),Getline(n),"%s\n",en);
            Swig_warning(WARN_PARSE_REDEFINED,Getfile(c),Getline(c),"%s\n",ec);
          } else if (!is_friend(n) && !is_friend(c)) {
            Swig_warning(WARN_PARSE_REDUNDANT,Getfile(n),Getline(n),"%s\n",en);
            Swig_warning(WARN_PARSE_REDUNDANT,Getfile(c),Getline(c),"%s\n",ec);
          }
	  SWIG_WARN_NODE_END(n);
          Printf(e,"%s:%d:%s\n%s:%d:%s\n",Getfile(n),Getline(n),en,
                 Getfile(c),Getline(c),ec);
          Setattr(n,"error",e);
	  Delete(e);
          Delete(en);
          Delete(ec);
        }
      }
    }
    /* restore the class scope if needed */
    if (isfriend) {
      Swig_symbol_setscope(old_scope);
      if (old_prefix) {
	Delete(Namespaceprefix);
	Namespaceprefix = old_prefix;
      }
    }
    Delete(symname);

    if (add_only_one) return;
    n = nextSibling(n);
  }
}


/* add symbols a parse tree node copy */

static void add_symbols_copy(Node *n) {
  String *name;
  int    emode = 0;
  while (n) {
    char *cnodeType = Char(nodeType(n));

    if (strcmp(cnodeType,"access") == 0) {
      String *kind = Getattr(n,"kind");
      if (Strcmp(kind,"public") == 0) {
	cplus_mode = CPLUS_PUBLIC;
      } else if (Strcmp(kind,"private") == 0) {
	cplus_mode = CPLUS_PRIVATE;
      } else if (Strcmp(kind,"protected") == 0) {
	cplus_mode = CPLUS_PROTECTED;
      }
      n = nextSibling(n);
      continue;
    }

    add_oldname = Getattr(n,"sym:name");
    if ((add_oldname) || (Getattr(n,"sym:needs_symtab"))) {
      int old_inclass = -1;
      Node *old_current_class = 0;
      if (add_oldname) {
	DohIncref(add_oldname);
	/*  Disable this, it prevents %rename to work with templates */
	/* If already renamed, we used that name  */
	/*
	if (Strcmp(add_oldname, Getattr(n,"name")) != 0) {
	  Delete(yyrename);
	  yyrename = Copy(add_oldname);
	}
	*/
      }
      Delattr(n,"sym:needs_symtab");
      Delattr(n,"sym:name");

      add_only_one = 1;
      add_symbols(n);

      if (Getattr(n,"partialargs")) {
	Swig_symbol_cadd(Getattr(n,"partialargs"),n);
      }
      add_only_one = 0;
      name = Getattr(n,"name");
      if (Getattr(n,"requires_symtab")) {
	Swig_symbol_newscope();
	Swig_symbol_setscopename(name);
	Delete(Namespaceprefix);
	Namespaceprefix = Swig_symbol_qualifiedscopename(0);
      }
      if (strcmp(cnodeType,"class") == 0) {
	old_inclass = inclass;
	inclass = 1;
	old_current_class = current_class;
	current_class = n;
	if (Strcmp(Getattr(n,"kind"),"class") == 0) {
	  cplus_mode = CPLUS_PRIVATE;
	} else {
	  cplus_mode = CPLUS_PUBLIC;
	}
      }
      if (strcmp(cnodeType,"extend") == 0) {
	emode = cplus_mode;
	cplus_mode = CPLUS_PUBLIC;
      }
      add_symbols_copy(firstChild(n));
      if (strcmp(cnodeType,"extend") == 0) {
	cplus_mode = emode;
      }
      if (Getattr(n,"requires_symtab")) {
	Setattr(n,"symtab", Swig_symbol_popscope());
	Delattr(n,"requires_symtab");
	Delete(Namespaceprefix);
	Namespaceprefix = Swig_symbol_qualifiedscopename(0);
      }
      if (add_oldname) {
	Delete(add_oldname);
	add_oldname = 0;
      }
      if (strcmp(cnodeType,"class") == 0) {
	inclass = old_inclass;
	current_class = old_current_class;
      }
    } else {
      if (strcmp(cnodeType,"extend") == 0) {
	emode = cplus_mode;
	cplus_mode = CPLUS_PUBLIC;
      }
      add_symbols_copy(firstChild(n));
      if (strcmp(cnodeType,"extend") == 0) {
	cplus_mode = emode;
      }
    }
    n = nextSibling(n);
  }
}

/* Add in the "defaultargs" attribute for functions in instantiated templates.
 * n should be any instantiated template (class or start of linked list of functions). */
static void update_defaultargs(Node *n) {
  if (n) {
    Node *firstdefaultargs = n;
    update_defaultargs(firstChild(n));
    n = nextSibling(n);
    /* recursively loop through nodes of all types, but all we really need are the overloaded functions */
    while (n) {
      update_defaultargs(firstChild(n));
      if (!Getattr(n, "defaultargs")) {
	if (Getattr(n, "needs_defaultargs")) {
	  Setattr(n, "defaultargs", firstdefaultargs);
	  Delattr(n, "needs_defaultargs");
	} else {
	  firstdefaultargs = n;
	}
      } else {
	/* Functions added in with %extend (for specialized template classes) will already have default args patched up */
	assert(Getattr(n, "defaultargs") == firstdefaultargs);
      }
      n = nextSibling(n);
    }
  }
}

/* Check a set of declarations to see if any are pure-abstract */

static List *pure_abstracts(Node *n) {
  List *abstracts = 0;
  while (n) {
    if (Cmp(nodeType(n),"cdecl") == 0) {
      String *decl = Getattr(n,"decl");
      if (SwigType_isfunction(decl)) {
	String *init = Getattr(n,"value");
	if (Cmp(init,"0") == 0) {
	  if (!abstracts) {
	    abstracts = NewList();
	  }
	  Append(abstracts,n);
	  SetFlag(n,"abstract");
	}
      }
    } else if (Cmp(nodeType(n),"destructor") == 0) {
      if (Cmp(Getattr(n,"value"),"0") == 0) {
	if (!abstracts) {
	  abstracts = NewList();
	}
	Append(abstracts,n);
	SetFlag(n,"abstract");
      }
    }
    n = nextSibling(n);
  }
  return abstracts;
}

/* Recompute the "abstracts" attribute for the classes in instantiated templates, similarly to update_defaultargs() above. */
static void update_abstracts(Node *n) {
  for (; n; n = nextSibling(n)) {
    Node* const child = firstChild(n);
    if (!child)
      continue;

    update_abstracts(child);

    if (Getattr(n, "needs_abstracts")) {
      Setattr(n, "abstracts", pure_abstracts(child));
      Delattr(n, "needs_abstracts");
    }
  }
}

/* Make a classname */

static String *make_class_name(String *name) {
  String *nname = 0;
  String *prefix;
  if (Namespaceprefix) {
    nname= NewStringf("%s::%s", Namespaceprefix, name);
  } else {
    nname = NewString(name);
  }
  prefix = SwigType_istemplate_templateprefix(nname);
  if (prefix) {
    String *args, *qargs;
    args   = SwigType_templateargs(nname);
    qargs  = Swig_symbol_type_qualify(args,0);
    Append(prefix,qargs);
    Delete(nname);
    Delete(args);
    Delete(qargs);
    nname = prefix;
  }
  return nname;
}

/* Use typedef name as class name */

static void add_typedef_name(Node *n, Node *declnode, String *oldName, Symtab *cscope, String *scpname) {
  String *class_rename = 0;
  SwigType *decl = Getattr(declnode, "decl");
  if (!decl || !Len(decl)) {
    String *cname;
    String *tdscopename;
    String *class_scope = Swig_symbol_qualifiedscopename(cscope);
    String *name = Getattr(declnode, "name");
    cname = Copy(name);
    Setattr(n, "tdname", cname);
    tdscopename = class_scope ? NewStringf("%s::%s", class_scope, name) : Copy(name);
    class_rename = Getattr(n, "class_rename");
    if (class_rename && (Strcmp(class_rename, oldName) == 0))
      Setattr(n, "class_rename", NewString(name));
    if (!classes_typedefs) classes_typedefs = NewHash();
    if (!Equal(scpname, tdscopename) && !Getattr(classes_typedefs, tdscopename)) {
      Setattr(classes_typedefs, tdscopename, n);
    }
    Setattr(n, "decl", decl);
    Delete(class_scope);
    Delete(cname);
    Delete(tdscopename);
  }
}

/* If the class name is qualified.  We need to create or lookup namespace entries */

static Symtab *set_scope_to_global() {
  Symtab *symtab = Swig_symbol_global_scope();
  Swig_symbol_setscope(symtab);
  return symtab;
}
 
/* Remove the block braces, { and }, if the 'noblock' attribute is set.
 * Node *kw can be either a Hash or Parmlist. */
static String *remove_block(Node *kw, const String *inputcode) {
  String *modified_code = 0;
  while (kw) {
   String *name = Getattr(kw,"name");
   if (name && (Cmp(name,"noblock") == 0)) {
     char *cstr = Char(inputcode);
     int len = Len(inputcode);
     if (len && cstr[0] == '{') {
       --len; ++cstr; 
       if (len && cstr[len - 1] == '}') { --len; }
       /* we now remove the extra spaces */
       while (len && isspace((int)cstr[0])) { --len; ++cstr; }
       while (len && isspace((int)cstr[len - 1])) { --len; }
       modified_code = NewStringWithSize(cstr, len);
       break;
     }
   }
   kw = nextSibling(kw);
  }
  return modified_code;
}

/*
#define RESOLVE_DEBUG 1
*/
static Node *nscope = 0;
static Node *nscope_inner = 0;

/* Remove the scope prefix from cname and return the base name without the prefix.
 * The scopes required for the symbol name are resolved and/or created, if required.
 * For example AA::BB::CC as input returns CC and creates the namespace AA then inner 
 * namespace BB in the current scope. */
static String *resolve_create_node_scope(String *cname, int is_class_definition) {
  Symtab *gscope = 0;
  Node *cname_node = 0;
  String *last = Swig_scopename_last(cname);
  nscope = 0;
  nscope_inner = 0;  

  if (Strncmp(cname,"::" ,2) != 0) {
    if (is_class_definition) {
      /* Only lookup symbols which are in scope via a using declaration but not via a using directive.
         For example find y via 'using x::y' but not y via a 'using namespace x'. */
      cname_node = Swig_symbol_clookup_no_inherit(cname, 0);
      if (!cname_node) {
	Node *full_lookup_node = Swig_symbol_clookup(cname, 0);
	if (full_lookup_node) {
	 /* This finds a symbol brought into scope via both a using directive and a using declaration. */
	  Node *last_node = Swig_symbol_clookup_no_inherit(last, 0);
	  if (last_node == full_lookup_node)
	    cname_node = last_node;
	}
      }
    } else {
      /* For %template, the template needs to be in scope via any means. */
      cname_node = Swig_symbol_clookup(cname, 0);
    }
  }
#if RESOLVE_DEBUG
  if (!cname_node)
    Printf(stdout, "symbol does not yet exist (%d): [%s]\n", is_class_definition, cname);
  else
    Printf(stdout, "symbol does exist (%d): [%s]\n", is_class_definition, cname);
#endif

  if (cname_node) {
    /* The symbol has been defined already or is in another scope.
       If it is a weak symbol, it needs replacing and if it was brought into the current scope,
       the scope needs adjusting appropriately for the new symbol.
       Similarly for defined templates. */
    Symtab *symtab = Getattr(cname_node, "sym:symtab");
    Node *sym_weak = Getattr(cname_node, "sym:weak");
    if ((symtab && sym_weak) || Equal(nodeType(cname_node), "template")) {
      /* Check if the scope is the current scope */
      String *current_scopename = Swig_symbol_qualifiedscopename(0);
      String *found_scopename = Swig_symbol_qualifiedscopename(symtab);
      if (!current_scopename)
	current_scopename = NewString("");
      if (!found_scopename)
	found_scopename = NewString("");

      {
	int fail = 1;
	List *current_scopes = Swig_scopename_tolist(current_scopename);
	List *found_scopes = Swig_scopename_tolist(found_scopename);
        Iterator cit = First(current_scopes);
	Iterator fit = First(found_scopes);
#if RESOLVE_DEBUG
Printf(stdout, "comparing current: [%s] found: [%s]\n", current_scopename, found_scopename);
#endif
	for (; fit.item && cit.item; fit = Next(fit), cit = Next(cit)) {
	  String *current = cit.item;
	  String *found = fit.item;
#if RESOLVE_DEBUG
	  Printf(stdout, "  looping %s %s\n", current, found);
#endif
	  if (Strcmp(current, found) != 0)
	    break;
	}

	if (!cit.item) {
	  String *subscope = NewString("");
	  for (; fit.item; fit = Next(fit)) {
	    if (Len(subscope) > 0)
	      Append(subscope, "::");
	    Append(subscope, fit.item);
	  }
	  if (Len(subscope) > 0)
	    cname = NewStringf("%s::%s", subscope, last);
	  else
	    cname = Copy(last);
#if RESOLVE_DEBUG
	  Printf(stdout, "subscope to create: [%s] cname: [%s]\n", subscope, cname);
#endif
	  fail = 0;
	  Delete(subscope);
	} else {
	  if (is_class_definition) {
	    if (!fit.item) {
	      /* It is valid to define a new class with the same name as one forward declared in a parent scope */
	      fail = 0;
	    } else if (Swig_scopename_check(cname)) {
	      /* Classes defined with scope qualifiers must have a matching forward declaration in matching scope */
	      fail = 1;
	    } else {
	      /* This may let through some invalid cases */
	      fail = 0;
	    }
#if RESOLVE_DEBUG
	    Printf(stdout, "scope for class definition, fail: %d\n", fail);
#endif
	  } else {
#if RESOLVE_DEBUG
	    Printf(stdout, "no matching base scope for template\n");
#endif
	    fail = 1;
	  }
	}

	Delete(found_scopes);
	Delete(current_scopes);

	if (fail) {
	  String *cname_resolved = NewStringf("%s::%s", found_scopename, last);
	  Swig_error(cparse_file, cparse_line, "'%s' resolves to '%s' and was incorrectly instantiated in scope '%s' instead of within scope '%s'.\n", cname, cname_resolved, current_scopename, found_scopename);
	  cname = Copy(last);
	  Delete(cname_resolved);
	}
      }

      Delete(current_scopename);
      Delete(found_scopename);
    }
  } else if (!is_class_definition) {
    /* A template instantiation requires a template to be found in scope... fail here too?
    Swig_error(cparse_file, cparse_line, "No template found to instantiate '%s' with %%template.\n", cname);
     */
  }

  if (Swig_scopename_check(cname)) {
    Node   *ns;
    String *prefix = Swig_scopename_prefix(cname);
    if (prefix && (Strncmp(prefix,"::",2) == 0)) {
/* I don't think we can use :: global scope to declare classes and hence neither %template. - consider reporting error instead - wsfulton. */
      /* Use the global scope */
      String *nprefix = NewString(Char(prefix)+2);
      Delete(prefix);
      prefix= nprefix;
      gscope = set_scope_to_global();
    }
    if (Len(prefix) == 0) {
      String *base = Copy(last);
      /* Use the global scope, but we need to add a 'global' namespace.  */
      if (!gscope) gscope = set_scope_to_global();
      /* note that this namespace is not the "unnamed" one,
	 and we don't use Setattr(nscope,"name", ""),
	 because the unnamed namespace is private */
      nscope = new_node("namespace");
      Setattr(nscope,"symtab", gscope);;
      nscope_inner = nscope;
      Delete(last);
      return base;
    }
    /* Try to locate the scope */
    ns = Swig_symbol_clookup(prefix,0);
    if (!ns) {
      Swig_error(cparse_file,cparse_line,"Undefined scope '%s'\n", prefix);
    } else {
      Symtab *nstab = Getattr(ns,"symtab");
      if (!nstab) {
	Swig_error(cparse_file,cparse_line, "'%s' is not defined as a valid scope.\n", prefix);
	ns = 0;
      } else {
	/* Check if the node scope is the current scope */
	String *tname = Swig_symbol_qualifiedscopename(0);
	String *nname = Swig_symbol_qualifiedscopename(nstab);
	if (tname && (Strcmp(tname,nname) == 0)) {
	  ns = 0;
	  cname = Copy(last);
	}
	Delete(tname);
	Delete(nname);
      }
      if (ns) {
	/* we will try to create a new node using the namespaces we
	   can find in the scope name */
	List *scopes = Swig_scopename_tolist(prefix);
	String *sname;
	Iterator si;

	for (si = First(scopes); si.item; si = Next(si)) {
	  Node *ns1,*ns2;
	  sname = si.item;
	  ns1 = Swig_symbol_clookup(sname,0);
	  assert(ns1);
	  if (Strcmp(nodeType(ns1),"namespace") == 0) {
	    if (Getattr(ns1,"alias")) {
	      ns1 = Getattr(ns1,"namespace");
	    }
	  } else {
	    /* now this last part is a class */
	    si = Next(si);
	    /*  or a nested class tree, which is unrolled here */
	    for (; si.item; si = Next(si)) {
	      if (si.item) {
		Printf(sname,"::%s",si.item);
	      }
	    }
	    /* we get the 'inner' class */
	    nscope_inner = Swig_symbol_clookup(sname,0);
	    /* set the scope to the inner class */
	    Swig_symbol_setscope(Getattr(nscope_inner,"symtab"));
	    /* save the last namespace prefix */
	    Delete(Namespaceprefix);
	    Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	    /* and return the node name, including the inner class prefix */
	    break;
	  }
	  /* here we just populate the namespace tree as usual */
	  ns2 = new_node("namespace");
	  Setattr(ns2,"name",sname);
	  Setattr(ns2,"symtab", Getattr(ns1,"symtab"));
	  add_symbols(ns2);
	  Swig_symbol_setscope(Getattr(ns1,"symtab"));
	  Delete(Namespaceprefix);
	  Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	  if (nscope_inner) {
	    if (Getattr(nscope_inner,"symtab") != Getattr(ns2,"symtab")) {
	      appendChild(nscope_inner,ns2);
	      Delete(ns2);
	    }
	  }
	  nscope_inner = ns2;
	  if (!nscope) nscope = ns2;
	}
	cname = Copy(last);
	Delete(scopes);
      }
    }
    Delete(prefix);
  }
  Delete(last);

  return cname;
}
 
/* look for simple typedef name in typedef list */
static String *try_to_find_a_name_for_unnamed_structure(const char *storage, Node *decls) {
  String *name = 0;
  Node *n = decls;
  if (storage && (strcmp(storage, "typedef") == 0)) {
    for (; n; n = nextSibling(n)) {
      if (!Len(Getattr(n, "decl"))) {
	name = Copy(Getattr(n, "name"));
	break;
      }
    }
  }
  return name;
}

/* traverse copied tree segment, and update outer class links*/
static void update_nested_classes(Node *n)
{
  Node *c = firstChild(n);
  while (c) {
    if (Getattr(c, "nested:outer"))
      Setattr(c, "nested:outer", n);
    update_nested_classes(c);
    c = nextSibling(c);
  }
}

/* -----------------------------------------------------------------------------
 * nested_forward_declaration()
 * 
 * Nested struct handling for C++ code if the nested classes are disabled.
 * Create the nested class/struct/union as a forward declaration.
 * ----------------------------------------------------------------------------- */

static Node *nested_forward_declaration(const char *storage, const char *kind, String *sname, String *name, Node *cpp_opt_declarators) {
  Node *nn = 0;

  if (sname) {
    /* Add forward declaration of the nested type */
    Node *n = new_node("classforward");
    Setattr(n, "kind", kind);
    Setattr(n, "name", sname);
    Setattr(n, "storage", storage);
    Setattr(n, "sym:weak", "1");
    add_symbols(n);
    nn = n;
  }

  /* Add any variable instances. Also add in any further typedefs of the nested type.
     Note that anonymous typedefs (eg typedef struct {...} a, b;) are treated as class forward declarations */
  if (cpp_opt_declarators) {
    int storage_typedef = (storage && (strcmp(storage, "typedef") == 0));
    int variable_of_anonymous_type = !sname && !storage_typedef;
    if (!variable_of_anonymous_type) {
      int anonymous_typedef = !sname && (storage && (strcmp(storage, "typedef") == 0));
      Node *n = cpp_opt_declarators;
      SwigType *type = name;
      while (n) {
	Setattr(n, "type", type);
	Setattr(n, "storage", storage);
	if (anonymous_typedef) {
	  Setattr(n, "nodeType", "classforward");
	  Setattr(n, "sym:weak", "1");
	}
	n = nextSibling(n);
      }
      add_symbols(cpp_opt_declarators);

      if (nn) {
	set_nextSibling(nn, cpp_opt_declarators);
      } else {
	nn = cpp_opt_declarators;
      }
    }
  }

  if (!currentOuterClass || !GetFlag(currentOuterClass, "nested")) {
    if (nn && Equal(nodeType(nn), "classforward")) {
      Node *n = nn;
      if (!GetFlag(n, "feature:ignore")) {
	SWIG_WARN_NODE_BEGIN(n);
	Swig_warning(WARN_PARSE_NAMED_NESTED_CLASS, cparse_file, cparse_line,"Nested %s not currently supported (%s ignored)\n", kind, sname ? sname : name);
	SWIG_WARN_NODE_END(n);
      }
    } else {
      Swig_warning(WARN_PARSE_UNNAMED_NESTED_CLASS, cparse_file, cparse_line, "Nested %s not currently supported (ignored).\n", kind);
    }
  }

  return nn;
}


Node *Swig_cparse(File *f) {
  scanner_file(f);
  top = 0;
  yyparse();
  return top;
}

static void single_new_feature(const char *featurename, String *val, Hash *featureattribs, char *declaratorid, SwigType *type, ParmList *declaratorparms, String *qualifier) {
  String *fname;
  String *name;
  String *fixname;
  SwigType *t = Copy(type);

  /* Printf(stdout, "single_new_feature: [%s] [%s] [%s] [%s] [%s] [%s]\n", featurename, val, declaratorid, t, ParmList_str_defaultargs(declaratorparms), qualifier); */

  /* Warn about deprecated features */
  if (strcmp(featurename, "nestedworkaround") == 0)
    Swig_warning(WARN_DEPRECATED_NESTED_WORKAROUND, cparse_file, cparse_line, "The 'nestedworkaround' feature is deprecated.\n");

  fname = NewStringf("feature:%s",featurename);
  if (declaratorid) {
    fixname = feature_identifier_fix(declaratorid);
  } else {
    fixname = NewStringEmpty();
  }
  if (Namespaceprefix) {
    name = NewStringf("%s::%s",Namespaceprefix, fixname);
  } else {
    name = fixname;
  }

  if (declaratorparms) Setmeta(val,"parms",declaratorparms);
  if (!Len(t)) t = 0;
  if (t) {
    if (qualifier) SwigType_push(t,qualifier);
    if (SwigType_isfunction(t)) {
      SwigType *decl = SwigType_pop_function(t);
      if (SwigType_ispointer(t)) {
	String *nname = NewStringf("*%s",name);
	Swig_feature_set(Swig_cparse_features(), nname, decl, fname, val, featureattribs);
	Delete(nname);
      } else {
	Swig_feature_set(Swig_cparse_features(), name, decl, fname, val, featureattribs);
      }
      Delete(decl);
    } else if (SwigType_ispointer(t)) {
      String *nname = NewStringf("*%s",name);
      Swig_feature_set(Swig_cparse_features(),nname,0,fname,val, featureattribs);
      Delete(nname);
    }
  } else {
    /* Global feature, that is, feature not associated with any particular symbol */
    Swig_feature_set(Swig_cparse_features(),name,0,fname,val, featureattribs);
  }
  Delete(fname);
  Delete(name);
}

/* Add a new feature to the Hash. Additional features are added if the feature has a parameter list (declaratorparms)
 * and one or more of the parameters have a default argument. An extra feature is added for each defaulted parameter,
 * simulating the equivalent overloaded method. */
static void new_feature(const char *featurename, String *val, Hash *featureattribs, char *declaratorid, SwigType *type, ParmList *declaratorparms, String *qualifier) {

  ParmList *declparms = declaratorparms;

  /* remove the { and } braces if the noblock attribute is set */
  String *newval = remove_block(featureattribs, val);
  val = newval ? newval : val;

  /* Add the feature */
  single_new_feature(featurename, val, featureattribs, declaratorid, type, declaratorparms, qualifier);

  /* Add extra features if there are default parameters in the parameter list */
  if (type) {
    while (declparms) {
      if (ParmList_has_defaultargs(declparms)) {

        /* Create a parameter list for the new feature by copying all
           but the last (defaulted) parameter */
        ParmList* newparms = CopyParmListMax(declparms, ParmList_len(declparms)-1);

        /* Create new declaration - with the last parameter removed */
        SwigType *newtype = Copy(type);
        Delete(SwigType_pop_function(newtype)); /* remove the old parameter list from newtype */
        SwigType_add_function(newtype,newparms);

        single_new_feature(featurename, Copy(val), featureattribs, declaratorid, newtype, newparms, qualifier);
        declparms = newparms;
      } else {
        declparms = 0;
      }
    }
  }
}

/* check if a function declaration is a plain C object */
static int is_cfunction(Node *n) {
  if (!cparse_cplusplus || cparse_externc)
    return 1;
  if (Swig_storage_isexternc(n)) {
    return 1;
  }
  return 0;
}

/* If the Node is a function with parameters, check to see if any of the parameters
 * have default arguments. If so create a new function for each defaulted argument. 
 * The additional functions form a linked list of nodes with the head being the original Node n. */
static void default_arguments(Node *n) {
  Node *function = n;

  if (function) {
    ParmList *varargs = Getattr(function,"feature:varargs");
    if (varargs) {
      /* Handles the %varargs directive by looking for "feature:varargs" and 
       * substituting ... with an alternative set of arguments.  */
      Parm     *p = Getattr(function,"parms");
      Parm     *pp = 0;
      while (p) {
	SwigType *t = Getattr(p,"type");
	if (Strcmp(t,"v(...)") == 0) {
	  if (pp) {
	    ParmList *cv = Copy(varargs);
	    set_nextSibling(pp,cv);
	    Delete(cv);
	  } else {
	    ParmList *cv =  Copy(varargs);
	    Setattr(function,"parms", cv);
	    Delete(cv);
	  }
	  break;
	}
	pp = p;
	p = nextSibling(p);
      }
    }

    /* Do not add in functions if kwargs is being used or if user wants old default argument wrapping
       (one wrapped method per function irrespective of number of default arguments) */
    if (compact_default_args 
	|| is_cfunction(function) 
	|| GetFlag(function,"feature:compactdefaultargs") 
	|| (GetFlag(function,"feature:kwargs") && kwargs_supported)) {
      ParmList *p = Getattr(function,"parms");
      if (p) 
        Setattr(p,"compactdefargs", "1"); /* mark parameters for special handling */
      function = 0; /* don't add in extra methods */
    }
  }

  while (function) {
    ParmList *parms = Getattr(function,"parms");
    if (ParmList_has_defaultargs(parms)) {

      /* Create a parameter list for the new function by copying all
         but the last (defaulted) parameter */
      ParmList* newparms = CopyParmListMax(parms,ParmList_len(parms)-1);

      /* Create new function and add to symbol table */
      {
	SwigType *ntype = Copy(nodeType(function));
	char *cntype = Char(ntype);
        Node *new_function = new_node(ntype);
        SwigType *decl = Copy(Getattr(function,"decl"));
        int constqualifier = SwigType_isconst(decl);
	String *ccode = Copy(Getattr(function,"code"));
	String *cstorage = Copy(Getattr(function,"storage"));
	String *cvalue = Copy(Getattr(function,"value"));
	SwigType *ctype = Copy(Getattr(function,"type"));
	String *cthrow = Copy(Getattr(function,"throw"));

        Delete(SwigType_pop_function(decl)); /* remove the old parameter list from decl */
        SwigType_add_function(decl,newparms);
        if (constqualifier)
          SwigType_add_qualifier(decl,"const");

        Setattr(new_function,"name", Getattr(function,"name"));
        Setattr(new_function,"code", ccode);
        Setattr(new_function,"decl", decl);
        Setattr(new_function,"parms", newparms);
        Setattr(new_function,"storage", cstorage);
        Setattr(new_function,"value", cvalue);
        Setattr(new_function,"type", ctype);
        Setattr(new_function,"throw", cthrow);

	Delete(ccode);
	Delete(cstorage);
	Delete(cvalue);
	Delete(ctype);
	Delete(cthrow);
	Delete(decl);

        {
          Node *throws = Getattr(function,"throws");
	  ParmList *pl = CopyParmList(throws);
          if (throws) Setattr(new_function,"throws",pl);
	  Delete(pl);
        }

        /* copy specific attributes for global (or in a namespace) template functions - these are not templated class methods */
        if (strcmp(cntype,"template") == 0) {
          Node *templatetype = Getattr(function,"templatetype");
          Node *symtypename = Getattr(function,"sym:typename");
          Parm *templateparms = Getattr(function,"templateparms");
          if (templatetype) {
	    Node *tmp = Copy(templatetype);
	    Setattr(new_function,"templatetype",tmp);
	    Delete(tmp);
	  }
          if (symtypename) {
	    Node *tmp = Copy(symtypename);
	    Setattr(new_function,"sym:typename",tmp);
	    Delete(tmp);
	  }
          if (templateparms) {
	    Parm *tmp = CopyParmList(templateparms);
	    Setattr(new_function,"templateparms",tmp);
	    Delete(tmp);
	  }
        } else if (strcmp(cntype,"constructor") == 0) {
          /* only copied for constructors as this is not a user defined feature - it is hard coded in the parser */
          if (GetFlag(function,"feature:new")) SetFlag(new_function,"feature:new");
        }

        add_symbols(new_function);
        /* mark added functions as ones with overloaded parameters and point to the parsed method */
        Setattr(new_function,"defaultargs", n);

        /* Point to the new function, extending the linked list */
        set_nextSibling(function, new_function);
	Delete(new_function);
        function = new_function;
	
	Delete(ntype);
      }
    } else {
      function = 0;
    }
  }
}

/* -----------------------------------------------------------------------------
 * mark_nodes_as_extend()
 *
 * Used by the %extend to mark subtypes with "feature:extend".
 * template instances declared within %extend are skipped
 * ----------------------------------------------------------------------------- */

static void mark_nodes_as_extend(Node *n) {
  for (; n; n = nextSibling(n)) {
    if (Getattr(n, "template") && Strcmp(nodeType(n), "class") == 0)
      continue;
    /* Fix me: extend is not a feature. Replace with isextendmember? */
    Setattr(n, "feature:extend", "1");
    mark_nodes_as_extend(firstChild(n));
  }
}

/* -----------------------------------------------------------------------------
 * add_qualifier_to_declarator()
 *
 * Normally the qualifier is pushed on to the front of the type.
 * Adding a qualifier to a pointer to member function is a special case.
 * For example       : typedef double (Cls::*pmf)(void) const;
 * The qualifier is  : q(const).
 * The declarator is : m(Cls).f(void).
 * We need           : m(Cls).q(const).f(void).
 * ----------------------------------------------------------------------------- */

static String *add_qualifier_to_declarator(SwigType *type, SwigType *qualifier) {
  int is_pointer_to_member_function = 0;
  String *decl = Copy(type);
  String *poppedtype = NewString("");
  assert(qualifier);

  while (decl) {
    if (SwigType_ismemberpointer(decl)) {
      String *memberptr = SwigType_pop(decl);
      if (SwigType_isfunction(decl)) {
	is_pointer_to_member_function = 1;
	SwigType_push(decl, qualifier);
	SwigType_push(decl, memberptr);
	Insert(decl, 0, poppedtype);
	Delete(memberptr);
	break;
      } else {
	Append(poppedtype, memberptr);
      }
      Delete(memberptr);
    } else {
      String *popped = SwigType_pop(decl);
      if (!popped)
	break;
      Append(poppedtype, popped);
      Delete(popped);
    }
  }

  if (!is_pointer_to_member_function) {
    Delete(decl);
    decl = Copy(type);
    SwigType_push(decl, qualifier);
  }

  Delete(poppedtype);
  return decl;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
  const char  *id;
  List  *bases;
  struct Define {
    String *val;
    String *rawval;
    int     type;
    String *qualifier;
    String *refqualifier;
    String *bitfield;
    Parm   *throws;
    String *throwf;
    String *nexcept;
    String *final;
  } dtype;
  struct {
    const char *type;
    String *filename;
    int   line;
  } loc;
  struct {
    char      *id;
    SwigType  *type;
    String    *defarg;
    ParmList  *parms;
    short      have_parms;
    ParmList  *throws;
    String    *throwf;
    String    *nexcept;
    String    *final;
  } decl;
  Parm         *tparms;
  struct {
    String     *method;
    Hash       *kwargs;
  } tmap;
  struct {
    String     *type;
    String     *us;
  } ptype;
  SwigType     *type;
  String       *str;
  Parm         *p;
  ParmList     *pl;
  int           intvalue;
  Node         *node;
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  182
/* YYNRULES -- Number of rules.  */
#define YYNRULES  613
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   397

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    16,    19,    25,    29,
      32,    35,    38,    40,    42,    44,    46,    48,    50,    52,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    81,    83,    85,    87,    89,    91,    93,
      95,    97,    98,   107,   113,   117,   123,   129,   139,   143,
     146,   149,   155,   158,   164,   167,   172,   174,   176,   184,
     192,   198,   199,   207,   209,   211,   214,   217,   219,   226,
     233,   240,   244,   249,   253,   261,   270,   276,   280,   282,
     284,   288,   290,   295,   303,   310,   312,   314,   322,   332,
     341,   352,   358,   366,   373,   382,   384,   386,   392,   397,
     403,   411,   413,   417,   424,   431,   440,   442,   445,   449,
     451,   454,   458,   465,   471,   481,   484,   486,   488,   490,
     491,   498,   500,   507,   518,   520,   527,   537,   539,   545,
     547,   549,   551,   553,   555,   557,   559,   561,   563,   575,
     589,   597,   599,   601,   603,   604,   608,   610,   613,   616,
     619,   621,   627,   636,   648,   655,   657,   659,   661,   663,
     665,   667,   668,   678,   679,   688,   690,   695,   700,   701,
     708,   712,   717,   719,   721,   723,   725,   727,   729,   731,
     734,   736,   738,   740,   744,   746,   750,   755,   756,   763,
     764,   770,   776,   779,   780,   781,   789,   791,   793,   794,
     798,   800,   802,   804,   806,   808,   810,   812,   814,   818,
     820,   822,   824,   826,   828,   830,   832,   834,   836,   838,
     841,   844,   851,   858,   866,   875,   884,   893,   903,   911,
     917,   920,   923,   926,   929,   931,   933,   935,   937,   939,
     941,   943,   945,   947,   949,   951,   954,   959,   962,   965,
     970,   973,   979,   981,   983,   985,   987,   989,   992,   994,
     996,   999,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1017,
    1020,  1023,  1026,  1028,  1031,  1034,  1037,  1040,  1042,  1044,
    1047,  1049,  1053,  1058,  1060,  1063,  1071,  1075,  1077,  1080,
    1083,  1085,  1088,  1090,  1094,  1096,  1098,  1100,  1103,  1109,
    1112,  1115,  1117,  1120,  1123,  1125,  1131,  1133,  1135,  1141,
    1143,  1146,  1150,  1154,  1156,  1159,  1162,  1166,  1171,  1177,
    1182,  1188,  1195,  1202,  1207,  1213,  1219,  1226,  1234,  1243,
    1252,  1260,  1268,  1270,  1273,  1277,  1282,  1288,  1292,  1297,
    1302,  1304,  1307,  1312,  1317,  1322,  1328,  1335,  1341,  1348,
    1352,  1357,  1362,  1368,  1370,  1373,  1376,  1379,  1383,  1387,
    1389,  1392,  1395,  1397,  1399,  1402,  1406,  1410,  1415,  1419,
    1424,  1427,  1431,  1435,  1440,  1446,  1450,  1454,  1457,  1460,
    1462,  1464,  1467,  1469,  1471,  1473,  1475,  1478,  1480,  1482,
    1484,  1486,  1489,  1491,  1494,  1498,  1500,  1502,  1504,  1507,
    1509,  1511,  1514,  1516,  1521,  1523,  1525,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1557,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1579,  1581,  1583,  1585,  1588,  1592,  1597,  1599,
    1603,  1605,  1608,  1610,  1614,  1616,  1618,  1620,  1624,  1628,
    1632,  1634,  1636,  1638,  1644,  1653,  1655,  1657,  1659,  1661,
    1665,  1670,  1676,  1682,  1688,  1695,  1702,  1705,  1708,  1711,
    1713,  1715,  1717,  1719,  1721,  1723,  1725,  1727,  1731,  1735,
    1739,  1743,  1747,  1751,  1755,  1759,  1763,  1767,  1771,  1775,
    1779,  1783,  1787,  1791,  1797,  1800,  1803,  1806,  1809,  1812,
    1816,  1818,  1820,  1822,  1823,  1827,  1829,  1831,  1835,  1836,
    1841,  1842,  1849,  1851,  1853,  1855,  1857,  1859,  1864,  1869,
    1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,
    1891,  1893,  1896,  1899,  1901,  1903,  1908,  1910,  1912,  1918,
    1921,  1926,  1928,  1930,  1933,  1935,  1937,  1941,  1945,  1950,
    1955,  1959,  1964,  1967,  1969,  1971,  1975,  1980,  1987,  1990,
    1993,  1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,
    2016,  2021,  2023,  2027,  2029,  2032,  2036,  2040,  2043,  2046,
    2049,  2051,  2054,  2056,  2060,  2063,  2068,  2070,  2074,  2076,
    2080,  2084,  2087,  2090,  2093,  2096,  2098,  2101,  2103,  2105,
    2107,  2109,  2113,  2115,  2118,  2120,  2124,  2130,  2132,  2136,
    2140,  2146,  2148,  2150
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     144,     0,    -1,   145,    -1,   121,   240,    43,    -1,   121,
       1,    -1,   122,   240,    43,    -1,   122,     1,    -1,   123,
      40,   236,    41,    43,    -1,   123,     1,    43,    -1,   145,
     146,    -1,   145,   124,    -1,   145,   125,    -1,   324,    -1,
     147,    -1,   184,    -1,   200,    -1,    43,    -1,     1,    -1,
     199,    -1,     1,   120,    -1,   148,    -1,   150,    -1,   151,
      -1,   152,    -1,   153,    -1,   154,    -1,   157,    -1,   158,
      -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,
      -1,   166,    -1,   169,    -1,   171,    -1,   174,    -1,   176,
      -1,   181,    -1,   182,    -1,   183,    -1,    -1,    66,   320,
     296,   311,    46,   149,   217,    47,    -1,    98,   180,    46,
     178,    47,    -1,    99,   178,    43,    -1,    62,   308,    54,
     265,    43,    -1,    62,   258,   248,   245,    43,    -1,    62,
     258,   250,    40,   236,    41,   254,   245,    43,    -1,    62,
       1,    43,    -1,    97,     4,    -1,    97,   317,    -1,    96,
      40,   308,    41,    46,    -1,    96,    46,    -1,    96,    40,
     308,    41,    43,    -1,    96,    43,    -1,   317,    46,   240,
      47,    -1,   317,    -1,   155,    -1,   101,    40,   156,    42,
     322,    41,     4,    -1,   101,    40,   156,    42,   322,    41,
      46,    -1,   101,    40,   156,    41,    43,    -1,    -1,   160,
     320,   317,    59,   159,   145,    60,    -1,     8,    -1,     9,
      -1,    94,     4,    -1,    94,    46,    -1,     4,    -1,    10,
      40,   309,   321,    41,   317,    -1,    10,    40,   309,   321,
      41,     4,    -1,    10,    40,   309,   321,    41,    46,    -1,
      56,   320,   309,    -1,    63,    40,   309,    41,    -1,    63,
      40,    41,    -1,    93,    40,   308,    41,   235,   308,    43,
      -1,    93,    40,   308,    41,   235,   258,   248,    43,    -1,
      67,   168,   308,    54,   167,    -1,    67,   168,   308,    -1,
     317,    -1,     4,    -1,    40,   308,    41,    -1,   324,    -1,
     170,   248,   309,    43,    -1,   170,    40,   322,    41,   248,
     302,    43,    -1,   170,    40,   322,    41,   317,    43,    -1,
      64,    -1,    65,    -1,    68,    40,   309,    41,   248,   302,
     172,    -1,    68,    40,   309,    42,   323,    41,   248,   302,
      43,    -1,    68,    40,   309,   173,    41,   248,   302,   172,
      -1,    68,    40,   309,    42,   323,   173,    41,   248,   302,
      43,    -1,    68,    40,   309,    41,   172,    -1,    68,    40,
     309,    42,   323,    41,    43,    -1,    68,    40,   309,   173,
      41,   172,    -1,    68,    40,   309,    42,   323,   173,    41,
      43,    -1,   319,    -1,    43,    -1,   114,    40,   236,    41,
      43,    -1,    42,   309,    54,   323,    -1,    42,   309,    54,
     323,   173,    -1,    69,    40,   175,    41,   248,   302,    43,
      -1,   236,    -1,    13,    42,   240,    -1,    95,    40,   177,
      41,   178,   319,    -1,    95,    40,   177,    41,   178,    43,
      -1,    95,    40,   177,    41,   178,    54,   180,    43,    -1,
     322,    -1,   180,   179,    -1,    42,   180,   179,    -1,   324,
      -1,   258,   247,    -1,    40,   236,    41,    -1,    40,   236,
      41,    40,   236,    41,    -1,   113,    40,   236,    41,   172,
      -1,   100,    40,   310,    41,   315,   103,   241,   104,    43,
      -1,   102,   317,    -1,   186,    -1,   198,    -1,   197,    -1,
      -1,    44,   317,    46,   185,   145,    47,    -1,   190,    -1,
      91,   311,    54,   258,   247,    43,    -1,   118,   103,   209,
     104,    91,   311,    54,   258,   247,    43,    -1,   227,    -1,
     235,   258,   248,   302,   188,   187,    -1,   235,    87,   248,
     302,   111,   189,   299,   188,   187,    -1,    43,    -1,    42,
     248,   302,   188,   187,    -1,    46,    -1,     1,    -1,   245,
      -1,   262,    -1,    32,    -1,    30,    -1,    35,    -1,   311,
      -1,   261,    -1,   235,    87,   311,    54,   191,    40,   236,
      41,   302,   192,   193,    -1,   235,    87,   311,    54,   191,
      40,   236,    41,   302,   111,   258,   192,   193,    -1,   235,
      87,   311,    54,   191,   192,   193,    -1,    57,    -1,    46,
      -1,    43,    -1,    -1,    40,   194,    43,    -1,    70,    -1,
      70,    71,    -1,    70,    52,    -1,    76,   260,    -1,   324,
      -1,   235,   195,   270,   196,    43,    -1,   235,   195,   270,
     196,    46,   273,    47,    43,    -1,   235,   195,   270,   196,
      46,   273,    47,   248,   302,   188,   187,    -1,   235,   258,
      40,   236,    41,   303,    -1,   201,    -1,   205,    -1,   206,
      -1,   213,    -1,   214,    -1,   226,    -1,    -1,   235,   294,
     311,   285,    46,   202,   217,    47,   204,    -1,    -1,   235,
     294,   285,    46,   203,   217,    47,   204,    -1,    43,    -1,
     248,   302,   188,   187,    -1,   235,   294,   311,    43,    -1,
      -1,   118,   103,   209,   104,   207,   208,    -1,   118,   294,
     311,    -1,    44,   118,   294,   311,    -1,   186,    -1,   201,
      -1,   223,    -1,   206,    -1,   205,    -1,   225,    -1,   210,
      -1,   211,   212,    -1,   324,    -1,   293,    -1,   240,    -1,
      42,   211,   212,    -1,   324,    -1,    91,   311,    43,    -1,
      91,    92,   311,    43,    -1,    -1,    92,   311,    46,   215,
     145,    47,    -1,    -1,    92,    46,   216,   145,    47,    -1,
      92,   308,    54,   311,    43,    -1,   222,   217,    -1,    -1,
      -1,    66,    46,   218,   217,    47,   219,   217,    -1,   158,
      -1,   324,    -1,    -1,     1,   220,   217,    -1,   184,    -1,
     223,    -1,   224,    -1,   228,    -1,   229,    -1,   225,    -1,
     205,    -1,   201,    -1,   235,   311,    43,    -1,   213,    -1,
     206,    -1,   226,    -1,   182,    -1,   183,    -1,   232,    -1,
     157,    -1,   181,    -1,    43,    -1,   221,    -1,   124,   221,
      -1,   221,   125,    -1,   235,   258,    40,   236,    41,   303,
      -1,   140,   313,    40,   236,    41,   230,    -1,    78,   140,
     313,    40,   236,    41,   231,    -1,   235,   120,   258,   253,
      40,   236,    41,   231,    -1,   235,   120,   258,   131,    40,
     236,    41,   231,    -1,   235,   120,   258,   128,    40,   236,
      41,   231,    -1,   235,   120,   258,   253,   131,    40,   236,
      41,   231,    -1,   235,   120,   258,    40,   236,    41,   231,
      -1,    81,    40,   236,    41,    46,    -1,    83,    40,    -1,
      74,    76,    -1,    73,    76,    -1,    75,    76,    -1,   166,
      -1,   152,    -1,   164,    -1,   169,    -1,   171,    -1,   174,
      -1,   162,    -1,   176,    -1,   150,    -1,   151,    -1,   153,
      -1,   302,    43,    -1,   302,    54,   267,    43,    -1,   302,
      46,    -1,   302,    43,    -1,   302,    54,   265,    43,    -1,
     302,    46,    -1,   235,   233,    76,   278,    43,    -1,   262,
      -1,    32,    -1,    30,    -1,    35,    -1,   311,    -1,    44,
     317,    -1,    44,    -1,   234,    -1,   234,    85,    -1,   234,
      21,    -1,    77,    -1,    21,    -1,    78,    -1,    79,    -1,
      82,    -1,    84,    -1,    82,    84,    -1,    84,    82,    -1,
      77,    84,    -1,    84,    77,    -1,    85,    -1,    85,    77,
      -1,    77,    85,    -1,    44,    85,    -1,    85,    44,    -1,
     324,    -1,   237,    -1,   240,   238,    -1,   324,    -1,    42,
     240,   238,    -1,    42,   125,   240,   238,    -1,   324,    -1,
     259,   246,    -1,   118,   103,   294,   104,   294,   311,   245,
      -1,    48,    48,    48,    -1,   239,    -1,   124,   239,    -1,
     239,   125,    -1,   242,    -1,   244,   243,    -1,   324,    -1,
      42,   244,   243,    -1,   324,    -1,   240,    -1,   280,    -1,
      54,   265,    -1,    54,   265,    57,   278,    58,    -1,    54,
      46,    -1,    76,   278,    -1,   324,    -1,   248,   245,    -1,
     251,   245,    -1,   245,    -1,   250,    40,   236,    41,   254,
      -1,   248,    -1,   251,    -1,   250,    40,   236,    41,   254,
      -1,   324,    -1,   253,   249,    -1,   253,   131,   249,    -1,
     253,   128,   249,    -1,   250,    -1,   131,   249,    -1,   128,
     249,    -1,   311,   116,   249,    -1,   253,   311,   116,   249,
      -1,   253,   311,   116,   131,   249,    -1,   311,   116,   131,
     249,    -1,   253,    48,    48,    48,   249,    -1,   253,   131,
      48,    48,    48,   249,    -1,   253,   128,    48,    48,    48,
     249,    -1,    48,    48,    48,   250,    -1,   131,    48,    48,
      48,   249,    -1,   128,    48,    48,    48,   249,    -1,   311,
     116,    48,    48,    48,   249,    -1,   253,   311,   116,    48,
      48,    48,   249,    -1,   253,   311,   116,   131,    48,    48,
      48,   249,    -1,   253,   311,   116,   128,    48,    48,    48,
     249,    -1,   311,   116,   131,    48,    48,    48,   249,    -1,
     311,   116,   128,    48,    48,    48,   249,    -1,   311,    -1,
     140,   311,    -1,    40,   311,    41,    -1,    40,   253,   249,
      41,    -1,    40,   311,   116,   249,    41,    -1,   249,    57,
      58,    -1,   249,    57,   278,    58,    -1,   249,    40,   236,
      41,    -1,   311,    -1,   140,   311,    -1,    40,   253,   250,
      41,    -1,    40,   131,   250,    41,    -1,    40,   128,   250,
      41,    -1,    40,   311,   116,   248,    41,    -1,    40,   311,
     116,   256,   248,    41,    -1,    40,   311,   116,   251,    41,
      -1,    40,   311,   116,   256,   251,    41,    -1,   250,    57,
      58,    -1,   250,    57,   278,    58,    -1,   250,    40,   236,
      41,    -1,   119,     3,    40,   236,    41,    -1,   253,    -1,
     253,   252,    -1,   253,   131,    -1,   253,   128,    -1,   253,
     131,   252,    -1,   253,   128,   252,    -1,   252,    -1,   131,
     252,    -1,   128,   252,    -1,   131,    -1,   128,    -1,   311,
     116,    -1,   311,   116,   256,    -1,   253,   311,   116,    -1,
     253,   311,   116,   252,    -1,   252,    57,    58,    -1,   252,
      57,   278,    58,    -1,    57,    58,    -1,    57,   278,    58,
      -1,    40,   251,    41,    -1,   252,    40,   236,    41,    -1,
     252,    40,   236,    41,   254,    -1,    40,   236,    41,    -1,
     138,   256,   253,    -1,   138,   253,    -1,   138,   256,    -1,
     138,    -1,   256,    -1,   256,   255,    -1,   255,    -1,   131,
      -1,   128,    -1,   257,    -1,   257,   256,    -1,    49,    -1,
      50,    -1,    51,    -1,   259,    -1,   256,   260,    -1,   260,
      -1,   260,   256,    -1,   256,   260,   256,    -1,   262,    -1,
      32,    -1,    30,    -1,   195,   311,    -1,    35,    -1,   311,
      -1,   294,   311,    -1,   261,    -1,    86,    40,   311,    41,
      -1,   263,    -1,   264,    -1,   264,   263,    -1,    22,    -1,
      24,    -1,    25,    -1,    28,    -1,    29,    -1,    26,    -1,
      27,    -1,    31,    -1,    23,    -1,    33,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,    -1,   266,   278,    -1,
     267,    -1,   268,    -1,   269,    -1,   105,    -1,   106,    -1,
     308,    -1,   324,    -1,   152,    -1,   152,   271,    -1,   271,
      -1,   324,    -1,   274,    -1,   274,   125,    -1,   274,    42,
     273,    -1,   274,    42,   125,   273,    -1,   272,    -1,   272,
     275,   272,    -1,   276,    -1,   124,   276,    -1,   308,    -1,
     308,    54,   277,    -1,   278,    -1,   280,    -1,   258,    -1,
       3,   111,     3,    -1,   279,   111,     3,    -1,   279,    48,
       3,    -1,   281,    -1,   279,    -1,   317,    -1,    55,    40,
     258,   246,    41,    -1,    55,    48,    48,    48,    40,   258,
     246,    41,    -1,   282,    -1,   318,    -1,    11,    -1,    12,
      -1,    40,   278,    41,    -1,    40,   278,    41,   278,    -1,
      40,   278,   253,    41,   278,    -1,    40,   278,   131,    41,
     278,    -1,    40,   278,   128,    41,   278,    -1,    40,   278,
     253,   131,    41,   278,    -1,    40,   278,   253,   128,    41,
     278,    -1,   131,   278,    -1,   128,   278,    -1,   138,   278,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,   278,   135,   278,
      -1,   278,   134,   278,    -1,   278,   138,   278,    -1,   278,
     137,   278,    -1,   278,   136,   278,    -1,   278,   131,   278,
      -1,   278,   129,   278,    -1,   278,   130,   278,    -1,   278,
     133,   278,    -1,   278,   132,   278,    -1,   278,   128,   278,
      -1,   278,   127,   278,    -1,   278,   109,   278,    -1,   278,
     110,   278,    -1,   278,   108,   278,    -1,   278,   107,   278,
      -1,   278,   112,   278,    76,   278,    -1,   134,   278,    -1,
     135,   278,    -1,   140,   278,    -1,   139,   278,    -1,   258,
      40,    -1,    48,    48,    48,    -1,   283,    -1,   324,    -1,
     286,    -1,    -1,    76,   287,   288,    -1,   324,    -1,   289,
      -1,   288,    42,   289,    -1,    -1,   297,   290,   311,   284,
      -1,    -1,   297,   292,   291,   297,   311,   284,    -1,    74,
      -1,    73,    -1,    75,    -1,    71,    -1,    72,    -1,    71,
      48,    48,    48,    -1,    72,    48,    48,    48,    -1,   293,
      -1,    52,    -1,    53,    -1,    71,    -1,    52,    -1,    53,
      -1,   295,    -1,   324,    -1,    78,    -1,   324,    -1,    89,
      -1,    90,    -1,    90,    89,    -1,    89,    90,    -1,   298,
      -1,   324,    -1,    80,    40,   236,    41,    -1,    88,    -1,
     298,    -1,    80,    40,   236,    41,   298,    -1,    88,   298,
      -1,    88,    40,   278,    41,    -1,   254,    -1,   300,    -1,
     254,   300,    -1,   301,    -1,   324,    -1,   302,   304,    43,
      -1,   302,   304,    46,    -1,    40,   236,    41,    43,    -1,
      40,   236,    41,    46,    -1,    54,   265,    43,    -1,   300,
      54,   267,    43,    -1,    76,   305,    -1,   324,    -1,   306,
      -1,   305,    42,   306,    -1,   306,    48,    48,    48,    -1,
     305,    42,   306,    48,    48,    48,    -1,   311,    40,    -1,
     311,    46,    -1,   103,   241,   104,    -1,     3,    -1,    89,
      -1,    90,    -1,   308,    -1,   267,    -1,   317,    -1,   309,
      -1,   324,    -1,   313,   312,    -1,   115,   142,   314,   312,
      -1,   313,    -1,   115,   142,   314,    -1,   119,    -1,   119,
     307,    -1,   115,   142,   119,    -1,   142,   314,   312,    -1,
     142,   314,    -1,   142,   119,    -1,   117,   313,    -1,   308,
      -1,   308,   307,    -1,   313,    -1,   118,   308,   307,    -1,
     308,   316,    -1,   115,   142,   308,   316,    -1,   308,    -1,
     115,   142,   308,    -1,   119,    -1,   115,   142,   119,    -1,
     142,   308,   316,    -1,   142,   308,    -1,   142,   119,    -1,
     117,   308,    -1,   317,     6,    -1,     6,    -1,   318,     7,
      -1,     7,    -1,   317,    -1,    46,    -1,     4,    -1,    40,
     322,    41,    -1,   324,    -1,    42,   322,    -1,   324,    -1,
     309,    54,   323,    -1,   309,    54,   323,    42,   322,    -1,
     309,    -1,   309,    42,   322,    -1,   309,    54,   155,    -1,
     309,    54,   155,    42,   322,    -1,   317,    -1,   281,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1713,  1713,  1725,  1729,  1732,  1735,  1738,  1741,  1746,
    1755,  1759,  1766,  1771,  1772,  1773,  1774,  1775,  1785,  1801,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1838,  1838,  1920,  1930,  1941,  1961,  1985,  2009,  2020,
    2029,  2048,  2054,  2060,  2065,  2072,  2079,  2083,  2096,  2105,
    2120,  2133,  2133,  2189,  2190,  2197,  2216,  2247,  2251,  2262,
    2268,  2287,  2330,  2336,  2349,  2355,  2381,  2387,  2394,  2395,
    2398,  2399,  2406,  2452,  2498,  2509,  2512,  2539,  2545,  2551,
    2557,  2565,  2571,  2577,  2583,  2591,  2592,  2593,  2596,  2601,
    2611,  2647,  2648,  2683,  2700,  2708,  2721,  2746,  2752,  2756,
    2759,  2770,  2775,  2788,  2800,  3098,  3108,  3115,  3116,  3120,
    3120,  3145,  3151,  3161,  3173,  3182,  3262,  3325,  3329,  3354,
    3358,  3369,  3374,  3375,  3376,  3380,  3381,  3382,  3393,  3398,
    3403,  3410,  3416,  3421,  3424,  3424,  3437,  3440,  3443,  3452,
    3455,  3462,  3484,  3513,  3611,  3664,  3665,  3666,  3667,  3668,
    3669,  3674,  3674,  3923,  3923,  4070,  4071,  4083,  4101,  4101,
    4362,  4368,  4374,  4377,  4380,  4383,  4386,  4389,  4394,  4430,
    4434,  4437,  4440,  4445,  4449,  4454,  4464,  4495,  4495,  4553,
    4553,  4575,  4602,  4619,  4624,  4619,  4632,  4633,  4634,  4634,
    4650,  4651,  4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,
    4676,  4677,  4678,  4679,  4680,  4681,  4682,  4683,  4685,  4688,
    4692,  4704,  4733,  4763,  4796,  4812,  4830,  4849,  4869,  4889,
    4897,  4904,  4911,  4919,  4927,  4930,  4934,  4937,  4938,  4939,
    4940,  4941,  4942,  4943,  4944,  4947,  4958,  4969,  4982,  4993,
    5004,  5018,  5021,  5024,  5025,  5029,  5031,  5039,  5051,  5052,
    5053,  5054,  5055,  5056,  5057,  5058,  5059,  5060,  5061,  5062,
    5063,  5064,  5065,  5066,  5067,  5068,  5069,  5070,  5077,  5088,
    5092,  5099,  5103,  5108,  5112,  5124,  5134,  5144,  5147,  5151,
    5157,  5170,  5174,  5177,  5181,  5185,  5213,  5221,  5234,  5250,
    5261,  5271,  5283,  5287,  5291,  5298,  5320,  5337,  5356,  5375,
    5382,  5390,  5399,  5408,  5412,  5421,  5432,  5443,  5455,  5465,
    5479,  5487,  5496,  5505,  5509,  5518,  5529,  5540,  5552,  5562,
    5572,  5583,  5596,  5603,  5611,  5627,  5635,  5646,  5657,  5668,
    5687,  5695,  5712,  5720,  5727,  5734,  5745,  5757,  5768,  5780,
    5791,  5802,  5822,  5843,  5849,  5855,  5862,  5869,  5878,  5887,
    5890,  5899,  5908,  5915,  5922,  5929,  5937,  5947,  5958,  5969,
    5980,  5987,  5994,  5997,  6014,  6032,  6042,  6049,  6055,  6060,
    6067,  6071,  6076,  6083,  6087,  6093,  6097,  6103,  6104,  6105,
    6111,  6117,  6121,  6122,  6126,  6133,  6136,  6137,  6141,  6142,
    6144,  6147,  6150,  6155,  6166,  6191,  6194,  6248,  6252,  6256,
    6260,  6264,  6268,  6272,  6276,  6280,  6284,  6288,  6292,  6296,
    6300,  6306,  6306,  6322,  6327,  6330,  6336,  6351,  6367,  6368,
    6371,  6372,  6376,  6377,  6381,  6385,  6390,  6398,  6407,  6412,
    6417,  6420,  6426,  6434,  6446,  6461,  6462,  6482,  6486,  6496,
    6502,  6505,  6508,  6512,  6517,  6522,  6523,  6528,  6542,  6558,
    6568,  6586,  6593,  6600,  6607,  6615,  6623,  6627,  6631,  6637,
    6638,  6639,  6640,  6641,  6642,  6643,  6644,  6647,  6651,  6655,
    6659,  6663,  6667,  6671,  6675,  6679,  6683,  6687,  6691,  6695,
    6699,  6713,  6717,  6721,  6727,  6731,  6735,  6739,  6743,  6759,
    6764,  6767,  6772,  6777,  6777,  6778,  6781,  6798,  6807,  6807,
    6825,  6825,  6843,  6844,  6845,  6848,  6852,  6856,  6860,  6866,
    6869,  6873,  6879,  6883,  6887,  6893,  6896,  6901,  6902,  6905,
    6908,  6911,  6914,  6919,  6922,  6927,  6933,  6939,  6945,  6951,
    6957,  6965,  6973,  6978,  6985,  6988,  6998,  7009,  7020,  7030,
    7040,  7048,  7060,  7061,  7064,  7065,  7066,  7067,  7070,  7082,
    7088,  7097,  7098,  7099,  7102,  7103,  7104,  7107,  7108,  7111,
    7116,  7120,  7123,  7126,  7129,  7132,  7137,  7141,  7144,  7151,
    7157,  7160,  7165,  7168,  7174,  7179,  7183,  7186,  7189,  7192,
    7197,  7201,  7204,  7207,  7213,  7216,  7219,  7227,  7230,  7233,
    7237,  7242,  7255,  7257,  7270,  7274,  7279,  7285,  7289,  7294,
    7298,  7305,  7308,  7313
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "HBLOCK", "POUND", "STRING",
  "WSTRING", "INCLUDE", "IMPORT", "INSERT", "CHARCONST", "WCHARCONST",
  "NUM_INT", "NUM_FLOAT", "NUM_UNSIGNED", "NUM_LONG", "NUM_ULONG",
  "NUM_LONGLONG", "NUM_ULONGLONG", "NUM_BOOL", "TYPEDEF", "TYPE_INT",
  "TYPE_UNSIGNED", "TYPE_SHORT", "TYPE_LONG", "TYPE_FLOAT", "TYPE_DOUBLE",
  "TYPE_CHAR", "TYPE_WCHAR", "TYPE_VOID", "TYPE_SIGNED", "TYPE_BOOL",
  "TYPE_COMPLEX", "TYPE_TYPEDEF", "TYPE_RAW", "TYPE_NON_ISO_INT8",
  "TYPE_NON_ISO_INT16", "TYPE_NON_ISO_INT32", "TYPE_NON_ISO_INT64",
  "LPAREN", "RPAREN", "COMMA", "SEMI", "EXTERN", "INIT", "LBRACE",
  "RBRACE", "PERIOD", "CONST_QUAL", "VOLATILE", "REGISTER", "STRUCT",
  "UNION", "EQUAL", "SIZEOF", "MODULE", "LBRACKET", "RBRACKET",
  "BEGINFILE", "ENDOFFILE", "ILLEGAL", "CONSTANT", "NAME", "RENAME",
  "NAMEWARN", "EXTEND", "PRAGMA", "FEATURE", "VARARGS", "ENUM", "CLASS",
  "TYPENAME", "PRIVATE", "PUBLIC", "PROTECTED", "COLON", "STATIC",
  "VIRTUAL", "FRIEND", "THROW", "CATCH", "EXPLICIT", "STATIC_ASSERT",
  "CONSTEXPR", "THREAD_LOCAL", "DECLTYPE", "AUTO", "NOEXCEPT", "OVERRIDE",
  "FINAL", "USING", "NAMESPACE", "NATIVE", "INLINE", "TYPEMAP", "EXCEPT",
  "ECHO", "APPLY", "CLEAR", "SWIGTEMPLATE", "FRAGMENT", "WARN", "LESSTHAN",
  "GREATERTHAN", "DELETE_KW", "DEFAULT", "LESSTHANOREQUALTO",
  "GREATERTHANOREQUALTO", "EQUALTO", "NOTEQUALTO", "ARROW", "QUESTIONMARK",
  "TYPES", "PARMS", "NONID", "DSTAR", "DCNOT", "TEMPLATE", "OPERATOR",
  "CONVERSIONOPERATOR", "PARSETYPE", "PARSEPARM", "PARSEPARMS",
  "DOXYGENSTRING", "DOXYGENPOSTSTRING", "CAST", "LOR", "LAND", "OR", "XOR",
  "AND", "RSHIFT", "LSHIFT", "MINUS", "PLUS", "MODULO", "SLASH", "STAR",
  "LNOT", "NOT", "UMINUS", "DCOLON", "$accept", "program", "interface",
  "declaration", "swig_directive", "extend_directive", "@1",
  "apply_directive", "clear_directive", "constant_directive",
  "echo_directive", "except_directive", "stringtype", "fname",
  "fragment_directive", "include_directive", "@2", "includetype",
  "inline_directive", "insert_directive", "module_directive",
  "name_directive", "native_directive", "pragma_directive", "pragma_arg",
  "pragma_lang", "rename_directive", "rename_namewarn",
  "feature_directive", "stringbracesemi", "featattr", "varargs_directive",
  "varargs_parms", "typemap_directive", "typemap_type", "tm_list",
  "tm_tail", "typemap_parm", "types_directive", "template_directive",
  "warn_directive", "c_declaration", "@3", "c_decl", "c_decl_tail",
  "initializer", "cpp_alternate_rettype", "cpp_lambda_decl",
  "lambda_introducer", "lambda_body", "lambda_tail", "@4", "c_enum_key",
  "c_enum_inherit", "c_enum_forward_decl", "c_enum_decl",
  "c_constructor_decl", "cpp_declaration", "cpp_class_decl", "@5", "@6",
  "cpp_opt_declarators", "cpp_forward_class_decl", "cpp_template_decl",
  "@7", "cpp_template_possible", "template_parms", "templateparameters",
  "templateparameter", "templateparameterstail", "cpp_using_decl",
  "cpp_namespace_decl", "@8", "@9", "cpp_members", "@10", "@11", "@12",
  "cpp_member_no_dox", "cpp_member", "cpp_constructor_decl",
  "cpp_destructor_decl", "cpp_conversion_operator", "cpp_catch_decl",
  "cpp_static_assert", "cpp_protection_decl", "cpp_swig_directive",
  "cpp_end", "cpp_vend", "anonymous_bitfield", "anon_bitfield_type",
  "extern_string", "storage_class", "parms", "rawparms", "ptail",
  "parm_no_dox", "parm", "valparms", "rawvalparms", "valptail", "valparm",
  "def_args", "parameter_declarator", "plain_declarator", "declarator",
  "notso_direct_declarator", "direct_declarator", "abstract_declarator",
  "direct_abstract_declarator", "pointer", "cv_ref_qualifier",
  "ref_qualifier", "type_qualifier", "type_qualifier_raw", "type",
  "rawtype", "type_right", "decltype", "primitive_type",
  "primitive_type_list", "type_specifier", "definetype", "@13",
  "default_delete", "deleted_definition", "explicit_default", "ename",
  "constant_directives", "optional_ignored_defines", "enumlist",
  "enumlist_item", "edecl_with_dox", "edecl", "etype", "expr", "exprmem",
  "valexpr", "exprnum", "exprcompound", "ellipsis", "variadic", "inherit",
  "raw_inherit", "@14", "base_list", "base_specifier", "@15", "@16",
  "access_specifier", "templcpptype", "cpptype", "classkey", "classkeyopt",
  "opt_virtual", "virt_specifier_seq", "virt_specifier_seq_opt",
  "exception_specification", "qualifiers_exception_specification",
  "cpp_const", "ctor_end", "ctor_initializer", "mem_initializer_list",
  "mem_initializer", "less_valparms_greater", "identifier", "idstring",
  "idstringopt", "idcolon", "idcolontail", "idtemplate",
  "idtemplatetemplate", "idcolonnt", "idcolontailnt", "string", "wstring",
  "stringbrace", "options", "options_ex", "kwargs", "stringnum", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   143,   144,   144,   144,   144,   144,   144,   144,   145,
     145,   145,   145,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   149,   148,   150,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   154,   154,   155,   156,   156,   157,   157,
     157,   159,   158,   160,   160,   161,   161,   162,   162,   162,
     162,   163,   164,   164,   165,   165,   166,   166,   167,   167,
     168,   168,   169,   169,   169,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   172,   172,   173,   173,
     174,   175,   175,   176,   176,   176,   177,   178,   179,   179,
     180,   180,   180,   181,   182,   183,   184,   184,   184,   185,
     184,   184,   184,   184,   184,   186,   186,   187,   187,   187,
     187,   188,   189,   189,   189,   189,   189,   189,   190,   190,
     190,   191,   192,   193,   194,   193,   195,   195,   195,   196,
     196,   197,   198,   198,   199,   200,   200,   200,   200,   200,
     200,   202,   201,   203,   201,   204,   204,   205,   207,   206,
     206,   206,   208,   208,   208,   208,   208,   208,   209,   210,
     210,   211,   211,   212,   212,   213,   213,   215,   214,   216,
     214,   214,   217,   218,   219,   217,   217,   217,   220,   217,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   222,   222,
     222,   223,   224,   224,   225,   225,   225,   225,   225,   226,
     227,   228,   228,   228,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   230,   230,   230,   231,   231,
     231,   232,   233,   233,   233,   233,   233,   234,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   237,
     237,   238,   238,   238,   239,   239,   239,   240,   240,   240,
     241,   242,   242,   243,   243,   244,   244,   245,   245,   245,
     245,   245,   246,   246,   246,   246,   247,   247,   247,   247,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   249,   249,   249,   249,   249,   249,   249,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     252,   252,   252,   252,   252,   252,   253,   253,   253,   253,
     254,   254,   254,   255,   255,   256,   256,   257,   257,   257,
     258,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   262,   263,   263,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   266,   265,   265,   267,   267,   268,   269,   270,   270,
     271,   271,   272,   272,   273,   273,   273,   273,   273,   274,
     275,   275,   276,   276,   277,   278,   278,   279,   279,   279,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     284,   284,   285,   287,   286,   286,   288,   288,   290,   289,
     291,   289,   292,   292,   292,   293,   293,   293,   293,   294,
     294,   294,   295,   295,   295,   296,   296,   297,   297,   298,
     298,   298,   298,   299,   299,   300,   300,   300,   300,   300,
     300,   301,   301,   301,   302,   302,   303,   303,   303,   303,
     303,   303,   304,   304,   305,   305,   305,   305,   306,   306,
     307,   308,   308,   308,   309,   309,   309,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   312,   312,
     313,   313,   314,   314,   315,   315,   315,   315,   315,   315,
     316,   316,   316,   316,   317,   317,   318,   318,   319,   319,
     319,   320,   320,   321,   321,   322,   322,   322,   322,   322,
     322,   323,   323,   324
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     3,     2,     5,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     8,     5,     3,     5,     5,     9,     3,     2,
       2,     5,     2,     5,     2,     4,     1,     1,     7,     7,
       5,     0,     7,     1,     1,     2,     2,     1,     6,     6,
       6,     3,     4,     3,     7,     8,     5,     3,     1,     1,
       3,     1,     4,     7,     6,     1,     1,     7,     9,     8,
      10,     5,     7,     6,     8,     1,     1,     5,     4,     5,
       7,     1,     3,     6,     6,     8,     1,     2,     3,     1,
       2,     3,     6,     5,     9,     2,     1,     1,     1,     0,
       6,     1,     6,    10,     1,     6,     9,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    11,    13,
       7,     1,     1,     1,     0,     3,     1,     2,     2,     2,
       1,     5,     8,    11,     6,     1,     1,     1,     1,     1,
       1,     0,     9,     0,     8,     1,     4,     4,     0,     6,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     3,     1,     3,     4,     0,     6,     0,
       5,     5,     2,     0,     0,     7,     1,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     6,     6,     7,     8,     8,     8,     9,     7,     5,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     2,     4,
       2,     5,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     1,     2,
       1,     3,     4,     1,     2,     7,     3,     1,     2,     2,
       1,     2,     1,     3,     1,     1,     1,     2,     5,     2,
       2,     1,     2,     2,     1,     5,     1,     1,     5,     1,
       2,     3,     3,     1,     2,     2,     3,     4,     5,     4,
       5,     6,     6,     4,     5,     5,     6,     7,     8,     8,
       7,     7,     1,     2,     3,     4,     5,     3,     4,     4,
       1,     2,     4,     4,     4,     5,     6,     5,     6,     3,
       4,     4,     5,     1,     2,     2,     2,     3,     3,     1,
       2,     2,     1,     1,     2,     3,     3,     4,     3,     4,
       2,     3,     3,     4,     5,     3,     3,     2,     2,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     2,     1,
       1,     2,     1,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     3,     4,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     5,     8,     1,     1,     1,     1,     3,
       4,     5,     5,     5,     6,     6,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     2,     2,     2,     2,     2,     3,
       1,     1,     1,     0,     3,     1,     1,     3,     0,     4,
       0,     6,     1,     1,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     4,     1,     1,     5,     2,
       4,     1,     1,     2,     1,     1,     3,     3,     4,     4,
       3,     4,     2,     1,     1,     3,     4,     6,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     1,     2,     3,     3,     2,     2,     2,
       1,     2,     1,     3,     2,     4,     1,     3,     1,     3,
       3,     2,     2,     2,     2,     1,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     3,     5,     1,     3,     3,
       5,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     613,     0,     0,     0,     0,     0,    12,     4,   561,   407,
     415,   408,   409,   412,   413,   410,   411,   397,   414,   396,
     416,   399,   417,   418,   419,   420,     0,   387,   388,   389,
     520,   521,   146,   515,   516,     0,   562,   563,     0,     0,
     573,     0,     0,   287,     0,     0,   385,   613,   392,   402,
     395,   404,   405,   519,     0,   580,   400,   571,     6,     0,
       0,   613,     1,    17,    67,    63,    64,     0,   263,    16,
     258,   613,     0,     0,    85,    86,   613,   613,     0,     0,
     262,   264,   265,     0,   266,     0,   267,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     9,    13,    20,    21,    22,    23,
      24,    25,    26,    27,   613,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    14,
     116,   121,   118,   117,    18,    15,   155,   156,   157,   158,
     159,   160,   124,   259,     0,   277,     0,   148,   147,     0,
       0,     0,     0,     0,   613,   574,   288,   398,   289,     3,
     391,   386,   613,     0,   421,     0,     0,   573,   363,   362,
     379,     0,   304,   284,   613,   313,   613,   359,   353,   340,
     301,   393,   406,   401,   581,     0,     0,   569,     5,     8,
       0,   278,   613,   280,    19,     0,   595,   275,     0,   257,
       0,     0,   602,     0,     0,   390,   580,     0,   613,     0,
       0,    81,     0,   613,   270,   274,   613,   268,   230,   271,
     269,   276,   273,     0,     0,   189,   580,     0,     0,    65,
      66,     0,     0,    54,    52,    49,    50,   613,     0,   613,
       0,   613,   613,     0,   115,   613,   613,     0,     0,     0,
       0,     0,     0,   313,     0,   340,   261,   260,     0,   613,
       0,   613,   286,     0,     0,     0,     0,   575,   582,   572,
       0,   561,   597,   457,   458,   469,   470,   471,   472,   473,
     474,   475,   476,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,   290,   613,   446,   390,     0,   451,
     445,   450,   455,   452,   456,   292,   394,   613,   363,   362,
       0,     0,   353,   400,     0,   299,   426,   427,   297,     0,
     423,   424,   425,   370,     0,   445,   300,     0,   613,     0,
       0,   315,   361,   332,     0,   314,   360,   377,   378,   341,
     302,   613,     0,   303,   613,     0,     0,   356,   355,   310,
     354,   332,   364,   579,   578,   577,     0,     0,   279,   283,
     565,   564,   613,   566,     0,   594,   119,   607,     0,    71,
      48,     0,   613,   313,   421,    73,     0,   523,   524,   522,
     525,     0,   526,     0,    77,     0,     0,     0,   101,     0,
       0,   185,     0,   613,     0,   187,     0,     0,   106,     0,
       0,     0,   110,   306,   313,   307,   309,    44,     0,   107,
     109,   567,     0,   568,    57,     0,    56,     0,     0,   178,
     613,   182,   519,   180,   170,     0,     0,     0,     0,   564,
       0,     0,     0,     0,   613,     0,     0,   332,     0,   613,
     340,   613,   580,   429,   613,   613,   503,     0,   502,   401,
     505,   517,   518,   403,     0,   570,     0,     0,     0,     0,
       0,   467,   466,   494,   495,   468,   497,   496,   560,     0,
     291,   294,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   363,   362,   353,   400,     0,   340,     0,
     375,   372,   356,   355,     0,   340,   364,     0,     0,   422,
     371,   613,   353,   400,     0,   333,   613,     0,     0,   376,
       0,   349,     0,     0,   368,     0,     0,     0,   312,   358,
       0,   311,   357,   366,     0,     0,     0,   316,   365,   576,
       7,     0,   613,     0,     0,   604,   171,   613,     0,     0,
     601,     0,   613,     0,    72,     0,    80,     0,     0,     0,
       0,     0,     0,     0,   186,   613,     0,     0,   613,   613,
       0,     0,   111,     0,   613,   613,     0,     0,     0,     0,
       0,   168,     0,   179,   184,    61,     0,     0,     0,     0,
      82,     0,     0,     0,   536,   529,   530,   384,   383,   541,
     382,   380,   537,   542,   544,     0,   545,     0,     0,     0,
     150,     0,   400,   613,   613,   163,   167,     0,   583,     0,
     447,   459,     0,     0,   379,     0,   613,     0,   613,   492,
     491,   489,   490,     0,   488,   487,   483,   484,   482,   486,
     485,   478,   477,   481,   480,   479,   449,   448,     0,   364,
     344,   343,   342,   366,     0,     0,   365,   323,     0,     0,
       0,   332,   334,   364,     0,     0,   337,     0,     0,   351,
     350,   373,   369,     0,     0,     0,     0,     0,     0,   317,
     367,     0,     0,     0,   319,   613,   281,   603,     0,     0,
     608,   609,   612,   611,   605,    46,     0,    45,    41,    79,
      76,    78,   600,    96,   599,     0,    91,   613,   598,    95,
       0,   611,     0,     0,   102,   613,   229,     0,   190,   191,
       0,   258,     0,     0,    53,    51,   613,    43,     0,   108,
       0,   588,   586,     0,    60,     0,     0,   113,     0,   613,
     613,   613,     0,   613,     0,     0,   351,   613,     0,   539,
     532,   531,   543,   381,     0,   141,     0,   149,   151,   613,
     613,     0,   131,   527,   504,   506,   508,   528,     0,   161,
     613,   460,     0,     0,   379,   378,     0,     0,     0,     0,
       0,   293,     0,   345,   347,     0,     0,   298,   352,   335,
       0,   325,   339,   338,   324,   305,   374,   320,     0,     0,
       0,     0,     0,   318,     0,     0,     0,   282,    69,    70,
      68,   120,     0,     0,   351,     0,   613,     0,     0,     0,
       0,     0,    93,   613,     0,   122,   188,   257,     0,   580,
     104,     0,   103,     0,   351,     0,     0,     0,   584,   613,
       0,    55,     0,   258,     0,   172,   173,   176,   175,   169,
     174,   177,     0,   183,     0,     0,    84,     0,     0,   134,
     133,   135,   613,   137,   132,   136,   613,   142,     0,   430,
     432,   438,     0,   434,   433,   613,   421,   542,   613,   154,
     130,     0,   127,   129,   125,   613,   513,   512,   514,     0,
     510,   198,   217,     0,     0,     0,     0,   264,   613,     0,
     242,   243,   235,   244,   215,   196,   240,   236,   234,   237,
     238,   239,   241,   216,   212,   213,   200,   207,   206,   210,
     209,     0,   218,     0,   201,   202,   205,   211,   203,   204,
     214,     0,   277,     0,   285,   463,   462,   461,     0,     0,
     453,     0,   493,   346,   348,   336,   322,   321,     0,     0,
       0,   326,     0,     0,   610,   606,   613,     0,     0,    87,
     611,    98,    92,   613,     0,     0,   100,     0,    74,     0,
     112,   308,   589,   587,   593,   592,   591,     0,    58,    59,
       0,   613,     0,     0,     0,    62,    83,   535,   540,   533,
     613,   534,     0,   144,   143,   140,   431,     0,   613,   440,
     442,     0,   613,   435,     0,     0,     0,     0,     0,   553,
     613,   507,   613,   613,     0,   193,   232,   231,   233,     0,
     219,     0,     0,   220,   192,   397,   396,   399,     0,   395,
     400,     0,   465,   464,   613,   327,     0,     0,   331,   330,
       0,    42,     0,    99,     0,    94,   613,    89,    75,   105,
     585,   590,     0,   613,     0,     0,   613,   538,     0,   613,
       0,   441,   439,     0,   152,   613,   613,   436,     0,   550,
       0,   552,   554,     0,   546,   547,   613,     0,   500,   509,
     501,     0,   199,     0,     0,   613,   165,   164,   613,     0,
     208,     0,     0,   329,   328,    47,    97,    88,     0,   114,
       0,   168,   613,     0,     0,     0,     0,   126,     0,   145,
     443,   444,   613,   437,   548,   549,   551,     0,     0,   558,
     559,     0,     0,   613,     0,   613,     0,   613,     0,   162,
     454,    90,   123,     0,   613,   613,   613,     0,   613,     0,
       0,     0,   555,     0,   128,   499,   511,   194,     0,   613,
       0,   251,   613,     0,     0,     0,   613,   221,     0,   138,
     153,     0,   556,     0,   613,   222,     0,   166,   228,     0,
     613,   613,   613,     0,     0,     0,   195,   223,   245,   247,
       0,   248,   250,   421,   226,   225,   224,   613,   139,   557,
       0,     0,   227,   246,   249
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,   104,   105,   106,   815,   900,   901,   902,
     903,   111,   414,   415,   904,   905,   741,   114,   115,   906,
     117,   907,   119,   908,   700,   210,   909,   122,   910,   706,
     560,   911,   387,   912,   397,   240,   409,   241,   913,   914,
     915,   916,   547,   130,   884,   761,   862,   131,   756,   868,
     995,  1060,    42,   609,   132,   133,   134,   135,   917,   933,
     768,  1087,   918,   919,   739,   849,   418,   419,   420,   583,
     920,   140,   568,   393,   921,  1083,  1163,  1014,   922,   923,
     924,   925,   926,   927,   142,   928,   929,  1165,  1168,   930,
    1028,   143,   931,   310,   191,   358,    43,   192,   293,   294,
     470,   295,   762,   173,   402,   174,   331,   253,   176,   177,
     254,   599,   600,    45,    46,   296,   205,    48,    49,    50,
      51,    52,   318,   319,   360,   321,   322,   441,   870,   871,
     872,   873,   998,   999,  1110,   298,   299,   325,   301,   302,
    1078,  1079,   447,   448,   614,   764,   765,   889,  1013,   890,
      53,    54,   380,   381,   766,   602,   990,   603,   604,  1169,
     879,  1008,  1071,  1072,   184,    55,   367,   412,    56,   187,
      57,   269,   733,   838,   303,   304,   709,   201,   544,   368,
     694,   193
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1036
static const yytype_int16 yypact[] =
{
     607,  4470,  4573,   263,   108,  3914, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,    70, -1036, -1036, -1036,
   -1036, -1036,    38,   205,   225,   300, -1036, -1036,   219,   244,
     375,  5202,   394,   355,   412,  5485,   735,  1755,   735, -1036,
   -1036, -1036,  3007, -1036,   394,   375, -1036,   236, -1036,   445,
     464,  4883, -1036,   396, -1036, -1036, -1036,   486, -1036, -1036,
      40,   496,  4986,   515, -1036, -1036,   496,   550,   557,   564,
     418, -1036, -1036,   582,   543,   598,   297,    39,   240,   380,
     600,   189,   611,   662,   201,  5273,  5273,   616,   618,   626,
     632,   343, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   496, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,  1624, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,    28,  5344, -1036,   599, -1036, -1036,   629,
     631,   394,   226,   592,  2272, -1036, -1036, -1036, -1036, -1036,
     735, -1036,  3506,   636,   202,  2402,  3182,    47,   235,   439,
     139,   394, -1036, -1036,   281,   327,   281,   330,  1941,   572,
   -1036, -1036, -1036, -1036, -1036,    72,   511, -1036, -1036, -1036,
     659, -1036,   668, -1036, -1036,   946, -1036, -1036,   592,   214,
     946,   946, -1036,   671,  1951, -1036,   128,  1003,   411,    72,
      72, -1036,   946,  4780, -1036, -1036,  4883, -1036, -1036, -1036,
   -1036, -1036, -1036,   394,    56, -1036,   169,   673,    72, -1036,
   -1036,   946,    72, -1036, -1036, -1036,   717,  4883,   679,  1381,
     690,   693,   946,   626,   717,  4883,  4883,   394,   626,  2244,
     408,   571,   946,   350,  1480,   620, -1036, -1036,  1951,   394,
    2486,   491, -1036,   707,   710,   697,    72, -1036, -1036,   236,
     669,   663, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,  3182,   352,  3182,  3182,  3182,  3182,  3182,
    3182,  3182, -1036,   676, -1036,   752,   762,   109,  2630,    49,
      26, -1036, -1036,   717,   809, -1036, -1036,  3623,    54,    54,
     776,   778,   346,   709,   779, -1036, -1036, -1036,   769,  3182,
   -1036, -1036, -1036, -1036,  4417, -1036,  2630,   789,  3623,   782,
     394,   387,   330, -1036,   790,   387,   330, -1036,   703, -1036,
   -1036,  4883,  2532, -1036,  4883,  2662,   799,   886,  1039,   387,
     330,   733,   888, -1036, -1036,   236,   807,  4676, -1036, -1036,
   -1036, -1036,   814,   717,   394, -1036, -1036,   292,   810, -1036,
   -1036,   979,   281,   390,   480, -1036,   817, -1036, -1036, -1036,
   -1036,   394, -1036,   822,   811,   633,   826,   823, -1036,   829,
     830, -1036,  5415, -1036,   394, -1036,   831,   834, -1036,   836,
     838,  5273, -1036, -1036,   481, -1036, -1036, -1036,  5273, -1036,
   -1036, -1036,   840, -1036, -1036,   651,   220,   841,   780, -1036,
     846, -1036,    61, -1036, -1036,   173,   161,   161,   161,   552,
     767,   849,   222,   850,  4883,  1211,  1671,   784,  2746,  1214,
     146,   816,   187, -1036,  3740,  1214, -1036,   848, -1036,   242,
   -1036, -1036, -1036, -1036,   375, -1036,   592,   899,  3473,  5415,
     856,  3018,  3141, -1036, -1036, -1036, -1036, -1036, -1036,  2272,
   -1036, -1036, -1036,  3182,  3182,  3182,  3182,  3182,  3182,  3182,
    3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,
     903,   907, -1036,   531,   531,  1222,   795,   383, -1036,   449,
   -1036, -1036,   531,   531,   504,   797,   403,   161,  3182,  2630,
   -1036,  4883,  1102,    18,   866, -1036,  4883,  2792,   872, -1036,
     881, -1036,  4727,   890, -1036,  4830,   884,   887,   387,   330,
     892,   387,   330,  3330,   896,   897,  1848,   387, -1036, -1036,
   -1036,  4883,   668,   946,   909, -1036, -1036, -1036,   946,  2351,
   -1036,   905,  4883,   908, -1036,   915, -1036,   462,  1677,  2490,
     912,  4883,  1951,   921, -1036,  1381,  4027,   926, -1036,   880,
    5273,   376,   932,   927,  4883,   693,   488,   930,   946,  4883,
      83,   889,  4883, -1036, -1036, -1036,   403,  1178,   806,    23,
   -1036,   938,  2876,   943,   179,   894,   902, -1036, -1036,   528,
   -1036,   -27, -1036, -1036, -1036,   874, -1036,   929,  5485,   416,
   -1036,   947,   767,   281,   916, -1036, -1036,   951, -1036,   394,
   -1036,  3182,  2922,  3052,  3312,    14,  1755,   956,   752,  1398,
    1398,  1594,  1594,  2501,  2889,  3018,  3027,  1239,  3141,   895,
     895,   661,   661, -1036, -1036, -1036, -1036, -1036,   797,   735,
   -1036, -1036, -1036,   531,   958,   967,  1381,   350,  5362,   970,
     555,   797, -1036,   249,   806,   974, -1036,  5478,   806,   422,
   -1036,   422, -1036,   806,   975,   976,   977,   989,  1987,   387,
     330,   990,   992,   993,   387,   668, -1036, -1036,   404,  4140,
   -1036,   985, -1036,   220,  1001, -1036,  1006, -1036, -1036, -1036,
   -1036,   717, -1036, -1036, -1036,   978, -1036,  1214,   717, -1036,
    1000,   121,   675,  1677, -1036,  1214, -1036,  1017, -1036, -1036,
    4253,    82,  5415,   359, -1036, -1036,  4883, -1036,  1020, -1036,
     920, -1036,   239,   960, -1036,  1029,  1024, -1036,   394,  1837,
     846, -1036,  1381,  1214,   288,   806, -1036,  4883,  3182, -1036,
   -1036, -1036, -1036, -1036,  4645, -1036,   280, -1036, -1036,  1013,
    2396,   591, -1036, -1036,  1035, -1036,   737, -1036,  2142, -1036,
     281,  2630,  3182,  3182,  3312,  3810,  3182,  1041,  1043,  1045,
    1040, -1036,  3182, -1036, -1036,  1048,  1050, -1036, -1036, -1036,
     608,   387, -1036, -1036,   387, -1036, -1036,   387,   806,   806,
    1054,  1055,  1056,   387,   806,  1058,  1063, -1036, -1036, -1036,
     717, -1036,   946,   946,   422,  2142,  4883,    83,  2351,  1387,
     946,  1072, -1036,  1214,  1071, -1036, -1036,   717,  1951,    53,
   -1036,  5273, -1036,  1074,   422,   233,    72,   339, -1036,  2272,
     275, -1036,  1062,    40,   448, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,  5057, -1036,  4366,  1075, -1036,  1081,  3590, -1036,
   -1036, -1036,   614, -1036, -1036, -1036,  4883, -1036,   492,  1013,
   -1036,    97,  1077,    16, -1036,  4883,   480,  1076,  1049, -1036,
   -1036,  1951, -1036, -1036, -1036,   916, -1036, -1036, -1036,   394,
   -1036, -1036, -1036,  1086,  1059,  1060,  1065,   994,  3400,    72,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  1099,  1022,  2142, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  5129,  1101,  2142, -1036,  2630,  2630,  2630,  3182,  3182,
   -1036,  5415,  2760, -1036, -1036, -1036,   387,   387,   806,  1103,
    1107,   387,   806,   806, -1036, -1036,   281,  1109,  1116, -1036,
     717,  1118, -1036,  1214,  1821,    83, -1036,  1122, -1036,  1124,
   -1036, -1036, -1036,   239, -1036, -1036,   239,  1064, -1036, -1036,
    5415,  4883,  1951,  5415,  2616, -1036, -1036,   614, -1036, -1036,
     281, -1036,  1128, -1036, -1036, -1036, -1036,    72,  1013, -1036,
    1120,  1886,    45, -1036,  1137,  1140,   480,   394,   494, -1036,
    1214, -1036,  1132,   916,  2142, -1036, -1036, -1036, -1036,    72,
   -1036,  1145,  2004, -1036, -1036,  1110,  1112,  1113,  1114,  1119,
      52,  1147,  2630,  2630,  1755,   387,   806,   806,   387,   387,
    1153, -1036,  1155, -1036,  1158, -1036,  1214, -1036, -1036, -1036,
   -1036, -1036,  1160,  1381,  1100,    84,  3740, -1036,   591,  1214,
    1162, -1036, -1036,  3182, -1036,  1214,  1013, -1036,   516, -1036,
    1163,  1165,  1164,   372, -1036, -1036,   281,  1167, -1036, -1036,
   -1036,   394, -1036,  2142,  1168,  4883, -1036, -1036,  1214,  3182,
   -1036,  2004,  1169,   387,   387, -1036, -1036, -1036,  1170, -1036,
    1173, -1036,  4883,  1171,  1179,    22,  1181, -1036,    21, -1036,
   -1036,  2630,   281, -1036, -1036, -1036, -1036,   394,  1172, -1036,
   -1036,   591,  1176,  1132,  1180,  4883,  1187,   281,  3687, -1036,
   -1036, -1036, -1036,  1191,  4883,  4883,  4883,  1196,  2396,  5415,
     492,   591,  1190,  1192, -1036, -1036, -1036, -1036,  1198,  1214,
     591, -1036,  1214,  1200,  1202,  1203,  4883, -1036,  1199, -1036,
   -1036,  1205, -1036,  2142,  1214, -1036,   228, -1036, -1036,   627,
    1214,  1214,  1214,  1206,   492,  1210, -1036, -1036, -1036, -1036,
     480, -1036, -1036,   480, -1036, -1036, -1036,  1214, -1036, -1036,
    1207,  1217, -1036, -1036, -1036
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1036, -1036,  -364, -1036, -1036, -1036, -1036,    17,    43,    -2,
      55, -1036,   699, -1036,    58,    73, -1036, -1036, -1036,    75,
   -1036,    76, -1036,    87, -1036, -1036,    88, -1036,    93,  -561,
    -680,   100, -1036,   101, -1036,  -356,   686,   -89,   112,   114,
     116,   117, -1036,   527,  -973,  -921, -1036, -1036, -1036, -1035,
    -870, -1036,  -140, -1036, -1036, -1036, -1036, -1036,     6, -1036,
   -1036,   178,    32,    33, -1036, -1036,   294, -1036,   694,   537,
     133, -1036, -1036, -1036,  -787, -1036, -1036, -1036,   385, -1036,
     545, -1036,   547,   135, -1036, -1036, -1036, -1036,  -115, -1036,
   -1036, -1036,     7,   -35, -1036,  -501,  1246,    64,   456, -1036,
     670,   827,   -39,  -609,  -549,   575,  1235,     5,  -148,  1304,
     218,  -618,   698,    85, -1036,   -65,    41,   -24,   551,  -714,
    1255, -1036,  -365, -1036,  -163, -1036, -1036, -1036,   441,   310,
    -946, -1036, -1036,   316, -1036,  1159, -1036,  -141,  -525, -1036,
   -1036,   192,   865, -1036, -1036, -1036,   434, -1036, -1036, -1036,
    -231,   -83, -1036, -1036,   307,  -571, -1036,  -589, -1036,   700,
     183, -1036, -1036,   206,   -20,  1157,  -168, -1036,  1031,  -183,
    -150,  1136, -1036,  -413,  1298, -1036,   604,   191, -1036,  -177,
    -534,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -614
static const yytype_int16 yytable[] =
{
       6,   320,   268,   109,   259,   145,   238,   204,   172,   553,
     752,   136,   144,   300,   311,   422,   717,   779,   247,   737,
     155,   160,   107,   749,   692,   712,   190,   362,   957,   566,
     239,   239,   821,   369,   692,   353,   268,   137,   138,   376,
     864,   686,    47,    47,   385,   573,   196,   180,   108,   256,
     327,   795,   175,   796,   398,   776,  1067,     8,  1002,   662,
     110,   261,  1136,   112,   662,    44,    59,   867,  -296,  1058,
     270,   202,   431,  1140,   411,     8,   202,   211,   113,   260,
     116,   118,    47,   221,   433,  1107,   455,   702,   196,   196,
     147,   405,   120,   121,   162,  1090,   968,   490,   123,   391,
       8,   597,    47,  -181,   598,   124,   125,    72,    62,   148,
     392,   165,     8,   257,   202,   364,   222,   126,   146,   127,
    1113,   128,   129,  1174,  1102,   197,   703,   365,  -256,   704,
    -296,   161,  1139,   181,   663,   340,  1024,   343,   139,   745,
     141,  1003,   777,    36,    37,   778,  1031,   155,  1144,   162,
     154,  -613,   822,  1137,   305,  1121,   154,   163,   198,   311,
     491,    36,    37,   164,     8,  -181,   165,   197,  1160,    38,
    1066,   877,   539,   167,   180,  -566,   180,  1167,   388,   365,
     311,   389,   374,   689,   807,   166,    36,    37,    27,    28,
      29,  1141,   359,   229,   171,   297,   956,   705,    36,    37,
     607,   371,   400,    47,   720,   235,  1150,   196,   382,   373,
     417,   320,  1103,  -613,   723,  1104,   971,  1029,   292,   748,
     365,   997,   170,   394,    38,     8,   365,  1082,   167,     8,
    -428,   154,   585,  -428,  -613,   230,     8,   168,     8,   406,
     169,   410,   413,     8,   404,   306,   423,   170,   315,   171,
      36,    37,     8,   149,    47,   338,   959,    47,   172,   443,
     366,   450,   438,  -428,    60,   178,   579,   208,   595,   596,
    1159,  1178,   154,   150,  1179,   328,    38,   170,    47,   978,
     167,  1043,  1180,   329,   961,   616,    47,    47,  -613,   432,
     154,   989,   165,   692,   365,   471,  1124,   180,    27,    28,
      29,   171,   175,    61,  1188,   248,   520,   316,   317,   523,
     421,    36,    37,   497,   499,    36,    37,   504,   446,   575,
     866,   979,    36,    37,    36,    37,   867,   565,   300,    36,
      37,   856,   223,   551,   548,   164,   239,    38,    36,    37,
     151,    40,     8,   239,   266,   267,   549,   153,    47,     8,
      38,   422,   972,   185,    40,    38,   836,   166,   655,    40,
     170,   152,   545,   702,    38,   196,   687,   341,    40,    47,
     344,   690,   180,   619,   219,   330,  1176,   854,   186,   220,
     312,   837,    47,     8,   342,    47,   162,   345,   337,   330,
     434,   710,   459,     6,   626,    30,    31,     8,    47,   591,
     460,   735,   830,   165,  1047,   704,     8,   342,   808,   611,
     196,     8,  1119,   831,    33,    34,  1057,   405,  1120,   724,
     584,   542,   725,   434,   650,  1092,   225,   516,    36,    37,
     552,   497,   499,   504,   618,    36,    37,   538,   655,   606,
     342,   610,     8,   162,   517,   606,   246,   342,   432,   450,
     809,   163,    27,    28,    29,   159,   329,   178,   975,   758,
     165,    38,   759,   377,   378,   167,   699,   428,   196,    36,
      37,    27,    28,    29,   502,    47,   659,   503,   154,   328,
     158,   665,   379,    36,    37,    47,   171,   334,   188,   434,
     651,     8,    36,    37,     8,    38,   165,    36,    37,    40,
      30,    31,   214,   215,  1100,   239,   342,   189,   786,    38,
     297,  1005,   657,    40,     8,   178,   194,   696,    38,    33,
      34,   574,   167,    38,   601,   495,   195,    40,    36,    37,
     601,   168,   993,   292,   169,   994,   200,  1074,   342,   728,
    1075,   170,   359,   171,   434,   652,   512,     6,   330,   877,
     597,   981,    47,   598,    38,   207,   519,    47,    40,  1114,
    1050,   342,  1115,  1051,   109,   406,   145,   446,     6,   145,
     404,   307,   136,   144,     8,   410,   722,    36,    37,   330,
      36,    37,    47,   107,   757,   316,   317,   172,   165,   428,
     209,   656,   880,    47,   786,   516,   789,   212,   137,   138,
      36,    37,    47,   730,   213,   685,    38,   731,   593,   108,
      40,   432,   517,   180,   767,    47,   594,   595,   596,   334,
      47,   110,   216,    47,   112,   714,   180,   217,   471,   266,
     354,   175,   196,   881,   882,   954,   955,   883,   218,   113,
     228,   116,   118,   736,    30,    31,   421,   262,   516,   945,
     588,   231,   710,   120,   121,   154,   242,   828,   243,   123,
      36,    37,   428,    33,    34,   517,   124,   125,  -580,  -580,
    1181,   742,   245,  1182,   558,   559,   625,   263,   126,   264,
     127,  1183,   128,   129,   314,   359,    38,   109,   352,   145,
      40,   833,   577,   578,  -580,   136,   144,   252,   300,   139,
     356,   141,   232,   595,   596,   233,   107,   606,   234,   775,
     357,   330,   857,   320,   370,   606,   819,   820,   109,   395,
     145,   137,   138,   365,   178,   401,   136,   144,     1,     2,
       3,   934,   108,   407,   538,   408,   438,   107,   453,   145,
     584,     6,   969,   606,   110,   846,   852,   112,   538,  1021,
     422,   160,   137,   138,   601,   451,   601,   869,   452,   874,
     606,   247,   113,   108,   116,   118,   239,    47,   932,   261,
     180,   847,   848,   456,   457,   110,   120,   121,   112,   372,
     468,   958,   123,   178,    27,    28,    29,   984,    47,   124,
     125,   259,   601,   113,   469,   116,   118,   487,   488,   489,
     601,   126,   472,   127,   178,   128,   129,   120,   121,     8,
     886,   887,   888,   123,   403,   932,   492,   500,  1191,   501,
     124,   125,   139,   606,   141,   506,   508,   507,   601,   511,
     514,   992,   126,   439,   127,   445,   128,   129,   518,   305,
    1004,   170,   337,  1070,   178,   601,   432,   526,   261,   533,
     540,   550,   109,   139,   145,   141,   543,    47,   554,   775,
     136,   144,   991,   556,   562,   557,   984,   869,   561,  1084,
     563,   107,   569,   564,   178,   570,  1034,   571,  1009,   572,
     297,   576,   580,   586,   581,   767,   137,   138,   582,     8,
     587,     8,   608,   590,   615,    36,    37,   108,   145,   601,
     592,    68,   620,   292,   627,   405,   646,    47,   601,   110,
     647,   649,   112,   653,   664,  1053,    47,  1040,  1055,   601,
     668,    38,   669,   932,   721,    40,   328,   113,   432,   116,
     118,   671,   673,   932,   527,   674,   534,    27,    28,    29,
     675,   120,   121,   165,   681,   682,   330,   123,   695,     8,
     688,   697,   196,   713,   124,   125,   180,    80,    81,    82,
     178,   698,    84,   606,    86,    87,   126,   716,   127,   719,
     128,   129,   726,   734,   727,    36,    37,    36,    37,   746,
     738,   423,     8,   747,   750,   754,   755,   139,   760,   141,
     180,   751,   337,   519,   763,   172,   869,   769,   874,   783,
     869,    38,   874,    38,   780,    40,     8,    40,   784,   196,
     606,   788,  1080,   767,   932,   792,   535,  1190,   816,   536,
     320,  1106,    47,   798,   799,   800,   330,   812,   330,   485,
     486,   487,   488,   489,   180,    36,    37,   801,   804,   175,
     805,   806,     8,   813,   375,   421,   606,   814,   601,  1177,
    1126,   316,   317,   406,   818,  1184,  1185,  1186,   404,   606,
     825,   834,   835,   839,   869,   606,   874,  1133,    36,    37,
     840,   841,  1192,   157,  1158,    72,   180,   885,   179,   328,
     941,   654,   938,   932,   939,   183,   940,   530,   606,   943,
    1148,   944,    36,    37,    38,   601,   165,    47,    40,  1153,
    1154,  1155,   948,   949,   950,     8,   952,   426,   316,   317,
     427,   953,   180,   964,   966,   970,   980,   170,   986,   224,
     227,  1173,   987,  1080,  1001,  1007,    47,   180,    36,    37,
    1006,   601,  1015,   707,  1019,  1016,  1017,   715,   606,   605,
     403,  1018,   328,    47,   601,   613,  1022,  1023,  -197,   606,
     601,  1036,   606,   255,    38,  1037,  1041,  1042,    40,   165,
     820,   654,   743,   932,   606,  1048,    47,  1049,  1052,  1059,
     606,   606,   606,   601,  1063,    47,    47,    47,  1068,   330,
    1077,     8,   265,  1069,   196,  1085,  -254,   606,  -253,  -255,
    1089,    36,    37,   313,  1091,  -252,  1095,    47,  1096,   333,
     333,  1097,   339,  1099,  1101,  1109,  1116,  1117,  1125,   351,
    1130,  1134,  1118,  1131,     8,  1122,  1132,    38,   371,  1135,
    1143,    40,  1138,   601,  1145,     8,   163,  1147,  1149,   206,
     502,   785,  1152,   503,   601,   255,  1156,   601,  1161,  1164,
    1162,  1170,   330,  1171,  1172,   867,   226,  1187,   691,   601,
    1193,   432,   178,  1175,   390,   601,   601,   601,  1189,   527,
    1194,   729,   307,    27,    28,    29,   845,    36,    37,  1129,
     179,   178,   601,  1105,   428,  1054,   740,   853,   424,   165,
     430,   333,   333,  1020,   850,   437,   851,   156,   823,   440,
     157,   255,   449,    38,   593,   977,   628,   167,   781,   753,
      36,    37,   594,   595,   596,   863,   250,   182,  1062,   251,
     996,    36,    37,  1061,   617,  1146,   170,   785,   171,  1011,
    1081,  1157,   355,  1142,   324,   326,    38,   832,   179,     0,
      40,     0,     0,     0,     0,     0,     0,    38,   496,   498,
     498,    40,   597,   505,     0,   598,   473,   474,   475,   476,
     502,   330,   361,   503,     0,     0,     0,   361,   361,   513,
       0,   515,     0,     0,   361,     0,   383,   384,   199,   361,
     482,   483,   484,   485,   486,   487,   488,   489,   333,   333,
       0,     0,     0,   333,     8,   396,     0,     0,   361,   399,
       8,     0,   236,     0,   963,   546,     0,   244,     0,   361,
       0,     0,   430,   967,   335,     0,   429,   817,     0,   361,
       0,     0,   555,   349,     0,   824,   442,     0,     0,     0,
       0,   162,     0,   454,     0,   567,     0,   371,     0,   163,
     962,     0,     0,     0,     0,   163,     0,     0,   165,     0,
       0,     0,   458,   855,   461,   462,   463,   464,   465,   466,
     467,     0,     0,     0,     0,     0,  1010,   498,   498,   498,
     878,     0,     0,   589,     0,     0,   333,   333,     0,   333,
      36,    37,   332,   336,     0,   612,    36,    37,   509,     0,
       0,     0,   350,     8,     0,     0,   335,     0,     0,   349,
       0,     0,     0,   363,     0,     0,    38,     0,   363,   363,
     167,   522,    38,     0,   525,   363,   167,     0,     0,   168,
     363,     0,   169,     0,     0,   250,     0,     0,   251,   170,
     432,   171,     0,   965,     0,   170,   648,   171,   346,   363,
     483,   484,   485,   486,   487,   488,   489,   179,   498,  1046,
     363,   416,     0,   661,     0,     0,   425,   363,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   439,     0,   445,
       0,     0,     0,     0,   333,     0,     0,   333,     0,    36,
      37,     0,     0,     0,     0,     0,  1065,     0,     0,     0,
       0,     0,   528,   531,     0,     0,     0,   537,     0,   255,
       0,     0,     0,   255,     0,    38,   179,  1088,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,   436,   332,   336,     0,     0,   350,   179,   255,   333,
     330,     0,     0,   333,     0,     0,     0,     8,   403,     0,
       0,     0,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,     0,
     770,   529,   532,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,  1044,   249,     0,  1088,   658,     0,     0,
     528,   531,   163,   537,     8,     0,   667,     0,     0,     0,
       8,   702,     0,   196,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,   333,   333,     0,     0,     0,   333,
     361,   473,   474,     0,   333,   361,     0,     0,     0,   333,
    1076,   432,     0,    36,    37,     0,   361,   371,     0,   530,
     703,     0,     0,   704,     0,   163,   483,   484,   485,   486,
     487,   488,   489,   732,     0,   361,     0,     0,     0,    38,
       0,     0,     0,   167,   255,     0,  1098,   660,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,     8,  1108,
      36,    37,   170,     0,   171,  1112,    36,    37,   679,   842,
       0,   684,     0,   179,     0,     0,   333,     0,     0,     0,
     771,   635,   638,   645,     0,   865,    38,     0,  1127,     0,
      40,   705,    38,     0,     0,   162,   167,   332,   336,   350,
       0,     0,     0,   163,     0,   250,   529,   532,   251,   164,
       0,   330,   165,     0,     0,   170,   350,   171,     0,     0,
       0,     0,     0,   660,     8,     0,     0,   679,     0,   333,
     333,   166,     0,     0,     0,   333,     0,   680,   878,     0,
       0,   363,     0,     0,    36,    37,   363,   693,     0,  1166,
     255,     8,     0,     0,     0,   701,   708,   711,    68,   255,
       0,   371,     0,     0,  1045,     0,     0,     0,     0,   163,
      38,     0,     0,     0,   167,     0,   363,     0,   708,   829,
       0,   843,     0,   168,     0,   744,   169,     0,   432,     8,
       0,     0,     0,   170,     0,   171,   683,     0,   790,   791,
       0,     0,     0,   794,     0,     0,     0,   858,   797,     0,
      36,    37,   255,   803,    80,    81,    82,     0,     0,    84,
    1012,    86,    87,     0,     0,     0,   371,     0,     0,  1064,
       0,   935,   936,   465,   163,   937,    38,    36,    37,     0,
     167,   942,     0,     0,     8,     0,     0,     0,     0,   250,
       0,     0,   251,     0,     8,   844,     0,   680,     0,   170,
       0,   171,  1030,    38,     0,     0,     0,    40,     0,   361,
     361,     0,     0,     0,     0,    36,    37,   361,     0,   333,
     790,   328,     0,   333,   333,     0,   810,     0,   330,   346,
       8,   371,   973,   974,   976,   255,     0,     0,   165,   163,
       0,    38,     0,     0,     0,   167,     0,     8,     0,     0,
       0,   708,     0,   255,   250,   255,     0,   251,     0,   827,
       0,   708,     0,     0,   170,     0,   171,   432,  1000,     0,
      36,    37,   255,   946,   947,   802,     0,     0,  1073,   951,
      36,    37,     0,     0,   371,     0,     0,  1086,     0,     0,
       0,     0,   163,   255,     0,     0,    38,     0,     0,     0,
      40,     0,     0,     0,     0,   179,    38,   333,   333,   347,
     167,     0,   348,     0,     0,     0,    36,    37,     0,   250,
       0,   330,   251,     0,   179,     0,     0,   612,     0,   170,
       0,   171,     0,    36,    37,     0,     0,  1032,  1033,     0,
       0,     0,    38,     0,     0,     0,    40,     0,     0,     0,
     363,   363,  1123,     0,     0,   708,   960,     0,   363,    38,
       0,     0,   255,   167,     0,     0,     0,   330,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,     0,     0,
       0,   827,   170,   891,   171,  -613,    64,     0,  1073,     0,
      65,    66,    67,     0,  1000,     0,     0,     0,     0,     0,
       0,     0,     0,    68,  -613,  -613,  -613,  -613,  -613,  -613,
    -613,  -613,  -613,  -613,  -613,  -613,     0,  -613,  -613,  -613,
    -613,  -613,     0,  1035,     0,   892,    70,  1038,  1039,  -613,
       0,  -613,  -613,  -613,  -613,  -613,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,   893,    77,
      78,    79,  -613,  -613,  -613,   894,   895,   896,     0,    80,
     897,    82,  1111,    83,    84,    85,    86,    87,  -613,  -613,
       0,  -613,  -613,    88,     0,     0,     0,    92,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     8,  1128,     0,
     196,     0,     0,     0,     0,   100,     0,  -613,     0,     0,
     101,  -613,  -613,   708,     0,     0,   898,     0,     0,     0,
       0,  1093,  1094,     0,     0,   271,     0,     0,   196,   272,
       0,     0,   899,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,     0,   284,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,     0,     0,     0,   316,
     317,     0,     0,     0,     0,     0,     0,   196,    35,    38,
       0,    36,    37,    40,   275,   276,   277,   278,   279,   280,
     281,   282,   426,     0,     0,   427,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,    38,     0,     0,
      39,    40,     0,     0,     0,     0,    41,     0,     0,     0,
     285,     0,     0,   286,     0,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   875,    21,    22,    23,
      24,    25,   283,     0,     0,    27,    28,    29,     0,     0,
     876,    27,    28,    29,    30,    31,     0,   284,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,   593,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,     0,    35,     8,
       0,    36,    37,     8,     0,     0,   196,     0,     0,     0,
       0,     0,     0,   275,   276,   277,   278,   279,   280,   281,
     282,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,   597,     0,   444,   598,     0,     0,
     285,     0,     0,   286,   163,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,    36,    37,   782,     0,    36,
      37,    27,    28,    29,    30,    31,     0,   284,     0,     0,
     521,     0,     0,     0,     0,   316,   317,     0,     0,     0,
       0,    38,    32,    33,    34,   167,     0,     0,   473,   474,
     475,   476,     0,   477,   250,     0,     0,   251,    35,     8,
       0,    36,    37,     0,   170,     0,   171,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,  1056,     0,     0,     0,
     285,     0,     0,   286,   163,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,    36,    37,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    32,    33,    34,   167,     0,   473,   474,   475,
     476,     0,   477,     0,   250,     0,     0,   251,    35,     8,
       0,    36,    37,     0,   170,     0,   171,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,   432,     0,     0,     0,
     285,     0,     0,   286,   534,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,    36,    37,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
     666,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    32,    33,    34,    40,     0,   473,   474,   475,
     476,     0,     0,     0,   535,     0,     0,   536,    35,     8,
       0,    36,    37,     0,     0,     0,   330,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,   432,     0,     0,     0,
     285,     0,     0,   286,   676,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,   772,     0,    36,    37,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    32,    33,    34,    40,   473,   474,   475,   476,
       0,     0,     0,     0,   677,     0,     0,   678,    35,     0,
       0,    36,    37,     0,     0,     0,   330,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    38,    18,     0,
      20,    40,     0,    22,    23,    24,    25,     0,     0,     0,
     285,     0,     0,   286,     0,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,   773,     0,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,   473,   474,   475,   476,     0,
       0,     0,     0,     0,   473,   474,   475,   476,    35,     0,
       0,    36,    37,     0,     0,     0,     0,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
     285,     0,     0,   286,     0,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   473,   474,
     475,   476,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    36,    37,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
     285,     0,     0,   286,     0,   271,   287,   288,   196,   272,
     289,   290,   291,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,   283,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,    31,     0,   284,     0,     0,
     328,     0,     0,     0,     0,     0,     0,     0,   676,     0,
       0,     0,    32,    33,    34,     0,     0,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    36,    37,     0,    64,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    68,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   892,    70,    38,   287,   288,     0,    40,
     774,   290,   291,     0,     0,     0,     0,     0,   677,     0,
       0,   678,    72,    73,    74,    75,     0,    77,    78,    79,
     330,     0,     0,   894,   895,   896,     0,    80,   897,    82,
       0,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,    88,     0,     0,     0,    92,     0,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,   100,   621,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     899,    21,    22,    23,    24,    25,   307,     0,     0,     0,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
     473,   474,   475,   476,     0,   477,     0,     0,     0,     0,
       0,     0,    35,     0,     0,    36,    37,     0,     0,     0,
     478,   622,   480,   481,   623,   483,   484,   485,   486,   487,
     488,   624,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    39,    40,     8,     0,     0,     0,
      41,   988,     0,     0,   308,     0,     0,   309,     0,     0,
       0,     0,     0,     0,   170,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,   307,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,     0,   473,   474,   475,
     476,     0,   477,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    36,    37,     0,     0,     0,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
    1151,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    39,    40,     8,     0,     0,     0,    41,     0,     0,
       0,   493,     0,     0,   494,     0,     0,     0,     0,     0,
       0,   170,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,   473,   474,   475,   476,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,     8,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,    35,     0,     0,    36,
      37,     0,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,    38,     0,     0,    39,    40,
       0,     0,    30,    31,    41,     0,     0,     0,   426,     0,
       0,   427,     0,     0,     0,     0,     0,     0,   170,     0,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -2,    63,     0,  -613,    64,     0,
       0,     0,    65,    66,    67,    38,     0,     0,     0,    40,
       0,     0,     0,     0,     0,    68,  -613,  -613,  -613,  -613,
    -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,   170,  -613,
    -613,  -613,  -613,  -613,     0,     0,     0,    69,    70,     0,
       0,     0,     0,  -613,  -613,  -613,  -613,  -613,     0,     0,
      71,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,  -613,  -613,  -613,     0,     0,     0,
       0,    80,    81,    82,     0,    83,    84,    85,    86,    87,
    -613,  -613,     0,  -613,  -613,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,    63,  -613,
    -613,    64,   101,  -613,     0,    65,    66,    67,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,    68,  -613,
    -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,
    -613,     0,  -613,  -613,  -613,  -613,  -613,     0,     0,     0,
      69,    70,     0,     0,   718,     0,  -613,  -613,  -613,  -613,
    -613,     0,     0,    71,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,  -613,  -613,  -613,
       0,     0,     0,     0,    80,    81,    82,     0,    83,    84,
      85,    86,    87,  -613,  -613,     0,  -613,  -613,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,    63,  -613,  -613,    64,   101,  -613,     0,    65,    66,
      67,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,    68,  -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,
    -613,  -613,  -613,  -613,     0,  -613,  -613,  -613,  -613,  -613,
       0,     0,     0,    69,    70,     0,     0,   811,     0,  -613,
    -613,  -613,  -613,  -613,     0,     0,    71,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
    -613,  -613,  -613,     0,     0,     0,     0,    80,    81,    82,
       0,    83,    84,    85,    86,    87,  -613,  -613,     0,  -613,
    -613,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,    63,  -613,  -613,    64,   101,  -613,
       0,    65,    66,    67,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,    68,  -613,  -613,  -613,  -613,  -613,
    -613,  -613,  -613,  -613,  -613,  -613,  -613,     0,  -613,  -613,
    -613,  -613,  -613,     0,     0,     0,    69,    70,     0,     0,
     826,     0,  -613,  -613,  -613,  -613,  -613,     0,     0,    71,
       0,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,  -613,  -613,  -613,     0,     0,     0,     0,
      80,    81,    82,     0,    83,    84,    85,    86,    87,  -613,
    -613,     0,  -613,  -613,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    63,  -613,  -613,
      64,   101,  -613,     0,    65,    66,    67,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,    68,  -613,  -613,
    -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,  -613,
       0,  -613,  -613,  -613,  -613,  -613,     0,     0,     0,    69,
      70,     0,     0,     0,     0,  -613,  -613,  -613,  -613,  -613,
       0,     0,    71,     0,     0,     0,   985,     0,    72,    73,
      74,    75,    76,    77,    78,    79,  -613,  -613,  -613,     0,
       0,     0,     0,    80,    81,    82,     0,    83,    84,    85,
      86,    87,  -613,  -613,     0,  -613,  -613,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     7,     0,     8,     0,   510,     0,     0,     0,   100,
       0,  -613,     0,     0,   101,  -613,     0,     0,     0,     0,
     102,   103,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,   473,   474,   475,   476,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,     0,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,    35,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    36,    37,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,   859,    18,   860,    20,     8,
     861,    22,    23,    24,    25,     0,     0,     0,    38,     0,
       0,    39,    40,     0,     0,     0,     0,    41,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
       0,    35,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    35,     0,    40,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,   670,     0,     0,     0,     0,
       0,    38,     0,   386,    39,    40,     0,     0,     0,     0,
      41,   541,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,   473,   474,   475,   476,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,     0,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,    35,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,   672,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,   473,   474,   475,
     476,     0,   477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,     0,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,    35,
       0,     0,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    39,    40,     0,     0,     0,     0,    41,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,    36,    37,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    38,     0,     0,     0,    40,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    34,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,   982,     0,    36,    37,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,  1025,
      18,  1026,    20,     0,  1027,    22,    23,    24,    25,     0,
       0,     0,    38,     0,     0,     0,    40,   983,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    34,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,   258,     0,    36,    37,
       0,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,     0,     0,    38,     0,     0,     0,    40,   983,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    36,    37,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,   237,     0,     0,     0,    38,     0,     0,
      39,    40,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    36,    37,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,    34,     0,     8,     0,
     787,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,   258,     0,    36,    37,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    38,
       0,     0,     0,    40,    27,    28,    29,    30,    31,   473,
     474,   475,   476,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,     8,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,    35,     0,     0,    36,    37,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,     0,   793,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,     0,
     477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,    40,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489
};

static const yytype_int16 yycheck[] =
{
       0,   164,   152,     5,   144,     5,    95,    72,    47,   374,
     599,     5,     5,   154,   162,   246,   565,   626,   101,   580,
      40,    45,     5,   594,   549,   559,    61,   195,   815,   393,
      95,    96,   712,   201,   559,   185,   186,     5,     5,   207,
     754,   542,     1,     2,   212,   401,     6,    47,     5,    21,
       3,   669,    47,   671,   231,    41,  1002,     3,    42,    41,
       5,   144,    40,     5,    41,     1,     2,    46,    42,   990,
     153,    71,   249,  1108,   242,     3,    76,    77,     5,   144,
       5,     5,    41,    44,   252,  1058,   269,     4,     6,     6,
      52,   239,     5,     5,    40,    43,    43,    48,     5,    43,
       3,   128,    61,    42,   131,     5,     5,    62,     0,    71,
      54,    57,     3,    85,   114,   198,    77,     5,    48,     5,
    1066,     5,     5,  1158,    40,    85,    43,     6,    76,    46,
     104,    46,   111,    48,   116,   174,   923,   176,     5,   116,
       5,   125,   128,    89,    90,   131,   933,   167,  1121,    40,
     103,    42,   713,   131,   154,  1076,   103,    48,   118,   307,
     111,    89,    90,    54,     3,   104,    57,    85,  1141,   115,
     125,   760,   355,   119,   174,    54,   176,  1150,   213,     6,
     328,   216,    54,   547,   685,    76,    89,    90,    49,    50,
      51,  1112,   192,     4,   140,   154,   814,   114,    89,    90,
      54,    40,   237,   162,   568,     4,  1127,     6,   208,   204,
     245,   374,   128,   104,   570,   131,   834,   931,   154,    40,
       6,   124,   138,    54,   115,     3,     6,  1014,   119,     3,
      43,   103,    59,    46,   125,    46,     3,   128,     3,   239,
     131,   241,   242,     3,   239,   160,   246,   138,    46,   140,
      89,    90,     3,    48,   213,   170,   817,   216,   297,   259,
      46,   261,   116,    76,     1,    47,    46,    76,    89,    90,
    1140,    43,   103,    48,    46,    40,   115,   138,   237,     4,
     119,   961,    54,    48,   818,    43,   245,   246,    46,    40,
     103,   862,    57,   818,     6,   295,  1083,   297,    49,    50,
      51,   140,   297,    40,  1174,   114,   341,   105,   106,   344,
     246,    89,    90,   308,   309,    89,    90,   312,    76,   408,
      40,    46,    89,    90,    89,    90,    46,   392,   469,    89,
      90,    43,    92,   372,    42,    54,   401,   115,    89,    90,
      40,   119,     3,   408,   118,   119,    54,   103,   307,     3,
     115,   582,   119,   117,   119,   115,   117,    76,   506,   119,
     138,   142,   362,     4,   115,     6,   543,    40,   119,   328,
      40,   548,   372,   456,    77,   140,  1163,   741,   142,    82,
     162,   142,   341,     3,    57,   344,    40,    57,   170,   140,
      40,   559,    40,   393,   459,    52,    53,     3,   357,   434,
      48,   578,    43,    57,   965,    46,     3,    57,     4,   444,
       6,     3,    40,    54,    71,    72,   987,   565,    46,    43,
     420,   357,    46,    40,    41,  1034,    46,    40,    89,    90,
      40,   426,   427,   428,   454,    89,    90,   352,   586,   439,
      57,   441,     3,    40,    57,   445,   103,    57,    40,   449,
      46,    48,    49,    50,    51,    43,    48,   239,   119,    43,
      57,   115,    46,    52,    53,   119,     4,   249,     6,    89,
      90,    49,    50,    51,   128,   434,   511,   131,   103,    40,
     125,   516,    71,    89,    90,   444,   140,    48,    43,    40,
      41,     3,    89,    90,     3,   115,    57,    89,    90,   119,
      52,    53,    84,    85,  1053,   570,    57,    43,   656,   115,
     469,   876,   507,   119,     3,   297,   120,   552,   115,    71,
      72,    40,   119,   115,   439,   307,    40,   119,    89,    90,
     445,   128,    40,   469,   131,    43,    40,    43,    57,   574,
      46,   138,   542,   140,    40,    41,   328,   547,   140,  1138,
     128,   103,   511,   131,   115,    40,   338,   516,   119,    43,
     973,    57,    46,   976,   566,   565,   566,    76,   568,   569,
     565,    40,   566,   566,     3,   575,   569,    89,    90,   140,
      89,    90,   541,   566,   608,   105,   106,   626,    57,   371,
      40,   506,     1,   552,   742,    40,    41,    40,   566,   566,
      89,    90,   561,   115,    40,   541,   115,   119,    80,   566,
     119,    40,    57,   613,   614,   574,    88,    89,    90,    48,
     579,   566,    40,   582,   566,   561,   626,    84,   628,   118,
     119,   626,     6,    42,    43,   812,   813,    46,    40,   566,
      40,   566,   566,   579,    52,    53,   582,    48,    40,    41,
     432,    40,   820,   566,   566,   103,    40,   722,    40,   566,
      89,    90,   444,    71,    72,    57,   566,   566,   116,   117,
      43,   586,    40,    46,    41,    42,   458,    48,   566,    48,
     566,    54,   566,   566,    48,   685,   115,   689,   116,   689,
     119,   726,    41,    42,   142,   689,   689,   122,   839,   566,
      41,   566,    40,    89,    90,    43,   689,   707,    46,   624,
      42,   140,   747,   876,    43,   715,    41,    42,   720,    46,
     720,   689,   689,     6,   506,    46,   720,   720,   121,   122,
     123,   770,   689,    43,   649,    42,   116,   720,    41,   739,
     740,   741,   831,   743,   689,   739,   739,   689,   663,   899,
     981,   775,   720,   720,   669,    48,   671,   759,    48,   759,
     760,   844,   689,   720,   689,   689,   831,   726,   768,   852,
     770,   739,   739,   104,   111,   720,   689,   689,   720,   204,
     104,   816,   689,   565,    49,    50,    51,   852,   747,   689,
     689,   931,   707,   720,    42,   720,   720,   136,   137,   138,
     715,   689,    40,   689,   586,   689,   689,   720,   720,     3,
      73,    74,    75,   720,   239,   815,     7,    41,  1183,    41,
     720,   720,   689,   823,   689,   116,    57,    48,   743,    40,
      48,   866,   720,   258,   720,   260,   720,   720,    48,   839,
     875,   138,   624,  1006,   626,   760,    40,    48,   931,   116,
      43,    41,   854,   720,   854,   720,    42,   816,    41,   774,
     854,   854,   862,    41,    41,    54,   931,   869,    42,  1019,
      41,   854,    41,    43,   656,    41,   941,    41,   878,    41,
     839,    41,    41,   116,   104,   885,   854,   854,    42,     3,
      41,     3,    76,    43,    46,    89,    90,   854,   898,   814,
     116,    21,     3,   839,    48,  1053,     3,   866,   823,   854,
       3,   116,   854,   116,    48,   980,   875,   956,   983,   834,
      48,   115,    41,   923,    44,   119,    40,   854,    40,   854,
     854,    41,    48,   933,    48,    48,    48,    49,    50,    51,
      48,   854,   854,    57,    48,    48,   140,   854,    43,     3,
      41,    43,     6,    41,   854,   854,   956,    77,    78,    79,
     742,    46,    82,   963,    84,    85,   854,    46,   854,    43,
     854,   854,    40,    43,    47,    89,    90,    89,    90,    41,
      91,   981,     3,    40,    90,   111,    57,   854,    41,   854,
     990,    89,   774,   775,    78,  1034,   998,    46,   998,    41,
    1002,   115,  1002,   115,    48,   119,     3,   119,    41,     6,
    1010,    41,  1012,  1013,  1014,    41,   128,  1180,    40,   131,
    1183,  1056,   981,    48,    48,    48,   140,    42,   140,   134,
     135,   136,   137,   138,  1034,    89,    90,    48,    48,  1034,
      48,    48,     3,    42,    41,   981,  1046,    41,   963,  1164,
    1085,   105,   106,  1053,    54,  1170,  1171,  1172,  1053,  1059,
      43,    41,   142,   103,  1066,  1065,  1066,  1102,    89,    90,
      41,    47,  1187,    42,  1139,    62,  1076,    42,    47,    40,
      40,   506,    41,  1083,    41,    54,    41,    48,  1088,    41,
    1125,    41,    89,    90,   115,  1010,    57,  1056,   119,  1134,
    1135,  1136,    48,    48,    48,     3,    48,   128,   105,   106,
     131,    48,  1112,    41,    43,    41,    54,   138,    43,    88,
      89,  1156,    41,  1123,    47,    76,  1085,  1127,    89,    90,
      54,  1046,    46,   558,   140,    76,    76,   562,  1138,   439,
     565,    76,    40,  1102,  1059,   445,    47,   125,    47,  1149,
    1065,    48,  1152,   122,   115,    48,    47,    41,   119,    57,
      42,   586,   587,  1163,  1164,    43,  1125,    43,   104,    41,
    1170,  1171,  1172,  1088,    54,  1134,  1135,  1136,    41,   140,
      48,     3,   151,    43,     6,    40,    76,  1187,    76,    76,
      76,    89,    90,   162,    47,    76,    43,  1156,    43,   168,
     169,    43,   171,    43,   104,    43,    43,    42,    40,   178,
      41,    40,    48,    43,     3,    48,    43,   115,    40,    40,
      48,   119,    41,  1138,    48,     3,    48,    47,    41,    72,
     128,   656,    41,   131,  1149,   204,    40,  1152,    48,    41,
      48,    41,   140,    41,    41,    46,    89,    41,   549,  1164,
      43,    40,  1034,    48,   223,  1170,  1171,  1172,    48,    48,
      43,   575,    40,    49,    50,    51,   739,    89,    90,  1091,
     239,  1053,  1187,  1055,  1056,   981,   582,   740,   247,    57,
     249,   250,   251,   898,   739,   254,   739,    41,   713,   258,
     259,   260,   261,   115,    80,   839,   469,   119,   628,   601,
      89,    90,    88,    89,    90,   754,   128,    52,   998,   131,
     869,    89,    90,   997,   449,  1123,   138,   742,   140,   885,
    1013,  1138,   186,  1117,   165,   166,   115,   723,   297,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   115,   307,   308,
     309,   119,   128,   312,    -1,   131,   107,   108,   109,   110,
     128,   140,   195,   131,    -1,    -1,    -1,   200,   201,   328,
      -1,   330,    -1,    -1,   207,    -1,   209,   210,    70,   212,
     131,   132,   133,   134,   135,   136,   137,   138,   347,   348,
      -1,    -1,    -1,   352,     3,   228,    -1,    -1,   231,   232,
       3,    -1,    94,    -1,   819,   364,    -1,    99,    -1,   242,
      -1,    -1,   371,   828,   169,    -1,   249,   707,    -1,   252,
      -1,    -1,   381,   178,    -1,   715,   259,    -1,    -1,    -1,
      -1,    40,    -1,   266,    -1,   394,    -1,    40,    -1,    48,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    57,    -1,
      -1,    -1,   283,   743,   285,   286,   287,   288,   289,   290,
     291,    -1,    -1,    -1,    -1,    -1,   881,   426,   427,   428,
     760,    -1,    -1,   432,    -1,    -1,   435,   436,    -1,   438,
      89,    90,   168,   169,    -1,   444,    89,    90,   319,    -1,
      -1,    -1,   178,     3,    -1,    -1,   251,    -1,    -1,   254,
      -1,    -1,    -1,   195,    -1,    -1,   115,    -1,   200,   201,
     119,   342,   115,    -1,   345,   207,   119,    -1,    -1,   128,
     212,    -1,   131,    -1,    -1,   128,    -1,    -1,   131,   138,
      40,   140,    -1,   823,    -1,   138,   495,   140,    48,   231,
     132,   133,   134,   135,   136,   137,   138,   506,   507,   964,
     242,   243,    -1,   512,    -1,    -1,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,   982,    -1,   984,
      -1,    -1,    -1,    -1,   533,    -1,    -1,   536,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,    -1,
      -1,    -1,   347,   348,    -1,    -1,    -1,   352,    -1,   558,
      -1,    -1,    -1,   562,    -1,   115,   565,  1022,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,   131,   308,   309,    -1,    -1,   312,   586,   587,   588,
     140,    -1,    -1,   592,    -1,    -1,    -1,     3,  1053,    -1,
      -1,    -1,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,    -1,
     619,   347,   348,    -1,    -1,    -1,    -1,   626,    -1,    -1,
      -1,    -1,    -1,   963,    40,    -1,  1091,   508,    -1,    -1,
     435,   436,    48,   438,     3,    -1,   517,    -1,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,   656,    -1,    -1,
      -1,    -1,    -1,    -1,   663,   664,    -1,    -1,    -1,   668,
     543,   107,   108,    -1,   673,   548,    -1,    -1,    -1,   678,
    1010,    40,    -1,    89,    90,    -1,   559,    40,    -1,    48,
      43,    -1,    -1,    46,    -1,    48,   132,   133,   134,   135,
     136,   137,   138,   576,    -1,   578,    -1,    -1,    -1,   115,
      -1,    -1,    -1,   119,   713,    -1,  1046,   512,    -1,    -1,
      -1,    -1,   128,    -1,    -1,   131,    -1,    -1,     3,  1059,
      89,    90,   138,    -1,   140,  1065,    89,    90,   533,   738,
      -1,   536,    -1,   742,    -1,    -1,   745,    -1,    -1,    -1,
     621,   622,   623,   624,    -1,   754,   115,    -1,  1088,    -1,
     119,   114,   115,    -1,    -1,    40,   119,   493,   494,   495,
      -1,    -1,    -1,    48,    -1,   128,   502,   503,   131,    54,
      -1,   140,    57,    -1,    -1,   138,   512,   140,    -1,    -1,
      -1,    -1,    -1,   588,     3,    -1,    -1,   592,    -1,   798,
     799,    76,    -1,    -1,    -1,   804,    -1,   533,  1138,    -1,
      -1,   543,    -1,    -1,    89,    90,   548,   549,    -1,  1149,
     819,     3,    -1,    -1,    -1,   557,   558,   559,    21,   828,
      -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
     115,    -1,    -1,    -1,   119,    -1,   578,    -1,   580,   722,
      -1,    44,    -1,   128,    -1,   587,   131,    -1,    40,     3,
      -1,    -1,    -1,   138,    -1,   140,    48,    -1,   663,   664,
      -1,    -1,    -1,   668,    -1,    -1,    -1,   748,   673,    -1,
      89,    90,   881,   678,    77,    78,    79,    -1,    -1,    82,
     889,    84,    85,    -1,    -1,    -1,    40,    -1,    -1,    43,
      -1,   772,   773,   774,    48,   776,   115,    89,    90,    -1,
     119,   782,    -1,    -1,     3,    -1,    -1,    -1,    -1,   128,
      -1,    -1,   131,    -1,     3,   118,    -1,   653,    -1,   138,
      -1,   140,   931,   115,    -1,    -1,    -1,   119,    -1,   812,
     813,    -1,    -1,    -1,    -1,    89,    90,   820,    -1,   948,
     745,    40,    -1,   952,   953,    -1,   688,    -1,   140,    48,
       3,    40,   835,   836,   837,   964,    -1,    -1,    57,    48,
      -1,   115,    -1,    -1,    -1,   119,    -1,     3,    -1,    -1,
      -1,   713,    -1,   982,   128,   984,    -1,   131,    -1,   721,
      -1,   723,    -1,    -1,   138,    -1,   140,    40,   871,    -1,
      89,    90,  1001,   798,   799,    48,    -1,    -1,  1007,   804,
      89,    90,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,  1022,    -1,    -1,   115,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,  1034,   115,  1036,  1037,   128,
     119,    -1,   131,    -1,    -1,    -1,    89,    90,    -1,   128,
      -1,   140,   131,    -1,  1053,    -1,    -1,  1056,    -1,   138,
      -1,   140,    -1,    89,    90,    -1,    -1,   938,   939,    -1,
      -1,    -1,   115,    -1,    -1,    -1,   119,    -1,    -1,    -1,
     812,   813,  1081,    -1,    -1,   817,   818,    -1,   820,   115,
      -1,    -1,  1091,   119,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,   843,   138,     1,   140,     3,     4,    -1,  1117,    -1,
       8,     9,    10,    -1,   997,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    -1,   948,    -1,    43,    44,   952,   953,    47,
      -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,  1063,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    -1,    -1,    -1,    95,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,     3,  1089,    -1,
       6,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
     118,   119,   120,   965,    -1,    -1,   124,    -1,    -1,    -1,
      -1,  1036,  1037,    -1,    -1,     3,    -1,    -1,     6,     7,
      -1,    -1,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,     6,    86,   115,
      -1,    89,    90,   119,    13,    14,    15,    16,    17,    18,
      19,    20,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,   115,    -1,    -1,
     118,   119,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
     128,    -1,    -1,   131,    -1,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    40,    35,    36,    37,
      38,    39,    40,    -1,    -1,    49,    50,    51,    -1,    -1,
      54,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    86,     3,
      -1,    89,    90,     3,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,   128,    -1,    40,   131,    -1,    -1,
     128,    -1,    -1,   131,    48,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    89,    90,    76,    -1,    89,
      90,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   115,    70,    71,    72,   119,    -1,    -1,   107,   108,
     109,   110,    -1,   112,   128,    -1,    -1,   131,    86,     3,
      -1,    89,    90,    -1,   138,    -1,   140,    -1,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
     128,    -1,    -1,   131,    48,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    70,    71,    72,   119,    -1,   107,   108,   109,
     110,    -1,   112,    -1,   128,    -1,    -1,   131,    86,     3,
      -1,    89,    90,    -1,   138,    -1,   140,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
     128,    -1,    -1,   131,    48,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    70,    71,    72,   119,    -1,   107,   108,   109,
     110,    -1,    -1,    -1,   128,    -1,    -1,   131,    86,     3,
      -1,    89,    90,    -1,    -1,    -1,   140,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
     128,    -1,    -1,   131,    48,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    89,    90,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    70,    71,    72,   119,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,    86,    -1,
      -1,    89,    90,    -1,    -1,    -1,   140,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,   115,    31,    -1,
      33,   119,    -1,    36,    37,    38,    39,    -1,    -1,    -1,
     128,    -1,    -1,   131,    -1,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    86,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,   131,    -1,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,   132,   133,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,   131,    -1,     3,   134,   135,     6,     7,
     138,   139,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     3,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    21,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,   115,   134,   135,    -1,   119,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,   131,    62,    63,    64,    65,    -1,    67,    68,    69,
     140,    -1,    -1,    73,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,   113,    41,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
     140,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
     107,   108,   109,   110,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,   119,     3,    -1,    -1,    -1,
     124,    41,    -1,    -1,   128,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,     3,    -1,    -1,    -1,   124,    -1,    -1,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,     3,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    86,    -1,    -1,    89,
      90,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,   119,
      -1,    -1,    52,    53,   124,    -1,    -1,    -1,   128,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,
      -1,    -1,     8,     9,    10,   115,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   138,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,     1,   115,
       3,     4,   118,   119,    -1,     8,     9,    10,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    44,    -1,    -1,    47,    -1,    49,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,     1,   115,     3,     4,   118,   119,    -1,     8,     9,
      10,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    44,    -1,    -1,    47,    -1,    49,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,     1,   115,     3,     4,   118,   119,
      -1,     8,     9,    10,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    43,    44,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,     1,   115,     3,
       4,   118,   119,    -1,     8,     9,    10,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,     1,    -1,     3,    -1,    58,    -1,    -1,    -1,   113,
      -1,   115,    -1,    -1,   118,   119,    -1,    -1,    -1,    -1,
     124,   125,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,   124,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     3,
      35,    36,    37,    38,    39,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,    -1,    -1,    -1,    -1,   124,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      -1,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    86,    -1,   119,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    58,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    13,   118,   119,    -1,    -1,    -1,    -1,
     124,   125,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    86,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,   124,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,   107,   108,   109,
     110,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    86,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,    -1,    -1,    -1,    -1,   124,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,   119,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    89,    90,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,   115,    -1,    -1,    -1,   119,   120,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    -1,    -1,   115,    -1,    -1,    -1,   119,   120,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,   115,    -1,    -1,
     118,   119,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,   119,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,     3,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    90,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,   119,    49,    50,    51,    52,    53,   107,
     108,   109,   110,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,     3,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    86,    -1,    -1,    89,    90,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,   119,    -1,    58,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,   119,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   121,   122,   123,   144,   145,   324,     1,     3,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    35,    36,    37,    38,    39,    48,    49,    50,    51,
      52,    53,    70,    71,    72,    86,    89,    90,   115,   118,
     119,   124,   195,   239,   240,   256,   257,   259,   260,   261,
     262,   263,   264,   293,   294,   308,   311,   313,     1,   240,
       1,    40,     0,     1,     4,     8,     9,    10,    21,    43,
      44,    56,    62,    63,    64,    65,    66,    67,    68,    69,
      77,    78,    79,    81,    82,    83,    84,    85,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     113,   118,   124,   125,   146,   147,   148,   150,   151,   152,
     153,   154,   157,   158,   160,   161,   162,   163,   164,   165,
     166,   169,   170,   171,   174,   176,   181,   182,   183,   184,
     186,   190,   197,   198,   199,   200,   201,   205,   206,   213,
     214,   226,   227,   234,   235,   324,    48,    52,    71,    48,
      48,    40,   142,   103,   103,   307,   239,   311,   125,    43,
     260,   256,    40,    48,    54,    57,    76,   119,   128,   131,
     138,   140,   245,   246,   248,   250,   251,   252,   253,   311,
     324,   256,   263,   311,   307,   117,   142,   312,    43,    43,
     236,   237,   240,   324,   120,    40,     6,    85,   118,   317,
      40,   320,   324,     1,   258,   259,   308,    40,   320,    40,
     168,   324,    40,    40,    84,    85,    40,    84,    40,    77,
      82,    44,    77,    92,   311,    46,   308,   311,    40,     4,
      46,    40,    40,    43,    46,     4,   317,    40,   180,   258,
     178,   180,    40,    40,   317,    40,   103,   294,   320,    40,
     128,   131,   248,   250,   253,   311,    21,    85,    87,   195,
     258,   294,    48,    48,    48,   311,   118,   119,   313,   314,
     294,     3,     7,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    40,    55,   128,   131,   134,   135,   138,
     139,   140,   240,   241,   242,   244,   258,   259,   278,   279,
     280,   281,   282,   317,   318,   324,   256,    40,   128,   131,
     236,   251,   253,   311,    48,    46,   105,   106,   265,   266,
     267,   268,   269,    58,   278,   280,   278,     3,    40,    48,
     140,   249,   252,   311,    48,   249,   252,   253,   256,   311,
     245,    40,    57,   245,    40,    57,    48,   128,   131,   249,
     252,   311,   116,   313,   119,   314,    41,    42,   238,   324,
     267,   308,   309,   317,   294,     6,    46,   309,   322,   309,
      43,    40,   248,   250,    54,    41,   309,    52,    53,    71,
     295,   296,   324,   308,   308,   309,    13,   175,   236,   236,
     311,    43,    54,   216,    54,    46,   308,   177,   322,   308,
     236,    46,   247,   248,   250,   251,   324,    43,    42,   179,
     324,   309,   310,   324,   155,   156,   317,   236,   209,   210,
     211,   240,   293,   324,   311,   317,   128,   131,   253,   308,
     311,   322,    40,   309,    40,   128,   131,   311,   116,   248,
     311,   270,   308,   324,    40,   248,    76,   285,   286,   311,
     324,    48,    48,    41,   308,   312,   104,   111,   278,    40,
      48,   278,   278,   278,   278,   278,   278,   278,   104,    42,
     243,   324,    40,   107,   108,   109,   110,   112,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      48,   111,     7,   128,   131,   253,   311,   250,   311,   250,
      41,    41,   128,   131,   250,   311,   116,    48,    57,   278,
      58,    40,   253,   311,    48,   311,    40,    57,    48,   253,
     236,    58,   278,   236,    58,   278,    48,    48,   249,   252,
      48,   249,   252,   116,    48,   128,   131,   249,   256,   312,
      43,   125,   240,    42,   321,   324,   311,   185,    42,    54,
      41,   245,    40,   265,    41,   311,    41,    54,    41,    42,
     173,    42,    41,    41,    43,   258,   145,   311,   215,    41,
      41,    41,    41,   178,    40,   180,    41,    41,    42,    46,
      41,   104,    42,   212,   324,    59,   116,    41,   253,   311,
      43,   236,   116,    80,    88,    89,    90,   128,   131,   254,
     255,   256,   298,   300,   301,   302,   324,    54,    76,   196,
     324,   236,   311,   302,   287,    46,    43,   285,   307,   294,
       3,    41,   128,   131,   138,   253,   258,    48,   244,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,     3,     3,   311,   116,
      41,    41,    41,   116,   248,   251,   256,   250,   278,   236,
     249,   311,    41,   116,    48,   236,    58,   278,    48,    41,
      58,    41,    58,    48,    48,    48,    48,   128,   131,   249,
     252,    48,    48,    48,   249,   240,   238,   322,    41,   145,
     322,   155,   281,   317,   323,    43,   236,    43,    46,     4,
     167,   317,     4,    43,    46,   114,   172,   248,   317,   319,
     309,   317,   323,    41,   240,   248,    46,   247,    47,    43,
     145,    44,   235,   178,    43,    46,    40,    47,   236,   179,
     115,   119,   308,   315,    43,   322,   240,   172,    91,   207,
     211,   159,   256,   248,   317,   116,    41,    40,    40,   298,
      90,    89,   300,   255,   111,    57,   191,   260,    43,    46,
      41,   188,   245,    78,   288,   289,   297,   324,   203,    46,
     311,   278,    41,    41,   138,   256,    41,   128,   131,   246,
      48,   243,    76,    41,    41,   248,   251,    58,    41,    41,
     249,   249,    41,    58,   249,   254,   254,   249,    48,    48,
      48,    48,    48,   249,    48,    48,    48,   238,     4,    46,
     317,    47,    42,    42,    41,   149,    40,   302,    54,    41,
      42,   173,   172,   248,   302,    43,    47,   317,   258,   308,
      43,    54,   319,   236,    41,   142,   117,   142,   316,   103,
      41,    47,   311,    44,   118,   186,   201,   205,   206,   208,
     223,   225,   235,   212,   145,   302,    43,   236,   278,    30,
      32,    35,   189,   261,   262,   311,    40,    46,   192,   152,
     271,   272,   273,   274,   324,    40,    54,   300,   302,   303,
       1,    42,    43,    46,   187,    42,    73,    74,    75,   290,
     292,     1,    43,    66,    73,    74,    75,    78,   124,   140,
     150,   151,   152,   153,   157,   158,   162,   164,   166,   169,
     171,   174,   176,   181,   182,   183,   184,   201,   205,   206,
     213,   217,   221,   222,   223,   224,   225,   226,   228,   229,
     232,   235,   324,   202,   245,   278,   278,   278,    41,    41,
      41,    40,   278,    41,    41,    41,   249,   249,    48,    48,
      48,   249,    48,    48,   322,   322,   254,   217,   236,   172,
     317,   323,    43,   248,    41,   302,    43,   248,    43,   180,
      41,   254,   119,   308,   308,   119,   308,   241,     4,    46,
      54,   103,    87,   120,   258,    60,    43,    41,    41,   298,
     299,   324,   236,    40,    43,   193,   271,   124,   275,   276,
     308,    47,    42,   125,   236,   265,    54,    76,   304,   324,
     248,   289,   311,   291,   220,    46,    76,    76,    76,   140,
     221,   313,    47,   125,   217,    30,    32,    35,   233,   262,
     311,   217,   278,   278,   258,   249,    48,    48,   249,   249,
     245,    47,    41,   173,   302,    43,   248,   172,    43,    43,
     316,   316,   104,   258,   209,   258,    40,   298,   188,    41,
     194,   276,   272,    54,    43,   248,   125,   273,    41,    43,
     267,   305,   306,   311,    43,    46,   302,    48,   283,   284,
     324,   297,   217,   218,   313,    40,    43,   204,   248,    76,
      43,    47,   246,   249,   249,    43,    43,    43,   302,    43,
     247,   104,    40,   128,   131,   253,   236,   187,   302,    43,
     277,   278,   302,   273,    43,    46,    43,    42,    48,    40,
      46,   188,    48,   311,   217,    40,   236,   302,   278,   204,
      41,    43,    43,   236,    40,    40,    40,   131,    41,   111,
     192,   188,   306,    48,   187,    48,   284,    47,   236,    41,
     188,    43,    41,   236,   236,   236,    40,   303,   258,   193,
     187,    48,    48,   219,    41,   230,   302,   187,   231,   302,
      41,    41,    41,   236,   192,    48,   217,   231,    43,    46,
      54,    43,    46,    54,   231,   231,   231,    41,   193,    48,
     267,   265,   231,    43,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
                   if (!classes) classes = NewHash();
		   Setattr((yyvsp[(1) - (1)].node),"classes",classes); 
		   Setattr((yyvsp[(1) - (1)].node),"name",ModuleName);
		   
		   if ((!module_node) && ModuleName) {
		     module_node = new_node("module");
		     Setattr(module_node,"name",ModuleName);
		   }
		   Setattr((yyvsp[(1) - (1)].node),"module",module_node);
	           top = (yyvsp[(1) - (1)].node);
               }
    break;

  case 3:

    {
                 top = Copy(Getattr((yyvsp[(2) - (3)].p),"type"));
		 Delete((yyvsp[(2) - (3)].p));
               }
    break;

  case 4:

    {
                 top = 0;
               }
    break;

  case 5:

    {
                 top = (yyvsp[(2) - (3)].p);
               }
    break;

  case 6:

    {
                 top = 0;
               }
    break;

  case 7:

    {
                 top = (yyvsp[(3) - (5)].pl);
               }
    break;

  case 8:

    {
                 top = 0;
               }
    break;

  case 9:

    {  
                   /* add declaration to end of linked list (the declaration isn't always a single declaration, sometimes it is a linked list itself) */
                   if (currentDeclComment != NULL) {
		     set_comment((yyvsp[(2) - (2)].node), currentDeclComment);
		     currentDeclComment = NULL;
                   }                                      
                   appendChild((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
                   (yyval.node) = (yyvsp[(1) - (2)].node);
               }
    break;

  case 10:

    {
                   currentDeclComment = (yyvsp[(2) - (2)].str); 
                   (yyval.node) = (yyvsp[(1) - (2)].node);
               }
    break;

  case 11:

    {
                   Node *node = lastChild((yyvsp[(1) - (2)].node));
                   if (node) {
                     set_comment(node, (yyvsp[(2) - (2)].str));
                   }
                   (yyval.node) = (yyvsp[(1) - (2)].node);
               }
    break;

  case 12:

    {
                   (yyval.node) = new_node("top");
               }
    break;

  case 13:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 14:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:

    { (yyval.node) = 0; }
    break;

  case 17:

    {
                  (yyval.node) = 0;
		  if (cparse_unknown_directive) {
		      Swig_error(cparse_file, cparse_line, "Unknown directive '%s'.\n", cparse_unknown_directive);
		  } else {
		      Swig_error(cparse_file, cparse_line, "Syntax error in input(1).\n");
		  }
		  exit(1);
               }
    break;

  case 18:

    { 
                  if ((yyval.node)) {
   		      add_symbols((yyval.node));
                  }
                  (yyval.node) = (yyvsp[(1) - (1)].node); 
	       }
    break;

  case 19:

    {
                  (yyval.node) = 0;
                  skip_decl();
               }
    break;

  case 20:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 22:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 25:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 28:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 29:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 32:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 41:

    {
               Node *cls;
	       String *clsname;
	       extendmode = 1;
	       cplus_mode = CPLUS_PUBLIC;
	       if (!classes) classes = NewHash();
	       if (!classes_typedefs) classes_typedefs = NewHash();
	       clsname = make_class_name((yyvsp[(4) - (5)].str));
	       cls = Getattr(classes,clsname);
	       if (!cls) {
	         cls = Getattr(classes_typedefs, clsname);
		 if (!cls) {
		   /* No previous definition. Create a new scope */
		   Node *am = Getattr(Swig_extend_hash(),clsname);
		   if (!am) {
		     Swig_symbol_newscope();
		     Swig_symbol_setscopename((yyvsp[(4) - (5)].str));
		     prev_symtab = 0;
		   } else {
		     prev_symtab = Swig_symbol_setscope(Getattr(am,"symtab"));
		   }
		   current_class = 0;
		 } else {
		   /* Previous typedef class definition.  Use its symbol table.
		      Deprecated, just the real name should be used. 
		      Note that %extend before the class typedef never worked, only %extend after the class typdef. */
		   prev_symtab = Swig_symbol_setscope(Getattr(cls, "symtab"));
		   current_class = cls;
		   SWIG_WARN_NODE_BEGIN(cls);
		   Swig_warning(WARN_PARSE_EXTEND_NAME, cparse_file, cparse_line, "Deprecated %%extend name used - the %s name '%s' should be used instead of the typedef name '%s'.\n", Getattr(cls, "kind"), SwigType_namestr(Getattr(cls, "name")), (yyvsp[(4) - (5)].str));
		   SWIG_WARN_NODE_END(cls);
		 }
	       } else {
		 /* Previous class definition.  Use its symbol table */
		 prev_symtab = Swig_symbol_setscope(Getattr(cls,"symtab"));
		 current_class = cls;
	       }
	       Classprefix = NewString((yyvsp[(4) - (5)].str));
	       Namespaceprefix= Swig_symbol_qualifiedscopename(0);
	       Delete(clsname);
	     }
    break;

  case 42:

    {
               String *clsname;
	       extendmode = 0;
               (yyval.node) = new_node("extend");
	       Setattr((yyval.node),"symtab",Swig_symbol_popscope());
	       if (prev_symtab) {
		 Swig_symbol_setscope(prev_symtab);
	       }
	       Namespaceprefix = Swig_symbol_qualifiedscopename(0);
               clsname = make_class_name((yyvsp[(4) - (8)].str));
	       Setattr((yyval.node),"name",clsname);

	       mark_nodes_as_extend((yyvsp[(7) - (8)].node));
	       if (current_class) {
		 /* We add the extension to the previously defined class */
		 appendChild((yyval.node), (yyvsp[(7) - (8)].node));
		 appendChild(current_class,(yyval.node));
	       } else {
		 /* We store the extensions in the extensions hash */
		 Node *am = Getattr(Swig_extend_hash(),clsname);
		 if (am) {
		   /* Append the members to the previous extend methods */
		   appendChild(am, (yyvsp[(7) - (8)].node));
		 } else {
		   appendChild((yyval.node), (yyvsp[(7) - (8)].node));
		   Setattr(Swig_extend_hash(),clsname,(yyval.node));
		 }
	       }
	       current_class = 0;
	       Delete(Classprefix);
	       Delete(clsname);
	       Classprefix = 0;
	       prev_symtab = 0;
	       (yyval.node) = 0;

	     }
    break;

  case 43:

    {
                    (yyval.node) = new_node("apply");
                    Setattr((yyval.node),"pattern",Getattr((yyvsp[(2) - (5)].p),"pattern"));
		    appendChild((yyval.node),(yyvsp[(4) - (5)].p));
               }
    break;

  case 44:

    {
		 (yyval.node) = new_node("clear");
		 appendChild((yyval.node),(yyvsp[(2) - (3)].p));
               }
    break;

  case 45:

    {
		   if (((yyvsp[(4) - (5)].dtype).type != T_ERROR) && ((yyvsp[(4) - (5)].dtype).type != T_SYMBOL)) {
		     SwigType *type = NewSwigType((yyvsp[(4) - (5)].dtype).type);
		     (yyval.node) = new_node("constant");
		     Setattr((yyval.node),"name",(yyvsp[(2) - (5)].id));
		     Setattr((yyval.node),"type",type);
		     Setattr((yyval.node),"value",(yyvsp[(4) - (5)].dtype).val);
		     if ((yyvsp[(4) - (5)].dtype).rawval) Setattr((yyval.node),"rawval", (yyvsp[(4) - (5)].dtype).rawval);
		     Setattr((yyval.node),"storage","%constant");
		     SetFlag((yyval.node),"feature:immutable");
		     add_symbols((yyval.node));
		     Delete(type);
		   } else {
		     if ((yyvsp[(4) - (5)].dtype).type == T_ERROR) {
		       Swig_warning(WARN_PARSE_UNSUPPORTED_VALUE,cparse_file,cparse_line,"Unsupported constant value (ignored)\n");
		     }
		     (yyval.node) = 0;
		   }

	       }
    break;

  case 46:

    {
		 if (((yyvsp[(4) - (5)].dtype).type != T_ERROR) && ((yyvsp[(4) - (5)].dtype).type != T_SYMBOL)) {
		   SwigType_push((yyvsp[(2) - (5)].type),(yyvsp[(3) - (5)].decl).type);
		   /* Sneaky callback function trick */
		   if (SwigType_isfunction((yyvsp[(2) - (5)].type))) {
		     SwigType_add_pointer((yyvsp[(2) - (5)].type));
		   }
		   (yyval.node) = new_node("constant");
		   Setattr((yyval.node),"name",(yyvsp[(3) - (5)].decl).id);
		   Setattr((yyval.node),"type",(yyvsp[(2) - (5)].type));
		   Setattr((yyval.node),"value",(yyvsp[(4) - (5)].dtype).val);
		   if ((yyvsp[(4) - (5)].dtype).rawval) Setattr((yyval.node),"rawval", (yyvsp[(4) - (5)].dtype).rawval);
		   Setattr((yyval.node),"storage","%constant");
		   SetFlag((yyval.node),"feature:immutable");
		   add_symbols((yyval.node));
		 } else {
		   if ((yyvsp[(4) - (5)].dtype).type == T_ERROR) {
		     Swig_warning(WARN_PARSE_UNSUPPORTED_VALUE,cparse_file,cparse_line, "Unsupported constant value\n");
		   }
		   (yyval.node) = 0;
		 }
               }
    break;

  case 47:

    {
		 if (((yyvsp[(8) - (9)].dtype).type != T_ERROR) && ((yyvsp[(8) - (9)].dtype).type != T_SYMBOL)) {
		   SwigType_add_function((yyvsp[(2) - (9)].type), (yyvsp[(5) - (9)].pl));
		   SwigType_push((yyvsp[(2) - (9)].type), (yyvsp[(7) - (9)].dtype).qualifier);
		   SwigType_push((yyvsp[(2) - (9)].type), (yyvsp[(3) - (9)].decl).type);
		   /* Sneaky callback function trick */
		   if (SwigType_isfunction((yyvsp[(2) - (9)].type))) {
		     SwigType_add_pointer((yyvsp[(2) - (9)].type));
		   }
		   (yyval.node) = new_node("constant");
		   Setattr((yyval.node), "name", (yyvsp[(3) - (9)].decl).id);
		   Setattr((yyval.node), "type", (yyvsp[(2) - (9)].type));
		   Setattr((yyval.node), "value", (yyvsp[(8) - (9)].dtype).val);
		   if ((yyvsp[(8) - (9)].dtype).rawval) Setattr((yyval.node), "rawval", (yyvsp[(8) - (9)].dtype).rawval);
		   Setattr((yyval.node), "storage", "%constant");
		   SetFlag((yyval.node), "feature:immutable");
		   add_symbols((yyval.node));
		 } else {
		   if ((yyvsp[(8) - (9)].dtype).type == T_ERROR) {
		     Swig_warning(WARN_PARSE_UNSUPPORTED_VALUE,cparse_file,cparse_line, "Unsupported constant value\n");
		   }
		   (yyval.node) = 0;
		 }
	       }
    break;

  case 48:

    {
		 Swig_warning(WARN_PARSE_BAD_VALUE,cparse_file,cparse_line,"Bad constant value (ignored).\n");
		 (yyval.node) = 0;
	       }
    break;

  case 49:

    {
		 char temp[64];
		 Replace((yyvsp[(2) - (2)].str),"$file",cparse_file, DOH_REPLACE_ANY);
		 sprintf(temp,"%d", cparse_line);
		 Replace((yyvsp[(2) - (2)].str),"$line",temp,DOH_REPLACE_ANY);
		 Printf(stderr,"%s\n", (yyvsp[(2) - (2)].str));
		 Delete((yyvsp[(2) - (2)].str));
                 (yyval.node) = 0;
	       }
    break;

  case 50:

    {
		 char temp[64];
		 String *s = (yyvsp[(2) - (2)].str);
		 Replace(s,"$file",cparse_file, DOH_REPLACE_ANY);
		 sprintf(temp,"%d", cparse_line);
		 Replace(s,"$line",temp,DOH_REPLACE_ANY);
		 Printf(stderr,"%s\n", s);
		 Delete(s);
                 (yyval.node) = 0;
               }
    break;

  case 51:

    {
                    skip_balanced('{','}');
		    (yyval.node) = 0;
		    Swig_warning(WARN_DEPRECATED_EXCEPT,cparse_file, cparse_line, "%%except is deprecated.  Use %%exception instead.\n");
	       }
    break;

  case 52:

    {
                    skip_balanced('{','}');
		    (yyval.node) = 0;
		    Swig_warning(WARN_DEPRECATED_EXCEPT,cparse_file, cparse_line, "%%except is deprecated.  Use %%exception instead.\n");
               }
    break;

  case 53:

    {
		 (yyval.node) = 0;
		 Swig_warning(WARN_DEPRECATED_EXCEPT,cparse_file, cparse_line, "%%except is deprecated.  Use %%exception instead.\n");
               }
    break;

  case 54:

    {
		 (yyval.node) = 0;
		 Swig_warning(WARN_DEPRECATED_EXCEPT,cparse_file, cparse_line, "%%except is deprecated.  Use %%exception instead.\n");
	       }
    break;

  case 55:

    {		 
                 (yyval.node) = NewHash();
                 Setattr((yyval.node),"value",(yyvsp[(1) - (4)].str));
		 Setattr((yyval.node),"type",Getattr((yyvsp[(3) - (4)].p),"type"));
               }
    break;

  case 56:

    {
                 (yyval.node) = NewHash();
                 Setattr((yyval.node),"value",(yyvsp[(1) - (1)].str));
              }
    break;

  case 57:

    {
                (yyval.node) = (yyvsp[(1) - (1)].node);
              }
    break;

  case 58:

    {
                   Hash *p = (yyvsp[(5) - (7)].node);
		   (yyval.node) = new_node("fragment");
		   Setattr((yyval.node),"value",Getattr((yyvsp[(3) - (7)].node),"value"));
		   Setattr((yyval.node),"type",Getattr((yyvsp[(3) - (7)].node),"type"));
		   Setattr((yyval.node),"section",Getattr(p,"name"));
		   Setattr((yyval.node),"kwargs",nextSibling(p));
		   Setattr((yyval.node),"code",(yyvsp[(7) - (7)].str));
                 }
    break;

  case 59:

    {
		   Hash *p = (yyvsp[(5) - (7)].node);
		   String *code;
                   skip_balanced('{','}');
		   (yyval.node) = new_node("fragment");
		   Setattr((yyval.node),"value",Getattr((yyvsp[(3) - (7)].node),"value"));
		   Setattr((yyval.node),"type",Getattr((yyvsp[(3) - (7)].node),"type"));
		   Setattr((yyval.node),"section",Getattr(p,"name"));
		   Setattr((yyval.node),"kwargs",nextSibling(p));
		   Delitem(scanner_ccode,0);
		   Delitem(scanner_ccode,DOH_END);
		   code = Copy(scanner_ccode);
		   Setattr((yyval.node),"code",code);
		   Delete(code);
                 }
    break;

  case 60:

    {
		   (yyval.node) = new_node("fragment");
		   Setattr((yyval.node),"value",Getattr((yyvsp[(3) - (5)].node),"value"));
		   Setattr((yyval.node),"type",Getattr((yyvsp[(3) - (5)].node),"type"));
		   Setattr((yyval.node),"emitonly","1");
		 }
    break;

  case 61:

    {
                     (yyvsp[(1) - (4)].loc).filename = Copy(cparse_file);
		     (yyvsp[(1) - (4)].loc).line = cparse_line;
		     scanner_set_location((yyvsp[(3) - (4)].str),1);
                     if ((yyvsp[(2) - (4)].node)) { 
		       String *maininput = Getattr((yyvsp[(2) - (4)].node), "maininput");
		       if (maininput)
		         scanner_set_main_input_file(NewString(maininput));
		     }
               }
    break;

  case 62:

    {
                     String *mname = 0;
                     (yyval.node) = (yyvsp[(6) - (7)].node);
		     scanner_set_location((yyvsp[(1) - (7)].loc).filename,(yyvsp[(1) - (7)].loc).line+1);
		     if (strcmp((yyvsp[(1) - (7)].loc).type,"include") == 0) set_nodeType((yyval.node),"include");
		     if (strcmp((yyvsp[(1) - (7)].loc).type,"import") == 0) {
		       mname = (yyvsp[(2) - (7)].node) ? Getattr((yyvsp[(2) - (7)].node),"module") : 0;
		       set_nodeType((yyval.node),"import");
		       if (import_mode) --import_mode;
		     }
		     
		     Setattr((yyval.node),"name",(yyvsp[(3) - (7)].str));
		     /* Search for the module (if any) */
		     {
			 Node *n = firstChild((yyval.node));
			 while (n) {
			     if (Strcmp(nodeType(n),"module") == 0) {
			         if (mname) {
				   Setattr(n,"name", mname);
				   mname = 0;
				 }
				 Setattr((yyval.node),"module",Getattr(n,"name"));
				 break;
			     }
			     n = nextSibling(n);
			 }
			 if (mname) {
			   /* There is no module node in the import
			      node, ie, you imported a .h file
			      directly.  We are forced then to create
			      a new import node with a module node.
			   */			      
			   Node *nint = new_node("import");
			   Node *mnode = new_node("module");
			   Setattr(mnode,"name", mname);
                           Setattr(mnode,"options",(yyvsp[(2) - (7)].node));
			   appendChild(nint,mnode);
			   Delete(mnode);
			   appendChild(nint,firstChild((yyval.node)));
			   (yyval.node) = nint;
			   Setattr((yyval.node),"module",mname);
			 }
		     }
		     Setattr((yyval.node),"options",(yyvsp[(2) - (7)].node));
               }
    break;

  case 63:

    { (yyval.loc).type = "include"; }
    break;

  case 64:

    { (yyval.loc).type = "import"; ++import_mode;}
    break;

  case 65:

    {
                 String *cpps;
		 if (Namespaceprefix) {
		   Swig_error(cparse_file, cparse_start_line, "%%inline directive inside a namespace is disallowed.\n");
		   (yyval.node) = 0;
		 } else {
		   (yyval.node) = new_node("insert");
		   Setattr((yyval.node),"code",(yyvsp[(2) - (2)].str));
		   /* Need to run through the preprocessor */
		   Seek((yyvsp[(2) - (2)].str),0,SEEK_SET);
		   Setline((yyvsp[(2) - (2)].str),cparse_start_line);
		   Setfile((yyvsp[(2) - (2)].str),cparse_file);
		   cpps = Preprocessor_parse((yyvsp[(2) - (2)].str));
		   start_inline(Char(cpps), cparse_start_line);
		   Delete((yyvsp[(2) - (2)].str));
		   Delete(cpps);
		 }
		 
	       }
    break;

  case 66:

    {
                 String *cpps;
		 int start_line = cparse_line;
		 skip_balanced('{','}');
		 if (Namespaceprefix) {
		   Swig_error(cparse_file, cparse_start_line, "%%inline directive inside a namespace is disallowed.\n");
		   
		   (yyval.node) = 0;
		 } else {
		   String *code;
                   (yyval.node) = new_node("insert");
		   Delitem(scanner_ccode,0);
		   Delitem(scanner_ccode,DOH_END);
		   code = Copy(scanner_ccode);
		   Setattr((yyval.node),"code", code);
		   Delete(code);		   
		   cpps=Copy(scanner_ccode);
		   start_inline(Char(cpps), start_line);
		   Delete(cpps);
		 }
               }
    break;

  case 67:

    {
                 (yyval.node) = new_node("insert");
		 Setattr((yyval.node),"code",(yyvsp[(1) - (1)].str));
	       }
    break;

  case 68:

    {
		 String *code = NewStringEmpty();
		 (yyval.node) = new_node("insert");
		 Setattr((yyval.node),"section",(yyvsp[(3) - (6)].id));
		 Setattr((yyval.node),"code",code);
		 Setattr((yyval.node),"options",(yyvsp[(4) - (6)].node));
		 if (Swig_insert_file((yyvsp[(6) - (6)].str),code) < 0) {
		   Swig_error(cparse_file, cparse_line, "Couldn't find '%s'.\n", (yyvsp[(6) - (6)].str));
		   (yyval.node) = 0;
		 } 
               }
    break;

  case 69:

    {
		 (yyval.node) = new_node("insert");
		 Setattr((yyval.node),"section",(yyvsp[(3) - (6)].id));
		 Setattr((yyval.node),"options",(yyvsp[(4) - (6)].node));
		 Setattr((yyval.node),"code",(yyvsp[(6) - (6)].str));
               }
    break;

  case 70:

    {
		 String *code;
                 skip_balanced('{','}');
		 (yyval.node) = new_node("insert");
		 Setattr((yyval.node),"section",(yyvsp[(3) - (6)].id));
		 Setattr((yyval.node),"options",(yyvsp[(4) - (6)].node));
		 Delitem(scanner_ccode,0);
		 Delitem(scanner_ccode,DOH_END);
		 code = Copy(scanner_ccode);
		 Setattr((yyval.node),"code", code);
		 Delete(code);
	       }
    break;

  case 71:

    {
                 (yyval.node) = new_node("module");
		 if ((yyvsp[(2) - (3)].node)) {
		   Setattr((yyval.node),"options",(yyvsp[(2) - (3)].node));
		   if (Getattr((yyvsp[(2) - (3)].node),"directors")) {
		     Wrapper_director_mode_set(1);
		     if (!cparse_cplusplus) {
		       Swig_error(cparse_file, cparse_line, "Directors are not supported for C code and require the -c++ option\n");
		     }
		   } 
		   if (Getattr((yyvsp[(2) - (3)].node),"dirprot")) {
		     Wrapper_director_protected_mode_set(1);
		   } 
		   if (Getattr((yyvsp[(2) - (3)].node),"allprotected")) {
		     Wrapper_all_protected_mode_set(1);
		   } 
		   if (Getattr((yyvsp[(2) - (3)].node),"templatereduce")) {
		     template_reduce = 1;
		   }
		   if (Getattr((yyvsp[(2) - (3)].node),"notemplatereduce")) {
		     template_reduce = 0;
		   }
		 }
		 if (!ModuleName) ModuleName = NewString((yyvsp[(3) - (3)].id));
		 if (!import_mode) {
		   /* first module included, we apply global
		      ModuleName, which can be modify by -module */
		   String *mname = Copy(ModuleName);
		   Setattr((yyval.node),"name",mname);
		   Delete(mname);
		 } else { 
		   /* import mode, we just pass the idstring */
		   Setattr((yyval.node),"name",(yyvsp[(3) - (3)].id));   
		 }		 
		 if (!module_node) module_node = (yyval.node);
	       }
    break;

  case 72:

    {
                 Swig_warning(WARN_DEPRECATED_NAME,cparse_file,cparse_line, "%%name is deprecated.  Use %%rename instead.\n");
		 Delete(yyrename);
                 yyrename = NewString((yyvsp[(3) - (4)].id));
		 (yyval.node) = 0;
               }
    break;

  case 73:

    {
		 Swig_warning(WARN_DEPRECATED_NAME,cparse_file,cparse_line, "%%name is deprecated.  Use %%rename instead.\n");
		 (yyval.node) = 0;
		 Swig_error(cparse_file,cparse_line,"Missing argument to %%name directive.\n");
	       }
    break;

  case 74:

    {
                 (yyval.node) = new_node("native");
		 Setattr((yyval.node),"name",(yyvsp[(3) - (7)].id));
		 Setattr((yyval.node),"wrap:name",(yyvsp[(6) - (7)].id));
	         add_symbols((yyval.node));
	       }
    break;

  case 75:

    {
		 if (!SwigType_isfunction((yyvsp[(7) - (8)].decl).type)) {
		   Swig_error(cparse_file,cparse_line,"%%native declaration '%s' is not a function.\n", (yyvsp[(7) - (8)].decl).id);
		   (yyval.node) = 0;
		 } else {
		     Delete(SwigType_pop_function((yyvsp[(7) - (8)].decl).type));
		     /* Need check for function here */
		     SwigType_push((yyvsp[(6) - (8)].type),(yyvsp[(7) - (8)].decl).type);
		     (yyval.node) = new_node("native");
	             Setattr((yyval.node),"name",(yyvsp[(3) - (8)].id));
		     Setattr((yyval.node),"wrap:name",(yyvsp[(7) - (8)].decl).id);
		     Setattr((yyval.node),"type",(yyvsp[(6) - (8)].type));
		     Setattr((yyval.node),"parms",(yyvsp[(7) - (8)].decl).parms);
		     Setattr((yyval.node),"decl",(yyvsp[(7) - (8)].decl).type);
		 }
	         add_symbols((yyval.node));
	       }
    break;

  case 76:

    {
                 (yyval.node) = new_node("pragma");
		 Setattr((yyval.node),"lang",(yyvsp[(2) - (5)].id));
		 Setattr((yyval.node),"name",(yyvsp[(3) - (5)].id));
		 Setattr((yyval.node),"value",(yyvsp[(5) - (5)].str));
	       }
    break;

  case 77:

    {
		(yyval.node) = new_node("pragma");
		Setattr((yyval.node),"lang",(yyvsp[(2) - (3)].id));
		Setattr((yyval.node),"name",(yyvsp[(3) - (3)].id));
	      }
    break;

  case 78:

    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 79:

    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 80:

    { (yyval.id) = (yyvsp[(2) - (3)].id); }
    break;

  case 81:

    { (yyval.id) = (char *) "swig"; }
    break;

  case 82:

    {
                SwigType *t = (yyvsp[(2) - (4)].decl).type;
		Hash *kws = NewHash();
		String *fixname;
		fixname = feature_identifier_fix((yyvsp[(2) - (4)].decl).id);
		Setattr(kws,"name",(yyvsp[(3) - (4)].id));
		if (!Len(t)) t = 0;
		/* Special declarator check */
		if (t) {
		  if (SwigType_isfunction(t)) {
		    SwigType *decl = SwigType_pop_function(t);
		    if (SwigType_ispointer(t)) {
		      String *nname = NewStringf("*%s",fixname);
		      if ((yyvsp[(1) - (4)].intvalue)) {
			Swig_name_rename_add(Namespaceprefix, nname,decl,kws,(yyvsp[(2) - (4)].decl).parms);
		      } else {
			Swig_name_namewarn_add(Namespaceprefix,nname,decl,kws);
		      }
		      Delete(nname);
		    } else {
		      if ((yyvsp[(1) - (4)].intvalue)) {
			Swig_name_rename_add(Namespaceprefix,(fixname),decl,kws,(yyvsp[(2) - (4)].decl).parms);
		      } else {
			Swig_name_namewarn_add(Namespaceprefix,(fixname),decl,kws);
		      }
		    }
		    Delete(decl);
		  } else if (SwigType_ispointer(t)) {
		    String *nname = NewStringf("*%s",fixname);
		    if ((yyvsp[(1) - (4)].intvalue)) {
		      Swig_name_rename_add(Namespaceprefix,(nname),0,kws,(yyvsp[(2) - (4)].decl).parms);
		    } else {
		      Swig_name_namewarn_add(Namespaceprefix,(nname),0,kws);
		    }
		    Delete(nname);
		  }
		} else {
		  if ((yyvsp[(1) - (4)].intvalue)) {
		    Swig_name_rename_add(Namespaceprefix,(fixname),0,kws,(yyvsp[(2) - (4)].decl).parms);
		  } else {
		    Swig_name_namewarn_add(Namespaceprefix,(fixname),0,kws);
		  }
		}
                (yyval.node) = 0;
		scanner_clear_rename();
              }
    break;

  case 83:

    {
		String *fixname;
		Hash *kws = (yyvsp[(3) - (7)].node);
		SwigType *t = (yyvsp[(5) - (7)].decl).type;
		fixname = feature_identifier_fix((yyvsp[(5) - (7)].decl).id);
		if (!Len(t)) t = 0;
		/* Special declarator check */
		if (t) {
		  if ((yyvsp[(6) - (7)].dtype).qualifier) SwigType_push(t,(yyvsp[(6) - (7)].dtype).qualifier);
		  if (SwigType_isfunction(t)) {
		    SwigType *decl = SwigType_pop_function(t);
		    if (SwigType_ispointer(t)) {
		      String *nname = NewStringf("*%s",fixname);
		      if ((yyvsp[(1) - (7)].intvalue)) {
			Swig_name_rename_add(Namespaceprefix, nname,decl,kws,(yyvsp[(5) - (7)].decl).parms);
		      } else {
			Swig_name_namewarn_add(Namespaceprefix,nname,decl,kws);
		      }
		      Delete(nname);
		    } else {
		      if ((yyvsp[(1) - (7)].intvalue)) {
			Swig_name_rename_add(Namespaceprefix,(fixname),decl,kws,(yyvsp[(5) - (7)].decl).parms);
		      } else {
			Swig_name_namewarn_add(Namespaceprefix,(fixname),decl,kws);
		      }
		    }
		    Delete(decl);
		  } else if (SwigType_ispointer(t)) {
		    String *nname = NewStringf("*%s",fixname);
		    if ((yyvsp[(1) - (7)].intvalue)) {
		      Swig_name_rename_add(Namespaceprefix,(nname),0,kws,(yyvsp[(5) - (7)].decl).parms);
		    } else {
		      Swig_name_namewarn_add(Namespaceprefix,(nname),0,kws);
		    }
		    Delete(nname);
		  }
		} else {
		  if ((yyvsp[(1) - (7)].intvalue)) {
		    Swig_name_rename_add(Namespaceprefix,(fixname),0,kws,(yyvsp[(5) - (7)].decl).parms);
		  } else {
		    Swig_name_namewarn_add(Namespaceprefix,(fixname),0,kws);
		  }
		}
                (yyval.node) = 0;
		scanner_clear_rename();
              }
    break;

  case 84:

    {
		if ((yyvsp[(1) - (6)].intvalue)) {
		  Swig_name_rename_add(Namespaceprefix,(yyvsp[(5) - (6)].str),0,(yyvsp[(3) - (6)].node),0);
		} else {
		  Swig_name_namewarn_add(Namespaceprefix,(yyvsp[(5) - (6)].str),0,(yyvsp[(3) - (6)].node));
		}
		(yyval.node) = 0;
		scanner_clear_rename();
              }
    break;

  case 85:

    {
		    (yyval.intvalue) = 1;
                }
    break;

  case 86:

    {
                    (yyval.intvalue) = 0;
                }
    break;

  case 87:

    {
                    String *val = (yyvsp[(7) - (7)].str) ? NewString((yyvsp[(7) - (7)].str)) : NewString("1");
                    new_feature((yyvsp[(3) - (7)].id), val, 0, (yyvsp[(5) - (7)].decl).id, (yyvsp[(5) - (7)].decl).type, (yyvsp[(5) - (7)].decl).parms, (yyvsp[(6) - (7)].dtype).qualifier);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 88:

    {
                    String *val = Len((yyvsp[(5) - (9)].str)) ? (yyvsp[(5) - (9)].str) : 0;
                    new_feature((yyvsp[(3) - (9)].id), val, 0, (yyvsp[(7) - (9)].decl).id, (yyvsp[(7) - (9)].decl).type, (yyvsp[(7) - (9)].decl).parms, (yyvsp[(8) - (9)].dtype).qualifier);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 89:

    {
                    String *val = (yyvsp[(8) - (8)].str) ? NewString((yyvsp[(8) - (8)].str)) : NewString("1");
                    new_feature((yyvsp[(3) - (8)].id), val, (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].decl).id, (yyvsp[(6) - (8)].decl).type, (yyvsp[(6) - (8)].decl).parms, (yyvsp[(7) - (8)].dtype).qualifier);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 90:

    {
                    String *val = Len((yyvsp[(5) - (10)].str)) ? (yyvsp[(5) - (10)].str) : 0;
                    new_feature((yyvsp[(3) - (10)].id), val, (yyvsp[(6) - (10)].node), (yyvsp[(8) - (10)].decl).id, (yyvsp[(8) - (10)].decl).type, (yyvsp[(8) - (10)].decl).parms, (yyvsp[(9) - (10)].dtype).qualifier);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 91:

    {
                    String *val = (yyvsp[(5) - (5)].str) ? NewString((yyvsp[(5) - (5)].str)) : NewString("1");
                    new_feature((yyvsp[(3) - (5)].id), val, 0, 0, 0, 0, 0);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 92:

    {
                    String *val = Len((yyvsp[(5) - (7)].str)) ? (yyvsp[(5) - (7)].str) : 0;
                    new_feature((yyvsp[(3) - (7)].id), val, 0, 0, 0, 0, 0);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 93:

    {
                    String *val = (yyvsp[(6) - (6)].str) ? NewString((yyvsp[(6) - (6)].str)) : NewString("1");
                    new_feature((yyvsp[(3) - (6)].id), val, (yyvsp[(4) - (6)].node), 0, 0, 0, 0);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 94:

    {
                    String *val = Len((yyvsp[(5) - (8)].str)) ? (yyvsp[(5) - (8)].str) : 0;
                    new_feature((yyvsp[(3) - (8)].id), val, (yyvsp[(6) - (8)].node), 0, 0, 0, 0);
                    (yyval.node) = 0;
                    scanner_clear_rename();
                  }
    break;

  case 95:

    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 96:

    { (yyval.str) = 0; }
    break;

  case 97:

    { (yyval.str) = (yyvsp[(3) - (5)].pl); }
    break;

  case 98:

    {
		  (yyval.node) = NewHash();
		  Setattr((yyval.node),"name",(yyvsp[(2) - (4)].id));
		  Setattr((yyval.node),"value",(yyvsp[(4) - (4)].str));
                }
    break;

  case 99:

    {
		  (yyval.node) = NewHash();
		  Setattr((yyval.node),"name",(yyvsp[(2) - (5)].id));
		  Setattr((yyval.node),"value",(yyvsp[(4) - (5)].str));
                  set_nextSibling((yyval.node),(yyvsp[(5) - (5)].node));
                }
    break;

  case 100:

    {
                 Parm *val;
		 String *name;
		 SwigType *t;
		 if (Namespaceprefix) name = NewStringf("%s::%s", Namespaceprefix, (yyvsp[(5) - (7)].decl).id);
		 else name = NewString((yyvsp[(5) - (7)].decl).id);
		 val = (yyvsp[(3) - (7)].pl);
		 if ((yyvsp[(5) - (7)].decl).parms) {
		   Setmeta(val,"parms",(yyvsp[(5) - (7)].decl).parms);
		 }
		 t = (yyvsp[(5) - (7)].decl).type;
		 if (!Len(t)) t = 0;
		 if (t) {
		   if ((yyvsp[(6) - (7)].dtype).qualifier) SwigType_push(t,(yyvsp[(6) - (7)].dtype).qualifier);
		   if (SwigType_isfunction(t)) {
		     SwigType *decl = SwigType_pop_function(t);
		     if (SwigType_ispointer(t)) {
		       String *nname = NewStringf("*%s",name);
		       Swig_feature_set(Swig_cparse_features(), nname, decl, "feature:varargs", val, 0);
		       Delete(nname);
		     } else {
		       Swig_feature_set(Swig_cparse_features(), name, decl, "feature:varargs", val, 0);
		     }
		     Delete(decl);
		   } else if (SwigType_ispointer(t)) {
		     String *nname = NewStringf("*%s",name);
		     Swig_feature_set(Swig_cparse_features(),nname,0,"feature:varargs",val, 0);
		     Delete(nname);
		   }
		 } else {
		   Swig_feature_set(Swig_cparse_features(),name,0,"feature:varargs",val, 0);
		 }
		 Delete(name);
		 (yyval.node) = 0;
              }
    break;

  case 101:

    { (yyval.pl) = (yyvsp[(1) - (1)].pl); }
    break;

  case 102:

    { 
		  int i;
		  int n;
		  Parm *p;
		  n = atoi(Char((yyvsp[(1) - (3)].dtype).val));
		  if (n <= 0) {
		    Swig_error(cparse_file, cparse_line,"Argument count in %%varargs must be positive.\n");
		    (yyval.pl) = 0;
		  } else {
		    String *name = Getattr((yyvsp[(3) - (3)].p), "name");
		    (yyval.pl) = Copy((yyvsp[(3) - (3)].p));
		    if (name)
		      Setattr((yyval.pl), "name", NewStringf("%s%d", name, n));
		    for (i = 1; i < n; i++) {
		      p = Copy((yyvsp[(3) - (3)].p));
		      name = Getattr(p, "name");
		      if (name)
		        Setattr(p, "name", NewStringf("%s%d", name, n-i));
		      set_nextSibling(p,(yyval.pl));
		      Delete((yyval.pl));
		      (yyval.pl) = p;
		    }
		  }
                }
    break;

  case 103:

    {
		   (yyval.node) = 0;
		   if ((yyvsp[(3) - (6)].tmap).method) {
		     String *code = 0;
		     (yyval.node) = new_node("typemap");
		     Setattr((yyval.node),"method",(yyvsp[(3) - (6)].tmap).method);
		     if ((yyvsp[(3) - (6)].tmap).kwargs) {
		       ParmList *kw = (yyvsp[(3) - (6)].tmap).kwargs;
                       code = remove_block(kw, (yyvsp[(6) - (6)].str));
		       Setattr((yyval.node),"kwargs", (yyvsp[(3) - (6)].tmap).kwargs);
		     }
		     code = code ? code : NewString((yyvsp[(6) - (6)].str));
		     Setattr((yyval.node),"code", code);
		     Delete(code);
		     appendChild((yyval.node),(yyvsp[(5) - (6)].p));
		   }
	       }
    break;

  case 104:

    {
		 (yyval.node) = 0;
		 if ((yyvsp[(3) - (6)].tmap).method) {
		   (yyval.node) = new_node("typemap");
		   Setattr((yyval.node),"method",(yyvsp[(3) - (6)].tmap).method);
		   appendChild((yyval.node),(yyvsp[(5) - (6)].p));
		 }
	       }
    break;

  case 105:

    {
		   (yyval.node) = 0;
		   if ((yyvsp[(3) - (8)].tmap).method) {
		     (yyval.node) = new_node("typemapcopy");
		     Setattr((yyval.node),"method",(yyvsp[(3) - (8)].tmap).method);
		     Setattr((yyval.node),"pattern", Getattr((yyvsp[(7) - (8)].p),"pattern"));
		     appendChild((yyval.node),(yyvsp[(5) - (8)].p));
		   }
	       }
    break;

  case 106:

    {
		 Hash *p;
		 String *name;
		 p = nextSibling((yyvsp[(1) - (1)].node));
		 if (p && (!Getattr(p,"value"))) {
 		   /* this is the deprecated two argument typemap form */
 		   Swig_warning(WARN_DEPRECATED_TYPEMAP_LANG,cparse_file, cparse_line,
				"Specifying the language name in %%typemap is deprecated - use #ifdef SWIG<LANG> instead.\n");
		   /* two argument typemap form */
		   name = Getattr((yyvsp[(1) - (1)].node),"name");
		   if (!name || (Strcmp(name,typemap_lang))) {
		     (yyval.tmap).method = 0;
		     (yyval.tmap).kwargs = 0;
		   } else {
		     (yyval.tmap).method = Getattr(p,"name");
		     (yyval.tmap).kwargs = nextSibling(p);
		   }
		 } else {
		   /* one-argument typemap-form */
		   (yyval.tmap).method = Getattr((yyvsp[(1) - (1)].node),"name");
		   (yyval.tmap).kwargs = p;
		 }
                }
    break;

  case 107:

    {
                 (yyval.p) = (yyvsp[(1) - (2)].p);
		 set_nextSibling((yyval.p),(yyvsp[(2) - (2)].p));
		}
    break;

  case 108:

    {
                 (yyval.p) = (yyvsp[(2) - (3)].p);
		 set_nextSibling((yyval.p),(yyvsp[(3) - (3)].p));
                }
    break;

  case 109:

    { (yyval.p) = 0;}
    break;

  case 110:

    {
                  Parm *parm;
		  SwigType_push((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].decl).type);
		  (yyval.p) = new_node("typemapitem");
		  parm = NewParmWithoutFileLineInfo((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].decl).id);
		  Setattr((yyval.p),"pattern",parm);
		  Setattr((yyval.p),"parms", (yyvsp[(2) - (2)].decl).parms);
		  Delete(parm);
		  /*		  $$ = NewParmWithoutFileLineInfo($1,$2.id);
				  Setattr($$,"parms",$2.parms); */
                }
    break;

  case 111:

    {
                  (yyval.p) = new_node("typemapitem");
		  Setattr((yyval.p),"pattern",(yyvsp[(2) - (3)].pl));
		  /*		  Setattr($$,"multitype",$2); */
               }
    break;

  case 112:

    {
		 (yyval.p) = new_node("typemapitem");
		 Setattr((yyval.p),"pattern", (yyvsp[(2) - (6)].pl));
		 /*                 Setattr($$,"multitype",$2); */
		 Setattr((yyval.p),"parms",(yyvsp[(5) - (6)].pl));
               }
    break;

  case 113:

    {
                   (yyval.node) = new_node("types");
		   Setattr((yyval.node),"parms",(yyvsp[(3) - (5)].pl));
                   if ((yyvsp[(5) - (5)].str))
		     Setattr((yyval.node),"convcode",NewString((yyvsp[(5) - (5)].str)));
               }
    break;

  case 114:

    {
                  Parm *p, *tp;
		  Node *n;
		  Node *outer_class = currentOuterClass;
		  Symtab *tscope = 0;
		  int     specialized = 0;
		  int     variadic = 0;

		  (yyval.node) = 0;

		  tscope = Swig_symbol_current();          /* Get the current scope */

		  /* If the class name is qualified, we need to create or lookup namespace entries */
		  (yyvsp[(5) - (9)].str) = resolve_create_node_scope((yyvsp[(5) - (9)].str), 0);

		  if (nscope_inner && Strcmp(nodeType(nscope_inner), "class") == 0) {
		    outer_class	= nscope_inner;
		  }

		  /*
		    We use the new namespace entry 'nscope' only to
		    emit the template node. The template parameters are
		    resolved in the current 'tscope'.

		    This is closer to the C++ (typedef) behavior.
		  */
		  n = Swig_cparse_template_locate((yyvsp[(5) - (9)].str),(yyvsp[(7) - (9)].p),tscope);

		  /* Patch the argument types to respect namespaces */
		  p = (yyvsp[(7) - (9)].p);
		  while (p) {
		    SwigType *value = Getattr(p,"value");
		    if (!value) {
		      SwigType *ty = Getattr(p,"type");
		      if (ty) {
			SwigType *rty = 0;
			int reduce = template_reduce;
			if (reduce || !SwigType_ispointer(ty)) {
			  rty = Swig_symbol_typedef_reduce(ty,tscope);
			  if (!reduce) reduce = SwigType_ispointer(rty);
			}
			ty = reduce ? Swig_symbol_type_qualify(rty,tscope) : Swig_symbol_type_qualify(ty,tscope);
			Setattr(p,"type",ty);
			Delete(ty);
			Delete(rty);
		      }
		    } else {
		      value = Swig_symbol_type_qualify(value,tscope);
		      Setattr(p,"value",value);
		      Delete(value);
		    }

		    p = nextSibling(p);
		  }

		  /* Look for the template */
		  {
                    Node *nn = n;
                    Node *linklistend = 0;
                    Node *linkliststart = 0;
                    while (nn) {
                      Node *templnode = 0;
                      if (Strcmp(nodeType(nn),"template") == 0) {
                        int nnisclass = (Strcmp(Getattr(nn,"templatetype"),"class") == 0); /* if not a templated class it is a templated function */
                        Parm *tparms = Getattr(nn,"templateparms");
                        if (!tparms) {
                          specialized = 1;
                        } else if (Getattr(tparms,"variadic") && strncmp(Char(Getattr(tparms,"variadic")), "1", 1)==0) {
                          variadic = 1;
                        }
                        if (nnisclass && !variadic && !specialized && (ParmList_len((yyvsp[(7) - (9)].p)) > ParmList_len(tparms))) {
                          Swig_error(cparse_file, cparse_line, "Too many template parameters. Maximum of %d.\n", ParmList_len(tparms));
                        } else if (nnisclass && !specialized && ((ParmList_len((yyvsp[(7) - (9)].p)) < (ParmList_numrequired(tparms) - (variadic?1:0))))) { /* Variadic parameter is optional */
                          Swig_error(cparse_file, cparse_line, "Not enough template parameters specified. %d required.\n", (ParmList_numrequired(tparms)-(variadic?1:0)) );
                        } else if (!nnisclass && ((ParmList_len((yyvsp[(7) - (9)].p)) != ParmList_len(tparms)))) {
                          /* must be an overloaded templated method - ignore it as it is overloaded with a different number of template parameters */
                          nn = Getattr(nn,"sym:nextSibling"); /* repeat for overloaded templated functions */
                          continue;
                        } else {
			  String *tname = Copy((yyvsp[(5) - (9)].str));
                          int def_supplied = 0;
                          /* Expand the template */
			  Node *templ = Swig_symbol_clookup((yyvsp[(5) - (9)].str),0);
			  Parm *targs = templ ? Getattr(templ,"templateparms") : 0;

                          ParmList *temparms;
                          if (specialized) temparms = CopyParmList((yyvsp[(7) - (9)].p));
                          else temparms = CopyParmList(tparms);

                          /* Create typedef's and arguments */
                          p = (yyvsp[(7) - (9)].p);
                          tp = temparms;
                          if (!p && ParmList_len(p) != ParmList_len(temparms)) {
                            /* we have no template parameters supplied in %template for a template that has default args*/
                            p = tp;
                            def_supplied = 1;
                          }

                          while (p) {
                            String *value = Getattr(p,"value");
                            if (def_supplied) {
                              Setattr(p,"default","1");
                            }
                            if (value) {
                              Setattr(tp,"value",value);
                            } else {
                              SwigType *ty = Getattr(p,"type");
                              if (ty) {
                                Setattr(tp,"type",ty);
                              }
                              Delattr(tp,"value");
                            }
			    /* fix default arg values */
			    if (targs) {
			      Parm *pi = temparms;
			      Parm *ti = targs;
			      String *tv = Getattr(tp,"value");
			      if (!tv) tv = Getattr(tp,"type");
			      while(pi != tp && ti && pi) {
				String *name = Getattr(ti,"name");
				String *value = Getattr(pi,"value");
				if (!value) value = Getattr(pi,"type");
				Replaceid(tv, name, value);
				pi = nextSibling(pi);
				ti = nextSibling(ti);
			      }
			    }
                            p = nextSibling(p);
                            tp = nextSibling(tp);
                            if (!p && tp) {
                              p = tp;
                              def_supplied = 1;
                            } else if (p && !tp) { /* Variadic template - tp < p */
			      SWIG_WARN_NODE_BEGIN(nn);
                              Swig_warning(WARN_CPP11_VARIADIC_TEMPLATE,cparse_file, cparse_line,"Only the first variadic template argument is currently supported.\n");
			      SWIG_WARN_NODE_END(nn);
                              break;
                            }
                          }

                          templnode = copy_node(nn);
			  update_nested_classes(templnode); /* update classes nested within template */
                          /* We need to set the node name based on name used to instantiate */
                          Setattr(templnode,"name",tname);
			  Delete(tname);
                          if (!specialized) {
                            Delattr(templnode,"sym:typename");
                          } else {
                            Setattr(templnode,"sym:typename","1");
                          }
			  /* for now, nested %template is allowed only in the same scope as the template declaration */
                          if ((yyvsp[(3) - (9)].id) && !(nnisclass && ((outer_class && (outer_class != Getattr(nn, "nested:outer")))
			    ||(extendmode && current_class && (current_class != Getattr(nn, "nested:outer")))))) {
			    /*
			       Comment this out for 1.3.28. We need to
			       re-enable it later but first we need to
			       move %ignore from using %rename to use
			       %feature(ignore).

			       String *symname = Swig_name_make(templnode,0,$3,0,0);
			    */
			    String *symname = NewString((yyvsp[(3) - (9)].id));
                            Swig_cparse_template_expand(templnode,symname,temparms,tscope);
                            Setattr(templnode,"sym:name",symname);
                          } else {
                            static int cnt = 0;
                            String *nname = NewStringf("__dummy_%d__", cnt++);
                            Swig_cparse_template_expand(templnode,nname,temparms,tscope);
                            Setattr(templnode,"sym:name",nname);
			    Delete(nname);
                            Setattr(templnode,"feature:onlychildren", "typemap,typemapitem,typemapcopy,typedef,types,fragment,apply");
			    if ((yyvsp[(3) - (9)].id)) {
			      Swig_warning(WARN_PARSE_NESTED_TEMPLATE, cparse_file, cparse_line, "Named nested template instantiations not supported. Processing as if no name was given to %%template().\n");
			    }
                          }
                          Delattr(templnode,"templatetype");
                          Setattr(templnode,"template",nn);
                          Setfile(templnode,cparse_file);
                          Setline(templnode,cparse_line);
                          Delete(temparms);
			  if (outer_class && nnisclass) {
			    SetFlag(templnode, "nested");
			    Setattr(templnode, "nested:outer", outer_class);
			  }
                          add_symbols_copy(templnode);

                          if (Strcmp(nodeType(templnode),"class") == 0) {

                            /* Identify pure abstract methods */
                            Setattr(templnode,"abstracts", pure_abstracts(firstChild(templnode)));

                            /* Set up inheritance in symbol table */
                            {
                              Symtab  *csyms;
                              List *baselist = Getattr(templnode,"baselist");
                              csyms = Swig_symbol_current();
                              Swig_symbol_setscope(Getattr(templnode,"symtab"));
                              if (baselist) {
                                List *bases = Swig_make_inherit_list(Getattr(templnode,"name"),baselist, Namespaceprefix);
                                if (bases) {
                                  Iterator s;
                                  for (s = First(bases); s.item; s = Next(s)) {
                                    Symtab *st = Getattr(s.item,"symtab");
                                    if (st) {
				      Setfile(st,Getfile(s.item));
				      Setline(st,Getline(s.item));
                                      Swig_symbol_inherit(st);
                                    }
                                  }
				  Delete(bases);
                                }
                              }
                              Swig_symbol_setscope(csyms);
                            }

                            /* Merge in %extend methods for this class.
			       This only merges methods within %extend for a template specialized class such as
			         template<typename T> class K {}; %extend K<int> { ... }
			       The copy_node() call above has already added in the generic %extend methods such as
			         template<typename T> class K {}; %extend K { ... } */

			    /* !!! This may be broken.  We may have to add the
			       %extend methods at the beginning of the class */
                            {
                              String *stmp = 0;
                              String *clsname;
                              Node *am;
                              if (Namespaceprefix) {
                                clsname = stmp = NewStringf("%s::%s", Namespaceprefix, Getattr(templnode,"name"));
                              } else {
                                clsname = Getattr(templnode,"name");
                              }
                              am = Getattr(Swig_extend_hash(),clsname);
                              if (am) {
                                Symtab *st = Swig_symbol_current();
                                Swig_symbol_setscope(Getattr(templnode,"symtab"));
                                /*			    Printf(stdout,"%s: %s %p %p\n", Getattr(templnode,"name"), clsname, Swig_symbol_current(), Getattr(templnode,"symtab")); */
                                Swig_extend_merge(templnode,am);
                                Swig_symbol_setscope(st);
				Swig_extend_append_previous(templnode,am);
                                Delattr(Swig_extend_hash(),clsname);
                              }
			      if (stmp) Delete(stmp);
                            }

                            /* Add to classes hash */
			    if (!classes)
			      classes = NewHash();

			    if (Namespaceprefix) {
			      String *temp = NewStringf("%s::%s", Namespaceprefix, Getattr(templnode,"name"));
			      Setattr(classes,temp,templnode);
			      Delete(temp);
			    } else {
			      String *qs = Swig_symbol_qualifiedscopename(templnode);
			      Setattr(classes, qs,templnode);
			      Delete(qs);
			    }
                          }
                        }

                        /* all the overloaded templated functions are added into a linked list */
                        if (!linkliststart)
                          linkliststart = templnode;
                        if (nscope_inner) {
                          /* non-global namespace */
                          if (templnode) {
                            appendChild(nscope_inner,templnode);
			    Delete(templnode);
                            if (nscope) (yyval.node) = nscope;
                          }
                        } else {
                          /* global namespace */
                          if (!linklistend) {
                            (yyval.node) = templnode;
                          } else {
                            set_nextSibling(linklistend,templnode);
			    Delete(templnode);
                          }
                          linklistend = templnode;
                        }
                      }
                      nn = Getattr(nn,"sym:nextSibling"); /* repeat for overloaded templated functions. If a templated class there will never be a sibling. */
                    }
                    update_defaultargs(linkliststart);
                    update_abstracts(linkliststart);
		  }
	          Swig_symbol_setscope(tscope);
		  Delete(Namespaceprefix);
		  Namespaceprefix = Swig_symbol_qualifiedscopename(0);
                }
    break;

  case 115:

    {
		  Swig_warning(0,cparse_file, cparse_line,"%s\n", (yyvsp[(2) - (2)].str));
		  (yyval.node) = 0;
               }
    break;

  case 116:

    {
                    (yyval.node) = (yyvsp[(1) - (1)].node); 
                    if ((yyval.node)) {
   		      add_symbols((yyval.node));
                      default_arguments((yyval.node));
   	            }
                }
    break;

  case 117:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 118:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 119:

    {
		  if (Strcmp((yyvsp[(2) - (3)].str),"C") == 0) {
		    cparse_externc = 1;
		  }
		}
    break;

  case 120:

    {
		  cparse_externc = 0;
		  if (Strcmp((yyvsp[(2) - (6)].str),"C") == 0) {
		    Node *n = firstChild((yyvsp[(5) - (6)].node));
		    (yyval.node) = new_node("extern");
		    Setattr((yyval.node),"name",(yyvsp[(2) - (6)].str));
		    appendChild((yyval.node),n);
		    while (n) {
		      SwigType *decl = Getattr(n,"decl");
		      if (SwigType_isfunction(decl) && !Equal(Getattr(n, "storage"), "typedef")) {
			Setattr(n,"storage","externc");
		      }
		      n = nextSibling(n);
		    }
		  } else {
		     Swig_warning(WARN_PARSE_UNDEFINED_EXTERN,cparse_file, cparse_line,"Unrecognized extern type \"%s\".\n", (yyvsp[(2) - (6)].str));
		    (yyval.node) = new_node("extern");
		    Setattr((yyval.node),"name",(yyvsp[(2) - (6)].str));
		    appendChild((yyval.node),firstChild((yyvsp[(5) - (6)].node)));
		  }
                }
    break;

  case 121:

    {
		  (yyval.node) = (yyvsp[(1) - (1)].node);
		  SWIG_WARN_NODE_BEGIN((yyval.node));
		  Swig_warning(WARN_CPP11_LAMBDA, cparse_file, cparse_line, "Lambda expressions and closures are not fully supported yet.\n");
		  SWIG_WARN_NODE_END((yyval.node));
		}
    break;

  case 122:

    {
		  /* Convert using statement to a typedef statement */
		  (yyval.node) = new_node("cdecl");
		  Setattr((yyval.node),"type",(yyvsp[(4) - (6)].type));
		  Setattr((yyval.node),"storage","typedef");
		  Setattr((yyval.node),"name",(yyvsp[(2) - (6)].str));
		  Setattr((yyval.node),"decl",(yyvsp[(5) - (6)].decl).type);
		  SetFlag((yyval.node),"typealias");
		  add_symbols((yyval.node));
		}
    break;

  case 123:

    {
		  /* Convert alias template to a "template" typedef statement */
		  (yyval.node) = new_node("template");
		  Setattr((yyval.node),"type",(yyvsp[(8) - (10)].type));
		  Setattr((yyval.node),"storage","typedef");
		  Setattr((yyval.node),"name",(yyvsp[(6) - (10)].str));
		  Setattr((yyval.node),"decl",(yyvsp[(9) - (10)].decl).type);
		  Setattr((yyval.node),"templateparms",(yyvsp[(3) - (10)].tparms));
		  Setattr((yyval.node),"templatetype","cdecl");
		  SetFlag((yyval.node),"aliastemplate");
		  add_symbols((yyval.node));
		}
    break;

  case 124:

    {
                   (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 125:

    {
	      String *decl = (yyvsp[(3) - (6)].decl).type;
              (yyval.node) = new_node("cdecl");
	      if ((yyvsp[(4) - (6)].dtype).qualifier)
	        decl = add_qualifier_to_declarator((yyvsp[(3) - (6)].decl).type, (yyvsp[(4) - (6)].dtype).qualifier);
	      Setattr((yyval.node),"refqualifier",(yyvsp[(4) - (6)].dtype).refqualifier);
	      Setattr((yyval.node),"type",(yyvsp[(2) - (6)].type));
	      Setattr((yyval.node),"storage",(yyvsp[(1) - (6)].id));
	      Setattr((yyval.node),"name",(yyvsp[(3) - (6)].decl).id);
	      Setattr((yyval.node),"decl",decl);
	      Setattr((yyval.node),"parms",(yyvsp[(3) - (6)].decl).parms);
	      Setattr((yyval.node),"value",(yyvsp[(5) - (6)].dtype).val);
	      Setattr((yyval.node),"throws",(yyvsp[(4) - (6)].dtype).throws);
	      Setattr((yyval.node),"throw",(yyvsp[(4) - (6)].dtype).throwf);
	      Setattr((yyval.node),"noexcept",(yyvsp[(4) - (6)].dtype).nexcept);
	      Setattr((yyval.node),"final",(yyvsp[(4) - (6)].dtype).final);
	      if ((yyvsp[(5) - (6)].dtype).val && (yyvsp[(5) - (6)].dtype).type) {
		/* store initializer type as it might be different to the declared type */
		SwigType *valuetype = NewSwigType((yyvsp[(5) - (6)].dtype).type);
		if (Len(valuetype) > 0)
		  Setattr((yyval.node),"valuetype",valuetype);
		else
		  Delete(valuetype);
	      }
	      if (!(yyvsp[(6) - (6)].node)) {
		if (Len(scanner_ccode)) {
		  String *code = Copy(scanner_ccode);
		  Setattr((yyval.node),"code",code);
		  Delete(code);
		}
	      } else {
		Node *n = (yyvsp[(6) - (6)].node);
		/* Inherit attributes */
		while (n) {
		  String *type = Copy((yyvsp[(2) - (6)].type));
		  Setattr(n,"type",type);
		  Setattr(n,"storage",(yyvsp[(1) - (6)].id));
		  n = nextSibling(n);
		  Delete(type);
		}
	      }
	      if ((yyvsp[(5) - (6)].dtype).bitfield) {
		Setattr((yyval.node),"bitfield", (yyvsp[(5) - (6)].dtype).bitfield);
	      }

	      if ((yyvsp[(3) - (6)].decl).id) {
		/* Look for "::" declarations (ignored) */
		if (Strstr((yyvsp[(3) - (6)].decl).id, "::")) {
		  /* This is a special case. If the scope name of the declaration exactly
		     matches that of the declaration, then we will allow it. Otherwise, delete. */
		  String *p = Swig_scopename_prefix((yyvsp[(3) - (6)].decl).id);
		  if (p) {
		    if ((Namespaceprefix && Strcmp(p, Namespaceprefix) == 0) ||
			(Classprefix && Strcmp(p, Classprefix) == 0)) {
		      String *lstr = Swig_scopename_last((yyvsp[(3) - (6)].decl).id);
		      Setattr((yyval.node), "name", lstr);
		      Delete(lstr);
		      set_nextSibling((yyval.node), (yyvsp[(6) - (6)].node));
		    } else {
		      Delete((yyval.node));
		      (yyval.node) = (yyvsp[(6) - (6)].node);
		    }
		    Delete(p);
		  } else {
		    Delete((yyval.node));
		    (yyval.node) = (yyvsp[(6) - (6)].node);
		  }
		} else {
		  set_nextSibling((yyval.node), (yyvsp[(6) - (6)].node));
		}
	      } else {
		Swig_error(cparse_file, cparse_line, "Missing symbol name for global declaration\n");
		(yyval.node) = 0;
	      }

	      if ((yyvsp[(4) - (6)].dtype).qualifier && (yyvsp[(1) - (6)].id) && Strstr((yyvsp[(1) - (6)].id), "static"))
		Swig_error(cparse_file, cparse_line, "Static function %s cannot have a qualifier.\n", Swig_name_decl((yyval.node)));
           }
    break;

  case 126:

    {
              (yyval.node) = new_node("cdecl");
	      if ((yyvsp[(4) - (9)].dtype).qualifier) SwigType_push((yyvsp[(3) - (9)].decl).type, (yyvsp[(4) - (9)].dtype).qualifier);
	      Setattr((yyval.node),"refqualifier",(yyvsp[(4) - (9)].dtype).refqualifier);
	      Setattr((yyval.node),"type",(yyvsp[(6) - (9)].node));
	      Setattr((yyval.node),"storage",(yyvsp[(1) - (9)].id));
	      Setattr((yyval.node),"name",(yyvsp[(3) - (9)].decl).id);
	      Setattr((yyval.node),"decl",(yyvsp[(3) - (9)].decl).type);
	      Setattr((yyval.node),"parms",(yyvsp[(3) - (9)].decl).parms);
	      Setattr((yyval.node),"value",(yyvsp[(4) - (9)].dtype).val);
	      Setattr((yyval.node),"throws",(yyvsp[(4) - (9)].dtype).throws);
	      Setattr((yyval.node),"throw",(yyvsp[(4) - (9)].dtype).throwf);
	      Setattr((yyval.node),"noexcept",(yyvsp[(4) - (9)].dtype).nexcept);
	      Setattr((yyval.node),"final",(yyvsp[(4) - (9)].dtype).final);
	      if (!(yyvsp[(9) - (9)].node)) {
		if (Len(scanner_ccode)) {
		  String *code = Copy(scanner_ccode);
		  Setattr((yyval.node),"code",code);
		  Delete(code);
		}
	      } else {
		Node *n = (yyvsp[(9) - (9)].node);
		while (n) {
		  String *type = Copy((yyvsp[(6) - (9)].node));
		  Setattr(n,"type",type);
		  Setattr(n,"storage",(yyvsp[(1) - (9)].id));
		  n = nextSibling(n);
		  Delete(type);
		}
	      }
	      if ((yyvsp[(4) - (9)].dtype).bitfield) {
		Setattr((yyval.node),"bitfield", (yyvsp[(4) - (9)].dtype).bitfield);
	      }

	      if (Strstr((yyvsp[(3) - (9)].decl).id,"::")) {
                String *p = Swig_scopename_prefix((yyvsp[(3) - (9)].decl).id);
		if (p) {
		  if ((Namespaceprefix && Strcmp(p, Namespaceprefix) == 0) ||
		      (Classprefix && Strcmp(p, Classprefix) == 0)) {
		    String *lstr = Swig_scopename_last((yyvsp[(3) - (9)].decl).id);
		    Setattr((yyval.node),"name",lstr);
		    Delete(lstr);
		    set_nextSibling((yyval.node), (yyvsp[(9) - (9)].node));
		  } else {
		    Delete((yyval.node));
		    (yyval.node) = (yyvsp[(9) - (9)].node);
		  }
		  Delete(p);
		} else {
		  Delete((yyval.node));
		  (yyval.node) = (yyvsp[(9) - (9)].node);
		}
	      } else {
		set_nextSibling((yyval.node), (yyvsp[(9) - (9)].node));
	      }

	      if ((yyvsp[(4) - (9)].dtype).qualifier && (yyvsp[(1) - (9)].id) && Strstr((yyvsp[(1) - (9)].id), "static"))
		Swig_error(cparse_file, cparse_line, "Static function %s cannot have a qualifier.\n", Swig_name_decl((yyval.node)));
           }
    break;

  case 127:

    { 
                   (yyval.node) = 0;
                   Clear(scanner_ccode); 
               }
    break;

  case 128:

    {
		 (yyval.node) = new_node("cdecl");
		 if ((yyvsp[(3) - (5)].dtype).qualifier) SwigType_push((yyvsp[(2) - (5)].decl).type,(yyvsp[(3) - (5)].dtype).qualifier);
		 Setattr((yyval.node),"refqualifier",(yyvsp[(3) - (5)].dtype).refqualifier);
		 Setattr((yyval.node),"name",(yyvsp[(2) - (5)].decl).id);
		 Setattr((yyval.node),"decl",(yyvsp[(2) - (5)].decl).type);
		 Setattr((yyval.node),"parms",(yyvsp[(2) - (5)].decl).parms);
		 Setattr((yyval.node),"value",(yyvsp[(4) - (5)].dtype).val);
		 Setattr((yyval.node),"throws",(yyvsp[(3) - (5)].dtype).throws);
		 Setattr((yyval.node),"throw",(yyvsp[(3) - (5)].dtype).throwf);
		 Setattr((yyval.node),"noexcept",(yyvsp[(3) - (5)].dtype).nexcept);
		 Setattr((yyval.node),"final",(yyvsp[(3) - (5)].dtype).final);
		 if ((yyvsp[(4) - (5)].dtype).bitfield) {
		   Setattr((yyval.node),"bitfield", (yyvsp[(4) - (5)].dtype).bitfield);
		 }
		 if (!(yyvsp[(5) - (5)].node)) {
		   if (Len(scanner_ccode)) {
		     String *code = Copy(scanner_ccode);
		     Setattr((yyval.node),"code",code);
		     Delete(code);
		   }
		 } else {
		   set_nextSibling((yyval.node), (yyvsp[(5) - (5)].node));
		 }
	       }
    break;

  case 129:

    { 
                   skip_balanced('{','}');
                   (yyval.node) = 0;
               }
    break;

  case 130:

    {
		   (yyval.node) = 0;
		   if (yychar == RPAREN) {
		       Swig_error(cparse_file, cparse_line, "Unexpected ')'.\n");
		   } else {
		       Swig_error(cparse_file, cparse_line, "Syntax error - possibly a missing semicolon.\n");
		   }
		   exit(1);
               }
    break;

  case 131:

    {
                   (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
              }
    break;

  case 132:

    { (yyval.node) = (yyvsp[(1) - (1)].type); }
    break;

  case 133:

    { (yyval.node) = (yyvsp[(1) - (1)].type); }
    break;

  case 134:

    { (yyval.node) = (yyvsp[(1) - (1)].type); }
    break;

  case 135:

    { (yyval.node) = (yyvsp[(1) - (1)].type); }
    break;

  case 136:

    { (yyval.node) = (yyvsp[(1) - (1)].str); }
    break;

  case 137:

    { (yyval.node) = (yyvsp[(1) - (1)].type); }
    break;

  case 138:

    {
		  (yyval.node) = new_node("lambda");
		  Setattr((yyval.node),"name",(yyvsp[(3) - (11)].str));
		  add_symbols((yyval.node));
	        }
    break;

  case 139:

    {
		  (yyval.node) = new_node("lambda");
		  Setattr((yyval.node),"name",(yyvsp[(3) - (13)].str));
		  add_symbols((yyval.node));
		}
    break;

  case 140:

    {
		  (yyval.node) = new_node("lambda");
		  Setattr((yyval.node),"name",(yyvsp[(3) - (7)].str));
		  add_symbols((yyval.node));
		}
    break;

  case 141:

    {
		  skip_balanced('[',']');
		  (yyval.node) = 0;
	        }
    break;

  case 142:

    {
		  skip_balanced('{','}');
		  (yyval.node) = 0;
		}
    break;

  case 143:

    {
		  (yyval.pl) = 0;
		}
    break;

  case 144:

    {
		  skip_balanced('(',')');
		}
    break;

  case 145:

    {
		  (yyval.pl) = 0;
		}
    break;

  case 146:

    {
		   (yyval.node) = (char *)"enum";
	      }
    break;

  case 147:

    {
		   (yyval.node) = (char *)"enum class";
	      }
    break;

  case 148:

    {
		   (yyval.node) = (char *)"enum struct";
	      }
    break;

  case 149:

    {
                   (yyval.node) = (yyvsp[(2) - (2)].type);
              }
    break;

  case 150:

    { (yyval.node) = 0; }
    break;

  case 151:

    {
		   SwigType *ty = 0;
		   int scopedenum = (yyvsp[(3) - (5)].id) && !Equal((yyvsp[(2) - (5)].node), "enum");
		   (yyval.node) = new_node("enumforward");
		   ty = NewStringf("enum %s", (yyvsp[(3) - (5)].id));
		   Setattr((yyval.node),"enumkey",(yyvsp[(2) - (5)].node));
		   if (scopedenum)
		     SetFlag((yyval.node), "scopedenum");
		   Setattr((yyval.node),"name",(yyvsp[(3) - (5)].id));
		   Setattr((yyval.node),"inherit",(yyvsp[(4) - (5)].node));
		   Setattr((yyval.node),"type",ty);
		   Setattr((yyval.node),"sym:weak", "1");
		   add_symbols((yyval.node));
	      }
    break;

  case 152:

    {
		  SwigType *ty = 0;
		  int scopedenum = (yyvsp[(3) - (8)].id) && !Equal((yyvsp[(2) - (8)].node), "enum");
                  (yyval.node) = new_node("enum");
		  ty = NewStringf("enum %s", (yyvsp[(3) - (8)].id));
		  Setattr((yyval.node),"enumkey",(yyvsp[(2) - (8)].node));
		  if (scopedenum)
		    SetFlag((yyval.node), "scopedenum");
		  Setattr((yyval.node),"name",(yyvsp[(3) - (8)].id));
		  Setattr((yyval.node),"inherit",(yyvsp[(4) - (8)].node));
		  Setattr((yyval.node),"type",ty);
		  appendChild((yyval.node),(yyvsp[(6) - (8)].node));
		  add_symbols((yyval.node));      /* Add to tag space */

		  if (scopedenum) {
		    Swig_symbol_newscope();
		    Swig_symbol_setscopename((yyvsp[(3) - (8)].id));
		    Delete(Namespaceprefix);
		    Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		  }

		  add_symbols((yyvsp[(6) - (8)].node));      /* Add enum values to appropriate enum or enum class scope */

		  if (scopedenum) {
		    Setattr((yyval.node),"symtab", Swig_symbol_popscope());
		    Delete(Namespaceprefix);
		    Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		  }
               }
    break;

  case 153:

    {
		 Node *n;
		 SwigType *ty = 0;
		 String   *unnamed = 0;
		 int       unnamedinstance = 0;
		 int scopedenum = (yyvsp[(3) - (11)].id) && !Equal((yyvsp[(2) - (11)].node), "enum");

		 (yyval.node) = new_node("enum");
		 Setattr((yyval.node),"enumkey",(yyvsp[(2) - (11)].node));
		 if (scopedenum)
		   SetFlag((yyval.node), "scopedenum");
		 Setattr((yyval.node),"inherit",(yyvsp[(4) - (11)].node));
		 if ((yyvsp[(3) - (11)].id)) {
		   Setattr((yyval.node),"name",(yyvsp[(3) - (11)].id));
		   ty = NewStringf("enum %s", (yyvsp[(3) - (11)].id));
		 } else if ((yyvsp[(8) - (11)].decl).id) {
		   unnamed = make_unnamed();
		   ty = NewStringf("enum %s", unnamed);
		   Setattr((yyval.node),"unnamed",unnamed);
                   /* name is not set for unnamed enum instances, e.g. enum { foo } Instance; */
		   if ((yyvsp[(1) - (11)].id) && Cmp((yyvsp[(1) - (11)].id),"typedef") == 0) {
		     Setattr((yyval.node),"name",(yyvsp[(8) - (11)].decl).id);
                   } else {
                     unnamedinstance = 1;
                   }
		   Setattr((yyval.node),"storage",(yyvsp[(1) - (11)].id));
		 }
		 if ((yyvsp[(8) - (11)].decl).id && Cmp((yyvsp[(1) - (11)].id),"typedef") == 0) {
		   Setattr((yyval.node),"tdname",(yyvsp[(8) - (11)].decl).id);
                   Setattr((yyval.node),"allows_typedef","1");
                 }
		 appendChild((yyval.node),(yyvsp[(6) - (11)].node));
		 n = new_node("cdecl");
		 Setattr(n,"type",ty);
		 Setattr(n,"name",(yyvsp[(8) - (11)].decl).id);
		 Setattr(n,"storage",(yyvsp[(1) - (11)].id));
		 Setattr(n,"decl",(yyvsp[(8) - (11)].decl).type);
		 Setattr(n,"parms",(yyvsp[(8) - (11)].decl).parms);
		 Setattr(n,"unnamed",unnamed);

                 if (unnamedinstance) {
		   SwigType *cty = NewString("enum ");
		   Setattr((yyval.node),"type",cty);
		   SetFlag((yyval.node),"unnamedinstance");
		   SetFlag(n,"unnamedinstance");
		   Delete(cty);
                 }
		 if ((yyvsp[(11) - (11)].node)) {
		   Node *p = (yyvsp[(11) - (11)].node);
		   set_nextSibling(n,p);
		   while (p) {
		     SwigType *cty = Copy(ty);
		     Setattr(p,"type",cty);
		     Setattr(p,"unnamed",unnamed);
		     Setattr(p,"storage",(yyvsp[(1) - (11)].id));
		     Delete(cty);
		     p = nextSibling(p);
		   }
		 } else {
		   if (Len(scanner_ccode)) {
		     String *code = Copy(scanner_ccode);
		     Setattr(n,"code",code);
		     Delete(code);
		   }
		 }

                 /* Ensure that typedef enum ABC {foo} XYZ; uses XYZ for sym:name, like structs.
                  * Note that class_rename/yyrename are bit of a mess so used this simple approach to change the name. */
                 if ((yyvsp[(8) - (11)].decl).id && (yyvsp[(3) - (11)].id) && Cmp((yyvsp[(1) - (11)].id),"typedef") == 0) {
		   String *name = NewString((yyvsp[(8) - (11)].decl).id);
                   Setattr((yyval.node), "parser:makename", name);
		   Delete(name);
                 }

		 add_symbols((yyval.node));       /* Add enum to tag space */
		 set_nextSibling((yyval.node),n);
		 Delete(n);

		 if (scopedenum) {
		   Swig_symbol_newscope();
		   Swig_symbol_setscopename((yyvsp[(3) - (11)].id));
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		 }

		 add_symbols((yyvsp[(6) - (11)].node));      /* Add enum values to appropriate enum or enum class scope */

		 if (scopedenum) {
		   Setattr((yyval.node),"symtab", Swig_symbol_popscope());
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		 }

	         add_symbols(n);
		 Delete(unnamed);
	       }
    break;

  case 154:

    {
                   /* This is a sick hack.  If the ctor_end has parameters,
                      and the parms parameter only has 1 parameter, this
                      could be a declaration of the form:

                         type (id)(parms)

			 Otherwise it's an error. */
                    int err = 0;
                    (yyval.node) = 0;

		    if ((ParmList_len((yyvsp[(4) - (6)].pl)) == 1) && (!Swig_scopename_check((yyvsp[(2) - (6)].type)))) {
		      SwigType *ty = Getattr((yyvsp[(4) - (6)].pl),"type");
		      String *name = Getattr((yyvsp[(4) - (6)].pl),"name");
		      err = 1;
		      if (!name) {
			(yyval.node) = new_node("cdecl");
			Setattr((yyval.node),"type",(yyvsp[(2) - (6)].type));
			Setattr((yyval.node),"storage",(yyvsp[(1) - (6)].id));
			Setattr((yyval.node),"name",ty);

			if ((yyvsp[(6) - (6)].decl).have_parms) {
			  SwigType *decl = NewStringEmpty();
			  SwigType_add_function(decl,(yyvsp[(6) - (6)].decl).parms);
			  Setattr((yyval.node),"decl",decl);
			  Setattr((yyval.node),"parms",(yyvsp[(6) - (6)].decl).parms);
			  if (Len(scanner_ccode)) {
			    String *code = Copy(scanner_ccode);
			    Setattr((yyval.node),"code",code);
			    Delete(code);
			  }
			}
			if ((yyvsp[(6) - (6)].decl).defarg) {
			  Setattr((yyval.node),"value",(yyvsp[(6) - (6)].decl).defarg);
			}
			Setattr((yyval.node),"throws",(yyvsp[(6) - (6)].decl).throws);
			Setattr((yyval.node),"throw",(yyvsp[(6) - (6)].decl).throwf);
			Setattr((yyval.node),"noexcept",(yyvsp[(6) - (6)].decl).nexcept);
			Setattr((yyval.node),"final",(yyvsp[(6) - (6)].decl).final);
			err = 0;
		      }
		    }
		    if (err) {
		      Swig_error(cparse_file,cparse_line,"Syntax error in input(2).\n");
		      exit(1);
		    }
                }
    break;

  case 155:

    {  (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 156:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 157:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 158:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 159:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 160:

    { (yyval.node) = 0; }
    break;

  case 161:

    {
                   String *prefix;
                   List *bases = 0;
		   Node *scope = 0;
		   String *code;
		   (yyval.node) = new_node("class");
		   Setline((yyval.node),cparse_start_line);
		   Setattr((yyval.node),"kind",(yyvsp[(2) - (5)].id));
		   if ((yyvsp[(4) - (5)].bases)) {
		     Setattr((yyval.node),"baselist", Getattr((yyvsp[(4) - (5)].bases),"public"));
		     Setattr((yyval.node),"protectedbaselist", Getattr((yyvsp[(4) - (5)].bases),"protected"));
		     Setattr((yyval.node),"privatebaselist", Getattr((yyvsp[(4) - (5)].bases),"private"));
		   }
		   Setattr((yyval.node),"allows_typedef","1");

		   /* preserve the current scope */
		   Setattr((yyval.node),"prev_symtab",Swig_symbol_current());
		  
		   /* If the class name is qualified.  We need to create or lookup namespace/scope entries */
		   scope = resolve_create_node_scope((yyvsp[(3) - (5)].str), 1);
		   /* save nscope_inner to the class - it may be overwritten in nested classes*/
		   Setattr((yyval.node), "nested:innerscope", nscope_inner);
		   Setattr((yyval.node), "nested:nscope", nscope);
		   Setfile(scope,cparse_file);
		   Setline(scope,cparse_line);
		   (yyvsp[(3) - (5)].str) = scope;
		   Setattr((yyval.node),"name",(yyvsp[(3) - (5)].str));

		   if (currentOuterClass) {
		     SetFlag((yyval.node), "nested");
		     Setattr((yyval.node), "nested:outer", currentOuterClass);
		     set_access_mode((yyval.node));
		   }
		   Swig_features_get(Swig_cparse_features(), Namespaceprefix, Getattr((yyval.node), "name"), 0, (yyval.node));
		   /* save yyrename to the class attribute, to be used later in add_symbols()*/
		   Setattr((yyval.node), "class_rename", make_name((yyval.node), (yyvsp[(3) - (5)].str), 0));
		   Setattr((yyval.node), "Classprefix", (yyvsp[(3) - (5)].str));
		   Classprefix = NewString((yyvsp[(3) - (5)].str));
		   /* Deal with inheritance  */
		   if ((yyvsp[(4) - (5)].bases))
		     bases = Swig_make_inherit_list((yyvsp[(3) - (5)].str),Getattr((yyvsp[(4) - (5)].bases),"public"),Namespaceprefix);
		   prefix = SwigType_istemplate_templateprefix((yyvsp[(3) - (5)].str));
		   if (prefix) {
		     String *fbase, *tbase;
		     if (Namespaceprefix) {
		       fbase = NewStringf("%s::%s", Namespaceprefix,(yyvsp[(3) - (5)].str));
		       tbase = NewStringf("%s::%s", Namespaceprefix, prefix);
		     } else {
		       fbase = Copy((yyvsp[(3) - (5)].str));
		       tbase = Copy(prefix);
		     }
		     Swig_name_inherit(tbase,fbase);
		     Delete(fbase);
		     Delete(tbase);
		   }
                   if (strcmp((yyvsp[(2) - (5)].id),"class") == 0) {
		     cplus_mode = CPLUS_PRIVATE;
		   } else {
		     cplus_mode = CPLUS_PUBLIC;
		   }
		   if (!cparse_cplusplus) {
		     set_scope_to_global();
		   }
		   Swig_symbol_newscope();
		   Swig_symbol_setscopename((yyvsp[(3) - (5)].str));
		   Swig_inherit_base_symbols(bases);
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		   cparse_start_line = cparse_line;

		   /* If there are active template parameters, we need to make sure they are
                      placed in the class symbol table so we can catch shadows */

		   if (template_parameters) {
		     Parm *tp = template_parameters;
		     while(tp) {
		       String *tpname = Copy(Getattr(tp,"name"));
		       Node *tn = new_node("templateparm");
		       Setattr(tn,"name",tpname);
		       Swig_symbol_cadd(tpname,tn);
		       tp = nextSibling(tp);
		       Delete(tpname);
		     }
		   }
		   Delete(prefix);
		   inclass = 1;
		   currentOuterClass = (yyval.node);
		   if (cparse_cplusplusout) {
		     /* save the structure declaration to declare it in global scope for C++ to see */
		     code = get_raw_text_balanced('{', '}');
		     Setattr((yyval.node), "code", code);
		     Delete(code);
		   }
               }
    break;

  case 162:

    {
		   Node *p;
		   SwigType *ty;
		   Symtab *cscope;
		   Node *am = 0;
		   String *scpname = 0;
		   (void) (yyvsp[(6) - (9)].node);
		   (yyval.node) = currentOuterClass;
		   currentOuterClass = Getattr((yyval.node), "nested:outer");
		   nscope_inner = Getattr((yyval.node), "nested:innerscope");
		   nscope = Getattr((yyval.node), "nested:nscope");
		   Delattr((yyval.node), "nested:innerscope");
		   Delattr((yyval.node), "nested:nscope");
		   if (nscope_inner && Strcmp(nodeType(nscope_inner), "class") == 0) { /* actual parent class for this class */
		     Node* forward_declaration = Swig_symbol_clookup_no_inherit(Getattr((yyval.node),"name"), Getattr(nscope_inner, "symtab"));
		     if (forward_declaration) {
		       Setattr((yyval.node), "access", Getattr(forward_declaration, "access"));
		     }
		     Setattr((yyval.node), "nested:outer", nscope_inner);
		     SetFlag((yyval.node), "nested");
                   }
		   if (!currentOuterClass)
		     inclass = 0;
		   cscope = Getattr((yyval.node), "prev_symtab");
		   Delattr((yyval.node), "prev_symtab");
		   
		   /* Check for pure-abstract class */
		   Setattr((yyval.node),"abstracts", pure_abstracts((yyvsp[(7) - (9)].node)));
		   
		   /* This bit of code merges in a previously defined %extend directive (if any) */
		   {
		     String *clsname = Swig_symbol_qualifiedscopename(0);
		     am = Getattr(Swig_extend_hash(), clsname);
		     if (am) {
		       Swig_extend_merge((yyval.node), am);
		       Delattr(Swig_extend_hash(), clsname);
		     }
		     Delete(clsname);
		   }
		   if (!classes) classes = NewHash();
		   scpname = Swig_symbol_qualifiedscopename(0);
		   Setattr(classes, scpname, (yyval.node));

		   appendChild((yyval.node), (yyvsp[(7) - (9)].node));
		   
		   if (am) 
		     Swig_extend_append_previous((yyval.node), am);

		   p = (yyvsp[(9) - (9)].node);
		   if (p && !nscope_inner) {
		     if (!cparse_cplusplus && currentOuterClass)
		       appendChild(currentOuterClass, p);
		     else
		      appendSibling((yyval.node), p);
		   }
		   
		   if (nscope_inner) {
		     ty = NewString(scpname); /* if the class is declared out of scope, let the declarator use fully qualified type*/
		   } else if (cparse_cplusplus && !cparse_externc) {
		     ty = NewString((yyvsp[(3) - (9)].str));
		   } else {
		     ty = NewStringf("%s %s", (yyvsp[(2) - (9)].id), (yyvsp[(3) - (9)].str));
		   }
		   while (p) {
		     Setattr(p, "storage", (yyvsp[(1) - (9)].id));
		     Setattr(p, "type" ,ty);
		     if (!cparse_cplusplus && currentOuterClass && (!Getattr(currentOuterClass, "name"))) {
		       SetFlag(p, "hasconsttype");
		       SetFlag(p, "feature:immutable");
		     }
		     p = nextSibling(p);
		   }
		   if ((yyvsp[(9) - (9)].node) && Cmp((yyvsp[(1) - (9)].id),"typedef") == 0)
		     add_typedef_name((yyval.node), (yyvsp[(9) - (9)].node), (yyvsp[(3) - (9)].str), cscope, scpname);
		   Delete(scpname);

		   if (cplus_mode != CPLUS_PUBLIC) {
		   /* we 'open' the class at the end, to allow %template
		      to add new members */
		     Node *pa = new_node("access");
		     Setattr(pa, "kind", "public");
		     cplus_mode = CPLUS_PUBLIC;
		     appendChild((yyval.node), pa);
		     Delete(pa);
		   }
		   if (currentOuterClass)
		     restore_access_mode((yyval.node));
		   Setattr((yyval.node), "symtab", Swig_symbol_popscope());
		   Classprefix = Getattr((yyval.node), "Classprefix");
		   Delattr((yyval.node), "Classprefix");
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		   if (cplus_mode == CPLUS_PRIVATE) {
		     (yyval.node) = 0; /* skip private nested classes */
		   } else if (cparse_cplusplus && currentOuterClass && ignore_nested_classes && !GetFlag((yyval.node), "feature:flatnested")) {
		     (yyval.node) = nested_forward_declaration((yyvsp[(1) - (9)].id), (yyvsp[(2) - (9)].id), (yyvsp[(3) - (9)].str), Copy((yyvsp[(3) - (9)].str)), (yyvsp[(9) - (9)].node));
		   } else if (nscope_inner) {
		     /* this is tricky */
		     /* we add the declaration in the original namespace */
		     if (Strcmp(nodeType(nscope_inner), "class") == 0 && cparse_cplusplus && ignore_nested_classes && !GetFlag((yyval.node), "feature:flatnested"))
		       (yyval.node) = nested_forward_declaration((yyvsp[(1) - (9)].id), (yyvsp[(2) - (9)].id), (yyvsp[(3) - (9)].str), Copy((yyvsp[(3) - (9)].str)), (yyvsp[(9) - (9)].node));
		     appendChild(nscope_inner, (yyval.node));
		     Swig_symbol_setscope(Getattr(nscope_inner, "symtab"));
		     Delete(Namespaceprefix);
		     Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		     yyrename = Copy(Getattr((yyval.node), "class_rename"));
		     add_symbols((yyval.node));
		     Delattr((yyval.node), "class_rename");
		     /* but the variable definition in the current scope */
		     Swig_symbol_setscope(cscope);
		     Delete(Namespaceprefix);
		     Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		     add_symbols((yyvsp[(9) - (9)].node));
		     if (nscope) {
		       (yyval.node) = nscope; /* here we return recreated namespace tower instead of the class itself */
		       if ((yyvsp[(9) - (9)].node)) {
			 appendSibling((yyval.node), (yyvsp[(9) - (9)].node));
		       }
		     } else if (!SwigType_istemplate(ty) && template_parameters == 0) { /* for template we need the class itself */
		       (yyval.node) = (yyvsp[(9) - (9)].node);
		     }
		   } else {
		     Delete(yyrename);
		     yyrename = 0;
		     if (!cparse_cplusplus && currentOuterClass) { /* nested C structs go into global scope*/
		       Node *outer = currentOuterClass;
		       while (Getattr(outer, "nested:outer"))
			 outer = Getattr(outer, "nested:outer");
		       appendSibling(outer, (yyval.node));
		       Swig_symbol_setscope(cscope); /* declaration goes in the parent scope */
		       add_symbols((yyvsp[(9) - (9)].node));
		       set_scope_to_global();
		       Delete(Namespaceprefix);
		       Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		       yyrename = Copy(Getattr((yyval.node), "class_rename"));
		       add_symbols((yyval.node));
		       if (!cparse_cplusplusout)
			 Delattr((yyval.node), "nested:outer");
		       Delattr((yyval.node), "class_rename");
		       (yyval.node) = 0;
		     } else {
		       yyrename = Copy(Getattr((yyval.node), "class_rename"));
		       add_symbols((yyval.node));
		       add_symbols((yyvsp[(9) - (9)].node));
		       Delattr((yyval.node), "class_rename");
		     }
		   }
		   Delete(ty);
		   Swig_symbol_setscope(cscope);
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		   Classprefix = currentOuterClass ? Getattr(currentOuterClass, "Classprefix") : 0;
	       }
    break;

  case 163:

    {
	       String *unnamed;
	       String *code;
	       unnamed = make_unnamed();
	       (yyval.node) = new_node("class");
	       Setline((yyval.node),cparse_start_line);
	       Setattr((yyval.node),"kind",(yyvsp[(2) - (4)].id));
	       if ((yyvsp[(3) - (4)].bases)) {
		 Setattr((yyval.node),"baselist", Getattr((yyvsp[(3) - (4)].bases),"public"));
		 Setattr((yyval.node),"protectedbaselist", Getattr((yyvsp[(3) - (4)].bases),"protected"));
		 Setattr((yyval.node),"privatebaselist", Getattr((yyvsp[(3) - (4)].bases),"private"));
	       }
	       Setattr((yyval.node),"storage",(yyvsp[(1) - (4)].id));
	       Setattr((yyval.node),"unnamed",unnamed);
	       Setattr((yyval.node),"allows_typedef","1");
	       if (currentOuterClass) {
		 SetFlag((yyval.node), "nested");
		 Setattr((yyval.node), "nested:outer", currentOuterClass);
		 set_access_mode((yyval.node));
	       }
	       Swig_features_get(Swig_cparse_features(), Namespaceprefix, 0, 0, (yyval.node));
	       /* save yyrename to the class attribute, to be used later in add_symbols()*/
	       Setattr((yyval.node), "class_rename", make_name((yyval.node),0,0));
	       if (strcmp((yyvsp[(2) - (4)].id),"class") == 0) {
		 cplus_mode = CPLUS_PRIVATE;
	       } else {
		 cplus_mode = CPLUS_PUBLIC;
	       }
	       Swig_symbol_newscope();
	       cparse_start_line = cparse_line;
	       currentOuterClass = (yyval.node);
	       inclass = 1;
	       Classprefix = 0;
	       Delete(Namespaceprefix);
	       Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	       /* save the structure declaration to make a typedef for it later*/
	       code = get_raw_text_balanced('{', '}');
	       Setattr((yyval.node), "code", code);
	       Delete(code);
	     }
    break;

  case 164:

    {
	       String *unnamed;
               List *bases = 0;
	       String *name = 0;
	       Node *n;
	       Classprefix = 0;
	       (void)(yyvsp[(5) - (8)].node);
	       (yyval.node) = currentOuterClass;
	       currentOuterClass = Getattr((yyval.node), "nested:outer");
	       if (!currentOuterClass)
		 inclass = 0;
	       else
		 restore_access_mode((yyval.node));
	       unnamed = Getattr((yyval.node),"unnamed");
               /* Check for pure-abstract class */
	       Setattr((yyval.node),"abstracts", pure_abstracts((yyvsp[(6) - (8)].node)));
	       n = (yyvsp[(8) - (8)].node);
	       if (cparse_cplusplus && currentOuterClass && ignore_nested_classes && !GetFlag((yyval.node), "feature:flatnested")) {
		 String *name = n ? Copy(Getattr(n, "name")) : 0;
		 (yyval.node) = nested_forward_declaration((yyvsp[(1) - (8)].id), (yyvsp[(2) - (8)].id), 0, name, n);
		 Swig_symbol_popscope();
	         Delete(Namespaceprefix);
		 Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	       } else if (n) {
	         appendSibling((yyval.node),n);
		 /* If a proper typedef name was given, we'll use it to set the scope name */
		 name = try_to_find_a_name_for_unnamed_structure((yyvsp[(1) - (8)].id), n);
		 if (name) {
		   String *scpname = 0;
		   SwigType *ty;
		   Setattr((yyval.node),"tdname",name);
		   Setattr((yyval.node),"name",name);
		   Swig_symbol_setscopename(name);
		   if ((yyvsp[(3) - (8)].bases))
		     bases = Swig_make_inherit_list(name,Getattr((yyvsp[(3) - (8)].bases),"public"),Namespaceprefix);
		   Swig_inherit_base_symbols(bases);

		     /* If a proper name was given, we use that as the typedef, not unnamed */
		   Clear(unnamed);
		   Append(unnamed, name);
		   if (cparse_cplusplus && !cparse_externc) {
		     ty = NewString(name);
		   } else {
		     ty = NewStringf("%s %s", (yyvsp[(2) - (8)].id),name);
		   }
		   while (n) {
		     Setattr(n,"storage",(yyvsp[(1) - (8)].id));
		     Setattr(n, "type", ty);
		     if (!cparse_cplusplus && currentOuterClass && (!Getattr(currentOuterClass, "name"))) {
		       SetFlag(n,"hasconsttype");
		       SetFlag(n,"feature:immutable");
		     }
		     n = nextSibling(n);
		   }
		   n = (yyvsp[(8) - (8)].node);

		   /* Check for previous extensions */
		   {
		     String *clsname = Swig_symbol_qualifiedscopename(0);
		     Node *am = Getattr(Swig_extend_hash(),clsname);
		     if (am) {
		       /* Merge the extension into the symbol table */
		       Swig_extend_merge((yyval.node),am);
		       Swig_extend_append_previous((yyval.node),am);
		       Delattr(Swig_extend_hash(),clsname);
		     }
		     Delete(clsname);
		   }
		   if (!classes) classes = NewHash();
		   scpname = Swig_symbol_qualifiedscopename(0);
		   Setattr(classes,scpname,(yyval.node));
		   Delete(scpname);
		 } else { /* no suitable name was found for a struct */
		   Setattr((yyval.node), "nested:unnamed", Getattr(n, "name")); /* save the name of the first declarator for later use in name generation*/
		   while (n) { /* attach unnamed struct to the declarators, so that they would receive proper type later*/
		     Setattr(n, "nested:unnamedtype", (yyval.node));
		     Setattr(n, "storage", (yyvsp[(1) - (8)].id));
		     n = nextSibling(n);
		   }
		   n = (yyvsp[(8) - (8)].node);
		   Swig_symbol_setscopename("<unnamed>");
		 }
		 appendChild((yyval.node),(yyvsp[(6) - (8)].node));
		 /* Pop the scope */
		 Setattr((yyval.node),"symtab",Swig_symbol_popscope());
		 if (name) {
		   Delete(yyrename);
		   yyrename = Copy(Getattr((yyval.node), "class_rename"));
		   Delete(Namespaceprefix);
		   Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		   add_symbols((yyval.node));
		   add_symbols(n);
		   Delattr((yyval.node), "class_rename");
		 }else if (cparse_cplusplus)
		   (yyval.node) = 0; /* ignore unnamed structs for C++ */
	         Delete(unnamed);
	       } else { /* unnamed struct w/o declarator*/
		 Swig_symbol_popscope();
	         Delete(Namespaceprefix);
		 Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		 add_symbols((yyvsp[(6) - (8)].node));
		 Delete((yyval.node));
		 (yyval.node) = (yyvsp[(6) - (8)].node); /* pass member list to outer class/namespace (instead of self)*/
	       }
	       Classprefix = currentOuterClass ? Getattr(currentOuterClass, "Classprefix") : 0;
              }
    break;

  case 165:

    { (yyval.node) = 0; }
    break;

  case 166:

    {
                        (yyval.node) = new_node("cdecl");
                        Setattr((yyval.node),"name",(yyvsp[(1) - (4)].decl).id);
                        Setattr((yyval.node),"decl",(yyvsp[(1) - (4)].decl).type);
                        Setattr((yyval.node),"parms",(yyvsp[(1) - (4)].decl).parms);
			set_nextSibling((yyval.node), (yyvsp[(4) - (4)].node));
                    }
    break;

  case 167:

    {
              if ((yyvsp[(1) - (4)].id) && (Strcmp((yyvsp[(1) - (4)].id),"friend") == 0)) {
		/* Ignore */
                (yyval.node) = 0; 
	      } else {
		(yyval.node) = new_node("classforward");
		Setattr((yyval.node),"kind",(yyvsp[(2) - (4)].id));
		Setattr((yyval.node),"name",(yyvsp[(3) - (4)].str));
		Setattr((yyval.node),"sym:weak", "1");
		add_symbols((yyval.node));
	      }
             }
    break;

  case 168:

    { 
		    if (currentOuterClass)
		      Setattr(currentOuterClass, "template_parameters", template_parameters);
		    template_parameters = (yyvsp[(3) - (4)].tparms); 
		    parsing_template_declaration = 1;
		  }
    break;

  case 169:

    {
			String *tname = 0;
			int     error = 0;

			/* check if we get a namespace node with a class declaration, and retrieve the class */
			Symtab *cscope = Swig_symbol_current();
			Symtab *sti = 0;
			Node *ntop = (yyvsp[(6) - (6)].node);
			Node *ni = ntop;
			SwigType *ntype = ni ? nodeType(ni) : 0;
			while (ni && Strcmp(ntype,"namespace") == 0) {
			  sti = Getattr(ni,"symtab");
			  ni = firstChild(ni);
			  ntype = nodeType(ni);
			}
			if (sti) {
			  Swig_symbol_setscope(sti);
			  Delete(Namespaceprefix);
			  Namespaceprefix = Swig_symbol_qualifiedscopename(0);
			  (yyvsp[(6) - (6)].node) = ni;
			}

			(yyval.node) = (yyvsp[(6) - (6)].node);
			if ((yyval.node)) tname = Getattr((yyval.node),"name");
			
			/* Check if the class is a template specialization */
			if (((yyval.node)) && (Strchr(tname,'<')) && (!is_operator(tname))) {
			  /* If a specialization.  Check if defined. */
			  Node *tempn = 0;
			  {
			    String *tbase = SwigType_templateprefix(tname);
			    tempn = Swig_symbol_clookup_local(tbase,0);
			    if (!tempn || (Strcmp(nodeType(tempn),"template") != 0)) {
			      SWIG_WARN_NODE_BEGIN(tempn);
			      Swig_warning(WARN_PARSE_TEMPLATE_SP_UNDEF, Getfile((yyval.node)),Getline((yyval.node)),"Specialization of non-template '%s'.\n", tbase);
			      SWIG_WARN_NODE_END(tempn);
			      tempn = 0;
			      error = 1;
			    }
			    Delete(tbase);
			  }
			  Setattr((yyval.node),"specialization","1");
			  Setattr((yyval.node),"templatetype",nodeType((yyval.node)));
			  set_nodeType((yyval.node),"template");
			  /* Template partial specialization */
			  if (tempn && ((yyvsp[(3) - (6)].tparms)) && ((yyvsp[(6) - (6)].node))) {
			    List   *tlist;
			    String *targs = SwigType_templateargs(tname);
			    tlist = SwigType_parmlist(targs);
			    /*			  Printf(stdout,"targs = '%s' %s\n", targs, tlist); */
			    if (!Getattr((yyval.node),"sym:weak")) {
			      Setattr((yyval.node),"sym:typename","1");
			    }
			    
			    if (Len(tlist) != ParmList_len(Getattr(tempn,"templateparms"))) {
			      Swig_error(Getfile((yyval.node)),Getline((yyval.node)),"Inconsistent argument count in template partial specialization. %d %d\n", Len(tlist), ParmList_len(Getattr(tempn,"templateparms")));
			      
			    } else {

			    /* This code builds the argument list for the partial template
			       specialization.  This is a little hairy, but the idea is as
			       follows:

			       $3 contains a list of arguments supplied for the template.
			       For example template<class T>.

			       tlist is a list of the specialization arguments--which may be
			       different.  For example class<int,T>.

			       tp is a copy of the arguments in the original template definition.
       
			       The patching algorithm walks through the list of supplied
			       arguments ($3), finds the position in the specialization arguments
			       (tlist), and then patches the name in the argument list of the
			       original template.
			    */

			    {
			      String *pn;
			      Parm *p, *p1;
			      int i, nargs;
			      Parm *tp = CopyParmList(Getattr(tempn,"templateparms"));
			      nargs = Len(tlist);
			      p = (yyvsp[(3) - (6)].tparms);
			      while (p) {
				for (i = 0; i < nargs; i++){
				  pn = Getattr(p,"name");
				  if (Strcmp(pn,SwigType_base(Getitem(tlist,i))) == 0) {
				    int j;
				    Parm *p1 = tp;
				    for (j = 0; j < i; j++) {
				      p1 = nextSibling(p1);
				    }
				    Setattr(p1,"name",pn);
				    Setattr(p1,"partialarg","1");
				  }
				}
				p = nextSibling(p);
			      }
			      p1 = tp;
			      i = 0;
			      while (p1) {
				if (!Getattr(p1,"partialarg")) {
				  Delattr(p1,"name");
				  Setattr(p1,"type", Getitem(tlist,i));
				} 
				i++;
				p1 = nextSibling(p1);
			      }
			      Setattr((yyval.node),"templateparms",tp);
			      Delete(tp);
			    }
  #if 0
			    /* Patch the parameter list */
			    if (tempn) {
			      Parm *p,*p1;
			      ParmList *tp = CopyParmList(Getattr(tempn,"templateparms"));
			      p = (yyvsp[(3) - (6)].tparms);
			      p1 = tp;
			      while (p && p1) {
				String *pn = Getattr(p,"name");
				Printf(stdout,"pn = '%s'\n", pn);
				if (pn) Setattr(p1,"name",pn);
				else Delattr(p1,"name");
				pn = Getattr(p,"type");
				if (pn) Setattr(p1,"type",pn);
				p = nextSibling(p);
				p1 = nextSibling(p1);
			      }
			      Setattr((yyval.node),"templateparms",tp);
			      Delete(tp);
			    } else {
			      Setattr((yyval.node),"templateparms",(yyvsp[(3) - (6)].tparms));
			    }
  #endif
			    Delattr((yyval.node),"specialization");
			    Setattr((yyval.node),"partialspecialization","1");
			    /* Create a specialized name for matching */
			    {
			      Parm *p = (yyvsp[(3) - (6)].tparms);
			      String *fname = NewString(Getattr((yyval.node),"name"));
			      String *ffname = 0;
			      ParmList *partialparms = 0;

			      char   tmp[32];
			      int    i, ilen;
			      while (p) {
				String *n = Getattr(p,"name");
				if (!n) {
				  p = nextSibling(p);
				  continue;
				}
				ilen = Len(tlist);
				for (i = 0; i < ilen; i++) {
				  if (Strstr(Getitem(tlist,i),n)) {
				    sprintf(tmp,"$%d",i+1);
				    Replaceid(fname,n,tmp);
				  }
				}
				p = nextSibling(p);
			      }
			      /* Patch argument names with typedef */
			      {
				Iterator tt;
				Parm *parm_current = 0;
				List *tparms = SwigType_parmlist(fname);
				ffname = SwigType_templateprefix(fname);
				Append(ffname,"<(");
				for (tt = First(tparms); tt.item; ) {
				  SwigType *rtt = Swig_symbol_typedef_reduce(tt.item,0);
				  SwigType *ttr = Swig_symbol_type_qualify(rtt,0);

				  Parm *newp = NewParmWithoutFileLineInfo(ttr, 0);
				  if (partialparms)
				    set_nextSibling(parm_current, newp);
				  else
				    partialparms = newp;
				  parm_current = newp;

				  Append(ffname,ttr);
				  tt = Next(tt);
				  if (tt.item) Putc(',',ffname);
				  Delete(rtt);
				  Delete(ttr);
				}
				Delete(tparms);
				Append(ffname,")>");
			      }
			      {
				Node *new_partial = NewHash();
				String *partials = Getattr(tempn,"partials");
				if (!partials) {
				  partials = NewList();
				  Setattr(tempn,"partials",partials);
				  Delete(partials);
				}
				/*			      Printf(stdout,"partial: fname = '%s', '%s'\n", fname, Swig_symbol_typedef_reduce(fname,0)); */
				Setattr(new_partial, "partialparms", partialparms);
				Setattr(new_partial, "templcsymname", ffname);
				Append(partials, new_partial);
			      }
			      Setattr((yyval.node),"partialargs",ffname);
			      Swig_symbol_cadd(ffname,(yyval.node));
			    }
			    }
			    Delete(tlist);
			    Delete(targs);
			  } else {
			    /* An explicit template specialization */
			    /* add default args from primary (unspecialized) template */
			    String *ty = Swig_symbol_template_deftype(tname,0);
			    String *fname = Swig_symbol_type_qualify(ty,0);
			    Swig_symbol_cadd(fname,(yyval.node));
			    Delete(ty);
			    Delete(fname);
			  }
			}  else if ((yyval.node)) {
			  Setattr((yyval.node),"templatetype",nodeType((yyvsp[(6) - (6)].node)));
			  set_nodeType((yyval.node),"template");
			  Setattr((yyval.node),"templateparms", (yyvsp[(3) - (6)].tparms));
			  if (!Getattr((yyval.node),"sym:weak")) {
			    Setattr((yyval.node),"sym:typename","1");
			  }
			  add_symbols((yyval.node));
			  default_arguments((yyval.node));
			  /* We also place a fully parameterized version in the symbol table */
			  {
			    Parm *p;
			    String *fname = NewStringf("%s<(", Getattr((yyval.node),"name"));
			    p = (yyvsp[(3) - (6)].tparms);
			    while (p) {
			      String *n = Getattr(p,"name");
			      if (!n) n = Getattr(p,"type");
			      Append(fname,n);
			      p = nextSibling(p);
			      if (p) Putc(',',fname);
			    }
			    Append(fname,")>");
			    Swig_symbol_cadd(fname,(yyval.node));
			  }
			}
			(yyval.node) = ntop;
			Swig_symbol_setscope(cscope);
			Delete(Namespaceprefix);
			Namespaceprefix = Swig_symbol_qualifiedscopename(0);
			if (error || (nscope_inner && Strcmp(nodeType(nscope_inner), "class") == 0)) {
			  (yyval.node) = 0;
			}
			if (currentOuterClass)
			  template_parameters = Getattr(currentOuterClass, "template_parameters");
			else
			  template_parameters = 0;
			parsing_template_declaration = 0;
                }
    break;

  case 170:

    {
		  Swig_warning(WARN_PARSE_EXPLICIT_TEMPLATE, cparse_file, cparse_line, "Explicit template instantiation ignored.\n");
                  (yyval.node) = 0; 
		}
    break;

  case 171:

    {
		  Swig_warning(WARN_PARSE_EXPLICIT_TEMPLATE, cparse_file, cparse_line, "Explicit template instantiation ignored.\n");
                  (yyval.node) = 0; 
                }
    break;

  case 172:

    {
		  (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 173:

    {
                   (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 174:

    {
                   (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 175:

    {
		  (yyval.node) = 0;
                }
    break;

  case 176:

    {
                  (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 177:

    {
                  (yyval.node) = (yyvsp[(1) - (1)].node);
                }
    break;

  case 178:

    {
		   /* Rip out the parameter names */
		  Parm *p = (yyvsp[(1) - (1)].pl);
		  (yyval.tparms) = (yyvsp[(1) - (1)].pl);

		  while (p) {
		    String *name = Getattr(p,"name");
		    if (!name) {
		      /* Hmmm. Maybe it's a 'class T' parameter */
		      char *type = Char(Getattr(p,"type"));
		      /* Template template parameter */
		      if (strncmp(type,"template<class> ",16) == 0) {
			type += 16;
		      }
		      if ((strncmp(type,"class ",6) == 0) || (strncmp(type,"typename ", 9) == 0)) {
			char *t = strchr(type,' ');
			Setattr(p,"name", t+1);
		      } else 
                      /* Variadic template args */
		      if ((strncmp(type,"class... ",9) == 0) || (strncmp(type,"typename... ", 12) == 0)) {
			char *t = strchr(type,' ');
			Setattr(p,"name", t+1);
			Setattr(p,"variadic", "1");
		      } else {
			/*
			 Swig_error(cparse_file, cparse_line, "Missing template parameter name\n");
			 $$.rparms = 0;
			 $$.parms = 0;
			 break; */
		      }
		    }
		    p = nextSibling(p);
		  }
                 }
    break;

  case 179:

    {
                      set_nextSibling((yyvsp[(1) - (2)].p),(yyvsp[(2) - (2)].pl));
                      (yyval.pl) = (yyvsp[(1) - (2)].p);
                   }
    break;

  case 180:

    { (yyval.pl) = 0; }
    break;

  case 181:

    {
		    (yyval.p) = NewParmWithoutFileLineInfo(NewString((yyvsp[(1) - (1)].id)), 0);
                  }
    break;

  case 182:

    {
                    (yyval.p) = (yyvsp[(1) - (1)].p);
                  }
    break;

  case 183:

    {
                         set_nextSibling((yyvsp[(2) - (3)].p),(yyvsp[(3) - (3)].pl));
                         (yyval.pl) = (yyvsp[(2) - (3)].p);
                       }
    break;

  case 184:

    { (yyval.pl) = 0; }
    break;

  case 185:

    {
                  String *uname = Swig_symbol_type_qualify((yyvsp[(2) - (3)].str),0);
		  String *name = Swig_scopename_last((yyvsp[(2) - (3)].str));
                  (yyval.node) = new_node("using");
		  Setattr((yyval.node),"uname",uname);
		  Setattr((yyval.node),"name", name);
		  Delete(uname);
		  Delete(name);
		  add_symbols((yyval.node));
             }
    break;

  case 186:

    {
	       Node *n = Swig_symbol_clookup((yyvsp[(3) - (4)].str),0);
	       if (!n) {
		 Swig_error(cparse_file, cparse_line, "Nothing known about namespace '%s'\n", (yyvsp[(3) - (4)].str));
		 (yyval.node) = 0;
	       } else {

		 while (Strcmp(nodeType(n),"using") == 0) {
		   n = Getattr(n,"node");
		 }
		 if (n) {
		   if (Strcmp(nodeType(n),"namespace") == 0) {
		     Symtab *current = Swig_symbol_current();
		     Symtab *symtab = Getattr(n,"symtab");
		     (yyval.node) = new_node("using");
		     Setattr((yyval.node),"node",n);
		     Setattr((yyval.node),"namespace", (yyvsp[(3) - (4)].str));
		     if (current != symtab) {
		       Swig_symbol_inherit(symtab);
		     }
		   } else {
		     Swig_error(cparse_file, cparse_line, "'%s' is not a namespace.\n", (yyvsp[(3) - (4)].str));
		     (yyval.node) = 0;
		   }
		 } else {
		   (yyval.node) = 0;
		 }
	       }
             }
    break;

  case 187:

    { 
                Hash *h;
		Node *parent_ns = 0;
		List *scopes = Swig_scopename_tolist((yyvsp[(2) - (3)].str));
		int ilen = Len(scopes);
		int i;

/*
Printf(stdout, "==== Namespace %s creation...\n", $2);
*/
		(yyval.node) = 0;
		for (i = 0; i < ilen; i++) {
		  Node *ns = new_node("namespace");
		  Symtab *current_symtab = Swig_symbol_current();
		  String *scopename = Getitem(scopes, i);
		  Setattr(ns, "name", scopename);
		  (yyval.node) = ns;
		  if (parent_ns)
		    appendChild(parent_ns, ns);
		  parent_ns = ns;
		  h = Swig_symbol_clookup(scopename, 0);
		  if (h && (current_symtab == Getattr(h, "sym:symtab")) && (Strcmp(nodeType(h), "namespace") == 0)) {
/*
Printf(stdout, "  Scope %s [found C++17 style]\n", scopename);
*/
		    if (Getattr(h, "alias")) {
		      h = Getattr(h, "namespace");
		      Swig_warning(WARN_PARSE_NAMESPACE_ALIAS, cparse_file, cparse_line, "Namespace alias '%s' not allowed here. Assuming '%s'\n",
				   scopename, Getattr(h, "name"));
		      scopename = Getattr(h, "name");
		    }
		    Swig_symbol_setscope(Getattr(h, "symtab"));
		  } else {
/*
Printf(stdout, "  Scope %s [creating single scope C++17 style]\n", scopename);
*/
		    h = Swig_symbol_newscope();
		    Swig_symbol_setscopename(scopename);
		  }
		  Delete(Namespaceprefix);
		  Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		}
		Delete(scopes);
             }
    break;

  case 188:

    {
		Node *n = (yyvsp[(4) - (6)].node);
		Node *top_ns = 0;
		do {
		  Setattr(n, "symtab", Swig_symbol_popscope());
		  Delete(Namespaceprefix);
		  Namespaceprefix = Swig_symbol_qualifiedscopename(0);
		  add_symbols(n);
		  top_ns = n;
		  n = parentNode(n);
		} while(n);
		appendChild((yyvsp[(4) - (6)].node), firstChild((yyvsp[(5) - (6)].node)));
		Delete((yyvsp[(5) - (6)].node));
		(yyval.node) = top_ns;
             }
    break;

  case 189:

    {
	       Hash *h;
	       (yyvsp[(1) - (2)].node) = Swig_symbol_current();
	       h = Swig_symbol_clookup("    ",0);
	       if (h && (Strcmp(nodeType(h),"namespace") == 0)) {
		 Swig_symbol_setscope(Getattr(h,"symtab"));
	       } else {
		 Swig_symbol_newscope();
		 /* we don't use "__unnamed__", but a long 'empty' name */
		 Swig_symbol_setscopename("    ");
	       }
	       Namespaceprefix = 0;
             }
    break;

  case 190:

    {
	       (yyval.node) = (yyvsp[(4) - (5)].node);
	       set_nodeType((yyval.node),"namespace");
	       Setattr((yyval.node),"unnamed","1");
	       Setattr((yyval.node),"symtab", Swig_symbol_popscope());
	       Swig_symbol_setscope((yyvsp[(1) - (5)].node));
	       Delete(Namespaceprefix);
	       Namespaceprefix = Swig_symbol_qualifiedscopename(0);
	       add_symbols((yyval.node));
             }
    break;

  case 191:

    {
	       /* Namespace alias */
	       Node *n;
	       (yyval.node) = new_node("namespace");
	       Setattr((yyval.node),"name",(yyvsp[(2) - (5)].id));
	       Setattr((yyval.node),"alias",(yyvsp[(4) - (5)].str));
	       n = Swig_symbol_clookup((yyvsp[(4) - (5)].str),0);
	       if (!n) {
		 Swig_error(cparse_file, cparse_line, "Unknown namespace '%s'\n", (yyvsp[(4) - (5)].str));
		 (yyval.node) = 0;
	       } else {
		 if (Strcmp(nodeType(n),"namespace") != 0) {
		   Swig_error(cparse_file, cparse_line, "'%s' is not a namespace\n",(yyvsp[(4) - (5)].str));
		   (yyval.node) = 0;
		 } else {
		   while (Getattr(n,"alias")) {
		     n = Getattr(n,"namespace");
		   }
		   Setattr((yyval.node),"namespace",n);
		   add_symbols((yyval.node));
		   /* Set up a scope alias */
		   Swig_symbol_alias((yyvsp[(2) - (5)].id),Getattr(n,"symtab"));
		 }
	       }
             }
    break;

  case 192:

    {
                   (yyval.node) = (yyvsp[(1) - (2)].node);
                   /* Insert cpp_member (including any siblings) to the front of the cpp_members linked list */
		   if ((yyval.node)) {
		     Node *p = (yyval.node);
		     Node *pp =0;
		     while (p) {
		       pp = p;
		       p = nextSibling(p);
		     }
		     set_nextSibling(pp,(yyvsp[(2) - (2)].node));
		     if ((yyvsp[(2) - (2)].node))
		       set_previousSibling((yyvsp[(2) - (2)].node), pp);
		   } else {
		     (yyval.node) = (yyvsp[(2) - (2)].node);
		   }
             }
    break;

  case 193:

    { 
	       extendmode = 1;
	       if (cplus_mode != CPLUS_PUBLIC) {
		 Swig_error(cparse_file,cparse_line,"%%extend can only be used in a public section\n");
	       }
             }
    break;

  case 194:

    {
	       extendmode = 0;
	     }
    break;

  case 195:

    {
	       (yyval.node) = new_node("extend");
	       mark_nodes_as_extend((yyvsp[(4) - (7)].node));
	       appendChild((yyval.node),(yyvsp[(4) - (7)].node));
	       set_nextSibling((yyval.node),(yyvsp[(7) - (7)].node));
	     }
    break;

  case 196:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 197:

    { (yyval.node) = 0;}
    break;

  case 198:

    {
	       int start_line = cparse_line;
	       skip_decl();
	       Swig_error(cparse_file,start_line,"Syntax error in input(3).\n");
	       exit(1);
	       }
    break;

  case 199:

    { 
		 (yyval.node) = (yyvsp[(3) - (3)].node);
   	     }
    break;

  case 200:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:

    { 
                 (yyval.node) = (yyvsp[(1) - (1)].node); 
		 if (extendmode && current_class) {
		   String *symname;
		   symname= make_name((yyval.node),Getattr((yyval.node),"name"), Getattr((yyval.node),"decl"));
		   if (Strcmp(symname,Getattr((yyval.node),"name")) == 0) {
		     /* No renaming operation.  Set name to class name */
		     Delete(yyrename);
		     yyrename = NewString(Getattr(current_class,"sym:name"));
		   } else {
		     Delete(yyrename);
		     yyrename = symname;
		   }
		 }
		 add_symbols((yyval.node));
                 default_arguments((yyval.node));
             }
    break;

  case 202:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 205:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 208:

    { (yyval.node) = 0; }
    break;

  case 209:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 210:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:

    { (yyval.node) = 0; }
    break;

  case 212:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:

    { (yyval.node) = 0; }
    break;

  case 215:

    {(yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:

    {(yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 217:

    { (yyval.node) = 0; }
    break;

  case 218:

    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
	     }
    break;

  case 219:

    {
	         (yyval.node) = (yyvsp[(2) - (2)].node);
		 set_comment((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].str));
	     }
    break;

  case 220:

    {
	         (yyval.node) = (yyvsp[(1) - (2)].node);
		 set_comment((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].str));
	     }
    break;

  case 221:

    {
              if (inclass || extendmode) {
		SwigType *decl = NewStringEmpty();
		(yyval.node) = new_node("constructor");
		Setattr((yyval.node),"storage",(yyvsp[(1) - (6)].id));
		Setattr((yyval.node),"name",(yyvsp[(2) - (6)].type));
		Setattr((yyval.node),"parms",(yyvsp[(4) - (6)].pl));
		SwigType_add_function(decl,(yyvsp[(4) - (6)].pl));
		Setattr((yyval.node),"decl",decl);
		Setattr((yyval.node),"throws",(yyvsp[(6) - (6)].decl).throws);
		Setattr((yyval.node),"throw",(yyvsp[(6) - (6)].decl).throwf);
		Setattr((yyval.node),"noexcept",(yyvsp[(6) - (6)].decl).nexcept);
		Setattr((yyval.node),"final",(yyvsp[(6) - (6)].decl).final);
		if (Len(scanner_ccode)) {
		  String *code = Copy(scanner_ccode);
		  Setattr((yyval.node),"code",code);
		  Delete(code);
		}
		SetFlag((yyval.node),"feature:new");
		if ((yyvsp[(6) - (6)].decl).defarg)
		  Setattr((yyval.node),"value",(yyvsp[(6) - (6)].decl).defarg);
	      } else {
		(yyval.node) = 0;
              }
              }
    break;

  case 222:

    {
               String *name = NewStringf("%s",(yyvsp[(2) - (6)].str));
	       if (*(Char(name)) != '~') Insert(name,0,"~");
               (yyval.node) = new_node("destructor");
	       Setattr((yyval.node),"name",name);
	       Delete(name);
	       if (Len(scanner_ccode)) {
		 String *code = Copy(scanner_ccode);
		 Setattr((yyval.node),"code",code);
		 Delete(code);
	       }
	       {
		 String *decl = NewStringEmpty();
		 SwigType_add_function(decl,(yyvsp[(4) - (6)].pl));
		 Setattr((yyval.node),"decl",decl);
		 Delete(decl);
	       }
	       Setattr((yyval.node),"throws",(yyvsp[(6) - (6)].dtype).throws);
	       Setattr((yyval.node),"throw",(yyvsp[(6) - (6)].dtype).throwf);
	       Setattr((yyval.node),"noexcept",(yyvsp[(6) - (6)].dtype).nexcept);
	       Setattr((yyval.node),"final",(yyvsp[(6) - (6)].dtype).final);
	       if ((yyvsp[(6) - (6)].dtype).val)
	         Setattr((yyval.node),"value",(yyvsp[(6) - (6)].dtype).val);
	       if ((yyvsp[(6) - (6)].dtype).qualifier)
		 Swig_error(cparse_file, cparse_line, "Destructor %s %s cannot have a qualifier.\n", Swig_name_decl((yyval.node)), SwigType_str((yyvsp[(6) - (6)].dtype).qualifier, 0));
	       add_symbols((yyval.node));
	      }
    break;

  case 223:

    {
		String *name;
		(yyval.node) = new_node("destructor");
		Setattr((yyval.node),"storage","virtual");
	        name = NewStringf("%s",(yyvsp[(3) - (7)].str));
		if (*(Char(name)) != '~') Insert(name,0,"~");
		Setattr((yyval.node),"name",name);
		Delete(name);
		Setattr((yyval.node),"throws",(yyvsp[(7) - (7)].dtype).throws);
		Setattr((yyval.node),"throw",(yyvsp[(7) - (7)].dtype).throwf);
		Setattr((yyval.node),"noexcept",(yyvsp[(7) - (7)].dtype).nexcept);
		Setattr((yyval.node),"final",(yyvsp[(7) - (7)].dtype).final);
		if ((yyvsp[(7) - (7)].dtype).val)
		  Setattr((yyval.node),"value",(yyvsp[(7) - (7)].dtype).val);
		if (Len(scanner_ccode)) {
		  String *code = Copy(scanner_ccode);
		  Setattr((yyval.node),"code",code);
		  Delete(code);
		}
		{
		  String *decl = NewStringEmpty();
		  SwigType_add_function(decl,(yyvsp[(5) - (7)].pl));
		  Setattr((yyval.node),"decl",decl);
		  Delete(decl);
		}
		if ((yyvsp[(7) - (7)].dtype).qualifier)
		  Swig_error(cparse_file, cparse_line, "Destructor %s %s cannot have a qualifier.\n", Swig_name_decl((yyval.node)), SwigType_str((yyvsp[(7) - (7)].dtype).qualifier, 0));
		add_symbols((yyval.node));
	      }
    break;

  case 224:

    {
                 (yyval.node) = new_node("cdecl");
                 Setattr((yyval.node),"type",(yyvsp[(3) - (8)].type));
		 Setattr((yyval.node),"name",(yyvsp[(2) - (8)].str));
		 Setattr((yyval.node),"storage",(yyvsp[(1) - (8)].id));

		 SwigType_add_function((yyvsp[(4) - (8)].type),(yyvsp[(6) - (8)].pl));
		 if ((yyvsp[(8) - (8)].dtype).qualifier) {
		   SwigType_push((yyvsp[(4) - (8)].type),(yyvsp[(8) - (8)].dtype).qualifier);
		 }
		 Setattr((yyval.node),"refqualifier",(yyvsp[(8) - (8)].dtype).refqualifier);
		 Setattr((yyval.node),"decl",(yyvsp[(4) - (8)].type));
		 Setattr((yyval.node),"parms",(yyvsp[(6) - (8)].pl));
		 Setattr((yyval.node),"conversion_operator","1");
		 add_symbols((yyval.node));
              }
    break;

  case 225:

    {
		 SwigType *decl;
                 (yyval.node) = new_node("cdecl");
                 Setattr((yyval.node),"type",(yyvsp[(3) - (8)].type));
		 Setattr((yyval.node),"name",(yyvsp[(2) - (8)].str));
		 Setattr((yyval.node),"storage",(yyvsp[(1) - (8)].id));
		 decl = NewStringEmpty();
		 SwigType_add_reference(decl);
		 SwigType_add_function(decl,(yyvsp[(6) - (8)].pl));
		 if ((yyvsp[(8) - (8)].dtype).qualifier) {
		   SwigType_push(decl,(yyvsp[(8) - (8)].dtype).qualifier);
		 }
		 Setattr((yyval.node),"refqualifier",(yyvsp[(8) - (8)].dtype).refqualifier);
		 Setattr((yyval.node),"decl",decl);
		 Setattr((yyval.node),"parms",(yyvsp[(6) - (8)].pl));
		 Setattr((yyval.node),"conversion_operator","1");
		 add_symbols((yyval.node));
	       }
    break;

  case 226:

    {
		 SwigType *decl;
                 (yyval.node) = new_node("cdecl");
                 Setattr((yyval.node),"type",(yyvsp[(3) - (8)].type));
		 Setattr((yyval.node),"name",(yyvsp[(2) - (8)].str));
		 Setattr((yyval.node),"storage",(yyvsp[(1) - (8)].id));
		 decl = NewStringEmpty();
		 SwigType_add_rvalue_reference(decl);
		 SwigType_add_function(decl,(yyvsp[(6) - (8)].pl));
		 if ((yyvsp[(8) - (8)].dtype).qualifier) {
		   SwigType_push(decl,(yyvsp[(8) - (8)].dtype).qualifier);
		 }
		 Setattr((yyval.node),"refqualifier",(yyvsp[(8) - (8)].dtype).refqualifier);
		 Setattr((yyval.node),"decl",decl);
		 Setattr((yyval.node),"parms",(yyvsp[(6) - (8)].pl));
		 Setattr((yyval.node),"conversion_operator","1");
		 add_symbols((yyval.node));
	       }
    break;

  case 227:

    {
		 SwigType *decl;
                 (yyval.node) = new_node("cdecl");
                 Setattr((yyval.node),"type",(yyvsp[(3) - (9)].type));
		 Setattr((yyval.node),"name",(yyvsp[(2) - (9)].str));
		 Setattr((yyval.node),"storage",(yyvsp[(1) - (9)].id));
		 decl = NewStringEmpty();
		 SwigType_add_pointer(decl);
		 SwigType_add_reference(decl);
		 SwigType_add_function(decl,(yyvsp[(7) - (9)].pl));
		 if ((yyvsp[(9) - (9)].dtype).qualifier) {
		   SwigType_push(decl,(yyvsp[(9) - (9)].dtype).qualifier);
		 }
		 Setattr((yyval.node),"refqualifier",(yyvsp[(9) - (9)].dtype).refqualifier);
		 Setattr((yyval.node),"decl",decl);
		 Setattr((yyval.node),"parms",(yyvsp[(7) - (9)].pl));
		 Setattr((yyval.node),"conversion_operator","1");
		 add_symbols((yyval.node));
	       }
    break;

  case 228:

    {
		String *t = NewStringEmpty();
		(yyval.node) = new_node("cdecl");
		Setattr((yyval.node),"type",(yyvsp[(3) - (7)].type));
		Setattr((yyval.node),"name",(yyvsp[(2) - (7)].str));
		 Setattr((yyval.node),"storage",(yyvsp[(1) - (7)].id));
		SwigType_add_function(t,(yyvsp[(5) - (7)].pl));
		if ((yyvsp[(7) - (7)].dtype).qualifier) {
		  SwigType_push(t,(yyvsp[(7) - (7)].dtype).qualifier);
		}
		 Setattr((yyval.node),"refqualifier",(yyvsp[(7) - (7)].dtype).refqualifier);
		Setattr((yyval.node),"decl",t);
		Setattr((yyval.node),"parms",(yyvsp[(5) - (7)].pl));
		Setattr((yyval.node),"conversion_operator","1");
		add_symbols((yyval.node));
              }
    break;

  case 229:

    {
                 skip_balanced('{','}');
                 (yyval.node) = 0;
               }
    break;

  case 230:

    {
                skip_balanced('(',')');
                (yyval.node) = 0;
              }
    break;

  case 231:

    { 
                (yyval.node) = new_node("access");
		Setattr((yyval.node),"kind","public");
                cplus_mode = CPLUS_PUBLIC;
              }
    break;

  case 232:

    { 
                (yyval.node) = new_node("access");
                Setattr((yyval.node),"kind","private");
		cplus_mode = CPLUS_PRIVATE;
	      }
    break;

  case 233:

    { 
		(yyval.node) = new_node("access");
		Setattr((yyval.node),"kind","protected");
		cplus_mode = CPLUS_PROTECTED;
	      }
    break;

  case 234:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 235:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 236:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 237:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 238:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 239:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 240:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 241:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 242:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 243:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 244:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 245:

    {
	            Clear(scanner_ccode);
		    (yyval.dtype).val = 0;
		    (yyval.dtype).qualifier = (yyvsp[(1) - (2)].dtype).qualifier;
		    (yyval.dtype).refqualifier = (yyvsp[(1) - (2)].dtype).refqualifier;
		    (yyval.dtype).bitfield = 0;
		    (yyval.dtype).throws = (yyvsp[(1) - (2)].dtype).throws;
		    (yyval.dtype).throwf = (yyvsp[(1) - (2)].dtype).throwf;
		    (yyval.dtype).nexcept = (yyvsp[(1) - (2)].dtype).nexcept;
		    (yyval.dtype).final = (yyvsp[(1) - (2)].dtype).final;
               }
    break;

  case 246:

    {
	            Clear(scanner_ccode);
		    (yyval.dtype).val = (yyvsp[(3) - (4)].dtype).val;
		    (yyval.dtype).qualifier = (yyvsp[(1) - (4)].dtype).qualifier;
		    (yyval.dtype).refqualifier = (yyvsp[(1) - (4)].dtype).refqualifier;
		    (yyval.dtype).bitfield = 0;
		    (yyval.dtype).throws = (yyvsp[(1) - (4)].dtype).throws;
		    (yyval.dtype).throwf = (yyvsp[(1) - (4)].dtype).throwf;
		    (yyval.dtype).nexcept = (yyvsp[(1) - (4)].dtype).nexcept;
		    (yyval.dtype).final = (yyvsp[(1) - (4)].dtype).final;
               }
    break;

  case 247:

    { 
		    skip_balanced('{','}'); 
		    (yyval.dtype).val = 0;
		    (yyval.dtype).qualifier = (yyvsp[(1) - (2)].dtype).qualifier;
		    (yyval.dtype).refqualifier = (yyvsp[(1) - (2)].dtype).refqualifier;
		    (yyval.dtype).bitfield = 0;
		    (yyval.dtype).throws = (yyvsp[(1) - (2)].dtype).throws;
		    (yyval.dtype).throwf = (yyvsp[(1) - (2)].dtype).throwf;
		    (yyval.dtype).nexcept = (yyvsp[(1) - (2)].dtype).nexcept;
		    (yyval.dtype).final = (yyvsp[(1) - (2)].dtype).final;
	       }
    break;

  case 248:

    { 
                     Clear(scanner_ccode);
                     (yyval.dtype).val = 0;
                     (yyval.dtype).qualifier = (yyvsp[(1) - (2)].dtype).qualifier;
                     (yyval.dtype).refqualifier = (yyvsp[(1) - (2)].dtype).refqualifier;
                     (yyval.dtype).bitfield = 0;
                     (yyval.dtype).throws = (yyvsp[(1) - (2)].dtype).throws;
                     (yyval.dtype).throwf = (yyvsp[(1) - (2)].dtype).throwf;
                     (yyval.dtype).nexcept = (yyvsp[(1) - (2)].dtype).nexcept;
                     (yyval.dtype).final = (yyvsp[(1) - (2)].dtype).final;
                }
    break;

  case 249:

    { 
                     Clear(scanner_ccode);
                     (yyval.dtype).val = (yyvsp[(3) - (4)].dtype).val;
                     (yyval.dtype).qualifier = (yyvsp[(1) - (4)].dtype).qualifier;
                     (yyval.dtype).refqualifier = (yyvsp[(1) - (4)].dtype).refqualifier;
                     (yyval.dtype).bitfield = 0;
                     (yyval.dtype).throws = (yyvsp[(1) - (4)].dtype).throws; 
                     (yyval.dtype).throwf = (yyvsp[(1) - (4)].dtype).throwf; 
                     (yyval.dtype).nexcept = (yyvsp[(1) - (4)].dtype).nexcept;
                     (yyval.dtype).final = (yyvsp[(1) - (4)].dtype).final;
               }
    break;

  case 250:

    { 
                     skip_balanced('{','}');
                     (yyval.dtype).val = 0;
                     (yyval.dtype).qualifier = (yyvsp[(1) - (2)].dtype).qualifier;
                     (yyval.dtype).refqualifier = (yyvsp[(1) - (2)].dtype).refqualifier;
                     (yyval.dtype).bitfield = 0;
                     (yyval.dtype).throws = (yyvsp[(1) - (2)].dtype).throws; 
                     (yyval.dtype).throwf = (yyvsp[(1) - (2)].dtype).throwf; 
                     (yyval.dtype).nexcept = (yyvsp[(1) - (2)].dtype).nexcept;
                     (yyval.dtype).final = (yyvsp[(1) - (2)].dtype).final;
               }
    break;

  case 251:

    { }
    break;

  case 252:

    { (yyval.type) = (yyvsp[(1) - (1)].type);
                  /* Printf(stdout,"primitive = '%s'\n", $$);*/
                }
    break;

  case 253:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 254:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 255:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 256:

    {
		  (yyval.type) = (yyvsp[(1) - (1)].str);
               }
    break;

  case 257:

    {
                   if (Strcmp((yyvsp[(2) - (2)].str),"C") == 0) {
		     (yyval.id) = "externc";
                   } else if (Strcmp((yyvsp[(2) - (2)].str),"C++") == 0) {
		     (yyval.id) = "extern";
		   } else {
		     Swig_warning(WARN_PARSE_UNDEFINED_EXTERN,cparse_file, cparse_line,"Unrecognized extern type \"%s\".\n", (yyvsp[(2) - (2)].str));
		     (yyval.id) = 0;
		   }
               }
    break;

  case 258:

    { (yyval.id) = "extern"; }
    break;

  case 259:

    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 260:

    { (yyval.id) = "thread_local"; }
    break;

  case 261:

    { (yyval.id) = "typedef"; }
    break;

  case 262:

    { (yyval.id) = "static"; }
    break;

  case 263:

    { (yyval.id) = "typedef"; }
    break;

  case 264:

    { (yyval.id) = "virtual"; }
    break;

  case 265:

    { (yyval.id) = "friend"; }
    break;

  case 266:

    { (yyval.id) = "explicit"; }
    break;

  case 267:

    { (yyval.id) = "constexpr"; }
    break;

  case 268:

    { (yyval.id) = "explicit constexpr"; }
    break;

  case 269:

    { (yyval.id) = "explicit constexpr"; }
    break;

  case 270:

    { (yyval.id) = "static constexpr"; }
    break;

  case 271:

    { (yyval.id) = "static constexpr"; }
    break;

  case 272:

    { (yyval.id) = "thread_local"; }
    break;

  case 273:

    { (yyval.id) = "static thread_local"; }
    break;

  case 274:

    { (yyval.id) = "static thread_local"; }
    break;

  case 275:

    { (yyval.id) = "extern thread_local"; }
    break;

  case 276:

    { (yyval.id) = "extern thread_local"; }
    break;

  case 277:

    { (yyval.id) = 0; }
    break;

  case 278:

    {
                 Parm *p;
		 (yyval.pl) = (yyvsp[(1) - (1)].pl);
		 p = (yyvsp[(1) - (1)].pl);
                 while (p) {
		   Replace(Getattr(p,"type"),"typename ", "", DOH_REPLACE_ANY);
		   p = nextSibling(p);
                 }
               }
    break;

  case 279:

    {
                  set_nextSibling((yyvsp[(1) - (2)].p),(yyvsp[(2) - (2)].pl));
                  (yyval.pl) = (yyvsp[(1) - (2)].p);
		}
    break;

  case 280:

    {
		  (yyval.pl) = 0;
		  previousNode = currentNode;
		  currentNode=0;
	       }
    break;

  case 281:

    {
                 set_nextSibling((yyvsp[(2) - (3)].p),(yyvsp[(3) - (3)].pl));
		 (yyval.pl) = (yyvsp[(2) - (3)].p);
                }
    break;

  case 282:

    {
		 set_comment(previousNode, (yyvsp[(2) - (4)].str));
                 set_nextSibling((yyvsp[(3) - (4)].p), (yyvsp[(4) - (4)].pl));
		 (yyval.pl) = (yyvsp[(3) - (4)].p);
               }
    break;

  case 283:

    { (yyval.pl) = 0; }
    break;

  case 284:

    {
                   SwigType_push((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].decl).type);
		   (yyval.p) = NewParmWithoutFileLineInfo((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].decl).id);
		   previousNode = currentNode;
		   currentNode = (yyval.p);
		   Setfile((yyval.p),cparse_file);
		   Setline((yyval.p),cparse_line);
		   if ((yyvsp[(2) - (2)].decl).defarg) {
		     Setattr((yyval.p),"value",(yyvsp[(2) - (2)].decl).defarg);
		   }
		}
    break;

  case 285:

    {
                  (yyval.p) = NewParmWithoutFileLineInfo(NewStringf("template<class> %s %s", (yyvsp[(5) - (7)].id),(yyvsp[(6) - (7)].str)), 0);
		  previousNode = currentNode;
		  currentNode = (yyval.p);
		  Setfile((yyval.p),cparse_file);
		  Setline((yyval.p),cparse_line);
                  if ((yyvsp[(7) - (7)].dtype).val) {
                    Setattr((yyval.p),"value",(yyvsp[(7) - (7)].dtype).val);
                  }
                }
    break;

  case 286:

    {
		  SwigType *t = NewString("v(...)");
		  (yyval.p) = NewParmWithoutFileLineInfo(t, 0);
		  previousNode = currentNode;
		  currentNode = (yyval.p);
		  Setfile((yyval.p),cparse_file);
		  Setline((yyval.p),cparse_line);
		}
    break;

  case 287:

    {
		  (yyval.p) = (yyvsp[(1) - (1)].p);
		}
    break;

  case 288:

    {
		  (yyval.p) = (yyvsp[(2) - (2)].p);
		  set_comment((yyvsp[(2) - (2)].p), (yyvsp[(1) - (2)].str));
		}
    break;

  case 289:

    {
		  (yyval.p) = (yyvsp[(1) - (2)].p);
		  set_comment((yyvsp[(1) - (2)].p), (yyvsp[(2) - (2)].str));
		}
    break;

  case 290:

    {
                 Parm *p;
		 (yyval.p) = (yyvsp[(1) - (1)].p);
		 p = (yyvsp[(1) - (1)].p);
                 while (p) {
		   if (Getattr(p,"type")) {
		     Replace(Getattr(p,"type"),"typename ", "", DOH_REPLACE_ANY);
		   }
		   p = nextSibling(p);
                 }
               }
    break;

  case 291:

    {
                  set_nextSibling((yyvsp[(1) - (2)].p),(yyvsp[(2) - (2)].p));
                  (yyval.p) = (yyvsp[(1) - (2)].p);
		}
    break;

  case 292:

    { (yyval.p) = 0; }
    break;

  case 293:

    {
                 set_nextSibling((yyvsp[(2) - (3)].p),(yyvsp[(3) - (3)].p));
		 (yyval.p) = (yyvsp[(2) - (3)].p);
                }
    break;

  case 294:

    { (yyval.p) = 0; }
    break;

  case 295:

    {
		  (yyval.p) = (yyvsp[(1) - (1)].p);
		  {
		    /* We need to make a possible adjustment for integer parameters. */
		    SwigType *type;
		    Node     *n = 0;

		    while (!n) {
		      type = Getattr((yyvsp[(1) - (1)].p),"type");
		      n = Swig_symbol_clookup(type,0);     /* See if we can find a node that matches the typename */
		      if ((n) && (Strcmp(nodeType(n),"cdecl") == 0)) {
			SwigType *decl = Getattr(n,"decl");
			if (!SwigType_isfunction(decl)) {
			  String *value = Getattr(n,"value");
			  if (value) {
			    String *v = Copy(value);
			    Setattr((yyvsp[(1) - (1)].p),"type",v);
			    Delete(v);
			    n = 0;
			  }
			}
		      } else {
			break;
		      }
		    }
		  }

               }
    break;

  case 296:

    {
                  (yyval.p) = NewParmWithoutFileLineInfo(0,0);
                  Setfile((yyval.p),cparse_file);
		  Setline((yyval.p),cparse_line);
		  Setattr((yyval.p),"value",(yyvsp[(1) - (1)].dtype).val);
               }
    break;

  case 297:

    { 
                  (yyval.dtype) = (yyvsp[(2) - (2)].dtype); 
		  if ((yyvsp[(2) - (2)].dtype).type == T_ERROR) {
		    Swig_warning(WARN_PARSE_BAD_DEFAULT,cparse_file, cparse_line, "Can't set default argument (ignored)\n");
		    (yyval.dtype).val = 0;
		    (yyval.dtype).rawval = 0;
		    (yyval.dtype).bitfield = 0;
		    (yyval.dtype).throws = 0;
		    (yyval.dtype).throwf = 0;
		    (yyval.dtype).nexcept = 0;
		    (yyval.dtype).final = 0;
		  }
               }
    break;

  case 298:

    { 
		  (yyval.dtype) = (yyvsp[(2) - (5)].dtype);
		  if ((yyvsp[(2) - (5)].dtype).type == T_ERROR) {
		    Swig_warning(WARN_PARSE_BAD_DEFAULT,cparse_file, cparse_line, "Can't set default argument (ignored)\n");
		    (yyval.dtype) = (yyvsp[(2) - (5)].dtype);
		    (yyval.dtype).val = 0;
		    (yyval.dtype).rawval = 0;
		    (yyval.dtype).bitfield = 0;
		    (yyval.dtype).throws = 0;
		    (yyval.dtype).throwf = 0;
		    (yyval.dtype).nexcept = 0;
		    (yyval.dtype).final = 0;
		  } else {
		    (yyval.dtype).val = NewStringf("%s[%s]",(yyvsp[(2) - (5)].dtype).val,(yyvsp[(4) - (5)].dtype).val); 
		  }		  
               }
    break;

  case 299:

    {
		 skip_balanced('{','}');
		 (yyval.dtype).val = NewString(scanner_ccode);
		 (yyval.dtype).rawval = 0;
                 (yyval.dtype).type = T_INT;
		 (yyval.dtype).bitfield = 0;
		 (yyval.dtype).throws = 0;
		 (yyval.dtype).throwf = 0;
		 (yyval.dtype).nexcept = 0;
		 (yyval.dtype).final = 0;
	       }
    break;

  case 300:

    { 
		 (yyval.dtype).val = 0;
		 (yyval.dtype).rawval = 0;
		 (yyval.dtype).type = 0;
		 (yyval.dtype).bitfield = (yyvsp[(2) - (2)].dtype).val;
		 (yyval.dtype).throws = 0;
		 (yyval.dtype).throwf = 0;
		 (yyval.dtype).nexcept = 0;
		 (yyval.dtype).final = 0;
	       }
    break;

  case 301:

    {
                 (yyval.dtype).val = 0;
                 (yyval.dtype).rawval = 0;
                 (yyval.dtype).type = T_INT;
		 (yyval.dtype).bitfield = 0;
		 (yyval.dtype).throws = 0;
		 (yyval.dtype).throwf = 0;
		 (yyval.dtype).nexcept = 0;
		 (yyval.dtype).final = 0;
               }
    break;

  case 302:

    {
                 (yyval.decl) = (yyvsp[(1) - (2)].decl);
		 (yyval.decl).defarg = (yyvsp[(2) - (2)].dtype).rawval ? (yyvsp[(2) - (2)].dtype).rawval : (yyvsp[(2) - (2)].dtype).val;
            }
    break;

  case 303:

    {
              (yyval.decl) = (yyvsp[(1) - (2)].decl);
	      (yyval.decl).defarg = (yyvsp[(2) - (2)].dtype).rawval ? (yyvsp[(2) - (2)].dtype).rawval : (yyvsp[(2) - (2)].dtype).val;
            }
    break;

  case 304:

    {
   	      (yyval.decl).type = 0;
              (yyval.decl).id = 0;
	      (yyval.decl).defarg = (yyvsp[(1) - (1)].dtype).rawval ? (yyvsp[(1) - (1)].dtype).rawval : (yyvsp[(1) - (1)].dtype).val;
            }
    break;

  case 305:

    {
	      SwigType *t;
	      (yyval.decl) = (yyvsp[(1) - (5)].decl);
	      t = NewStringEmpty();
	      SwigType_add_function(t,(yyvsp[(3) - (5)].pl));
	      if ((yyvsp[(5) - (5)].dtype).qualifier)
	        SwigType_push(t, (yyvsp[(5) - (5)].dtype).qualifier);
	      if (!(yyval.decl).have_parms) {
		(yyval.decl).parms = (yyvsp[(3) - (5)].pl);
		(yyval.decl).have_parms = 1;
	      }
	      if (!(yyval.decl).type) {
		(yyval.decl).type = t;
	      } else {
		SwigType_push(t, (yyval.decl).type);
		Delete((yyval.decl).type);
		(yyval.decl).type = t;
	      }
	      (yyval.decl).defarg = 0;
	    }
    break;

  case 306:

    {
                 (yyval.decl) = (yyvsp[(1) - (1)].decl);
		 if (SwigType_isfunction((yyvsp[(1) - (1)].decl).type)) {
		   Delete(SwigType_pop_function((yyvsp[(1) - (1)].decl).type));
		 } else if (SwigType_isarray((yyvsp[(1) - (1)].decl).type)) {
		   SwigType *ta = SwigType_pop_arrays((yyvsp[(1) - (1)].decl).type);
		   if (SwigType_isfunction((yyvsp[(1) - (1)].decl).type)) {
		     Delete(SwigType_pop_function((yyvsp[(1) - (1)].decl).type));
		   } else {
		     (yyval.decl).parms = 0;
		   }
		   SwigType_push((yyvsp[(1) - (1)].decl).type,ta);
		   Delete(ta);
		 } else {
		   (yyval.decl).parms = 0;
		 }
            }
    break;

  case 307:

    {
              (yyval.decl) = (yyvsp[(1) - (1)].decl);
	      if (SwigType_isfunction((yyvsp[(1) - (1)].decl).type)) {
		Delete(SwigType_pop_function((yyvsp[(1) - (1)].decl).type));
	      } else if (SwigType_isarray((yyvsp[(1) - (1)].decl).type)) {
		SwigType *ta = SwigType_pop_arrays((yyvsp[(1) - (1)].decl).type);
		if (SwigType_isfunction((yyvsp[(1) - (1)].decl).type)) {
		  Delete(SwigType_pop_function((yyvsp[(1) - (1)].decl).type));
		} else {
		  (yyval.decl).parms = 0;
		}
		SwigType_push((yyvsp[(1) - (1)].decl).type,ta);
		Delete(ta);
	      } else {
		(yyval.decl).parms = 0;
	      }
            }
    break;

  case 308:

    {
	      SwigType *t;
	      (yyval.decl) = (yyvsp[(1) - (5)].decl);
	      t = NewStringEmpty();
	      SwigType_add_function(t, (yyvsp[(3) - (5)].pl));
	      if ((yyvsp[(5) - (5)].dtype).qualifier)
	        SwigType_push(t, (yyvsp[(5) - (5)].dtype).qualifier);
	      if (!(yyval.decl).have_parms) {
		(yyval.decl).parms = (yyvsp[(3) - (5)].pl);
		(yyval.decl).have_parms = 1;
	      }
	      if (!(yyval.decl).type) {
		(yyval.decl).type = t;
	      } else {
		SwigType_push(t, (yyval.decl).type);
		Delete((yyval.decl).type);
		(yyval.decl).type = t;
	      }
	    }
    break;

  case 309:

    {
   	      (yyval.decl).type = 0;
              (yyval.decl).id = 0;
	      (yyval.decl).parms = 0;
	      }
    break;

  case 310:

    {
              (yyval.decl) = (yyvsp[(2) - (2)].decl);
	      if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (2)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (2)].type);
           }
    break;

  case 311:

    {
              (yyval.decl) = (yyvsp[(3) - (3)].decl);
	      SwigType_add_reference((yyvsp[(1) - (3)].type));
              if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (3)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (3)].type);
           }
    break;

  case 312:

    {
              (yyval.decl) = (yyvsp[(3) - (3)].decl);
	      SwigType_add_rvalue_reference((yyvsp[(1) - (3)].type));
              if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (3)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (3)].type);
           }
    break;

  case 313:

    {
              (yyval.decl) = (yyvsp[(1) - (1)].decl);
	      if (!(yyval.decl).type) (yyval.decl).type = NewStringEmpty();
           }
    break;

  case 314:

    {
	     (yyval.decl) = (yyvsp[(2) - (2)].decl);
	     (yyval.decl).type = NewStringEmpty();
	     SwigType_add_reference((yyval.decl).type);
	     if ((yyvsp[(2) - (2)].decl).type) {
	       SwigType_push((yyval.decl).type,(yyvsp[(2) - (2)].decl).type);
	       Delete((yyvsp[(2) - (2)].decl).type);
	     }
           }
    break;

  case 315:

    {
	     /* Introduced in C++11, move operator && */
             /* Adds one S/R conflict */
	     (yyval.decl) = (yyvsp[(2) - (2)].decl);
	     (yyval.decl).type = NewStringEmpty();
	     SwigType_add_rvalue_reference((yyval.decl).type);
	     if ((yyvsp[(2) - (2)].decl).type) {
	       SwigType_push((yyval.decl).type,(yyvsp[(2) - (2)].decl).type);
	       Delete((yyvsp[(2) - (2)].decl).type);
	     }
           }
    break;

  case 316:

    { 
	     SwigType *t = NewStringEmpty();

	     (yyval.decl) = (yyvsp[(3) - (3)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(1) - (3)].str));
	     if ((yyval.decl).type) {
	       SwigType_push(t,(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = t;
	     }
    break;

  case 317:

    { 
	     SwigType *t = NewStringEmpty();
	     (yyval.decl) = (yyvsp[(4) - (4)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(2) - (4)].str));
	     SwigType_push((yyvsp[(1) - (4)].type),t);
	     if ((yyval.decl).type) {
	       SwigType_push((yyvsp[(1) - (4)].type),(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = (yyvsp[(1) - (4)].type);
	     Delete(t);
	   }
    break;

  case 318:

    { 
	     (yyval.decl) = (yyvsp[(5) - (5)].decl);
	     SwigType_add_memberpointer((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str));
	     SwigType_add_reference((yyvsp[(1) - (5)].type));
	     if ((yyval.decl).type) {
	       SwigType_push((yyvsp[(1) - (5)].type),(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = (yyvsp[(1) - (5)].type);
	   }
    break;

  case 319:

    { 
	     SwigType *t = NewStringEmpty();
	     (yyval.decl) = (yyvsp[(4) - (4)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(1) - (4)].str));
	     SwigType_add_reference(t);
	     if ((yyval.decl).type) {
	       SwigType_push(t,(yyval.decl).type);
	       Delete((yyval.decl).type);
	     } 
	     (yyval.decl).type = t;
	   }
    break;

  case 320:

    {
              (yyval.decl) = (yyvsp[(5) - (5)].decl);
	      if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (5)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (5)].type);
           }
    break;

  case 321:

    {
              (yyval.decl) = (yyvsp[(6) - (6)].decl);
	      SwigType_add_reference((yyvsp[(1) - (6)].type));
              if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (6)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (6)].type);
           }
    break;

  case 322:

    {
              (yyval.decl) = (yyvsp[(6) - (6)].decl);
	      SwigType_add_rvalue_reference((yyvsp[(1) - (6)].type));
              if ((yyval.decl).type) {
		SwigType_push((yyvsp[(1) - (6)].type),(yyval.decl).type);
		Delete((yyval.decl).type);
	      }
	      (yyval.decl).type = (yyvsp[(1) - (6)].type);
           }
    break;

  case 323:

    {
              (yyval.decl) = (yyvsp[(4) - (4)].decl);
	      if (!(yyval.decl).type) (yyval.decl).type = NewStringEmpty();
           }
    break;

  case 324:

    {
	     (yyval.decl) = (yyvsp[(5) - (5)].decl);
	     (yyval.decl).type = NewStringEmpty();
	     SwigType_add_reference((yyval.decl).type);
	     if ((yyvsp[(5) - (5)].decl).type) {
	       SwigType_push((yyval.decl).type,(yyvsp[(5) - (5)].decl).type);
	       Delete((yyvsp[(5) - (5)].decl).type);
	     }
           }
    break;

  case 325:

    {
	     /* Introduced in C++11, move operator && */
             /* Adds one S/R conflict */
	     (yyval.decl) = (yyvsp[(5) - (5)].decl);
	     (yyval.decl).type = NewStringEmpty();
	     SwigType_add_rvalue_reference((yyval.decl).type);
	     if ((yyvsp[(5) - (5)].decl).type) {
	       SwigType_push((yyval.decl).type,(yyvsp[(5) - (5)].decl).type);
	       Delete((yyvsp[(5) - (5)].decl).type);
	     }
           }
    break;

  case 326:

    { 
	     SwigType *t = NewStringEmpty();

	     (yyval.decl) = (yyvsp[(6) - (6)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(1) - (6)].str));
	     if ((yyval.decl).type) {
	       SwigType_push(t,(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = t;
	     }
    break;

  case 327:

    { 
	     SwigType *t = NewStringEmpty();
	     (yyval.decl) = (yyvsp[(7) - (7)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(2) - (7)].str));
	     SwigType_push((yyvsp[(1) - (7)].type),t);
	     if ((yyval.decl).type) {
	       SwigType_push((yyvsp[(1) - (7)].type),(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = (yyvsp[(1) - (7)].type);
	     Delete(t);
	   }
    break;

  case 328:

    { 
	     (yyval.decl) = (yyvsp[(8) - (8)].decl);
	     SwigType_add_memberpointer((yyvsp[(1) - (8)].type),(yyvsp[(2) - (8)].str));
	     SwigType_add_reference((yyvsp[(1) - (8)].type));
	     if ((yyval.decl).type) {
	       SwigType_push((yyvsp[(1) - (8)].type),(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = (yyvsp[(1) - (8)].type);
	   }
    break;

  case 329:

    { 
	     (yyval.decl) = (yyvsp[(8) - (8)].decl);
	     SwigType_add_memberpointer((yyvsp[(1) - (8)].type),(yyvsp[(2) - (8)].str));
	     SwigType_add_rvalue_reference((yyvsp[(1) - (8)].type));
	     if ((yyval.decl).type) {
	       SwigType_push((yyvsp[(1) - (8)].type),(yyval.decl).type);
	       Delete((yyval.decl).type);
	     }
	     (yyval.decl).type = (yyvsp[(1) - (8)].type);
	   }
    break;

  case 330:

    { 
	     SwigType *t = NewStringEmpty();
	     (yyval.decl) = (yyvsp[(7) - (7)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(1) - (7)].str));
	     SwigType_add_reference(t);
	     if ((yyval.decl).type) {
	       SwigType_push(t,(yyval.decl).type);
	       Delete((yyval.decl).type);
	     } 
	     (yyval.decl).type = t;
	   }
    break;

  case 331:

    { 
	     SwigType *t = NewStringEmpty();
	     (yyval.decl) = (yyvsp[(7) - (7)].decl);
	     SwigType_add_memberpointer(t,(yyvsp[(1) - (7)].str));
	     SwigType_add_rvalue_reference(t);
	     if ((yyval.decl).type) {
	       SwigType_push(t,(yyval.decl).type);
	       Delete((yyval.decl).type);
	     } 
	     (yyval.decl).type = t;
	   }
    break;

  case 332:

    {
                /* Note: This is non-standard C.  Template declarator is allowed to follow an identifier */
                 (yyval.decl).id = Char((yyvsp[(1) - (1)].str));
		 (yyval.decl).type = 0;
		 (yyval.decl).parms = 0;
		 (yyval.decl).have_parms = 0;
                  }
    break;

  case 333:

    {
                  (yyval.decl).id = Char(NewStringf("~%s",(yyvsp[(2) - (2)].str)));
                  (yyval.decl).type = 0;
                  (yyval.decl).parms = 0;
                  (yyval.decl).have_parms = 0;
                  }
    break;

  case 334:

    {
                  (yyval.decl).id = Char((yyvsp[(2) - (3)].str));
                  (yyval.decl).type = 0;
                  (yyval.decl).parms = 0;
                  (yyval.decl).have_parms = 0;
                  }
    break;

  case 335:

    {
		    (yyval.decl) = (yyvsp[(3) - (4)].decl);
		    if ((yyval.decl).type) {
		      SwigType_push((yyvsp[(2) - (4)].type),(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = (yyvsp[(2) - (4)].type);
                  }
    break;

  case 336:

    {
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(4) - (5)].decl);
		    t = NewStringEmpty();
		    SwigType_add_memberpointer(t,(yyvsp[(2) - (5)].str));
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
		    }
    break;

  case 337:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (3)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,"");
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 338:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,(yyvsp[(3) - (4)].dtype).val);
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 339:

    {
		    SwigType *t;
                    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
		    SwigType_add_function(t,(yyvsp[(3) - (4)].pl));
		    if (!(yyval.decl).have_parms) {
		      (yyval.decl).parms = (yyvsp[(3) - (4)].pl);
		      (yyval.decl).have_parms = 1;
		    }
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = t;
		    } else {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		      (yyval.decl).type = t;
		    }
		  }
    break;

  case 340:

    {
                /* Note: This is non-standard C.  Template declarator is allowed to follow an identifier */
                 (yyval.decl).id = Char((yyvsp[(1) - (1)].str));
		 (yyval.decl).type = 0;
		 (yyval.decl).parms = 0;
		 (yyval.decl).have_parms = 0;
                  }
    break;

  case 341:

    {
                  (yyval.decl).id = Char(NewStringf("~%s",(yyvsp[(2) - (2)].str)));
                  (yyval.decl).type = 0;
                  (yyval.decl).parms = 0;
                  (yyval.decl).have_parms = 0;
                  }
    break;

  case 342:

    {
		    (yyval.decl) = (yyvsp[(3) - (4)].decl);
		    if ((yyval.decl).type) {
		      SwigType_push((yyvsp[(2) - (4)].type),(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = (yyvsp[(2) - (4)].type);
                  }
    break;

  case 343:

    {
                    (yyval.decl) = (yyvsp[(3) - (4)].decl);
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = NewStringEmpty();
		    }
		    SwigType_add_reference((yyval.decl).type);
                  }
    break;

  case 344:

    {
                    (yyval.decl) = (yyvsp[(3) - (4)].decl);
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = NewStringEmpty();
		    }
		    SwigType_add_rvalue_reference((yyval.decl).type);
                  }
    break;

  case 345:

    {
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(4) - (5)].decl);
		    t = NewStringEmpty();
		    SwigType_add_memberpointer(t,(yyvsp[(2) - (5)].str));
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
		  }
    break;

  case 346:

    {
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(5) - (6)].decl);
		    t = NewStringEmpty();
		    SwigType_add_memberpointer(t, (yyvsp[(2) - (6)].str));
		    SwigType_push(t, (yyvsp[(4) - (6)].str));
		    if ((yyval.decl).type) {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
		  }
    break;

  case 347:

    {
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(4) - (5)].decl);
		    t = NewStringEmpty();
		    SwigType_add_memberpointer(t, (yyvsp[(2) - (5)].str));
		    if ((yyval.decl).type) {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
		  }
    break;

  case 348:

    {
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(5) - (6)].decl);
		    t = NewStringEmpty();
		    SwigType_add_memberpointer(t, (yyvsp[(2) - (6)].str));
		    SwigType_push(t, (yyvsp[(4) - (6)].str));
		    if ((yyval.decl).type) {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
		  }
    break;

  case 349:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (3)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,"");
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 350:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,(yyvsp[(3) - (4)].dtype).val);
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 351:

    {
		    SwigType *t;
                    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
		    SwigType_add_function(t,(yyvsp[(3) - (4)].pl));
		    if (!(yyval.decl).have_parms) {
		      (yyval.decl).parms = (yyvsp[(3) - (4)].pl);
		      (yyval.decl).have_parms = 1;
		    }
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = t;
		    } else {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		      (yyval.decl).type = t;
		    }
		  }
    break;

  case 352:

    {
		    SwigType *t;
                    Append((yyvsp[(1) - (5)].str), " "); /* intervening space is mandatory */
                    Append((yyvsp[(1) - (5)].str), Char((yyvsp[(2) - (5)].id)));
		    (yyval.decl).id = Char((yyvsp[(1) - (5)].str));
		    t = NewStringEmpty();
		    SwigType_add_function(t,(yyvsp[(4) - (5)].pl));
		    if (!(yyval.decl).have_parms) {
		      (yyval.decl).parms = (yyvsp[(4) - (5)].pl);
		      (yyval.decl).have_parms = 1;
		    }
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = t;
		    } else {
		      SwigType_push(t, (yyval.decl).type);
		      Delete((yyval.decl).type);
		      (yyval.decl).type = t;
		    }
		  }
    break;

  case 353:

    {
		    (yyval.decl).type = (yyvsp[(1) - (1)].type);
                    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
                  }
    break;

  case 354:

    { 
                     (yyval.decl) = (yyvsp[(2) - (2)].decl);
                     SwigType_push((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].decl).type);
		     (yyval.decl).type = (yyvsp[(1) - (2)].type);
		     Delete((yyvsp[(2) - (2)].decl).type);
                  }
    break;

  case 355:

    {
		    (yyval.decl).type = (yyvsp[(1) - (2)].type);
		    SwigType_add_reference((yyval.decl).type);
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		  }
    break;

  case 356:

    {
		    (yyval.decl).type = (yyvsp[(1) - (2)].type);
		    SwigType_add_rvalue_reference((yyval.decl).type);
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		  }
    break;

  case 357:

    {
		    (yyval.decl) = (yyvsp[(3) - (3)].decl);
		    SwigType_add_reference((yyvsp[(1) - (3)].type));
		    if ((yyval.decl).type) {
		      SwigType_push((yyvsp[(1) - (3)].type),(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = (yyvsp[(1) - (3)].type);
                  }
    break;

  case 358:

    {
		    (yyval.decl) = (yyvsp[(3) - (3)].decl);
		    SwigType_add_rvalue_reference((yyvsp[(1) - (3)].type));
		    if ((yyval.decl).type) {
		      SwigType_push((yyvsp[(1) - (3)].type),(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = (yyvsp[(1) - (3)].type);
                  }
    break;

  case 359:

    {
		    (yyval.decl) = (yyvsp[(1) - (1)].decl);
                  }
    break;

  case 360:

    {
		    (yyval.decl) = (yyvsp[(2) - (2)].decl);
		    (yyval.decl).type = NewStringEmpty();
		    SwigType_add_reference((yyval.decl).type);
		    if ((yyvsp[(2) - (2)].decl).type) {
		      SwigType_push((yyval.decl).type,(yyvsp[(2) - (2)].decl).type);
		      Delete((yyvsp[(2) - (2)].decl).type);
		    }
                  }
    break;

  case 361:

    {
		    (yyval.decl) = (yyvsp[(2) - (2)].decl);
		    (yyval.decl).type = NewStringEmpty();
		    SwigType_add_rvalue_reference((yyval.decl).type);
		    if ((yyvsp[(2) - (2)].decl).type) {
		      SwigType_push((yyval.decl).type,(yyvsp[(2) - (2)].decl).type);
		      Delete((yyvsp[(2) - (2)].decl).type);
		    }
                  }
    break;

  case 362:

    {
                    (yyval.decl).id = 0;
                    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
                    (yyval.decl).type = NewStringEmpty();
		    SwigType_add_reference((yyval.decl).type);
                  }
    break;

  case 363:

    {
                    (yyval.decl).id = 0;
                    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
                    (yyval.decl).type = NewStringEmpty();
		    SwigType_add_rvalue_reference((yyval.decl).type);
                  }
    break;

  case 364:

    { 
		    (yyval.decl).type = NewStringEmpty();
                    SwigType_add_memberpointer((yyval.decl).type,(yyvsp[(1) - (2)].str));
                    (yyval.decl).id = 0;
                    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
      	          }
    break;

  case 365:

    {
		    (yyval.decl).type = NewStringEmpty();
		    SwigType_add_memberpointer((yyval.decl).type, (yyvsp[(1) - (3)].str));
		    SwigType_push((yyval.decl).type, (yyvsp[(3) - (3)].str));
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		  }
    break;

  case 366:

    { 
		    SwigType *t = NewStringEmpty();
                    (yyval.decl).type = (yyvsp[(1) - (3)].type);
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		    SwigType_add_memberpointer(t,(yyvsp[(2) - (3)].str));
		    SwigType_push((yyval.decl).type,t);
		    Delete(t);
                  }
    break;

  case 367:

    { 
		    (yyval.decl) = (yyvsp[(4) - (4)].decl);
		    SwigType_add_memberpointer((yyvsp[(1) - (4)].type),(yyvsp[(2) - (4)].str));
		    if ((yyval.decl).type) {
		      SwigType_push((yyvsp[(1) - (4)].type),(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = (yyvsp[(1) - (4)].type);
                  }
    break;

  case 368:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (3)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,"");
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 369:

    { 
		    SwigType *t;
		    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
		    SwigType_add_array(t,(yyvsp[(3) - (4)].dtype).val);
		    if ((yyval.decl).type) {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		    }
		    (yyval.decl).type = t;
                  }
    break;

  case 370:

    { 
		    (yyval.decl).type = NewStringEmpty();
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		    SwigType_add_array((yyval.decl).type,"");
                  }
    break;

  case 371:

    { 
		    (yyval.decl).type = NewStringEmpty();
		    (yyval.decl).id = 0;
		    (yyval.decl).parms = 0;
		    (yyval.decl).have_parms = 0;
		    SwigType_add_array((yyval.decl).type,(yyvsp[(2) - (3)].dtype).val);
		  }
    break;

  case 372:

    {
                    (yyval.decl) = (yyvsp[(2) - (3)].decl);
		  }
    break;

  case 373:

    {
		    SwigType *t;
                    (yyval.decl) = (yyvsp[(1) - (4)].decl);
		    t = NewStringEmpty();
                    SwigType_add_function(t,(yyvsp[(3) - (4)].pl));
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = t;
		    } else {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		      (yyval.decl).type = t;
		    }
		    if (!(yyval.decl).have_parms) {
		      (yyval.decl).parms = (yyvsp[(3) - (4)].pl);
		      (yyval.decl).have_parms = 1;
		    }
		  }
    break;

  case 374:

    {
		    SwigType *t;
                    (yyval.decl) = (yyvsp[(1) - (5)].decl);
		    t = NewStringEmpty();
                    SwigType_add_function(t,(yyvsp[(3) - (5)].pl));
		    SwigType_push(t, (yyvsp[(5) - (5)].dtype).qualifier);
		    if (!(yyval.decl).type) {
		      (yyval.decl).type = t;
		    } else {
		      SwigType_push(t,(yyval.decl).type);
		      Delete((yyval.decl).type);
		      (yyval.decl).type = t;
		    }
		    if (!(yyval.decl).have_parms) {
		      (yyval.decl).parms = (yyvsp[(3) - (5)].pl);
		      (yyval.decl).have_parms = 1;
		    }
		  }
    break;

  case 375:

    {
                    (yyval.decl).type = NewStringEmpty();
                    SwigType_add_function((yyval.decl).type,(yyvsp[(2) - (3)].pl));
		    (yyval.decl).parms = (yyvsp[(2) - (3)].pl);
		    (yyval.decl).have_parms = 1;
		    (yyval.decl).id = 0;
                  }
    break;

  case 376:

    { 
             (yyval.type) = NewStringEmpty();
             SwigType_add_pointer((yyval.type));
	     SwigType_push((yyval.type),(yyvsp[(2) - (3)].str));
	     SwigType_push((yyval.type),(yyvsp[(3) - (3)].type));
	     Delete((yyvsp[(3) - (3)].type));
           }
    break;

  case 377:

    {
	     (yyval.type) = NewStringEmpty();
	     SwigType_add_pointer((yyval.type));
	     SwigType_push((yyval.type),(yyvsp[(2) - (2)].type));
	     Delete((yyvsp[(2) - (2)].type));
	   }
    break;

  case 378:

    { 
	     (yyval.type) = NewStringEmpty();
	     SwigType_add_pointer((yyval.type));
	     SwigType_push((yyval.type),(yyvsp[(2) - (2)].str));
           }
    break;

  case 379:

    {
	     (yyval.type) = NewStringEmpty();
	     SwigType_add_pointer((yyval.type));
           }
    break;

  case 380:

    {
		  (yyval.dtype).qualifier = (yyvsp[(1) - (1)].str);
		  (yyval.dtype).refqualifier = 0;
	       }
    break;

  case 381:

    {
		  (yyval.dtype).qualifier = (yyvsp[(1) - (2)].str);
		  (yyval.dtype).refqualifier = (yyvsp[(2) - (2)].str);
		  SwigType_push((yyval.dtype).qualifier, (yyvsp[(2) - (2)].str));
	       }
    break;

  case 382:

    {
		  (yyval.dtype).qualifier = NewStringEmpty();
		  (yyval.dtype).refqualifier = (yyvsp[(1) - (1)].str);
		  SwigType_push((yyval.dtype).qualifier, (yyvsp[(1) - (1)].str));
	       }
    break;

  case 383:

    {
	          (yyval.str) = NewStringEmpty();
	          SwigType_add_reference((yyval.str));
	       }
    break;

  case 384:

    {
	          (yyval.str) = NewStringEmpty();
	          SwigType_add_rvalue_reference((yyval.str));
	       }
    break;

  case 385:

    {
	          (yyval.str) = NewStringEmpty();
	          if ((yyvsp[(1) - (1)].id)) SwigType_add_qualifier((yyval.str),(yyvsp[(1) - (1)].id));
               }
    break;

  case 386:

    {
		  (yyval.str) = (yyvsp[(2) - (2)].str);
	          if ((yyvsp[(1) - (2)].id)) SwigType_add_qualifier((yyval.str),(yyvsp[(1) - (2)].id));
               }
    break;

  case 387:

    { (yyval.id) = "const"; }
    break;

  case 388:

    { (yyval.id) = "volatile"; }
    break;

  case 389:

    { (yyval.id) = 0; }
    break;

  case 390:

    {
                   (yyval.type) = (yyvsp[(1) - (1)].type);
                   Replace((yyval.type),"typename ","", DOH_REPLACE_ANY);
                }
    break;

  case 391:

    {
                   (yyval.type) = (yyvsp[(2) - (2)].type);
	           SwigType_push((yyval.type),(yyvsp[(1) - (2)].str));
               }
    break;

  case 392:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 393:

    {
		  (yyval.type) = (yyvsp[(1) - (2)].type);
	          SwigType_push((yyval.type),(yyvsp[(2) - (2)].str));
	       }
    break;

  case 394:

    {
		  (yyval.type) = (yyvsp[(2) - (3)].type);
	          SwigType_push((yyval.type),(yyvsp[(3) - (3)].str));
	          SwigType_push((yyval.type),(yyvsp[(1) - (3)].str));
	       }
    break;

  case 395:

    { (yyval.type) = (yyvsp[(1) - (1)].type);
                  /* Printf(stdout,"primitive = '%s'\n", $$);*/
               }
    break;

  case 396:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 397:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 398:

    { (yyval.type) = NewStringf("enum %s", (yyvsp[(2) - (2)].str)); }
    break;

  case 399:

    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 400:

    {
		  (yyval.type) = (yyvsp[(1) - (1)].str);
               }
    break;

  case 401:

    { 
		 (yyval.type) = NewStringf("%s %s", (yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].str));
               }
    break;

  case 402:

    {
                 (yyval.type) = (yyvsp[(1) - (1)].type);
               }
    break;

  case 403:

    {
                 Node *n = Swig_symbol_clookup((yyvsp[(3) - (4)].str),0);
                 if (!n) {
		   Swig_error(cparse_file, cparse_line, "Identifier %s not defined.\n", (yyvsp[(3) - (4)].str));
                   (yyval.type) = (yyvsp[(3) - (4)].str);
                 } else {
                   (yyval.type) = Getattr(n, "type");
                 }
               }
    break;

  case 404:

    {
		 if (!(yyvsp[(1) - (1)].ptype).type) (yyvsp[(1) - (1)].ptype).type = NewString("int");
		 if ((yyvsp[(1) - (1)].ptype).us) {
		   (yyval.type) = NewStringf("%s %s", (yyvsp[(1) - (1)].ptype).us, (yyvsp[(1) - (1)].ptype).type);
		   Delete((yyvsp[(1) - (1)].ptype).us);
                   Delete((yyvsp[(1) - (1)].ptype).type);
		 } else {
                   (yyval.type) = (yyvsp[(1) - (1)].ptype).type;
		 }
		 if (Cmp((yyval.type),"signed int") == 0) {
		   Delete((yyval.type));
		   (yyval.type) = NewString("int");
                 } else if (Cmp((yyval.type),"signed long") == 0) {
		   Delete((yyval.type));
                   (yyval.type) = NewString("long");
                 } else if (Cmp((yyval.type),"signed short") == 0) {
		   Delete((yyval.type));
		   (yyval.type) = NewString("short");
		 } else if (Cmp((yyval.type),"signed long long") == 0) {
		   Delete((yyval.type));
		   (yyval.type) = NewString("long long");
		 }
               }
    break;

  case 405:

    { 
                 (yyval.ptype) = (yyvsp[(1) - (1)].ptype);
               }
    break;

  case 406:

    {
                    if ((yyvsp[(1) - (2)].ptype).us && (yyvsp[(2) - (2)].ptype).us) {
		      Swig_error(cparse_file, cparse_line, "Extra %s specifier.\n", (yyvsp[(2) - (2)].ptype).us);
		    }
                    (yyval.ptype) = (yyvsp[(2) - (2)].ptype);
                    if ((yyvsp[(1) - (2)].ptype).us) (yyval.ptype).us = (yyvsp[(1) - (2)].ptype).us;
		    if ((yyvsp[(1) - (2)].ptype).type) {
		      if (!(yyvsp[(2) - (2)].ptype).type) (yyval.ptype).type = (yyvsp[(1) - (2)].ptype).type;
		      else {
			int err = 0;
			if ((Cmp((yyvsp[(1) - (2)].ptype).type,"long") == 0)) {
			  if ((Cmp((yyvsp[(2) - (2)].ptype).type,"long") == 0) || (Strncmp((yyvsp[(2) - (2)].ptype).type,"double",6) == 0)) {
			    (yyval.ptype).type = NewStringf("long %s", (yyvsp[(2) - (2)].ptype).type);
			  } else if (Cmp((yyvsp[(2) - (2)].ptype).type,"int") == 0) {
			    (yyval.ptype).type = (yyvsp[(1) - (2)].ptype).type;
			  } else {
			    err = 1;
			  }
			} else if ((Cmp((yyvsp[(1) - (2)].ptype).type,"short")) == 0) {
			  if (Cmp((yyvsp[(2) - (2)].ptype).type,"int") == 0) {
			    (yyval.ptype).type = (yyvsp[(1) - (2)].ptype).type;
			  } else {
			    err = 1;
			  }
			} else if (Cmp((yyvsp[(1) - (2)].ptype).type,"int") == 0) {
			  (yyval.ptype).type = (yyvsp[(2) - (2)].ptype).type;
			} else if (Cmp((yyvsp[(1) - (2)].ptype).type,"double") == 0) {
			  if (Cmp((yyvsp[(2) - (2)].ptype).type,"long") == 0) {
			    (yyval.ptype).type = NewString("long double");
			  } else if (Cmp((yyvsp[(2) - (2)].ptype).type,"complex") == 0) {
			    (yyval.ptype).type = NewString("double complex");
			  } else {
			    err = 1;
			  }
			} else if (Cmp((yyvsp[(1) - (2)].ptype).type,"float") == 0) {
			  if (Cmp((yyvsp[(2) - (2)].ptype).type,"complex") == 0) {
			    (yyval.ptype).type = NewString("float complex");
			  } else {
			    err = 1;
			  }
			} else if (Cmp((yyvsp[(1) - (2)].ptype).type,"complex") == 0) {
			  (yyval.ptype).type = NewStringf("%s complex", (yyvsp[(2) - (2)].ptype).type);
			} else {
			  err = 1;
			}
			if (err) {
			  Swig_error(cparse_file, cparse_line, "Extra %s specifier.\n", (yyvsp[(1) - (2)].ptype).type);
			}
		      }
		    }
               }
    break;

  case 407:

    { 
		    (yyval.ptype).type = NewString("int");
                    (yyval.ptype).us = 0;
               }
    break;

  case 408:

    { 
                    (yyval.ptype).type = NewString("short");
                    (yyval.ptype).us = 0;
                }
    break;

  case 409:

    { 
                    (yyval.ptype).type = NewString("long");
                    (yyval.ptype).us = 0;
                }
    break;

  case 410:

    { 
                    (yyval.ptype).type = NewString("char");
                    (yyval.ptype).us = 0;
                }
    break;

  case 411:

    { 
                    (yyval.ptype).type = NewString("wchar_t");
                    (yyval.ptype).us = 0;
                }
    break;

  case 412:

    { 
                    (yyval.ptype).type = NewString("float");
                    (yyval.ptype).us = 0;
                }
    break;

  case 413:

    { 
                    (yyval.ptype).type = NewString("double");
                    (yyval.ptype).us = 0;
                }
    break;

  case 414:

    { 
                    (yyval.ptype).us = NewString("signed");
                    (yyval.ptype).type = 0;
                }
    break;

  case 415:

    { 
                    (yyval.ptype).us = NewString("unsigned");
                    (yyval.ptype).type = 0;
                }
    break;

  case 416:

    { 
                    (yyval.ptype).type = NewString("complex");
                    (yyval.ptype).us = 0;
                }
    break;

  case 417:

    { 
                    (yyval.ptype).type = NewString("__int8");
                    (yyval.ptype).us = 0;
                }
    break;

  case 418:

    { 
                    (yyval.ptype).type = NewString("__int16");
                    (yyval.ptype).us = 0;
                }
    break;

  case 419:

    { 
                    (yyval.ptype).type = NewString("__int32");
                    (yyval.ptype).us = 0;
                }
    break;

  case 420:

    { 
                    (yyval.ptype).type = NewString("__int64");
                    (yyval.ptype).us = 0;
                }
    break;

  case 421:

    { /* scanner_check_typedef(); */ }
    break;

  case 422:

    {
                   (yyval.dtype) = (yyvsp[(2) - (2)].dtype);
		   if ((yyval.dtype).type == T_STRING) {
		     (yyval.dtype).rawval = NewStringf("\"%(escape)s\"",(yyval.dtype).val);
		   } else if ((yyval.dtype).type != T_CHAR && (yyval.dtype).type != T_WSTRING && (yyval.dtype).type != T_WCHAR) {
		     (yyval.dtype).rawval = NewStringf("%s", (yyval.dtype).val);
		   }
		   (yyval.dtype).qualifier = 0;
		   (yyval.dtype).refqualifier = 0;
		   (yyval.dtype).bitfield = 0;
		   (yyval.dtype).throws = 0;
		   (yyval.dtype).throwf = 0;
		   (yyval.dtype).nexcept = 0;
		   (yyval.dtype).final = 0;
		   scanner_ignore_typedef();
                }
    break;

  case 423:

    {
		  (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
		}
    break;

  case 424:

    {
		  (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
		}
    break;

  case 425:

    {
		  (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
		}
    break;

  case 426:

    {
		  (yyval.dtype).val = NewString("delete");
		  (yyval.dtype).rawval = 0;
		  (yyval.dtype).type = T_STRING;
		  (yyval.dtype).qualifier = 0;
		  (yyval.dtype).refqualifier = 0;
		  (yyval.dtype).bitfield = 0;
		  (yyval.dtype).throws = 0;
		  (yyval.dtype).throwf = 0;
		  (yyval.dtype).nexcept = 0;
		  (yyval.dtype).final = 0;
		}
    break;

  case 427:

    {
		  (yyval.dtype).val = NewString("default");
		  (yyval.dtype).rawval = 0;
		  (yyval.dtype).type = T_STRING;
		  (yyval.dtype).qualifier = 0;
		  (yyval.dtype).refqualifier = 0;
		  (yyval.dtype).bitfield = 0;
		  (yyval.dtype).throws = 0;
		  (yyval.dtype).throwf = 0;
		  (yyval.dtype).nexcept = 0;
		  (yyval.dtype).final = 0;
		}
    break;

  case 428:

    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 429:

    { (yyval.id) = (char *) 0;}
    break;

  case 434:

    {
		  Setattr((yyvsp[(1) - (1)].node),"_last",(yyvsp[(1) - (1)].node));
		  (yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 435:

    {
		  Setattr((yyvsp[(1) - (2)].node),"_last",(yyvsp[(1) - (2)].node));
		  set_comment((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].str));
		  (yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 436:

    {
		  if ((yyvsp[(3) - (3)].node)) {
		    set_nextSibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    Setattr((yyvsp[(1) - (3)].node),"_last",Getattr((yyvsp[(3) - (3)].node),"_last"));
		    Setattr((yyvsp[(3) - (3)].node),"_last",NULL);
		  }
		  (yyval.node) = (yyvsp[(1) - (3)].node);
		}
    break;

  case 437:

    {
		  if ((yyvsp[(4) - (4)].node)) {
		    set_nextSibling((yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));
		    Setattr((yyvsp[(1) - (4)].node),"_last",Getattr((yyvsp[(4) - (4)].node),"_last"));
		    Setattr((yyvsp[(4) - (4)].node),"_last",NULL);
		  }
		  set_comment((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].str));
		  (yyval.node) = (yyvsp[(1) - (4)].node);
		}
    break;

  case 438:

    {
		  (yyval.node) = 0;
		}
    break;

  case 439:

    {
		  (yyval.node) = (yyvsp[(2) - (3)].node);
		}
    break;

  case 440:

    {
		  (yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 441:

    {
		  (yyval.node) = (yyvsp[(2) - (2)].node);
		  set_comment((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].str));
		}
    break;

  case 442:

    {
		   SwigType *type = NewSwigType(T_INT);
		   (yyval.node) = new_node("enumitem");
		   Setattr((yyval.node),"name",(yyvsp[(1) - (1)].id));
		   Setattr((yyval.node),"type",type);
		   SetFlag((yyval.node),"feature:immutable");
		   Delete(type);
		 }
    break;

  case 443:

    {
		   SwigType *type = NewSwigType((yyvsp[(3) - (3)].dtype).type == T_BOOL ? T_BOOL : ((yyvsp[(3) - (3)].dtype).type == T_CHAR ? T_CHAR : T_INT));
		   (yyval.node) = new_node("enumitem");
		   Setattr((yyval.node),"name",(yyvsp[(1) - (3)].id));
		   Setattr((yyval.node),"type",type);
		   SetFlag((yyval.node),"feature:immutable");
		   Setattr((yyval.node),"enumvalue", (yyvsp[(3) - (3)].dtype).val);
		   Setattr((yyval.node),"value",(yyvsp[(1) - (3)].id));
		   Delete(type);
                 }
    break;

  case 444:

    {
                   (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
		   if (((yyval.dtype).type != T_INT) && ((yyval.dtype).type != T_UINT) &&
		       ((yyval.dtype).type != T_LONG) && ((yyval.dtype).type != T_ULONG) &&
		       ((yyval.dtype).type != T_LONGLONG) && ((yyval.dtype).type != T_ULONGLONG) &&
		       ((yyval.dtype).type != T_SHORT) && ((yyval.dtype).type != T_USHORT) &&
		       ((yyval.dtype).type != T_SCHAR) && ((yyval.dtype).type != T_UCHAR) &&
		       ((yyval.dtype).type != T_CHAR) && ((yyval.dtype).type != T_BOOL)) {
		     Swig_error(cparse_file,cparse_line,"Type error. Expecting an integral type\n");
		   }
                }
    break;

  case 445:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 446:

    {
		 Node *n;
		 (yyval.dtype).val = (yyvsp[(1) - (1)].type);
		 (yyval.dtype).type = T_INT;
		 /* Check if value is in scope */
		 n = Swig_symbol_clookup((yyvsp[(1) - (1)].type),0);
		 if (n) {
                   /* A band-aid for enum values used in expressions. */
                   if (Strcmp(nodeType(n),"enumitem") == 0) {
                     String *q = Swig_symbol_qualified(n);
                     if (q) {
                       (yyval.dtype).val = NewStringf("%s::%s", q, Getattr(n,"name"));
                       Delete(q);
                     }
                   }
		 }
               }
    break;

  case 447:

    {
		 (yyval.dtype).val = NewStringf("%s->%s", (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));
		 (yyval.dtype).type = 0;
	       }
    break;

  case 448:

    {
		 (yyval.dtype) = (yyvsp[(1) - (3)].dtype);
		 Printf((yyval.dtype).val, "->%s", (yyvsp[(3) - (3)].id));
	       }
    break;

  case 449:

    {
		 (yyval.dtype) = (yyvsp[(1) - (3)].dtype);
		 Printf((yyval.dtype).val, ".%s", (yyvsp[(3) - (3)].id));
	       }
    break;

  case 450:

    {
		    (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
               }
    break;

  case 451:

    {
		    (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
               }
    break;

  case 452:

    {
		    (yyval.dtype).val = (yyvsp[(1) - (1)].str);
                    (yyval.dtype).type = T_STRING;
               }
    break;

  case 453:

    {
		  SwigType_push((yyvsp[(3) - (5)].type),(yyvsp[(4) - (5)].decl).type);
		  (yyval.dtype).val = NewStringf("sizeof(%s)",SwigType_str((yyvsp[(3) - (5)].type),0));
		  (yyval.dtype).type = T_ULONG;
               }
    break;

  case 454:

    {
		  SwigType_push((yyvsp[(6) - (8)].type),(yyvsp[(7) - (8)].decl).type);
		  (yyval.dtype).val = NewStringf("sizeof...(%s)",SwigType_str((yyvsp[(6) - (8)].type),0));
		  (yyval.dtype).type = T_ULONG;
               }
    break;

  case 455:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 456:

    {
		    (yyval.dtype).val = (yyvsp[(1) - (1)].str);
		    (yyval.dtype).rawval = NewStringf("L\"%s\"", (yyval.dtype).val);
                    (yyval.dtype).type = T_WSTRING;
	       }
    break;

  case 457:

    {
		  (yyval.dtype).val = NewString((yyvsp[(1) - (1)].str));
		  if (Len((yyval.dtype).val)) {
		    (yyval.dtype).rawval = NewStringf("'%(escape)s'", (yyval.dtype).val);
		  } else {
		    (yyval.dtype).rawval = NewString("'\\0'");
		  }
		  (yyval.dtype).type = T_CHAR;
		  (yyval.dtype).bitfield = 0;
		  (yyval.dtype).throws = 0;
		  (yyval.dtype).throwf = 0;
		  (yyval.dtype).nexcept = 0;
		  (yyval.dtype).final = 0;
	       }
    break;

  case 458:

    {
		  (yyval.dtype).val = NewString((yyvsp[(1) - (1)].str));
		  if (Len((yyval.dtype).val)) {
		    (yyval.dtype).rawval = NewStringf("L\'%s\'", (yyval.dtype).val);
		  } else {
		    (yyval.dtype).rawval = NewString("L'\\0'");
		  }
		  (yyval.dtype).type = T_WCHAR;
		  (yyval.dtype).bitfield = 0;
		  (yyval.dtype).throws = 0;
		  (yyval.dtype).throwf = 0;
		  (yyval.dtype).nexcept = 0;
		  (yyval.dtype).final = 0;
	       }
    break;

  case 459:

    {
		    (yyval.dtype).val = NewStringf("(%s)",(yyvsp[(2) - (3)].dtype).val);
		    if ((yyvsp[(2) - (3)].dtype).rawval) {
		      (yyval.dtype).rawval = NewStringf("(%s)",(yyvsp[(2) - (3)].dtype).rawval);
		    }
		    (yyval.dtype).type = (yyvsp[(2) - (3)].dtype).type;
	       }
    break;

  case 460:

    {
                 (yyval.dtype) = (yyvsp[(4) - (4)].dtype);
		 if ((yyvsp[(4) - (4)].dtype).type != T_STRING) {
		   switch ((yyvsp[(2) - (4)].dtype).type) {
		     case T_FLOAT:
		     case T_DOUBLE:
		     case T_LONGDOUBLE:
		     case T_FLTCPLX:
		     case T_DBLCPLX:
		       (yyval.dtype).val = NewStringf("(%s)%s", (yyvsp[(2) - (4)].dtype).val, (yyvsp[(4) - (4)].dtype).val); /* SwigType_str and decimal points don't mix! */
		       break;
		     default:
		       (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (4)].dtype).val,0), (yyvsp[(4) - (4)].dtype).val);
		       break;
		   }
		 }
		 (yyval.dtype).type = promote((yyvsp[(2) - (4)].dtype).type, (yyvsp[(4) - (4)].dtype).type);
 	       }
    break;

  case 461:

    {
                 (yyval.dtype) = (yyvsp[(5) - (5)].dtype);
		 if ((yyvsp[(5) - (5)].dtype).type != T_STRING) {
		   SwigType_push((yyvsp[(2) - (5)].dtype).val,(yyvsp[(3) - (5)].type));
		   (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (5)].dtype).val,0), (yyvsp[(5) - (5)].dtype).val);
		 }
 	       }
    break;

  case 462:

    {
                 (yyval.dtype) = (yyvsp[(5) - (5)].dtype);
		 if ((yyvsp[(5) - (5)].dtype).type != T_STRING) {
		   SwigType_add_reference((yyvsp[(2) - (5)].dtype).val);
		   (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (5)].dtype).val,0), (yyvsp[(5) - (5)].dtype).val);
		 }
 	       }
    break;

  case 463:

    {
                 (yyval.dtype) = (yyvsp[(5) - (5)].dtype);
		 if ((yyvsp[(5) - (5)].dtype).type != T_STRING) {
		   SwigType_add_rvalue_reference((yyvsp[(2) - (5)].dtype).val);
		   (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (5)].dtype).val,0), (yyvsp[(5) - (5)].dtype).val);
		 }
 	       }
    break;

  case 464:

    {
                 (yyval.dtype) = (yyvsp[(6) - (6)].dtype);
		 if ((yyvsp[(6) - (6)].dtype).type != T_STRING) {
		   SwigType_push((yyvsp[(2) - (6)].dtype).val,(yyvsp[(3) - (6)].type));
		   SwigType_add_reference((yyvsp[(2) - (6)].dtype).val);
		   (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (6)].dtype).val,0), (yyvsp[(6) - (6)].dtype).val);
		 }
 	       }
    break;

  case 465:

    {
                 (yyval.dtype) = (yyvsp[(6) - (6)].dtype);
		 if ((yyvsp[(6) - (6)].dtype).type != T_STRING) {
		   SwigType_push((yyvsp[(2) - (6)].dtype).val,(yyvsp[(3) - (6)].type));
		   SwigType_add_rvalue_reference((yyvsp[(2) - (6)].dtype).val);
		   (yyval.dtype).val = NewStringf("(%s) %s", SwigType_str((yyvsp[(2) - (6)].dtype).val,0), (yyvsp[(6) - (6)].dtype).val);
		 }
 	       }
    break;

  case 466:

    {
		 (yyval.dtype) = (yyvsp[(2) - (2)].dtype);
                 (yyval.dtype).val = NewStringf("&%s",(yyvsp[(2) - (2)].dtype).val);
	       }
    break;

  case 467:

    {
		 (yyval.dtype) = (yyvsp[(2) - (2)].dtype);
                 (yyval.dtype).val = NewStringf("&&%s",(yyvsp[(2) - (2)].dtype).val);
	       }
    break;

  case 468:

    {
		 (yyval.dtype) = (yyvsp[(2) - (2)].dtype);
                 (yyval.dtype).val = NewStringf("*%s",(yyvsp[(2) - (2)].dtype).val);
	       }
    break;

  case 469:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 470:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 471:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 472:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 473:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 474:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 475:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 476:

    { (yyval.dtype) = (yyvsp[(1) - (1)].dtype); }
    break;

  case 477:

    {
		 (yyval.dtype).val = NewStringf("%s+%s", COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 478:

    {
		 (yyval.dtype).val = NewStringf("%s-%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 479:

    {
		 (yyval.dtype).val = NewStringf("%s*%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 480:

    {
		 (yyval.dtype).val = NewStringf("%s/%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 481:

    {
		 (yyval.dtype).val = NewStringf("%s%%%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 482:

    {
		 (yyval.dtype).val = NewStringf("%s&%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 483:

    {
		 (yyval.dtype).val = NewStringf("%s|%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 484:

    {
		 (yyval.dtype).val = NewStringf("%s^%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote((yyvsp[(1) - (3)].dtype).type,(yyvsp[(3) - (3)].dtype).type);
	       }
    break;

  case 485:

    {
		 (yyval.dtype).val = NewStringf("%s << %s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote_type((yyvsp[(1) - (3)].dtype).type);
	       }
    break;

  case 486:

    {
		 (yyval.dtype).val = NewStringf("%s >> %s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = promote_type((yyvsp[(1) - (3)].dtype).type);
	       }
    break;

  case 487:

    {
		 (yyval.dtype).val = NewStringf("%s&&%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 488:

    {
		 (yyval.dtype).val = NewStringf("%s||%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 489:

    {
		 (yyval.dtype).val = NewStringf("%s==%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 490:

    {
		 (yyval.dtype).val = NewStringf("%s!=%s",COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)),COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 491:

    {
		 (yyval.dtype).val = NewStringf("%s >= %s", COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)), COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 492:

    {
		 (yyval.dtype).val = NewStringf("%s <= %s", COMPOUND_EXPR_VAL((yyvsp[(1) - (3)].dtype)), COMPOUND_EXPR_VAL((yyvsp[(3) - (3)].dtype)));
		 (yyval.dtype).type = cparse_cplusplus ? T_BOOL : T_INT;
	       }
    break;

  case 493:

    {
		 (yyval.dtype).val = NewStringf("%s?%s:%s", COMPOUND_EXPR_VAL((yyvsp[(1) - (5)].dtype)), COMPOUND_EXPR_VAL((yyvsp[(3) - (5)].dtype)), COMPOUND_EXPR_VAL((yyvsp[(5) - (5)].dtype)));
		 /* This may not be exactly right, but is probably good enough
		  * for the purposes of parsing constant expressions. */
		 (yyval.dtype).type = promote((yyvsp[(3) - (5)].dtype).type, (yyvsp[(5) - (5)].dtype).type);
	       }
    break;

  case 494:

    {
		 (yyval.dtype).val = NewStringf("-%s",(yyvsp[(2) - (2)].dtype).val);
		 (yyval.dtype).type = (yyvsp[(2) - (2)].dtype).type;
	       }
    break;

  case 495:

    {
                 (yyval.dtype).val = NewStringf("+%s",(yyvsp[(2) - (2)].dtype).val);
		 (yyval.dtype).type = (yyvsp[(2) - (2)].dtype).type;
	       }
    break;

  case 496:

    {
		 (yyval.dtype).val = NewStringf("~%s",(yyvsp[(2) - (2)].dtype).val);
		 (yyval.dtype).type = (yyvsp[(2) - (2)].dtype).type;
	       }
    break;

  case 497:

    {
                 (yyval.dtype).val = NewStringf("!%s",COMPOUND_EXPR_VAL((yyvsp[(2) - (2)].dtype)));
		 (yyval.dtype).type = T_INT;
	       }
    break;

  case 498:

    {
		 String *qty;
                 skip_balanced('(',')');
		 qty = Swig_symbol_type_qualify((yyvsp[(1) - (2)].type),0);
		 if (SwigType_istemplate(qty)) {
		   String *nstr = SwigType_namestr(qty);
		   Delete(qty);
		   qty = nstr;
		 }
		 (yyval.dtype).val = NewStringf("%s%s",qty,scanner_ccode);
		 Clear(scanner_ccode);
		 (yyval.dtype).type = T_INT;
		 Delete(qty);
               }
    break;

  case 499:

    {
	        (yyval.str) = NewString("...");
	      }
    break;

  case 500:

    {
	        (yyval.str) = (yyvsp[(1) - (1)].str);
	      }
    break;

  case 501:

    {
	        (yyval.str) = 0;
	      }
    break;

  case 502:

    {
		 (yyval.bases) = (yyvsp[(1) - (1)].bases);
               }
    break;

  case 503:

    { inherit_list = 1; }
    break;

  case 504:

    { (yyval.bases) = (yyvsp[(3) - (3)].bases); inherit_list = 0; }
    break;

  case 505:

    { (yyval.bases) = 0; }
    break;

  case 506:

    {
		   Hash *list = NewHash();
		   Node *base = (yyvsp[(1) - (1)].node);
		   Node *name = Getattr(base,"name");
		   List *lpublic = NewList();
		   List *lprotected = NewList();
		   List *lprivate = NewList();
		   Setattr(list,"public",lpublic);
		   Setattr(list,"protected",lprotected);
		   Setattr(list,"private",lprivate);
		   Delete(lpublic);
		   Delete(lprotected);
		   Delete(lprivate);
		   Append(Getattr(list,Getattr(base,"access")),name);
	           (yyval.bases) = list;
               }
    break;

  case 507:

    {
		   Hash *list = (yyvsp[(1) - (3)].bases);
		   Node *base = (yyvsp[(3) - (3)].node);
		   Node *name = Getattr(base,"name");
		   Append(Getattr(list,Getattr(base,"access")),name);
                   (yyval.bases) = list;
               }
    break;

  case 508:

    {
		 (yyval.intvalue) = cparse_line;
	       }
    break;

  case 509:

    {
		 (yyval.node) = NewHash();
		 Setfile((yyval.node),cparse_file);
		 Setline((yyval.node),(yyvsp[(2) - (4)].intvalue));
		 Setattr((yyval.node),"name",(yyvsp[(3) - (4)].str));
		 Setfile((yyvsp[(3) - (4)].str),cparse_file);
		 Setline((yyvsp[(3) - (4)].str),(yyvsp[(2) - (4)].intvalue));
                 if (last_cpptype && (Strcmp(last_cpptype,"struct") != 0)) {
		   Setattr((yyval.node),"access","private");
		   Swig_warning(WARN_PARSE_NO_ACCESS, Getfile((yyval.node)), Getline((yyval.node)), "No access specifier given for base class '%s' (ignored).\n", SwigType_namestr((yyvsp[(3) - (4)].str)));
                 } else {
		   Setattr((yyval.node),"access","public");
		 }
		 if ((yyvsp[(4) - (4)].str))
		   SetFlag((yyval.node), "variadic");
               }
    break;

  case 510:

    {
		 (yyval.intvalue) = cparse_line;
	       }
    break;

  case 511:

    {
		 (yyval.node) = NewHash();
		 Setfile((yyval.node),cparse_file);
		 Setline((yyval.node),(yyvsp[(3) - (6)].intvalue));
		 Setattr((yyval.node),"name",(yyvsp[(5) - (6)].str));
		 Setfile((yyvsp[(5) - (6)].str),cparse_file);
		 Setline((yyvsp[(5) - (6)].str),(yyvsp[(3) - (6)].intvalue));
		 Setattr((yyval.node),"access",(yyvsp[(2) - (6)].id));
	         if (Strcmp((yyvsp[(2) - (6)].id),"public") != 0) {
		   Swig_warning(WARN_PARSE_PRIVATE_INHERIT, Getfile((yyval.node)), Getline((yyval.node)), "%s inheritance from base '%s' (ignored).\n", (yyvsp[(2) - (6)].id), SwigType_namestr((yyvsp[(5) - (6)].str)));
		 }
		 if ((yyvsp[(6) - (6)].str))
		   SetFlag((yyval.node), "variadic");
               }
    break;

  case 512:

    { (yyval.id) = (char*)"public"; }
    break;

  case 513:

    { (yyval.id) = (char*)"private"; }
    break;

  case 514:

    { (yyval.id) = (char*)"protected"; }
    break;

  case 515:

    { 
                   (yyval.id) = (char*)"class"; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 516:

    { 
                   (yyval.id) = (char *)"typename"; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 517:

    { 
                   (yyval.id) = (char *)"class..."; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 518:

    { 
                   (yyval.id) = (char *)"typename..."; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 519:

    {
                 (yyval.id) = (yyvsp[(1) - (1)].id);
               }
    break;

  case 520:

    { 
                   (yyval.id) = (char*)"struct"; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 521:

    {
                   (yyval.id) = (char*)"union"; 
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 522:

    {
                   (yyval.id) = (char*)"class";
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 523:

    {
                   (yyval.id) = (char*)"struct";
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 524:

    {
                   (yyval.id) = (char*)"union";
		   if (!inherit_list) last_cpptype = (yyval.id);
               }
    break;

  case 525:

    {
		   (yyval.id) = (yyvsp[(1) - (1)].id);
               }
    break;

  case 526:

    {
		   (yyval.id) = 0;
               }
    break;

  case 529:

    {
                   (yyval.str) = 0;
	       }
    break;

  case 530:

    {
                   (yyval.str) = NewString("1");
	       }
    break;

  case 531:

    {
                   (yyval.str) = NewString("1");
	       }
    break;

  case 532:

    {
                   (yyval.str) = NewString("1");
	       }
    break;

  case 533:

    {
                   (yyval.str) = (yyvsp[(1) - (1)].str);
               }
    break;

  case 534:

    {
                   (yyval.str) = 0;
               }
    break;

  case 535:

    {
                    (yyval.dtype).throws = (yyvsp[(3) - (4)].pl);
                    (yyval.dtype).throwf = NewString("1");
                    (yyval.dtype).nexcept = 0;
                    (yyval.dtype).final = 0;
	       }
    break;

  case 536:

    {
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = NewString("true");
                    (yyval.dtype).final = 0;
	       }
    break;

  case 537:

    {
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = 0;
                    (yyval.dtype).final = (yyvsp[(1) - (1)].str);
	       }
    break;

  case 538:

    {
                    (yyval.dtype).throws = (yyvsp[(3) - (5)].pl);
                    (yyval.dtype).throwf = NewString("1");
                    (yyval.dtype).nexcept = 0;
                    (yyval.dtype).final = (yyvsp[(5) - (5)].str);
	       }
    break;

  case 539:

    {
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = NewString("true");
                    (yyval.dtype).final = (yyvsp[(2) - (2)].str);
	       }
    break;

  case 540:

    {
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = (yyvsp[(3) - (4)].dtype).val;
                    (yyval.dtype).final = 0;
	       }
    break;

  case 541:

    {
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = 0;
                    (yyval.dtype).final = 0;
                    (yyval.dtype).qualifier = (yyvsp[(1) - (1)].dtype).qualifier;
                    (yyval.dtype).refqualifier = (yyvsp[(1) - (1)].dtype).refqualifier;
               }
    break;

  case 542:

    {
		    (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
                    (yyval.dtype).qualifier = 0;
                    (yyval.dtype).refqualifier = 0;
               }
    break;

  case 543:

    {
		    (yyval.dtype) = (yyvsp[(2) - (2)].dtype);
                    (yyval.dtype).qualifier = (yyvsp[(1) - (2)].dtype).qualifier;
                    (yyval.dtype).refqualifier = (yyvsp[(1) - (2)].dtype).refqualifier;
               }
    break;

  case 544:

    {
                    (yyval.dtype) = (yyvsp[(1) - (1)].dtype);
               }
    break;

  case 545:

    { 
                    (yyval.dtype).throws = 0;
                    (yyval.dtype).throwf = 0;
                    (yyval.dtype).nexcept = 0;
                    (yyval.dtype).final = 0;
                    (yyval.dtype).qualifier = 0;
                    (yyval.dtype).refqualifier = 0;
               }
    break;

  case 546:

    { 
                    Clear(scanner_ccode); 
                    (yyval.decl).have_parms = 0; 
                    (yyval.decl).defarg = 0; 
		    (yyval.decl).throws = (yyvsp[(1) - (3)].dtype).throws;
		    (yyval.decl).throwf = (yyvsp[(1) - (3)].dtype).throwf;
		    (yyval.decl).nexcept = (yyvsp[(1) - (3)].dtype).nexcept;
		    (yyval.decl).final = (yyvsp[(1) - (3)].dtype).final;
                    if ((yyvsp[(1) - (3)].dtype).qualifier)
                      Swig_error(cparse_file, cparse_line, "Constructor cannot have a qualifier.\n");
               }
    break;

  case 547:

    { 
                    skip_balanced('{','}'); 
                    (yyval.decl).have_parms = 0; 
                    (yyval.decl).defarg = 0; 
                    (yyval.decl).throws = (yyvsp[(1) - (3)].dtype).throws;
                    (yyval.decl).throwf = (yyvsp[(1) - (3)].dtype).throwf;
                    (yyval.decl).nexcept = (yyvsp[(1) - (3)].dtype).nexcept;
                    (yyval.decl).final = (yyvsp[(1) - (3)].dtype).final;
                    if ((yyvsp[(1) - (3)].dtype).qualifier)
                      Swig_error(cparse_file, cparse_line, "Constructor cannot have a qualifier.\n");
               }
    break;

  case 548:

    { 
                    Clear(scanner_ccode); 
                    (yyval.decl).parms = (yyvsp[(2) - (4)].pl); 
                    (yyval.decl).have_parms = 1; 
                    (yyval.decl).defarg = 0; 
		    (yyval.decl).throws = 0;
		    (yyval.decl).throwf = 0;
		    (yyval.decl).nexcept = 0;
		    (yyval.decl).final = 0;
               }
    break;

  case 549:

    {
                    skip_balanced('{','}'); 
                    (yyval.decl).parms = (yyvsp[(2) - (4)].pl); 
                    (yyval.decl).have_parms = 1; 
                    (yyval.decl).defarg = 0; 
                    (yyval.decl).throws = 0;
                    (yyval.decl).throwf = 0;
                    (yyval.decl).nexcept = 0;
                    (yyval.decl).final = 0;
               }
    break;

  case 550:

    { 
                    (yyval.decl).have_parms = 0; 
                    (yyval.decl).defarg = (yyvsp[(2) - (3)].dtype).val; 
                    (yyval.decl).throws = 0;
                    (yyval.decl).throwf = 0;
                    (yyval.decl).nexcept = 0;
                    (yyval.decl).final = 0;
               }
    break;

  case 551:

    {
                    (yyval.decl).have_parms = 0;
                    (yyval.decl).defarg = (yyvsp[(3) - (4)].dtype).val;
                    (yyval.decl).throws = (yyvsp[(1) - (4)].dtype).throws;
                    (yyval.decl).throwf = (yyvsp[(1) - (4)].dtype).throwf;
                    (yyval.decl).nexcept = (yyvsp[(1) - (4)].dtype).nexcept;
                    (yyval.decl).final = (yyvsp[(1) - (4)].dtype).final;
                    if ((yyvsp[(1) - (4)].dtype).qualifier)
                      Swig_error(cparse_file, cparse_line, "Constructor cannot have a qualifier.\n");
               }
    break;

  case 558:

    {
		  skip_balanced('(',')');
		  Clear(scanner_ccode);
		}
    break;

  case 559:

    {
		  skip_balanced('{','}');
		  Clear(scanner_ccode);
		}
    break;

  case 560:

    {
                     String *s = NewStringEmpty();
                     SwigType_add_template(s,(yyvsp[(2) - (3)].p));
                     (yyval.id) = Char(s);
		     scanner_last_id(1);
                }
    break;

  case 561:

    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 562:

    { (yyval.id) = Swig_copy_string("override"); }
    break;

  case 563:

    { (yyval.id) = Swig_copy_string("final"); }
    break;

  case 564:

    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 565:

    { (yyval.id) = Char((yyvsp[(1) - (1)].dtype).val); }
    break;

  case 566:

    { (yyval.id) = Char((yyvsp[(1) - (1)].str)); }
    break;

  case 567:

    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 568:

    { (yyval.id) = 0; }
    break;

  case 569:

    { 
                  (yyval.str) = 0;
		  if (!(yyval.str)) (yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
      	          Delete((yyvsp[(2) - (2)].str));
               }
    break;

  case 570:

    {
		 (yyval.str) = NewStringf("::%s%s",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
                 Delete((yyvsp[(4) - (4)].str));
               }
    break;

  case 571:

    {
		 (yyval.str) = NewString((yyvsp[(1) - (1)].str));
   	       }
    break;

  case 572:

    {
		 (yyval.str) = NewStringf("::%s",(yyvsp[(3) - (3)].str));
               }
    break;

  case 573:

    {
                 (yyval.str) = NewStringf("%s", (yyvsp[(1) - (1)].str));
	       }
    break;

  case 574:

    {
                 (yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].id));
	       }
    break;

  case 575:

    {
                 (yyval.str) = NewStringf("::%s",(yyvsp[(3) - (3)].str));
               }
    break;

  case 576:

    {
                   (yyval.str) = NewStringf("::%s%s",(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
		   Delete((yyvsp[(3) - (3)].str));
               }
    break;

  case 577:

    {
                   (yyval.str) = NewStringf("::%s",(yyvsp[(2) - (2)].str));
               }
    break;

  case 578:

    {
                   (yyval.str) = NewStringf("::%s",(yyvsp[(2) - (2)].str));
               }
    break;

  case 579:

    {
		 (yyval.str) = NewStringf("::~%s",(yyvsp[(2) - (2)].str));
               }
    break;

  case 580:

    {
		(yyval.str) = NewStringf("%s", (yyvsp[(1) - (1)].id));
	      }
    break;

  case 581:

    {
		(yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].id));
	      }
    break;

  case 582:

    {
		(yyval.str) = (yyvsp[(1) - (1)].str);
	      }
    break;

  case 583:

    {
		(yyval.str) = NewStringf("%s%s", (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id));
	      }
    break;

  case 584:

    {
                  (yyval.str) = 0;
		  if (!(yyval.str)) (yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].id),(yyvsp[(2) - (2)].str));
      	          Delete((yyvsp[(2) - (2)].str));
               }
    break;

  case 585:

    {
		 (yyval.str) = NewStringf("::%s%s",(yyvsp[(3) - (4)].id),(yyvsp[(4) - (4)].str));
                 Delete((yyvsp[(4) - (4)].str));
               }
    break;

  case 586:

    {
		 (yyval.str) = NewString((yyvsp[(1) - (1)].id));
   	       }
    break;

  case 587:

    {
		 (yyval.str) = NewStringf("::%s",(yyvsp[(3) - (3)].id));
               }
    break;

  case 588:

    {
                 (yyval.str) = NewString((yyvsp[(1) - (1)].str));
	       }
    break;

  case 589:

    {
                 (yyval.str) = NewStringf("::%s",(yyvsp[(3) - (3)].str));
               }
    break;

  case 590:

    {
                   (yyval.str) = NewStringf("::%s%s",(yyvsp[(2) - (3)].id),(yyvsp[(3) - (3)].str));
		   Delete((yyvsp[(3) - (3)].str));
               }
    break;

  case 591:

    {
                   (yyval.str) = NewStringf("::%s",(yyvsp[(2) - (2)].id));
               }
    break;

  case 592:

    {
                   (yyval.str) = NewStringf("::%s",(yyvsp[(2) - (2)].str));
               }
    break;

  case 593:

    {
		 (yyval.str) = NewStringf("::~%s",(yyvsp[(2) - (2)].id));
               }
    break;

  case 594:

    { 
                   (yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].id));
               }
    break;

  case 595:

    { (yyval.str) = NewString((yyvsp[(1) - (1)].id));}
    break;

  case 596:

    {
                   (yyval.str) = NewStringf("%s%s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].id));
               }
    break;

  case 597:

    { (yyval.str) = NewString((yyvsp[(1) - (1)].id));}
    break;

  case 598:

    {
		 (yyval.str) = (yyvsp[(1) - (1)].str);
               }
    break;

  case 599:

    {
                  skip_balanced('{','}');
		  (yyval.str) = NewString(scanner_ccode);
               }
    break;

  case 600:

    {
		 (yyval.str) = (yyvsp[(1) - (1)].str);
              }
    break;

  case 601:

    {
                  Hash *n;
                  (yyval.node) = NewHash();
                  n = (yyvsp[(2) - (3)].node);
                  while(n) {
                     String *name, *value;
                     name = Getattr(n,"name");
                     value = Getattr(n,"value");
		     if (!value) value = (String *) "1";
                     Setattr((yyval.node),name, value);
		     n = nextSibling(n);
		  }
               }
    break;

  case 602:

    { (yyval.node) = 0; }
    break;

  case 603:

    {
                  Hash *n;
                  (yyval.node) = NewHash();
                  n = (yyvsp[(2) - (2)].node);
                  while(n) {
                     String *name, *value;
                     name = Getattr(n,"name");
                     value = Getattr(n,"value");
		     if (!value) value = (String *) "1";
                     Setattr((yyval.node),name, value);
		     n = nextSibling(n);
		  }
               }
    break;

  case 604:

    { (yyval.node) = 0; }
    break;

  case 605:

    {
		 (yyval.node) = NewHash();
		 Setattr((yyval.node),"name",(yyvsp[(1) - (3)].id));
		 Setattr((yyval.node),"value",(yyvsp[(3) - (3)].str));
               }
    break;

  case 606:

    {
		 (yyval.node) = NewHash();
		 Setattr((yyval.node),"name",(yyvsp[(1) - (5)].id));
		 Setattr((yyval.node),"value",(yyvsp[(3) - (5)].str));
		 set_nextSibling((yyval.node),(yyvsp[(5) - (5)].node));
               }
    break;

  case 607:

    {
                 (yyval.node) = NewHash();
                 Setattr((yyval.node),"name",(yyvsp[(1) - (1)].id));
	       }
    break;

  case 608:

    {
                 (yyval.node) = NewHash();
                 Setattr((yyval.node),"name",(yyvsp[(1) - (3)].id));
                 set_nextSibling((yyval.node),(yyvsp[(3) - (3)].node));
               }
    break;

  case 609:

    {
                 (yyval.node) = (yyvsp[(3) - (3)].node);
		 Setattr((yyval.node),"name",(yyvsp[(1) - (3)].id));
               }
    break;

  case 610:

    {
                 (yyval.node) = (yyvsp[(3) - (5)].node);
		 Setattr((yyval.node),"name",(yyvsp[(1) - (5)].id));
		 set_nextSibling((yyval.node),(yyvsp[(5) - (5)].node));
               }
    break;

  case 611:

    {
		 (yyval.str) = (yyvsp[(1) - (1)].str);
               }
    break;

  case 612:

    {
                 (yyval.str) = Char((yyvsp[(1) - (1)].dtype).val);
               }
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





SwigType *Swig_cparse_type(String *s) {
   String *ns;
   ns = NewStringf("%s;",s);
   Seek(ns,0,SEEK_SET);
   scanner_file(ns);
   top = 0;
   scanner_next_token(PARSETYPE);
   yyparse();
   /*   Printf(stdout,"typeparse: '%s' ---> '%s'\n", s, top); */
   return top;
}


Parm *Swig_cparse_parm(String *s) {
   String *ns;
   ns = NewStringf("%s;",s);
   Seek(ns,0,SEEK_SET);
   scanner_file(ns);
   top = 0;
   scanner_next_token(PARSEPARM);
   yyparse();
   /*   Printf(stdout,"typeparse: '%s' ---> '%s'\n", s, top); */
   Delete(ns);
   return top;
}


ParmList *Swig_cparse_parms(String *s, Node *file_line_node) {
   String *ns;
   char *cs = Char(s);
   if (cs && cs[0] != '(') {
     ns = NewStringf("(%s);",s);
   } else {
     ns = NewStringf("%s;",s);
   }
   Setfile(ns, Getfile(file_line_node));
   Setline(ns, Getline(file_line_node));
   Seek(ns,0,SEEK_SET);
   scanner_file(ns);
   top = 0;
   scanner_next_token(PARSEPARMS);
   yyparse();
   /*   Printf(stdout,"typeparse: '%s' ---> '%s'\n", s, top); */
   return top;
}


