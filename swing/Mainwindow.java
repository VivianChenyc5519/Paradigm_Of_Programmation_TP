/**
 * @file Mainwindow.java
 * @brief Main window GUI for text area and button controls
 * 
 * This file defines the Mainwindow class which provides a Swing-based graphical
 * interface with a text area and three control buttons. Users can interact with
 * the text area through buttons and menu items to append text and control the window.
 */

import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.*;

/**
 * @class Mainwindow
 * @brief Main window with buttons and text area
 * 
 * The Mainwindow class extends JFrame to provide a graphical user interface with
 * a text area and control buttons. It allows users to:
 * - Append text to the text area using Button1 or the "Button1" menu item
 * - Append different text using Button2 or the "Button2" menu item
 * - Exit the application using Button3 or the "Button3" menu item
 * 
 * The interface uses BorderLayout to organize components: menu bar (top), toolbar (north),
 * text area with scroll pane (center), and button controls (south). Events are handled
 * through an inner ButtonAction class.
 * 
 * @note The window includes both button controls and a menu bar with corresponding menu items
 */
public class Mainwindow extends JFrame {

    /**
     * Serial version UID for serialization compatibility
     */
    private static final long serialVersionUID = 1L;

    /**
     * Text area for displaying and editing content
     */
    private JTextArea text;

    /**
     * Panel containing control buttons
     */
    private JPanel buttons;

    /**
     * First button for appending text
     */
    private JButton button1;

    /**
     * Second button for appending text
     */
    private JButton button2;

    /**
     * Exit button for closing the application
     */
    private JButton button3;

    /**
     * Scroll pane for the text area to enable scrolling
     */
    private JScrollPane scrollPane;

    /**
     * Menu item for Button1 action (currently unused in some contexts)
     */
    private JMenuItem item1;

    /**
     * Menu item for Button2 action (currently unused in some contexts)
     */
    private JMenuItem item2;

    /**
     * Menu item for Button3 action (currently unused in some contexts)
     */
    private JMenuItem item3;

    /**
     * @brief Main method to launch the Mainwindow application
     * 
     * Creates and displays a new instance of the Mainwindow GUI.
     * 
     * @param[in] argv Command line arguments (not used)
     */
    public static void main(String argv[]) {
        new Mainwindow();
    }

    /**
     * @brief Constructor for Mainwindow
     * 
     * Initializes the graphical user interface with all components including
     * text area, buttons, scroll pane, menu bar, and toolbar. Sets up the layout
     * using BorderLayout and configures event listeners for user interactions.
     * The window is configured with title "MainWindow" and exits on close.
     */
    public Mainwindow() {
        // Initialize the variables
        buttons = new JPanel();
        text = new JTextArea(10, 10);
        button1 = new JButton("Button1");
        button2 = new JButton("Button2");
        button3 = new JButton("Exit");
        scrollPane = new JScrollPane(text);
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu();
        JToolBar toolBar = new JToolBar();
        ButtonAction action = new ButtonAction();
        item1 = new JMenuItem(action);
        item1.setText("Button1");
        item2 = new JMenuItem(action);
        item2.setText("Button2");
        item3 = new JMenuItem(action);
        item3.setText("Button3");
        // Create panel for buttons
        buttons.add(new JLabel("Use the buttons to control the text area!"));
        buttons.add(button1);
        button1.addActionListener(action);
        buttons.add(button2);
        button2.addActionListener(action);
        buttons.add(button3);
        button3.addActionListener(action);
        // create menubar
        menuBar.add(menu);
        menu.setText("Buttons");
        menu.add(item1);
        menu.add(item2);
        menu.add(item3);
        // Add components
        add(BorderLayout.SOUTH, buttons);
        //add(BorderLayout.CENTER, text);
        add(BorderLayout.CENTER, scrollPane);
        add(BorderLayout.NORTH, toolBar);
        setJMenuBar(menuBar);
        
        setTitle("MainWindow");
        setDefaultCloseOperation((EXIT_ON_CLOSE));
        pack();
        setVisible(true);
    }

    /**
     * @class ButtonAction
     * @brief Inner class for handling button and menu item actions
     * 
     * The ButtonAction class extends AbstractAction to handle action events
     * triggered by buttons and menu items. It processes button presses by
     * appending corresponding text to the text area or exiting the application.
     */
    private class ButtonAction extends AbstractAction {

        /**
         * @brief Handles button action events
         * 
         * Processes the action triggered by button clicks or menu item selection:
         * - Button1/item1: Appends "The first button appending..\n" to text area
         * - Button2/item2: Appends "The second button appending..\n" to text area
         * - Button3/item3: Exits the application
         * 
         * @param[in] e The action event containing information about the button/menu item clicked
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            var button = e.getSource();
            if (button == button1 || button == item1) {
                text.append("The first button appending..\n");
            } else if (button == button2|| button == item2) {
                text.append("The second button appending..\n");
            } else if (button == button3|| button == item3){
                System.exit(0);
            }
        }
    }
}
