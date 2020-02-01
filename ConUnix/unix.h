/*
 *
 */

#ifndef STRUCT_MAP_DEFINED
#define STRUCT_MAP_DEFINED
struct map
{
  char *m_size;
  char *m_addr;
};
#endif

/* malloc.c */
int malloc (struct map *, int);
void mfree (struct map *, int size, int aa);
