package Tarea3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Barco {
    public Barco() {
    }
    static int fila;

    public List<String[][]> split_matrix(String[][] Matriz, int n, int m) {
        List<String[][]> L = new ArrayList<String[][]>(n);
        getmatriz(Matriz, n, m, L);
        return L;
    }

    private void getmatriz(String[][] Matrix, int n, int m, List<String[][]> L) {
        if (n == 1) {
            L.add(Matrix);
        }
        int new_len = n / 2;
        String[][] left = new String[n][new_len];
        String[][] right = new String[n][new_len];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= new_len) {
                    right[i][j - new_len] = Matrix[i][j];
                } else {
                    left[i][j] = Matrix[i][j];
                }
            }
        }

        String[][] upper_left = new String[new_len][new_len];
        String[][] upper_right = new String[new_len][new_len];
        String[][] down_left = new String[new_len][new_len];
        String[][] down_right = new String[new_len][new_len];

        for (int i = 0; i < n; i++) {
            if (i >= new_len) {
                down_left[i - new_len] = left[i];
                down_right[i - new_len] = right[i];
            } else {
                upper_left[i] = left[i];
                upper_right[i] = right[i];
            }
        }

        if (new_len != m) {
            getmatriz(upper_left, new_len, m, L);
            getmatriz(upper_right, new_len, m, L);
            getmatriz(down_left, new_len, m, L);
            getmatriz(down_right, new_len, m, L);
        } else {
            L.add(upper_left);
            L.add(upper_right);
            L.add(down_left);
            L.add(down_right);
        }
    }
}
