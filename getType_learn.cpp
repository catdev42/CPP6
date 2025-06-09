type ScalarConverter::getType(std::string str)
{
	int i = 0;
	int dot = 0;
	int afterDot = 0;
	int hasChar = 0;

	if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
		return (POSITIVE_INF);
	else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
		return (NEGATIVE_INF);
	else if (str.compare("nanf") == 0 || str.compare("nan") == 0)
		return (NANF);
		
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (dot)
			afterDot++;
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] == '.')
			dot = 1;
		else 
			hasChar = 1;
		i++;
	}
	if (afterDot && str.back() != 'f')
		return (DOUBLE);
	else if (afterDot && str.back() == 'f')
		return (FLOAT);
	else if (hasChar)
		return (CHAR);
	else
		return (INT);
}