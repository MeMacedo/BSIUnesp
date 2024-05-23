import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;

public class Cliente extends JFrame implements Runnable {
  private static final int PORTA = 12345;
  static PrintStream os = null;
  Scanner is = null;

  PlayButton b1 = new PlayButton(0, 0);
  PlayButton b2 = new PlayButton(0, 1);
  PlayButton b3 = new PlayButton(0, 2);
  PlayButton b4 = new PlayButton(1, 0);
  PlayButton b5 = new PlayButton(1, 1);
  PlayButton b6 = new PlayButton(1, 2);
  PlayButton b7 = new PlayButton(2, 0);
  PlayButton b8 = new PlayButton(2, 1);
  PlayButton b9 = new PlayButton(2, 2);

  PlayButton[][] buttons = { { b1, b2, b3 }, { b4, b5, b6 }, { b7, b8, b9 } };

  Cliente() {
    super("Jogo da velha");
    JPanel p = new JPanel(new GridLayout(3, 3));

    p.add(b1);
    p.add(b2);
    p.add(b3);
    p.add(b4);
    p.add(b5);
    p.add(b6);
    p.add(b7);
    p.add(b8);
    p.add(b9);
    add(p);
    pack();
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setSize(200, 200);
    setVisible(true);
  }

  public void run() {
    Socket cliente = null;

    try {
      cliente = new Socket("127.0.0.1", PORTA);
      os = new PrintStream(cliente.getOutputStream(), true);
      is = new Scanner(cliente.getInputStream());
      System.out.println(is.nextLine());
      int i = 0;
      while (is.hasNextLine()) {
        String line = is.nextLine();
        if (isMessage(line)) {
          System.out.println(line);
        } else {
          String[] splitLine = line.split(" ");
          for (int j = 0; j < 3; j++) {
            buttons[i % 3][j].setText(splitLine[j]);
          }
          i++;
        }

      }
    } catch (UnknownHostException e) {
      System.err.println("Don't know about host.");
    } catch (IOException e) {
      System.err.println("Couldn't get I/O for the connection to host");
    }

  }

  public static void main(String[] args) {
    new Thread(new Cliente()).start();

  }

  private class PlayButton extends JButton implements ActionListener {
    PlayButton(int line, int column) {
      i = line;
      j = column;
      this.addActionListener(this);
    }

    final int i;
    final int j;

    public void actionPerformed(ActionEvent e) {
      os.println(String.format("%d,%d", i, j));

      try {
        SwingUtilities.invokeAndWait(new Runnable() {
          @Override
          public void run() {
            int i = 0;
            while (is.hasNextLine()) {
              String line = is.nextLine();
              if (isMessage(line)) {
                System.out.println(line);
              } else {
                String[] splitLine = line.split(" ");
                for (int j = 0; j < 3; j++) {
                  buttons[i % 3][j].setText(splitLine[j]);
                }
                i++;
              }

            }
          }
        });
      } catch (Exception error) {

      }
    }
  }

  boolean isMessage(String line) {

    if (line.equals("Você venceu!") || line.equals("Você perdeu!")) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; i++) {
          buttons[i][j].setEnabled(false);
        }
      }
      return true;
    }

    if (line.equals("Continue") || line.equals("X")
        || line.equals("O") || line.equals("Empate!")) {
      return true;
    }
    return false;
  }

}
