/*
 *  
 */

#include "unix.h"
#ifndef STRUCT_MAP_DEFINED
#define STRUCT_MAP_DEFINED
struct map
{
  char *m_size;
  char *m_addr;
};
#endif

int
malloc (struct map *mp, int size)
{
  register int a;
  register struct map *bp;

  for (bp = mp; bp->m_size; bp++)
    if (bp->m_size >= size) {
      a = bp->m_addr;
      bp->m_addr =+ size;
      if ((bp->m_size =- size) == 0)
	do {
	  bp++;
	  (bp-1)->m_addr = bp->m_addr;
	} while ((bp-1)->m_size = bp->m_size);
      return (a);
    }
  return (0);
}

void
mfree(struct map *mp, int size, int aa)
{
  register struct map *bp;
  register int t;
  register int a;

  a = aa;
  for (bp = mp; bp->m_addr <= a && bp->m_size != 0; bp++);
  if (bp > mp && (((int)((bp-1)->m_addr) + (int)((bp-1)->m_size)) == a)) {
    (bp-1)->m_size += a;
    if (a + size == bp->m_addr) {
      (bp-1)->m_size =+ (int) bp->m_size;
      while (bp->m_size) {
	bp++;
	(bp-1)->m_addr = bp->m_addr;
	(bp-1)->m_size = bp->m_size;
      }
    }
  } else {
    if (a+size == bp->m_addr && bp->m_size) {
      bp->m_addr =- size;
      bp->m_size =+ size;
    } else if (size)
      do {
	t = bp->m_addr;
	bp->m_addr = a;
	a = t;
	t = bp->m_size;
	bp->m_size = size;
	bp++;
      } while (size = t);
  }
}
