import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JanelaConsulta extends JInternalFrame implements ActionListener {
    PreparedStatement pStmt;
    JDesktopPane desktop;
    JButton bt1;
    JTextField tf1;
    JTextArea ta1;

    public JanelaConsulta(JDesktopPane d, Connection con, String tableName) {
        super("Consulta na tabela " + tableName, false, true, false, true);

        desktop = d;
        try {
            pStmt = con.prepareStatement("SELECT * FROM " + tableName + " WHERE ID LIKE ?");

            JPanel l1 = new JPanel();
            l1.add(new JLabel("ID: "));
            l1.add(tf1 = new JTextField(30));
            l1.add(bt1 = new JButton("Pesquisa"));
            add(l1, BorderLayout.NORTH);
            l1 = new JPanel();
            JScrollPane scrollPane = new JScrollPane(ta1 = new JTextArea(5, 30));
            l1.add(scrollPane);
            add(l1, BorderLayout.CENTER);

            bt1.addActionListener(this);
            pack();

            desktop.add(this);
            setVisible(true);

            setDefaultCloseOperation(HIDE_ON_CLOSE);

        } catch (Exception ex) {
            JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + ex, "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    public void actionPerformed(ActionEvent e) {
        try {
            ta1.setText("");
            pStmt.setInt(1, Integer.valueOf(tf1.getText()));
            ResultSet rs = pStmt.executeQuery();
            while (rs.next()) {
                String s = rs.getString(1);
                String n = rs.getString(2);
                ta1.append(s + "   " + n + "\n");
            }
            tf1.selectAll();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(desktop, "Problema interno.\n" + ex, "Erro", JOptionPane.ERROR_MESSAGE);
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
