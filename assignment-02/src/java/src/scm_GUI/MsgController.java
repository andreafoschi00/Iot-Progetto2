package scm_GUI;

import SerialCommChannel.SerialCommChannel;

public class MsgController extends Thread {
	
	private final SerialCommChannel channel;
	private final GUI viewGui;
	private final LogView logger;

	private int selftestPerformed;
	
	static final String CM_PREFIX = "cm";
	static final String WORKING_STATE = "wk";
	static final String ASSISTANCE_STATE = "ss";
	static final String COFFEEQ_PREFIX = "cfq";
	static final String CHOCOLATEQ_PREFIX = "chq";
	static final String TEAQ_PREFIX = "teq";
	static final String SELF_PREFIX = "sf";
	
	
	public MsgController(SerialCommChannel channel, GUI view, LogView logger) {
		this.channel = channel;
		this.viewGui = view;
		this.logger = logger;
		selftestPerformed = 0;
	}
	
	@Override
	public void run() {
	 while(true) {
		try {
			if(channel.isMsgAvailable()) {
				String msg = channel.receiveMsg();
					String cmd = msg.substring(CM_PREFIX.length());
					logger.log("new command: "+cmd);
					
					if(cmd.startsWith(WORKING_STATE)) {
						viewGui.setModalityInfo("Modality: WORKING");
					} else if(cmd.startsWith(ASSISTANCE_STATE)) {
						viewGui.setModalityInfo("Modality: ASSISTANCE");
					} else if(cmd.startsWith(COFFEEQ_PREFIX)) {
						cmd = msg.substring(CM_PREFIX.length() + COFFEEQ_PREFIX.length() + 1);
						viewGui.setCoffeeQuantity("Coffee available: " + cmd);
					} else if(cmd.startsWith(CHOCOLATEQ_PREFIX)) {
						cmd = msg.substring(CM_PREFIX.length() + CHOCOLATEQ_PREFIX.length() + 1);
						viewGui.setChocolateQuantity("Chocolate available: " + cmd);
					} else if(cmd.startsWith(TEAQ_PREFIX)) {
						cmd = msg.substring(CM_PREFIX.length() + TEAQ_PREFIX.length() + 1);
						viewGui.setTeaQuantity("Tea available: " + cmd);
					} else if(cmd.startsWith(SELF_PREFIX)) {
						selftestPerformed++;
						viewGui.setSelftestQuantity("Selftest performed: " + selftestPerformed);
					}
				
			}
			} catch(Exception ex) {
				ex.printStackTrace();
			}
	 }
	}
}
