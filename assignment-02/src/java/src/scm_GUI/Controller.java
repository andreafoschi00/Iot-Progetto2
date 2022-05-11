package scm_GUI;

import SerialCommChannel.SerialCommChannel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller implements ActionListener {

	SerialCommChannel channel;
	GUI viewGui;

	public Controller(String port, GUI view, LogView logger) throws Exception {
		this.viewGui = view;
		channel = new SerialCommChannel(port, 9600);
		new MsgController(channel,view,logger).start();

		System.out.println("Waiting arduino for rebootin...");
		Thread.sleep(4000);
		System.out.println("Ready");
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if(e.getActionCommand().equals("Refill")) {
				channel.sendMsg("refill");
				viewGui.refilled();
			} else if(e.getActionCommand().equals("Recover")) {
				channel.sendMsg("done");
				viewGui.recovered();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
