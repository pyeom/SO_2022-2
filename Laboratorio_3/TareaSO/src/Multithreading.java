package Tarea3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;



public class Multithreading {
    public static void main(String[] args) throws FileNotFoundException {
        int n, m, x = 0, y = 0;
        File file = new File("informe-nautico.txt");
        Scanner scan = new Scanner(file);
        String s = scan.nextLine();
        n = Integer.parseInt(s);
        s = scan.nextLine();
        m = Integer.parseInt(s);
        System.out.println(n);
        System.out.println(m);
        s = scan.nextLine();
        String[] Matrix;
        String[][] Matriz = new String[n][n];
        s = s.replace("[", "");
        s = s.replace("]", "");
        Matrix = s.split(",");
        for (int i = 0; i < n; i++) {
            String[] aux = Matrix[i].split(" ");
            System.arraycopy(aux, 0, Matriz[i], 0, n);
        }
        System.out.println(Arrays.deepToString(Matriz));
        List<String[][]> aux;
        Barco barquito = new Barco();
        aux = barquito.split_matrix(Matriz, n, m);
        for (int i=0;i<aux.size();i++){
            System.out.println(Arrays.deepToString(aux.get(i)));
            System.out.println("--------------------");
        }


        startTime = System.nanoTime();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (Objects.equals(Matriz[i][j], "1")){
                    x = i+1;
                    y = j+1;
                    System.out.println("Se encontró el barco en la fila " + x + " , columna  " + y);
                    break;
                }
            }
        }
        stopTime = System.nanoTime();
        long sinThread = (stopTime - startTime);
        System.out.println("Se tardó " + sinThread + " nano segundos sin hebras ");


        startTime = System.nanoTime();
        for (int i=0;i<aux.size();i++){
            Threading hilo = new Threading(aux.get(i), n, m, i, x, y);
            Thread mihilo = new Thread(hilo);
            mihilo.start();
        }

        stopTime = System.nanoTime();
        long conThread = (stopTime - startTime);
        System.out.println("Se tardó " + conThread + " nano segundos con hebras ");

    }

    public static long startTime;
    public static long stopTime;
}
