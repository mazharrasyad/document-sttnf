public class IssueRaiser {
	
	public Receiver setFirstReceiver;
	
	public void setFirstErrorHandler(Receiver firstErrorHandler)
	{
		this.setFirstReceiver = firstErrorHandler;
	}
	public void raiseMessage(Message message)
	{
		if (setFirstReceiver != null)
			setFirstReceiver.handleMessage(message);
	}
}