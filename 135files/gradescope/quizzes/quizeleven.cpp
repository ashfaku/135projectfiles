class Money
{
	public:
	   int dollars;
	   int cents;
};
Money add_money(Money x, Money y)
{
	int cents = x.cents + y.cents, dollars = x.dollars + y.dollars;
	dollars += (cents / 100);
	return {dollars, cents % 100};
}
