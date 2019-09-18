//calculate sum
int calSum(int a, int b) {
	int c;
	c = a + b;
	return c;
}

//calculate average
float calAverage(int a, int b) {
	int c;
	c = calSum(a, b) / (2 * 1.000);
	return c;
}

//initialize data array
void initData(int data[]) {
	int i = 0;

	while (i < 2) {
		data[i] = 011 * (i + 0x10);
		i++;
	}
}

void main() {
	char str[] = "2019 Compiler!!";

	int mode = 0; // 1: sum, 2:average
	int data[2];

	int sum = 0;
	float average = 0;

	initData(data);

	if (mode == 0)
		sum = calSum(data[0], data[1]);
	else 
		average = calAverage(data[0], data[1]);
}
