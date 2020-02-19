/*
 * Hash
 */
#include "./pcon.h"

#define M 1046527    /* M is prime */
#define NIL -1
#define STR_LEN 12
#define COM_LEN 8

int
getChar(char ch)
{
  if (ch == 'A')
    return (1);
  else if (ch == 'C')
    return (2);
  else if (ch == 'G')
    return (3);
  else if (ch == 'T')
    return (4);
  else
    return (0);
}

long long
getKey(char *str)
{
  long long sum = 0, p = 1, i;
  
  for (i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  
  return (sum);
}
    
int
h1(int key)
{
  return (key % M);
}

int
h2(int key)
{
  return (1 + (key % (M - 1)));
}

int
find(char **H, char *str)
{
  long long key, i, h;
  key = getKey(str);

  for (i = 0; ; i++) {
    h = (h1(key) + i*h2(key)) % M;
    
    if (H[h] && (strcmp(H[h], str) == 0))
      return (1);
    else if (H[h] == 0)
      return 0;
  }
  return (0);
}

int
insert(char **H, char *str)
{
  long long key, i, h;
  
  key = getKey(str);

  for (i = 0; ; i++) {
    h = (h1(key) + i*h2(key)) % M;

    if (H[h] == 0) {
      H[h] = strdup(str);
      return (0);
    }
      
    if (strcmp(H[h], str) == 0)
      return (1);   
  }
  
  return (0);
}

int
main(int argc, char *argv[])
{
  char *H[M];
  char com[COM_LEN+1], str[STR_LEN+1];
  int i, n, h;

  for (i = 0; i < M; i++)
    H[i] = 0;

  scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    scanf("%s %s", com, str);

    if (com[0] == 'i')
      insert(H, str);
    else if (find(H, str))
	printf("yes\n");
    else
	printf("no\n");
  }
   
  return (0);
}
