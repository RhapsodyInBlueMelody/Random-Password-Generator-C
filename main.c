#include <stdio.h>
#define SIZE 17
#define CHARSET_SIZE 62

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define PINK "\033[95m"
#define CYAN "\033[96m"
#define YELLOW "\033[93m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define BG_DARK "\033[48;5;235m"

int main() {

  FILE *fptr;

  unsigned char buffer;
  size_t bytes_read, index, counter = 0;
  char password[SIZE] = "";
  const char *charset =
      "0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

  printf(PINK BOLD "\n  ╔══════════════════════════════╗\n" RESET);
  printf(PINK BOLD "  ║  " RESET YELLOW " /\\_____/\\" PINK
                   "                  ║\n" RESET);
  printf(PINK BOLD "  ║  " RESET YELLOW "(  o   o  )" PINK
                   "                 ║\n" RESET);
  printf(PINK BOLD "  ║  " RESET YELLOW " =( Y )=  " PINK
                   "  purrword gen~   ║\n" RESET);
  printf(PINK BOLD "  ║  " RESET YELLOW "  )   (   " PINK
                   "                  ║\n" RESET);
  printf(PINK BOLD "  ╚══════════════════════════════╝\n\n" RESET);

  fptr = fopen("/dev/urandom", "rb");

  if (fptr == NULL) {
    printf(RED "  (T_T) " RESET "cannot open " BOLD "/dev/urandom" RESET
               " ... *sad meow*\n\n");
    return 1;
  }

  printf(CYAN "  ₊˚⊹ " RESET DIM
              "mixing up some secret ingredients...\n" RESET);

  while (counter < SIZE - 1) {
    if ((bytes_read = fread(&buffer, 1, 1, fptr)) != 1 || ferror(fptr)) {
      printf(RED "  (x_x) " RESET "error reading file — *hisses*\n\n");
      break;
    }
    if (buffer < 248) {
      index = buffer % CHARSET_SIZE;
      password[counter] = charset[index];
      counter++;
    }
  }

  password[SIZE - 1] = '\0';

  printf(CYAN "  ₊˚⊹ " RESET DIM
              "done kneading~ here's your purrword:\n\n" RESET);
  printf(PINK BOLD "  ┌──────────────────────────────┐\n" RESET);
  printf(PINK BOLD "  │  " RESET GREEN BOLD "  %s  " RESET PINK BOLD
                   "  │\n" RESET,
         password);
  printf(PINK BOLD "  └──────────────────────────────┘\n" RESET);
  printf(DIM "\n  ૮ ˶ᵔ ᵕ ᵔ˶ ა  keep it secret, keep it safe~ nya!\n\n" RESET);

  fclose(fptr);

  return 0;
}
