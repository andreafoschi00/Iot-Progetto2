package scm_GUI;

import java.awt.*; 
import javax.swing.*;
import javax.swing.border.Border;


public class GUI extends JFrame {
	
 /**
	 * 
	 */
 private static final long serialVersionUID = 2346903529418275343L;
 private final JButton refillBtn = new JButton("Refill");
 private final JButton recoverBtn = new JButton("Recover");

 private final JLabel modalityLbl = new JLabel("Modality:");
 private final JLabel lblCoffeeAvailable = new JLabel("Coffee available:");
 private final JLabel lblChocolateAvailable = new JLabel("Chocolate available:");
 private final JLabel lblTeaAvailable = new JLabel("Tea available:");
 private final JLabel selfTestLbl = new JLabel("Self-test performed:");
 
 

 public GUI() {
		 final JFrame frame = new JFrame();
		 frame.setTitle("Coffee machine manager");
		 frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		 frame.setSize(450, 450);
		 frame.setVisible(true);
		 
		 final BorderLayout border = new BorderLayout();
		 
		 final JPanel panel = new JPanel();
		 final JPanel panel2 = new JPanel(new FlowLayout ());
		 final JPanel panel3 = new JPanel(new GridLayout(5,1));
		 
		 final JLabel title = new JLabel("Coffee Machine Manager", JLabel.CENTER);
		 title.setFont(new Font("Serif", Font.BOLD, 30));		 
		 Border bord = BorderFactory.createLineBorder(Color.BLACK, 3);	 
		 title.setBorder(bord);
		 panel.setLayout(border);
		 frame.getContentPane().add(panel);
		 
		 refillBtn.setEnabled(false);
		 panel2.add(refillBtn);
		 recoverBtn.setEnabled(false);
		 panel2.add(recoverBtn);
		 
		 panel3.add(modalityLbl);
		 panel3.add(lblCoffeeAvailable);
		 panel3.add(lblChocolateAvailable);
		 panel3.add(lblTeaAvailable);
		 panel3.add(selfTestLbl);
		 
		 panel.add(title, BorderLayout.NORTH);
		 panel.add(panel3, BorderLayout.CENTER);
		 panel.add(panel2, BorderLayout.SOUTH);
		 
		 frame.setVisible(true);
	 
 }
    public void registerController(Controller contr){
		 refillBtn.addActionListener(contr);
		 recoverBtn.addActionListener(contr);
	}

	public void setModalityInfo(String msg) {
		SwingUtilities.invokeLater(() -> {
			modalityLbl.setText(msg);
		});
	}

	public void setCoffeeQuantity(String msg) {
		SwingUtilities.invokeLater(() -> {
			lblCoffeeAvailable.setText(msg);
		});
	}

	public void setChocolateQuantity(String msg) {
		SwingUtilities.invokeLater(() -> {
			lblChocolateAvailable.setText(msg);
		});
	}

	public void setTeaQuantity(String msg) {
		SwingUtilities.invokeLater(() -> {
			lblTeaAvailable.setText(msg);
		});
	}

	public void setSelftestQuantity(String msg) {
		SwingUtilities.invokeLater(() -> {
			selfTestLbl.setText(msg);
		});
	}

	public void startEmptyMaintenance() {
		SwingUtilities.invokeLater(() -> {
			refillBtn.setEnabled(true);
		});
	}

	public void startTempMaintenance() {
		SwingUtilities.invokeLater(() -> {
			recoverBtn.setEnabled(true);
		});
	}

	public void refilled(){
		SwingUtilities.invokeLater(() -> {
			refillBtn.setEnabled(false);
		});
	}

	public void recovered() {
		SwingUtilities.invokeLater(() -> {
			recoverBtn.setEnabled(false);
		});
	}
 
}
