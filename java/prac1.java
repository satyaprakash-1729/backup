import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.sql.*;

public class prac1 extends JFrame{
       private JLabel l1;
       private JTextField t1;
       private JTextField t2;
       private JButton b1;
       private JLabel l2;
       static final String JDBC_DRIVER = "com.mysql.jdbc.driver";
       static final String DB_URL = "jdbc:mysql://localhost/db";
       static final String USER = "mathayus";
       static final String PASSWORD = "hamunaptra";
       public prac1(){
            super("My Window");
            setLayout(new FlowLayout());
 
            Connection conn = null;
            Statement stmt = null;

            l1 = new JLabel("Username : ");
            Font fo = new Font("Serif", Font.BOLD + Font.ITALIC, 16);
            l1.setFont(fo);
            l1.setLocation(100,100);
            add(l1);

            t1 = new JTextField("", 50);
            Font fo2 = new Font("Serif", Font.PLAIN, 18);
            t1.setFont(fo2);
            t1.setLocation(100,150);
            t1.setVisible(true);
            t1.setEditable(true);
            add(t1);

            l2 = new JLabel("Password : ");
            l2.setFont(fo);
            l2.setLocation(200,100);
            add(l2);

            t2 = new JTextField("", 50);
            t2.setFont(fo2);
            t2.setLocation(200,150);
            t2.setVisible(true);
            t2.setEditable(true);
            add(t2);

            b1 = new JButton("Submit");
            b1.setSize(80,60);
            b1.setLocation(400,300);
            add(b1);

            this.setSize(1000,1000);
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            this.setVisible(true);

            Class.forName(JDBC_DRIVER);

            conn = DriverManager.getConnection(DB_URL,USER,PASSWORD);
            stmt = conn.createStatement();
            String sql;
            sql = "CREATE TABLE USERS("+
                    "USERNAME VARCHAR(20)    NOT NULL, "+
                    "PASSWORD VARCHAR(20)    NOT NULL, "+
                    "ID INT                                      NOT NULL, "+
                    "PRIMARY KEY(ID) "+
            ");";
            stmt.executeQuery(sql);
            myHandler handler = new myHandler();
            b1.addActionListener(handler);

       }
       private class myHandler implements ActionListener{
            public void actionPerformed(ActionEvent event){
                if(event.getSource()==b1){
                    String name = t1.getText()+"";
                    l2.setText("Hello! Nice to meet You, "+name+" ! :)");
                }
            }
       }
};