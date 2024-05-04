
/*Complete o primeiro exercício da lista anterior (GUI - Graphical User Interface) fazendo o
tratamento dos eventos para realizar o salvamento e carregamento do arquivo. Sempre que
necessário use um diálogo JOptionPane para receber o nome do arquivo.
Para abrir e ler o arquivo use:

FileInputStream in = new FileInputStream(nomeArq);
Scanner sin = new Scanner(in);
while (sin.hasNextLine()) {
txt.append(sin.nextLine());
txt.append("\n");
}
in.close();

em que:
nomeArq é uma String com o nome do arquivo
txt é o texto (StringBuffer) a ser colocado no JTextArea
Para gravar o arquivo use:

FileOutputStream out = new FileOutputStream(nomeArq);
out.write(txt.getBytes());
out.close();

em que:
nomeArq é uma String com o nome do arquivo
txt é o texto (String) retirado do JTextArea
Para encerrar o programa use:
System.exit(0);

As rotinas que faltarem para completar o programa devem ser pesquisadas na documentação do
Java (http://download.oracle.com/javase/8/docs/api/index.html). Veja também as dicas na
página seguinte. */

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Ex1 extends JFrame {
    JButton bAbrir = new JButton("Abrir");
    JButton bSalva = new JButton("Salvar");
    JButton bSalvarC = new JButton("Salvar Como");
    JButton bFecha = new JButton("Fechar");
    JTextArea texto = new JTextArea(10, 40);
    String arqName;

    Ex1() {
        super("Editor de texto");
        JPanel p = new JPanel(new GridLayout(10, 1));
        bAbrir.addActionListener(new FileActionListener());
        bSalva.addActionListener(new FileActionListener());
        bSalvarC.addActionListener(new FileActionListener());
        bFecha.addActionListener(new FileActionListener());
        p.add(bAbrir);
        p.add(bSalva);
        p.add(bSalvarC);
        p.add(bFecha);
        add(p, BorderLayout.WEST);

        add(texto, BorderLayout.EAST);
        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex1();
    }

    private class FileActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            Object eventSource = e.getSource();
            if (eventSource == bAbrir) {
                arqName = JOptionPane.showInputDialog("Escreva o nome do arquivo que quer abrir");

                FileInputStream arquiveStream;
                try {
                    arquiveStream = new FileInputStream(arqName);
                    Scanner in = new Scanner(arquiveStream);
                    StringBuffer txt = new StringBuffer();
                    while (in.hasNextLine()) {
                        txt.append(in.nextLine());
                        txt.append("\n");
                    }
                    in.close();
                    texto.setText(txt.toString());
                } catch (FileNotFoundException error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não encontrado",
                            "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }

            if (eventSource == bSalva) {
                String txt = texto.getText();

                if (arqName == null) {
                    arqName = JOptionPane.showInputDialog("Escreva o nome do arquivo que quer abrir");
                }
                try {
                    System.out.print(arqName);
                    FileOutputStream out = new FileOutputStream(arqName);
                    out.write(txt.getBytes());
                    out.close();
                } catch (FileNotFoundException error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não encontrado",
                            "Erro", JOptionPane.ERROR_MESSAGE);
                } catch (IOException error) {
                    JOptionPane.showMessageDialog(null, "Erro ao salvar o arquivo",
                            "Erro", JOptionPane.ERROR_MESSAGE);
                }

            }

            if (eventSource == bSalvarC) {

                String txt = texto.getText();
                String arquive = JOptionPane
                        .showInputDialog("Escreva o nome e tipo do arquivo para salvar (nome.tipo)");
                try {
                    File newFile = new File(arquive);
                    newFile.createNewFile();
                    FileWriter myWriter = new FileWriter(arquive);
                    myWriter.write(txt);
                    myWriter.close();
                } catch (IOException error) {
                    JOptionPane.showMessageDialog(null, "Erro ao salvar arquivo. Erro:" + error.toString(),
                            "Erro", JOptionPane.ERROR_MESSAGE);
                }

            }

            if (eventSource == bFecha) {
                System.exit(0);
            }

        }

    }
}
