/**
 * @file ClientGUI.java
 * @brief Graphical User Interface for the multimedia client
 * 
 * This file defines the ClientGUI class which provides a Swing-based graphical
 * interface for interacting with the multimedia server. Users can search for and
 * play multimedia items through an intuitive GUI with buttons and text fields.
 */

import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.*;

/**
 * @class ClientGUI
 * @brief Swing-based GUI for the multimedia client application
 * 
 * The ClientGUI class extends JFrame to provide a graphical user interface for
 * the multimedia client. It allows users to:
 * - Enter multimedia names in a text field
 * - Search for multimedia items using the Search button
 * - Play selected multimedia using the Play button
 * - Exit the application using the Exit button
 * 
 * The GUI communicates with a Client object to send requests to the multimedia
 * server and displays responses in a text area. The interface uses BorderLayout
 * to organize input field (North), output area (Center), and control buttons (South).
 * 
 * @note This class uses an inner class ButtonAction to handle button events
 * 
 * @sa Client
 */
public class ClientGUI extends JFrame {

    /**
     * The client object responsible for server communication
     */
    private Client client;
    /**
     * Serial version UID for serialization compatibility
     */
    private static final long serialVersionUID = 1L;
    /**
     * Text field for user input of multimedia names
     */
    private JTextField textinput;
    /**
     * Panel containing control buttons
     */
    private JPanel buttons;
    /**
     * Search button for searching multimedia items
     */
    private JButton button1;
    /**
     * Play button for playing selected multimedia items
     */
    private JButton button2;
    /**
     * Exit button for closing the application
     */
    private JButton button3;
    /**
     * Text area for displaying server responses and results
     */
    private JTextArea textoutput;

    /**
     * @brief Constructor for ClientGUI
     * 
     * Initializes the graphical user interface with all components including
     * text fields, buttons, text area, and layout. Creates a window with title
     * "MainWindow" and sets up event listeners for user interactions.
     * 
     * @param[in] client The Client object to handle server communication
     */
    public ClientGUI(Client client) {
        this.client = client;
        // Initialize the variables
        buttons = new JPanel();
        JPanel input = new JPanel();
        JLabel inLabel = new JLabel("Enter a multimedia name");
        textinput = new JTextField(16);
        textoutput = new JTextArea(50, 50);
        textoutput.setLineWrap(true);
        textoutput.setWrapStyleWord(true);
        textoutput.setEditable(false);
        button1 = new JButton("Search");
        button2 = new JButton("Play");
        button3 = new JButton("Exit");
        input.add(textinput);
        input.add(inLabel);
        ButtonAction action = new ButtonAction();
        // Create panel for buttons
        buttons.add(new JLabel("Use the buttons to select action to perform!"));
        buttons.add(button1);
        button1.addActionListener(action);
        buttons.add(button2);
        button2.addActionListener(action);
        buttons.add(button3);
        button3.addActionListener(action);
        // Add components
        add(BorderLayout.NORTH, input);
        add(BorderLayout.CENTER, textoutput);
        add(BorderLayout.SOUTH, buttons);
        // setJMenuBar(menuBar);
        setSize(1000, 800);
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
     * triggered by buttons and menu items. It processes search, play, and exit
     * operations based on which button was clicked.
     */
    private class ButtonAction extends AbstractAction {

        /**
         * @brief Handles button action events
         * 
         * Processes the action triggered by button clicks:
         * - Search button: Sends a "search" request with the entered multimedia name
         * - Play button: Sends a "play" request for the entered multimedia name
         * - Exit button: Closes the application
         * 
         * @param[in] e The action event containing information about the button clicked
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            var button = e.getSource();
            // search
            if (button == button1) {
                sendRequest("search");
                // play
            } else if (button == button2) {
                sendRequest("play");
            } else if (button == button3) {
                System.exit(0);
            }
        }
    }

    /**
     * @brief Sends a request to the multimedia server
     * 
     * Constructs a request message by combining an action (search or play) with
     * the multimedia name entered in the text field. Sends the request through
     * the client, displays the response in the text area, and clears the input field.
     * 
     * @param[in] action The action to perform ("search" or "play")
     */
    private void sendRequest(String action) {
        String request = action + " " + textinput.getText();
        String response = client.send(request);
        System.out.println("Response: " + response);
        textoutput.append(response);
        textoutput.append("\n");
        textinput.setText("");
    }

    /**
     * @brief Main method to launch the multimedia client GUI
     * 
     * Creates a Client instance connected to the server at localhost on port 3331,
     * then initializes and displays the ClientGUI window.
     * 
     * @param[in] args Command line arguments (not used)
     * @throws Exception If there are communication or initialization errors
     */
    public static void main(String[] args) throws Exception {
        Client client = new Client("localhost", 3331);
        new ClientGUI(client);
    }
}
