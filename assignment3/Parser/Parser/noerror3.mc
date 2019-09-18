//swap values
void swap(int num1, int num2){
	int temp;
	temp = num1;
	num1 = num2;
	num2 = num1;
}

int main(void){
	int a;
	int b;
	
	a = 100;
	b = 200;
	
	swap(a, b);
	return 0;
}