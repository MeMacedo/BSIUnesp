import java.awt.*;
import javax.swing.*;

class Ex2 extends JFrame {
    JButton bSoma = new JButton("Soma");
    JButton bMenos = new JButton("Subtrai");
    JButton bMult = new JButton("Multiplica");
    JButton bDiv = new JButton("Divide");
    JTextField text1 = new JTextField();
    JTextField text2 = new JTextField();

    Ex2() {
        super("Calculadora");
        JPanel p = new JPanel(new GridLayout(4, 1));
        p.add(bSoma);
        p.add(bMenos);
        p.add(bMult);
        p.add(bDiv);
        setLayout(new FlowLayout());

        add(new JTextField(10));
        add(p);
        add(new JTextField(10));
        add(new JLabel("= 0"));
        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex2();
    }
}
