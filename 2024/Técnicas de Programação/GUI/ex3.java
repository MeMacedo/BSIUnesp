import java.awt.*;
import javax.swing.*;

class Ex3 extends JFrame {
    JTextField texto1 = new JTextField(10);
    JTextField texto2 = new JTextField(10);
    JButton bCalc = new JButton("Calcular");

    Ex3() {
        super("Calculadora");
        JPanel p = new JPanel(new FlowLayout());
        JComboBox<String> box = new JComboBox<String>();
        box.addItem("Soma");
        box.addItem("Subtrai");
        box.addItem("Multiplica");

        box.addItem("Divide");
        p.add(texto1);
        p.add(box);
        p.add(texto2);
        p.add(new JLabel("= 0"));
        setLayout(new GridLayout(2, 1));

        add(p);
        add(bCalc);

        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex3();
    }
}
