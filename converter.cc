#include <cstdio>
#include <cstdlib>

void setA(int rx, int ry, int t, char *path) {
    path[0] = 'a';
    path[1] = rx;
    path[2] = ' ';
    path[3] = ry;
    path[4] = ' ';
    path[5] = '0';
    path[6] = ' ';
    path[7] = '1';
    path[8] = ' ';
    path[9] = '0';
    path[10] = ' ';
    path[11] = 2 * rx;
    path[12] = ' ';
    path[13] = '0';
}

int Circle2Path(int cx, int cy, int rx, int ry, char *path) {
    path[0] = 'M';
    path[1] = cx - rx;
    path[2] = ' ';
    path[3] = cy;

    setA(rx, ry, 2 * rx, path + 4);
    setA(rx, ry, -2 * rx, path + 17);

    path[31] = 'z';

    return 31;
}

int Line2Path(int x1, int y1, int x2, int y2, char *path) {
    path[0] = 'M';
    path[1] = x1;
    path[2] = ',';
    path[3] = y1;
    path[4] = 'L';
    path[5] = x2;
    path[6] = ',';
    path[7] = y2;
    path[8] = 'z';

    return 8;
}

int Rect2Path(int x, int y, int width, int heigth, char *path) {
    path[0] = 'M';
    path[1] = x;
    path[2] = ',';
    path[3] = y;
    path[4] = 'L';
    path[5] = x + width;
    path[6] = ',';
    path[7] = y + width;
    path[8] = 'z';

    return 8;
}

int Poly2Path(int **points, int size_points, char *path) {
    int t = 4;
    path[0] = 'M';
    path[1] = points[0][0];
    path[2] = ',';
    path[3] = points[0][1];

    for (int i = 1; i < size_points; i++) {
        path[t++] = 'L';
        path[t++] = points[i][0];
        path[t++] = ',';
        path[t++] = points[i][1];
    }

    path[t++] = 'z';

    return t;
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
