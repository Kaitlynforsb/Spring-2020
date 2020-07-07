//implementation file


namespace tax {

	double tax_amt (double total){

	double tax_rate = 0.06;
	return (total * tax_rate);

	} //end function




        double total_amt(double total) {
	
	double tax_rate = 0.06;
	double tax_amount = tax_rate * total;
	return (total + tax_amount);

	} //end function





} //end namespace
