package scm_GUI;


import javax.swing.*;

public class Test {

	private static GUI view = null;
	private static LogView logger = null;
	
 public static void main(String[] args) throws Exception {			
	SwingUtilities.invokeAndWait(() -> {
		view = new GUI();
		logger = new LogView();
	});		
	Controller contr = new Controller(args[0], view, logger);
	view.registerController(contr);
 }
}
