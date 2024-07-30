int select_language_choose() {
	int lang_size = 2;
	int number_temp = -1;
	int temp0 = 0, temp1 = 0;
	char code = 0;
	printf(line.l3);
	printf("\nPlease select language:\n");
	for (int il = 0;;) {
		if (il >= lang_size)break;
		printf(lang[il].chouse_language_l);
		printf(lang[il].language_name);
		printf(lang[il].chouse_language_r);
		printf(" [%d] ;\n",il);
		il++;
	}
	for (int il = 0;;) {
		printf("\n      : ");
		temp0 = 0, temp1 = 0, number_temp = -1;
		for (int il0 = 0, il1 = 0;;) {
			il1 = scanf_s("%c", &code, 1);
			if (il1) {
				if (code == 10)break;
				if (code >= '0' && code <= '9') {
					temp0 = code - '0';
					temp1 = temp1 * 10 + temp0;
				}
			}
			else il1 = getchar();
			il0++;
			if (il0 >= 10)break;
		}
		number_temp = temp1;
		if (number_temp > lang_size) {
			number_temp = -1;
		}
		if (number_temp != -1) {
			printf(lang[number_temp].chouse_language_chouse_return);
			printf(lang[number_temp].language_name);
			printf(lang[number_temp].chouse_language_confirm);
			printf("\n      : ");
			for (int il0 = 0, il1 = 0;;) {
				il1 = scanf_s("%c", &code, 1);
				if (il1) {
					if (code == 10)break;
					else if (code == 'Y' || code == 'y') {
						printf(lang[number_temp].chouse_language_done);
						language = number_temp;
						return 1;
					}
				}
				else il1 = getchar();
				il0++;
				if (il0 >= 10)break;
			}
			printf("\nConfirm failed\n");
			language = 0;
		}
		printf("\nSelect failed\n");
		if (il >= 10) {
			language = 1;
			printf("超过选择次数最大值，默认采用中文。\n");
			il = getchar();
			return -1;
		}
		il++;
	}
}

int select_language(int if_cls,int if_reset) {
	if (if_reset) {
		select_language_choose();
		return 1;
	}
	if (language == -1) {
		int language_temp = 0;
		int language_size = sizeof(lang);
		int temp0 = 0;
		FILE* conf_file;
		errno_t erro;
		erro = _access_s("Password_Maker_Encryption_Key.conf", 0);
		//erro = _access_s("Encryption.conf", 0);
		if (erro == 0) {
			erro = fopen_s(&conf_file, "Password_Maker_Encryption_Key.conf", "rb");
			//erro = fopen_s(&conf_file, "Encryption.conf", "rb");
			if (erro == 0) {
				for (int il0 = 0, il1 = 0;;) {
					il1 = fgetc(conf_file);
					if (il1 == EOF)break;
					if (il1 == 10)break;
					if (il1 == 'L') {
						for (int il2 = 0;;) {
							il1 = fgetc(conf_file);
							if (il1 == EOF)break;
							if (il1 == 10)break;
							if (il1 >= '0' && il1 <= '9') {
								for (;;) {
									if (il1 >= '0' && il1 <= '9') {
										temp0 = il1 - '0';
										language_temp = language_temp * 10 + temp0;
									}
									else break;
									il1 = fgetc(conf_file);
									if (il1 == EOF)break;
									if (il1 == 10)break;
								}
								if (language_temp >= language_size) {
									language = 0;
									break;
								}
								for (;;) {
									if (il1 == '[') {
										il1 = fgetc(conf_file);
										if (il1 == EOF)break;
										if (il1 == 10)break;
										if (il1 != lang[language_temp].language_id[1])continue;
										il1 = fgetc(conf_file);
										if (il1 == EOF)break;
										if (il1 == 10)break;
										if (il1 != lang[language_temp].language_id[2])continue;
										il1 = fgetc(conf_file);
										if (il1 == EOF)break;
										if (il1 == 10)break;
										if (il1 != lang[language_temp].language_id[3])continue;
										il1 = fgetc(conf_file);
										if (il1 == EOF)break;
										if (il1 == 10)break;
										if (il1 != lang[language_temp].language_id[4])continue;
										language = language_temp;
										return 0;
									}
									il1 = fgetc(conf_file);
									if (il1 == EOF)break;
									if (il1 == 10)break;
								}
								break;
							}
						}
					}
				}
				fclose(conf_file);
				printf("\n  Language sitel read failed!\n");
				select_language_choose();
				getchar();
				if (if_cls <= 1)system("cls");
				return 1;
			}
			return -1;
		}
		else {
			select_language_choose();
			getchar();
			if (if_cls <= 1)system("cls");
		}
		return 1;
	}
	return 2;
}
