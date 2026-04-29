/*
    Nama: Moch. Dimas Ristanto
    NIM : 13224083
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} artefak;

int compareArtefak(const void *a, const void *b) {
    artefak *artA = (artefak *)a;
    artefak *artB = (artefak *)b;

    // Kategori alfabetis naik
    int arsip = strcmp(artA->kategori, artB->kategori);
    if (arsip != 0) {
        return arsip;
    }

    // Jika sama, tahun naik
    if (artA->tahun != artB->tahun) {
        return artA->tahun - artB->tahun;
    }

    // Jika sama, nilai turun
    if (artA->nilai != artB->nilai) {
        return artB->nilai - artA->nilai;
    }

    // Jika sama, nama alfabetis naik
    return strcmp(artA->nama, artB->nama); // String dibandingkan
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    artefak *data = (artefak*)malloc(n*sizeof(artefak));

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }

    qsort(data, n, sizeof(artefak), compareArtefak); // Referensi: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

    for (int i = 0; i < n; i++) {
        printf("\n%s %s %d %d", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }

    free(data);
    return 0;
}
