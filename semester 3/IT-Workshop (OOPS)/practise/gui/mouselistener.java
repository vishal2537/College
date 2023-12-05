// package gui;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import org.w3c.dom.events.MouseEvent;
import java.awt.event.MouseEvent;

import java.awt.event.MouseListener;

public class mouselistener {
    public static void main(String[] args)
    {
        xyz x =new xyz();

    }
}

class xyz extends JFrame
{
    public xyz()
    {
        addMouseListener(new MouseAdapter()
        {
            public void mousePressed(MouseEvent me)
            {
                int x = me.getX();
                int y = me.getY();
                System.out.println(x + " . " + y);
            }
        });

        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
