public class FaxErrorHandler implements Receiver{
	private Receiver nextReceiver;
	@Override
	public void nextErrorHandler(Receiver nextReceiver)
	{
		this.nextReceiver = nextReceiver;
	}
	
	@Override
	public boolean handleMessage(Message message)
	{
		if (message.text.contains("Fax"))
		{
	
			System.out.println(" FaxErrorHandler processed " +message.priority +" priority issue :"+ message.text);
			return true;
		}
		else
		{
			if (nextReceiver != null)
				nextReceiver.handleMessage(message);
		}
		return false;
	}
}