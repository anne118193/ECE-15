#include <stdio.h>

int main() 
{
  int a, b, c;

  printf("Enter integers a,b,c: ");
  scanf("%d %d %d", &a, &b, &c);

  (!a || !b++ && c) ? printf("       !a || !b++ && c: True\n") : printf("       !a || !b++ && c: False\n");
  printf("%d %d %d\n", a, b, c);
  ((a-1 || b/2) && (c=c*2)) ? printf("(a-1 || b/2) && (c*=2): True\n") : printf("(a-1 || b/2) && (c*=2): False\n");
  printf("%d %d %d\n", a, b, c);
  ((a-- || --b) && (c+=2)) ? printf("(a-- || --b) && (c+=2): True\n") : printf("(a-- || --b) && (c+=2): False\n");
  printf("%d %d %d\n", a, b, c);
  (a || !(b && --c)) ? printf("      a || !(b && --c): True\n") : printf("      a || !(b && --c): False\n");
  printf("%d %d %d\n", a, b, c);

  return 0;
}
