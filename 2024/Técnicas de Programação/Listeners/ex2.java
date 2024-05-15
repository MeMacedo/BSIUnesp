/*Complete o segundo e o terceiro exercícios da lista anterior (GUI - Graphical User Interface)
fazendo o tratamento dos eventos e apresentando o resultado no JLabel que contém o valor
inicial “0”. Para que o resultado caiba no JLabel inicie-o com “ 0” (alguns espaços em
branco antes do zero). */

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

class Ex2 extends JFrame {
    JButton bSoma = new JButton("Soma");
    JButton bMenos = new JButton("Subtrai");
    JButton bMult = new JButton("Multiplica");
    JButton bDiv = new JButton("Divide");

    JTextField text1 = new JTextField(10);
    JTextField text2 = new JTextField(10);
    JLabel text3 = new JLabel("=     0.0");

    Ex2() {
        super("Calculadora");
        JPanel p = new JPanel(new GridLayout(4, 1));
        bSoma.addActionListener(new CalcActionListener());

        bMenos.addActionListener(new CalcActionListener());

        bDiv.addActionListener(new CalcActionListener());

        bMult.addActionListener(new CalcActionListener());

        p.add(bSoma);
        p.add(bMenos);
        p.add(bMult);
        p.add(bDiv);
        setLayout(new FlowLayout());

        add(text1);
        add(p);
        add(text2);
        add(text3);
        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex2();
    }

    private class CalcActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            double number1 = 0;
            double number2 = 0;
            try {
                number1 = Double.parseDouble(text1.getText());
                number2 = Double.parseDouble(text2.getText());
            } catch (Exception error) {
                error.printStackTrace();
            }

            if (e.getSource() == bSoma) {
                text3.setText(number1 + number2 + "");
            }
            if (e.getSource() == bDiv) {

                text3.setText(number1 / number2 + "");
            }
            if (e.getSource() == bMenos) {

                text3.setText(number1 - number2 + "");
            }
            if (e.getSource() == bMult) {

                text3.setText(number1 * number2 + "");
            }
        }
    }
}

class Ex3 extends JFrame {
    JTextField texto1 = new JTextField(10);
    JTextField texto2 = new JTextField(10);
    JLabel texto3 = new JLabel("=     0.0");
    JButton bCalc = new JButton("Calcular");
    JComboBox<String> box = new JComboBox<String>();

    Ex3() {
        super("Calculadora");
        JPanel p = new JPanel(new FlowLayout());

        box.addItem("Soma");
        box.addItem("Subtrai");
        box.addItem("Multiplica");
        box.addItem("Divide");
        p.add(texto1);
        p.add(box);
        p.add(texto2);
        p.add(texto3);
        setLayout(new GridLayout(2, 1));

        bCalc.addActionListener(new CalcActionListener());

        add(p);
        add(bCalc);

        pack();
        setVisible(true);
    }

    public static void main(String s[]) {
        new Ex3();
    }

    private class CalcActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            double number1 = 0;
            double number2 = 0;
            try {
                number1 = Double.parseDouble(texto1.getText());
                number2 = Double.parseDouble(texto2.getText());
            } catch (Exception error) {
                error.printStackTrace();
            }

            Object selected = box.getSelectedItem();

            if (selected == "Soma") {
                texto3.setText(number1 + number2 + "");
            }
            if (selected == "Divide") {

                texto3.setText(number1 / number2 + "");
            }
            if (selected == "Subtrai") {

                texto3.setText(number1 - number2 + "");
            }
            if (selected == "Multiplica") {

                texto3.setText(number1 * number2 + "");
            }
        }

    }
}
