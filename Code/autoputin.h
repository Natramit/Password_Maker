int autoputin(int char_in[],int size){
	int ch0 = 0, ch1 = 0,  number_from = 0;
	for (;;) {
		if (char_in[number_from] != 0 || char_in[number_from + 1] != 0 || char_in[number_from + 2] != 0) {
			char_in[number_from] = 0;
			number_from++;
		}
		else break;
	}
	number_from = 0;
	for (int i=0;;) {
		ch0 = scanf_s("%c", &(char)char_in[number_from], 1);
		if (ch0 != 0) {
			if (char_in[number_from] == 10||i>=size - 1) {
				char_in[number_from] = 0;
				break;
			}
			number_from++, i++;
		}
		else ch1 = getchar();
	}
	return 0;
}