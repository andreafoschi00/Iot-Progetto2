package scm_GUI;

import java.util.Date;

import javax.swing.*;


public class LogView extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 7133126864820626399L;
	private JTextArea logArea;
	
	public LogView(){
		super("Log ");
		setSize(600,600);

		JPanel panel = new JPanel();
		
		logArea = new JTextArea(30,40);	
		logArea.setEditable(false);
		
		JScrollPane scroll = new JScrollPane(logArea);
		panel.add(scroll);
		this.getContentPane().add(panel);
		
		this.setVisible(true);
	}
	public void log(String msg){
		SwingUtilities.invokeLater(() -> {
			String date = new Date().toString();
			logArea.append("["+date+"] "+ msg +"\n");
		});
	}
}

