import javax.imageio.ImageIO;
import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.net.URL;
import java.sql.*;

public class Grimoire extends JFrame implements ActionListener {
  Connection con;
  Statement stmt;
  JDesktopPane desktop;

  JMenuItem menuInsere;
  JMenuItem menuConsultaL;
  JMenuItem menuConsultaA;
  JMenuItem menuConsultaE;
  JMenuItem menuDeleta;

  JMenuItem menuTermina;

  public Grimoire() {
    super("Grimorio");

    setBounds(50, 50, 700, 500);
    setExtendedState(JFrame.MAXIMIZED_BOTH);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    desktop = new JDesktopPane() {
      private Image image;
      {
        try {
          image = ImageIO.read(
              new URL("https://i.etsystatic.com/35099491/r/il/b370a0/4749331636/il_fullxfull.4749331636_hnbh.jpg"));
        } catch (IOException e) {
          e.printStackTrace();
        }
      }

      @Override
      protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        g.drawImage(image, 0, 0, getWidth(), getHeight(), this);
      }
    };

    add(desktop);

    iniciaBD();

    createTables();

    setJMenuBar(criaMenu());

    setVisible(true);
  }

  void iniciaBD() {
    try {
      Class.forName("org.hsqldb.jdbcDriver");
      con = DriverManager.getConnection("jdbc:hsqldb:http://127.0.0.1:8080/", "sa", "");
      stmt = con.createStatement();
    } catch (ClassNotFoundException ex) {
      JOptionPane.showMessageDialog(null, "O driver do banco de dados não foi encontrado.\n" + ex, "Erro",
          JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    } catch (SQLException ex) {
      JOptionPane.showMessageDialog(null, "Erro na iniciação do acesso ao banco de dados\n" + ex, "Erro",
          JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    }
  }

  public void createTables() {
    try {
      stmt.execute(
          "CREATE TABLE IF NOT EXISTS BESTAS (NOME VARCHAR(30), ID BIGINT IDENTITY NOT NULL, PAIS_ORIGEM VARCHAR(30), COMPORTAMENTO VARCHAR(MAX), ID_FRAQUEZA BIGINT, PRIMARY KEY (ID))");
      stmt.execute(
          "CREATE TABLE IF NOT EXISTS FRAQUEZAS (NOME VARCHAR(30), ID BIGINT IDENTITY NOT NULL, USO VARCHAR(200)  PRIMARY KEY (ID))");
      stmt.execute(
          "CREATE TABLE IF NOT EXISTS FEITICOS (NOME VARCHAR(30), ID BIGINT IDENTITY NOT NULL, INGREDIENTES VARCHAR(300), PREPARO VARCHAR(MAX), PRIMARY KEY (ID))");

    } catch (SQLException ex) {
      if (ex.getMessage().contains("exists")) {
      } else {
        JOptionPane.showMessageDialog(desktop, "Erro na criação da tabela.\n" + ex, "Erro", JOptionPane.ERROR_MESSAGE);
      }
    } catch (NullPointerException ex) {
      JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + ex, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  JMenuBar criaMenu() {
    JMenuBar menuBar = new JMenuBar();
    JMenu menuBDConsult = new JMenu("Consultar");
    menuTermina = new JMenuItem("Fechar aba");
    menuInsere = new JMenuItem("Inserir") {
      @Override
      public Dimension getMaximumSize() {
        Dimension d1 = super.getPreferredSize();
        Dimension d2 = super.getMaximumSize();
        d2.width = d1.width;
        return d2;
      }
    };
    menuDeleta = new JMenuItem("Deletar") {
      @Override
      public Dimension getMaximumSize() {
        Dimension d1 = super.getPreferredSize();
        Dimension d2 = super.getMaximumSize();
        d2.width = d1.width;
        return d2;
      }
    };

    menuBar.add(menuBDConsult);
    menuConsultaL = new JMenuItem("Consulta Livro");
    menuBDConsult.add(menuConsultaL);
    menuConsultaA = new JMenuItem("Consulta Autor");
    menuBDConsult.add(menuConsultaA);
    menuConsultaE = new JMenuItem("Insere Editora");
    menuBDConsult.add(menuConsultaE);

    menuBar.add(menuInsere);
    menuBar.add(menuDeleta);
    menuBar.add(menuTermina);

    menuConsultaL.addActionListener(this);
    menuConsultaA.addActionListener(this);
    menuConsultaE.addActionListener(this);
    menuInsere.addActionListener(this);
    menuDeleta.addActionListener(this);
    menuTermina.addActionListener(this);
    return menuBar;
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == menuInsere) {
      new JanelaInsere(desktop, con);
    } else if (e.getSource() == menuDeleta) {
      new JanelaDeleta(desktop, con);

    } else if (e.getSource() == menuConsultaL) {
      new JanelaConsulta(desktop, con, "LIVROS");

    } else if (e.getSource() == menuConsultaA) {
      new JanelaConsulta(desktop, con, "AUTORES");

    } else if (e.getSource() == menuConsultaE) {
      new JanelaConsulta(desktop, con, "EDITORAS");

    } else if (e.getSource() == menuTermina) {
      System.exit(0);
    }
  }

  public void finalize() {
    try {
      stmt.close();
      con.close();
    } catch (SQLException e) {
      JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public static void main(String[] args) {
    new Grimoire();
  }
}
