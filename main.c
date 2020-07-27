//
//  arystr.c
//  CF.ArraysCString
//
//  Created by Alan Sampson on 6/19/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint8_t octet;

int ArraysCString(void);

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {

  printf("CF.ArraysCString\n");

  ArraysCString();

  return 0;
}

/*
 *  MARK: ArraysCString()
 */
int ArraysCString(void) {

  char const days[7][4] = {
    "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun",
  };
  size_t days_l = sizeof(days);
  
  char const * const dayp[7] = {
    "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun",
  };
  size_t dayp_l = sizeof(dayp);

  char const * const dayq[7] = {
    days[0], days[1], days[2], days[3],  days[4], days[5], days[6],
  };
  size_t dayq_l = sizeof(dayq);

  octet * op;
  size_t diff;
  size_t dlen;
  if ((void *) &days > (void *) &dayq) {
    op = (octet *) &dayq;
    diff = ((octet *) &days - (octet *) &dayq);
    dlen = diff + dayq_l;
  }
  else {
    op = (octet *) &days;
    diff = ((octet *) &dayq - (octet *) &days);
    dlen = diff + days_l;
  }
  printf("diff: %1$zu [%1$04zo - %1$04zx]\n", diff);
  printf("dlen: %1$zu [%1$04zo - %1$04zx]\n", dlen);

  printf("sizeof days: %1$" PRIuPTR " [%1$03" PRIoPTR " - %1$02" PRIxPTR "],"
         " 1st element address: %2$p,"
         " contents: %3$18p -> %3$s\n",
         days_l, &days[0][0], days[0]);
  printf("sizeof dayp: %1$" PRIuPTR " [%1$03" PRIoPTR " - %1$02" PRIxPTR "],"
         " 1st element address: %2$p,"
         " contents: %3$18p -> %3$s\n",
         dayp_l, &dayp[0], dayp[0]);
  printf("sizeof dayp: %1$" PRIuPTR " [%1$03" PRIoPTR " - %1$02" PRIxPTR "],"
         " 1st element address: %2$p,"
         " contents: %3$18p -> %3$s\n",
         dayq_l, &dayq[0], dayq[0]);

  //  ----+----|----+----|----+----|----+----|----+----|----+----|----+----|----+----|
  //  days array as hex
  putchar('\n');
  octet * dp;
  dp = (octet *) &days;
  printf("%18p: ", dp);
  for (size_t c = 0, sp = 1; c < days_l; ++c) {
    char cc = *dp++;
    printf("%02" PRIx8 "%s", cc, (sp++ % 4 == 0) ? " " : "");
  }
  putchar('\n');

  //  days array as char
  dp = (octet *) &days;
  printf("%18p: ", dp);
  for (size_t c = 0, sp = 1; c < days_l; ++c) {
    char cc = *dp++;
    cc = cc != '\0' ? cc : '.';
    printf("%2c%s", cc, (sp++ % 4 == 0) ? " " : "");
  }
  putchar('\n');

  //  ----+----|----+----|----+----|----+----|----+----|----+----|----+----|----+----|
  //  dayp array as bytes
  putchar('\n');
  dp = (octet *) &dayp;
  printf("%18p: ", dp);
  for (size_t c = 0, sp = 1; c < dayp_l; ++c) {
    printf("%02" PRIx8 " %s", *dp++, (sp++ % (sizeof(octet *) * 2) == sizeof(octet *)) ? "- " : "");
    if (sp % (sizeof(octet *) * 2) == 1) { printf("\n%18p: ", dp); }
  }
  putchar('\n');

  //  dayp array as poinnters
  putchar('\n');
  size_t dayp_e = dayp_l / sizeof(*dayp);
  for (size_t c = 0; c < dayp_e; ++c) {
    printf("%1$18p: %2$18p -> %2$s\n", &dayp[c], dayp[c]);
  }
  putchar('\n');

  //  ----+----|----+----|----+----|----+----|----+----|----+----|----+----|----+----|
  //  dayq array as bytes
  putchar('\n');
  dp = (octet *) &dayq;
  printf("%18p: ", dp);
  for (size_t c = 0, sp = 1; c < dayq_l; ++c) {
    printf("%02" PRIx8 " %s", *dp++, (sp++ % (sizeof(octet *) * 2) == sizeof(octet *)) ? "- " : "");
    if (sp % (sizeof(octet *) * 2) == 1) { printf("\n%18p: ", dp); }
  }
  putchar('\n');

  //  dayq array as pointers
  putchar('\n');
  size_t dayq_e = dayq_l / sizeof(*dayq);
  for (size_t c = 0; c < dayq_e; ++c) {
    printf("%1$18p: %2$18p -> %2$s\n", &dayq[c], dayq[c]);
  }
  putchar('\n');

  return 0;
}
