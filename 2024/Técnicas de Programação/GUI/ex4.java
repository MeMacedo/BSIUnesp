import java.awt.*;
import javax.swing.*;

class Ex4 extends JFrame {
    JTextField texto1 = new JTextField(10);
    JTextField texto2 = new JTextField(10);
    JButton bCalc = new JButton("Calcular");

    Ex4() {
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

        JPanel buttonFrame = new JPanel(new FlowLayout(FlowLayout.CENTER));
        buttonFrame.add(bCalc);

        setLayout(new GridLayout(2, 1));

        add(p);
        add(buttonFrame);

        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex4();
    }
}
