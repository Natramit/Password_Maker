int if_finded(int char_in[],int char_from[],int finded[]){
	int i = 0, i1 = 0, i2 = 0, order[100] = { 0 };
	for (i1=1;;) {
		if (char_from[i] == 0 && char_from[i + 1] == 0 || i >= 1000)break;
		if (char_from[i] == 0) {
			order[i1] = i+1;
			i1++;
		}
		i++;
	}
	for (i = 0, i1 = 0,i2=1;;) {
		if (order[i] == 0 && order[i + 1] == 0) {

			return 0;
			break;
		}
		if (char_in[i1] == 0) {
			i1 = 0;
			i++;
		}

		if (char_in[i1] == char_from[order[i]]|| char_in[i1]+32 == char_from[order[i]]) {
			for (;;) {
				if (char_from[order[i] + i2] == 0) {
					finded[i] = 1;
					i2 = 1;
					break;
				}
				if (char_in[i1 + i2] != char_from[order[i] + i2] && char_in[i1 + i2] + 32 != char_from[order[i] + i2]) {
					i2 = 1;
					break;
				}
				i2++;
			}
		}
		i1++;
	}
}
int find_no(int char_in[], int char_no[]){
	int i0 = 0, i1 = 0;
	for (;;) {
		if ((char_in[i0] == 0 && char_in[i0 + 1] == 0)||i0>=99)break;
		if (char_in[i0] == '!') {
			char_no[i1] = char_in[i0 + 1];
			i1++;
			if (i1 >= 100) {
				//printf("Unavailable characters exceed the maximum limit!\n");
				printf(lang[language].unavailable_chars_over);
				return 0;
			}
		}
		i0++;
	}
	return 1;
}