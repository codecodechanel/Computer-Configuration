void stock() {
	char str[] = "apple";
	int mode = 1; // 1: sell, 2:buy

	initData(data);

	if (mode == 1)
		sell_cnt = sell(data[0], data[1]);
	else 
		buy_cnt  = buy(data[0], data[1]);
	}
