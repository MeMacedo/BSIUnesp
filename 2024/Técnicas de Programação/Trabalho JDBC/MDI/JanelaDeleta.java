import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JanelaDeleta extends JInternalFrame implements ActionListener {
    PreparedStatement pStmt;
    Connection con;
    JDesktopPane desktop;
    String tableName = "BESTAS";
    ButtonGroup buttonGroup = new ButtonGroup();
    JRadioButton beastRadioButton = new JRadioButton("Bestas", true);
    JRadioButton weaknessRadioButton = new JRadioButton("Fraquezas");
    JRadioButton spellRadioButton = new JRadioButton("Feiticos");
    JButton button;
    JTextField field;
    JLabel label;

    public JanelaDeleta(JDesktopPane d, Connection conn) {
        super("Deletar", false, true, false, true);
        desktop = d;
        con = conn;

        setLayout(new GridLayout(3, 1));

        JPanel panel = new JPanel(new FlowLayout());
        JPanel panel2 = new JPanel(new FlowLayout());

        buttonGroup.add(beastRadioButton);
        buttonGroup.add(weaknessRadioButton);
        buttonGroup.add(spellRadioButton);

        panel.add(beastRadioButton);
        panel.add(weaknessRadioButton);
        panel.add(spellRadioButton);

        panel2.add(new JLabel("ID: "));
        panel2.add(field = new JTextField(30));
        panel2.add(button = new JButton("Deletar"));

        add(panel);
        add(panel2);
        add(label = new JLabel());

        pack();

        button.addActionListener(this);
        beastRadioButton.addActionListener(this);
        spellRadioButton.addActionListener(this);
        weaknessRadioButton.addActionListener(this);

        desktop.add(this);
        setDefaultCloseOperation(HIDE_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == beastRadioButton && !beastRadioButton.isSelected()) {

            tableName = "MONSTROS";
        } else if (e.getSource() == weaknessRadioButton && !weaknessRadioButton.isSelected()) {

            tableName = "FRAQUEZAS";
        } else if (e.getSource() == spellRadioButton && !spellRadioButton.isSelected()) {

            tableName = "FEITICOS";
        } else if (e.getSource() == button) {
            try {
                label.setText("");
                pStmt = con.prepareStatement("DELETE FROM " + tableName + " WHERE ID LIKE ?");
                pStmt.setInt(1, Integer.valueOf(field.getText()));
                Integer count = pStmt.executeUpdate();
                label.setText("" + count + "entradas foram excluídas da tabela");
            } catch (SQLException error) {
                JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public void finalize() {
        try {
            pStmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
