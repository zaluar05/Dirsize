#define _XOPEN_SOURCE 700

#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>

double tamanho = 0;

static int soma_byts(const char *fpath, const struct stat *info, int typeflag,
                     struct FTW *ftwbuff) {
  if (typeflag == FTW_F) {
    tamanho += (double)info->st_size;
  }
  return 0;
}

void menu(char *argv[]) {
  fprintf(stderr, "Chamada de programa feita de maneira errada.\n");
  fprintf(stderr, "Use da seguinte maneira:\n");
  fprintf(stderr, "%s <nome_do_diretorio>\n", argv[0]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    menu(argv);
    return EXIT_FAILURE;
  } else {
    char *caminho_dir = argv[1];

    if (nftw(caminho_dir, soma_byts, 64, FTW_PHYS) == -1) {
      fprintf(stderr, "Erro ao percorrer o diretório.\n");
      return EXIT_FAILURE;
    }
    fprintf(stdout, "Tamanho do diretório <%s>:\n%.5lf B\n", caminho_dir,
            tamanho);
    fprintf(stdout, "%.5lf MB\n", tamanho / (1024.0 * 1024.0));
    fprintf(stdout, "%.5lf GB\n", tamanho / (1024.0 * 1024.0 * 1024.0));
  }
  return EXIT_SUCCESS;
}
