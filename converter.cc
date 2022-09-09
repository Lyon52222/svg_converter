#include <cstdio>
#include <cstdlib>

void Circle2Path(int cx, int cy, int r, char *path) { path[0] = 'M'; }

void Line2Path(int x1, int y1, int x2, int y2, char *path) {
    path[0] = 'M';
    path[1] = x1;
    path[2] = ',';
    path[3] = y1;
    path[4] = 'L';
    path[5] = x2;
    path[6] = ',';
    path[7] = y2;
    path[8] = 'z';
}

void Rect2Path(int x, int y, int width, int heigth, char *path) {
    path[0] = 'M';
    path[1] = x;
    path[2] = ',';
    path[3] = y;
    path[4] = 'L';
    path[5] = x + width;
    path[6] = ',';
    path[7] = y + width;
    path[8] = 'z';
}

int main() {
    char *path = (char *)malloc(sizeof(char) * 100);

    Line2Path(1, 1, 100, 100, path);
    for (int i = 0; i < 9; i++) {
        printf("%d", path[i]);
    }

    delete path;

    return 0;
}
