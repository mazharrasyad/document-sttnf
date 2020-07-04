public class EmailErrorHandler implements Receiver{
	private Receiver nextReceiver;
	
	@Override
	public void nextErrorHandler(Receiver nextReceiver)
	{
		this.nextReceiver = nextReceiver;
	}
	
	@Override
	public boolean handleMessage(Message message)
	{
		if (message.text.contains("Email"))
		{
			System.out.println(" EmailErrorHandler processed "+message.
					priority+ " priority issue: "+message.text);
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