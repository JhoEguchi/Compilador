#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc, char *scope, char *dtype, char *itype );


/* Function st_lookup returns the memory
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name, char * scope);

char * st_lookup_type (char * name, char * scope);
char * st_check_scope (char * name, char * scope);
char * st_lookup_typeID (char * name, char * scope);

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
