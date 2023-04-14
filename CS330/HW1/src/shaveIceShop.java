public abstract class shaveIceShop {
	public int costSI = 10;
	public int numSI;
	private int cardAccepted = 0;
	private orderInterface orderBehavior;
	private paymentInterface paymentBehavior;
	
	public abstract void describeShop();
	
	public void pay()
	{
		paymentBehavior.pay(costSI, numSI);
	}
	
	public void order()
	{
		numSI = orderBehavior.order(numSI);
	}
	
	public void setPayment(paymentInterface newPaymentBehavior)
	{
		paymentBehavior = newPaymentBehavior;
	}
	
	public void setOrder(orderInterface newOrderBehavior)
	{
		orderBehavior = newOrderBehavior;
	}
	
	public int getCardAccepted()
	{
		return cardAccepted;
	}
	
	public void setCardAccepted(int newCardAccepted)
	{
		cardAccepted = newCardAccepted;
	}
	
	public void setCostSI(int newCostSI)
	{
		costSI = newCostSI;
	}
}
