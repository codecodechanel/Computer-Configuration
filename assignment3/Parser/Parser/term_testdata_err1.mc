void main() {
	char str[] = "2019 Compiler!!";
	int mode = 0; // 1: sum, 2:average

	initData(data);

	if (mode == 0)
		sum = calSum(data[0], data[1]);
	else 
		average = calAverage(data[0], data[1]);
