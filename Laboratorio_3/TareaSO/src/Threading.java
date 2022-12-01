package Tarea3;

import java.util.Objects;

public class Threading implements Runnable {

    private int id;
    private int catched;
    private int n;
    private int m;
    private int x;
    private int y;

    private int columna;
    private String[][] matriz;
    public Threading(String[][] matrix, int n, int m, int id, int x, int y) {
        this.matriz = matrix;

        this.id = id;
        this.n = n;
        this.m = m;
        this.y = y;
        this.x = x;
        this.catched = 0; // Bool, me dice si es que la hebra encontrÃ³ el barco
    }


    @Override
    public void run() {
        if (this.matriz.length != this.m) {
            this.catched = 0;
        }

        else {

            for (int i = 0; i < this.matriz.length;  i++) {
                for (int j = 0; j < this.matriz.length; j++) {
                    if (Objects.equals(this.matriz[i][j], "1")) {
                        this.catched = 1;
                        System.out.println("Se encontró el barco en la fila " + this.x + " , columna  " + this.y);
                        break;
                    }
                }
            }



        }
    }
}