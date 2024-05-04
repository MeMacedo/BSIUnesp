import java.awt.*;
import javax.swing.*;

class Ex1 extends JFrame {
    JButton bAbrir = new JButton("Abrir");
    JButton bSalva = new JButton("Salvar");
    JButton bSalvarC = new JButton("Salvar Como");
    JButton bFecha = new JButton("Fechar");
    JTextArea texto = new JTextArea(10, 40);

    Ex1() {
        super("Editor de texto");
        JPanel p = new JPanel(new GridLayout(10, 1));
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
}
