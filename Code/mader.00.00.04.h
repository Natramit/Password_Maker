int mask_code[10] = { 0 };

/*
* return  0 it not a number
* return !0 it is the value of the number
*/
int if_number(int char_in[]) {
	int value = 0, il00 = 0;
	for (;;) {
		if (char_in[il00]) {
			if (char_in[il00] <= '9' && char_in[il00] >= '0')value = value * 10 + char_in[il00] - 48;
			else break;
		}
		else break;
		il00++;
		if (il00 >= 3)break;
	}
	if (value && (char_in[il00] == 0 || char_in[il00] == 10))return value;
	else return 0;
}

/*
*
*/
int number_build(int number) {
	double ils[5] = { 0 }, temp00 = 0;
	int return_back = 0, iils[5] = { 0 };
	temp00 = number;
	if (temp00 < 0)temp00 = -temp00;
	for (int il0 = 0;;) {
		if (temp00 > 999 && il0 < 99)temp00 = temp00 / 100 + (int)temp00 % 100;
		else break;
		il0++;
	}
	if(mask_code[0]==0)ils[0] = (temp00 / 7) * 100, ils[1] = (temp00 / 13) * 1000, ils[2] = (temp00 / 17) * 1000, ils[3] = (temp00 / 19) * 1000, ils[4] = (temp00 / 23) * 1000;
	else {
		ils[0] = (temp00 / mask_code[1]) * 100, ils[1] = (temp00 / mask_code[2]) * 1000, ils[2] = (temp00 / mask_code[3]) * 1000, ils[3] = (temp00 / mask_code[4]) * 1000, ils[4] = (temp00 / mask_code[5]) * 1000;
		//printf("\n --------------------- | %d || %d || %d || %d || %d| mask 1~5\n", mask_code[1], mask_code[2], mask_code[3], mask_code[4], mask_code[5]);
	}
	for (int il0 = 0, il1 = 0, il2 = 10;;) {
		if ((int)ils[il0] % 10 == 0) {
			if (((int)(ils[il0] * il2) % 10) != 0)
			{
				ils[il0] = ils[il0] * il2;
			}
			else if (((int)(ils[il0] / il2) % 10) != 0) {
				ils[il0] = ils[il0] / il2;
			}
			else il2 = il2 * 10;
		}
		else {
			il0++, il1 = 0, il2 = 10;
		}
		il1++;
		if (il1 >= 20 || il0 >= 5) {
			break;
		}
	}
	//--------------------------- be int
	for (int il0 = 0;;) {
		iils[il0] = (int)((int)(ils[il0]) % 10);
		il0++;
		if (il0 >= 5)break;
	}

	////-------------------------- to exchange
	for (int il0 = 0, il1 = (int)temp00 % 5, il2 = (int)temp00 % 2;;) {
		if (il1 - 2 >= 0)il0 = il1 - il2 - 1;
		else il0 = il1 + il2 + 1;
		iils[il0] = iils[il0] + iils[il1];
		iils[il1] = iils[il0] - iils[il1];
		iils[il0] = iils[il0] - iils[il1];
		break;
	}
	//-------------------------- to sort_less
	for (int il0 = 0, il1 = 0;;) {
		if (iils[il0 + 1] > iils[il0]) {
			iils[il0] = iils[il0] + iils[il0 + 1];
			iils[il0 + 1] = iils[il0] - iils[il0 + 1];
			iils[il0] = iils[il0] - iils[il0 + 1];
		}
		il0++;
		if (il0 >= 4)break;
	}
	return_back = ((iils[4] * 10000) + (iils[2] * 1000) + (iils[3] * 100) + (iils[0] * 10) + iils[1]);
	return return_back;
}
/*
* int a     the code NO 1
* int b     the code NO 2
* int c     the code NO 3
* int min   the minster of number whell return
* int max   the maxster of number whell return
*/
int number_maker(int a, int b, int c, int min, int max)
{
	if (mask_code[0]) {
		a = a + mask_code[6], b = b + mask_code[7], c = c + mask_code[8];
		//printf("\n ------------------| %d || %d || %d | mask 6~8\n", mask_code[6], mask_code[7], mask_code[8]);
	}
	int turn_back = 0;
	if (a <= 100 || b <= 50 || c <= 120) {
		a = a + 101, b = b + 57, c = c + 123;
	}
	a = a * 3 + a % 12, b = b * 7 + b % 12, c = c * 11 + c % 12;
	turn_back = a + b + c;
	for (int times = 0;;) {
		turn_back = number_build(turn_back);
		//turn_back = turn_back / 10 + turn_back % 10;
		for (int il0 = 0;;) {
			if (turn_back >= min && turn_back <= max) {
				return turn_back;
			}
			else {
				turn_back = turn_back % (max - min + 1) + min + (turn_back / 3) % 7;
			}
			if (turn_back > max) {
				turn_back = turn_back - il0 % 10 - times % 10;
			}
			else if (turn_back < min) {
				turn_back = turn_back - il0 % 10 - times % 10;
			}
			if (il0 % 40 == 0) {
				if (turn_back > max)turn_back = turn_back % max;
				else if (turn_back < min)turn_back = turn_back % min + min;
			}
			if (il0 >= 400)break;
			il0++;
		}
		turn_back = turn_back + times;
		times++;
		if (times >= 999) {
			return 0;
			//printf("\n--------------------!!------------------- out put 0\n");
		}
	}
}
int ctr_number_maker_input(int* value) {
	char chars_in[100] = { 0 };
	for (int il0 = 0, il1 = 0;;) {
		il1 = scanf_s("%c", &chars_in[il0], 1);
		if (il1) {
			if (il0 >= 99 || chars_in[il0] == 10)return 1;
			*value = *value + il0 + (int)chars_in[il0] % (il0 + 3) + ((int)chars_in[il0] * (il0 + 3)) / 10;
		}
		//else il1 = getchar();
		il0++;
	}
}

/*
* return
* -1 文件缺失
*/
int ctr_mask_file_chack(FILE* mask_file,int if_printf) {
	extern int language;
	char mask_code_value = 0;
	int if_chack_start = 0, code_times = 0, if_chack_beginning = 0;
	int chack_left = 0, chack_line = 0, chack_all = 0, chack_line_number = 1;
	int if_breaked = 0, if_side_breaked = 0;
	if (if_printf <= 1) {
		//printf("\nChacking Encryption:\n");
		printf(lang[language].chack_encryption);
	}
	for (int il0 = 0;;) {
		if (mask_code_value == EOF)break;
		mask_code_value=fgetc(mask_file);
		if(if_printf<=1)printf("%c", mask_code_value);
		il0++;
		if (mask_code_value == '-')code_times++;
		if (code_times > 8 && mask_code_value == '>') {
			mask_code_value = fgetc(mask_file);
			if (mask_code_value == EOF)break;
			if(if_printf<=1)printf("%c", mask_code_value);
			if (mask_code_value != '>')return -1;
			mask_code_value = fgetc(mask_file);
			if (mask_code_value == EOF)break;
			if(if_printf<=1)printf("%c", mask_code_value);
			if (if_chack_start == 0) {
				if (mask_code_value != 's')return -1; 
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 't')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 'a')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 'r')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 't')return -1;
			}
			else {
				if (mask_code_value != 'e')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 'n')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if(if_printf<=1)printf("%c", mask_code_value);
				if (mask_code_value != 'd')return -1;
				if(if_printf<=1)printf("<<----------------------");
				if_chack_start = -1;
				if (chack_all % 2 != 1) {
					if (if_breaked == 0) {
						//printf(" | breaked2 | | %d |",chack_all);
						if_breaked++;
					}
				}
				//chack end
				if (chack_line_number == 49)return if_breaked;
				else return -1;
			}
			if_chack_beginning = 1;
			code_times = 0;
		}
		if (code_times > 8 && if_chack_beginning == 1 && mask_code_value == 10) {
			if_chack_start = 1, code_times = 0, if_chack_beginning = 0;
			//取出首次回车
			mask_code_value = fgetc(mask_file);
			if (mask_code_value == EOF)break;
			if(if_printf<=1)printf("%c", mask_code_value);
		}
		if (if_chack_start) {
			chack_line = chack_line + mask_code_value;
			if (mask_code_value == ' ') {
				chack_line = chack_line - '|' - ' ';
				if ((chack_line + chack_line_number) % 9 != 1) {
					if_breaked++, if_side_breaked++;
					//printf(" | breaked9 |");
				}
				//printf("\nleft mix is %d\n", chack_line);
				chack_left = chack_line;
			}
			if (mask_code_value == 10) {
				chack_line = chack_line - '|' - 10 - 13;
				//printf("\nline mix is %d\n", chack_line);
				if ((chack_line - chack_left + chack_line_number) % 7 != 1) {
					//if ((chack_line - chack_left) % 7 != 1) {
					if_breaked++, if_side_breaked++;
					//printf(" | breaked7 |");
				}
				if ((chack_line + chack_line_number) % 3 != 1) {
					//if ((chack_line - chack_left) % 7 != 1) {
					if (!if_side_breaked) {
						if_breaked++, if_side_breaked = 0;
						//printf(" | breaked3 |");
					}
				}
				//printf("\nline mix is %d\n", chack_line);
				chack_all = chack_all + chack_line;
				chack_line = 0, chack_line_number++;
			}
		}
		if (il0 >= 5000)break;
	}
	return -1;
}

/*
* return
* 0 file ready
* -1 file error close
*/
int ctr_number_maker(int if_printf,int* if_reset) {
	int number0 = 0, number1 = 0, number2 = 0;
	int mask_value_mix = 0, char_temp = 0;
	int mask_value_left = 0, mask_value_line = 0;
	FILE* mask_file;
	errno_t erro;
	if (*if_reset) {
		*if_reset = 0;
		goto mask_file_make;
	}
begin_chack:
	if (if_printf <= 1) {
		printf(line.l1);
		//printf("\n文件准备中……\n");
		printf(lang[language].file_preparation);
	}
	//if(if_printf<=1)printf("\n文件准备中……\n");
	erro = _access_s("Password_Maker_Encryption_Key.conf", 0);
	//erro = _access_s("Encryption.conf", 0);
	if (erro == 0) {
		if (if_printf <= 1) {
			//printf("File found.\nCheck file status...\n");
			printf(lang[language].chacking_file);
		}
		erro = fopen_s(&mask_file, "Password_Maker_Encryption_Key.conf", "rb");
		//erro = fopen_s(&mask_file, "Encryption.conf", "rb");
		if (erro == 0) {
			erro = ctr_mask_file_chack(mask_file, if_printf);
			fclose(mask_file);
			if (erro) {
				if (if_printf > 1)printf(line.l1);
				if (erro == -1) {
					//printf("\nFile corruption detected");
					printf(lang[language].file_corruption_detected);
				}
				else {
					//printf("\n %d errors found.");
					printf(lang[language].error_finds, erro);
				}
				//printf("\nCheck the key file integrity. \nTo regenerate the key, enter [ Y ] and enter the rest of the values to exit. \nPlease enter:");
				printf(lang[language].file_error);
				for (int ilc = 0,iln = 0,ili = 0,ilin = 0;;) {
					ilc = scanf_s("%c", &(char)ilin, 1);
					if (ilc) {
						if (ilin == 'y' || ilin == 'Y')ili = 1;
					}
					else ilc = getchar();
					if (ilin==10) {
						if (ili) {
							if (if_printf <= 1)system("cls");
							break;
						}
						else return -1;
					}
					iln++;
					if (iln > 10)break;
				}
			}
			else {
				if (if_printf <= 1) {
					//printf("\nThe file is ready.\n");
					printf(lang[language].file_ready);
				}
				if (if_printf <= 1)system("cls");
				return 0;
			}
		}
		else fclose(mask_file);
	}
mask_file_make:
	erro = fopen_s(&mask_file, "Password_Maker_Encryption_Key.conf", "w+");
	//erro = fopen_s(&mask_file, "Encryption.conf", "w+");
	if (erro == 0)
	{
		if (if_printf <= 1) {
			//printf("\nThe file is ready.\n");
			printf(lang[language].file_ready);
		}
		if (if_printf <= 1)system("cls");
	}
	else
	{
		//printf("File preparation failed!\nUnknown error!\n\nPlease try again!\nEnter the remaining values to exit.");
		printf(lang[language].file_failed);
		fclose(mask_file);
		scanf_s("%c", &(char)number0, 1);
		return -1;
	}
	printf(line.l2);
	//printf("\nYou need to enter three values to generate a private key before using it.\nNote: The maximum length of the input value is 99 bits, values beyond 99 bits will be ignored.\n\n\n    Please enter the first  value:");
	printf(lang[language].value_1);
	ctr_number_maker_input(&number0);
	//printf("\n    Please enter the second value:");
	printf(lang[language].value_2);
	ctr_number_maker_input(&number1);
	//printf("\n    Please enter the third  value:");
	printf(lang[language].value_3);
	ctr_number_maker_input(&number2);
	//printf("\n\n    Processing......");
	printf(lang[language].processing);
	//make start
	//number0 = number_maker(number0, number0 % 7, number0 % 99, 10000, 99999);
	//number1 = number_maker(number1, number0 % 13, number1 % 97, 10000, 99999);
	//number2 = number_maker(number2, number0 % 17, number2 % 79, 10000, 99999);
	int value0 = (int)((int)number0 / 100 + (int)number0 % 99), value1 = (int)((int)number1 / 97 + (int)number1 % 96), value2 = (int)((int)number2 / 91 + (int)number2 & 92);
	value0 = (int)(value1 / 44 + value2 % 27 + value0);
	value1 = (int)(value0 / 39 + value1);
	value2 = (int)(value2 / 70 + value2 % 45 + value2);
	//language-changed-------------------------------------------------------------------------------------------------------------------------------------
	//if (language == 0) {
	//	fprintf(mask_file, "ZH-CN\n");
	//}
	//else fprintf(mask_file, "EN-US\n");
	fprintf(mask_file,"L:%d | ", language);
	fprintf(mask_file, lang[language].language_id);
	fprintf(mask_file, " : ");
	fprintf(mask_file, lang[language].language_name);
	fprintf(mask_file, " ;\n");
	printf("\n              //////Encryption\\\\\\\\\\\\");
	fprintf(mask_file,"Encryption Code");
	printf("\n--------------------->>start<<---------------------\n");
	fprintf(mask_file,"\n--------------------->>start<<---------------------\n");
	for (int il0 = 1,il1 = 1,il2 = 0;;) {
		if (il1 > 48) {
			//printf("\n all mix is %d 2=%d\n", mask_value_mix, mask_value_mix % 2);
			break;
		}
		char_temp = (int)number_maker(il0 + value0, il0 % 2 + value1, il0 % 7 + value2 % (il0 % 37 + 1), 65, 122);
		//left_mix % 9  = 1
		if (il0 % 24 == 0 && il0 % 48 != 0) {
			if ((mask_value_line + char_temp + il1) % 9 != 1) {
				il2 = 1 - ((mask_value_line + char_temp + il1) % 9);
				if (il2 > 5) {
					char_temp = char_temp - 9 + il2;
				}
				else char_temp = char_temp + il2;
			}
			if (char_temp > 122)char_temp = char_temp - 9;
			if (char_temp < 65)char_temp = char_temp + 9;
			mask_value_left = mask_value_line + char_temp;
		}
		//right_mix % 7 = 1
		if (il0 % 48 == 0) {
			if ((mask_value_line - mask_value_left + char_temp + il1) % 7 != 1) {
				il2 = 1 - ((mask_value_line - mask_value_left + char_temp + il1) % 7);
				if (il2 > 4) {
					char_temp = char_temp - 7 + il2;
				}
				else char_temp = char_temp + il2;
			}
			//line_mix % 3 = 1
			il2 = 1 - ((mask_value_line + char_temp + il1) % 3);
			char_temp = char_temp + (il2 * 7);
			//all_mix +/- 21
			if (char_temp > 122)char_temp = char_temp - 21;
			if (char_temp < 65)char_temp = char_temp + 21;
			if (il1 >= 48) {
				if ((mask_value_mix + char_temp) % 2 != 1) {
					char_temp = char_temp - 21;
					if (char_temp > 122)char_temp = char_temp - 42;
					if (char_temp < 65)char_temp = char_temp + 42;
				}
			}
		}
		//
		mask_value_mix = mask_value_mix + char_temp;
		mask_value_line = mask_value_line + char_temp;
		printf("%c", char_temp);
		fprintf(mask_file,"%c", char_temp);
		if (il0 % 24 == 0) {
			if (il0 % 48 == 0) {
				printf("\n");
				fprintf(mask_file,"\n");
				il1++;
				mask_value_line = 0;
			}
			else {
				printf("| |");
				fprintf(mask_file,"| |");
			}
		}
		il0++;
	}
	printf("---------------------->>end<<----------------------\n");
	fprintf(mask_file,"---------------------->>end<<----------------------");
	fclose(mask_file);
	//make end
	if (if_printf <= 1)printf(line.l1);
	goto begin_chack;
}

int return_prime_number(int number_input,int unuse[]) {
	//7、11、13、17、19、23、29、31、37、41、43、47、53、59、61、67、71、73、79、83、89、97
	int number_return = 0, prime[22] = { 7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 }, less[22] = { 0 };
	for (int il0 = 0, il1 = 0;;) {
		if (prime[il0] == unuse[il1])prime[il0] = 512;
		il1++;
		if (il1 >= 5)il0++, il1 = 0;
		if (il0 >= 22)break;
	}
	for (int il0 = 0;;) {
		less[il0] = prime[il0] - number_input;
		if (less[il0] < 0)less[il0] = -less[il0];
		il0++;
		if (il0 >= 22)break;
	}
	for (int il0 = 0, il1 = 99;;) {
		if (less[il0] < il1) {
			number_return = il0;
			il1 = less[il0];
		}
		il0++;
		if (il0 >= 22)break;
	}
	number_return = prime[number_return];
	return number_return;
}

int be_prime_number() {
	int if_same = -1, times = -1;
	int number_temp[5] = { 0 }, number_used[5] = { 0 };

	for (int il0 = 0;;) {
		number_temp[il0] = return_prime_number(mask_code[il0 + 1],number_used);
		il0++;
		if (il0 >= 5)break;
	}
begin:
	if (if_same > -1) {
		number_temp[if_same] = return_prime_number(mask_code[if_same + 1], number_used);
	}
	if_same = -1, times++;
	for (int il0 = 0, il1 = 0, il2 = 0;;) {
		if (number_temp[il0] == number_temp[il1]) {
			if(il0!=il1)if_same = il0;
		}
		il0++;
		if (il0 >= 5) {
			il1++;
			il0 = il1 + 1;
		}
		if (il1 >= 5)break;
	}
	if (if_same > -1) {
		for (int il0 = 0;;) {
			number_used[il0] = number_temp[il0];
			il0++;
			if (il0 >= 5)break;
		}
		if (times >= 5) {
			return -1;
		}
		goto begin;
	}
	else {
		for (int il0 = 0;;) {
			mask_code[il0 + 1] = number_temp[il0];
			il0++;
			if (il0 >= 5)break;
		}
		//printf("\n primes | %d || %d || %d || %d || %d|\n",mask_code[1], mask_code[2], mask_code[3], mask_code[4], mask_code[5]);
		return 1;
	}
}

int ctr_number_get() {
	//extern int language;
	FILE* mask_file;
	errno_t erro;
	erro = fopen_s(&mask_file, "Password_Maker_Encryption_Key.conf", "rb");
	//erro = fopen_s(&mask_file, "Encryption.conf", "rb");
	if (erro == 0) {
		char mask_code_value = 0;
		int if_chack_start = 0, code_times = 0, if_chack_beginning = 0;
		int line_number = 1;
		int value_mix = 0, value_mix2 = 0, value_mix3 = 0;
		for (int il0 = 0;;) {
			mask_code_value = fgetc(mask_file);
			if (mask_code_value == EOF)break;
			il0++;
			if (mask_code_value == '-')code_times++;
			if (code_times > 8 && mask_code_value == '>') {
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if (mask_code_value != '>')return -1;
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
				if (if_chack_start == 0) {
					if (mask_code_value != 's')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 't')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 'a')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 'r')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 't')return -1;
				}
				else {
					if (mask_code_value != 'e')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 'n')return -1;
					mask_code_value = fgetc(mask_file);
					if (mask_code_value == EOF)break;
					if (mask_code_value != 'd')return -1;
					if_chack_start = -1;
					//chack end
					fclose(mask_file);
					mask_code_value = be_prime_number();
					mask_code[0] = 1;
					if (line_number == 49)return 0;
					else return -1;
				}
				if_chack_beginning = 1;
				code_times = 0;
			}
			if (code_times > 8 && if_chack_beginning == 1 && mask_code_value == 10) {
				if_chack_start = 1, code_times = 0, if_chack_beginning = 0;
				//取出首次回车
				mask_code_value = fgetc(mask_file);
				if (mask_code_value == EOF)break;
			}
			if (if_chack_start) {
				if (mask_code_value == ' ') {
					value_mix = value_mix + value_mix % (line_number + 3);
				}
				if (mask_code_value == 10) {
					/*mask_code
					* 0 is crl 0 unused ;!0 used
					* 1~5 is number_build_value is 7~23
					* 6~8 is number_maker_value 100~999
					* 9 is number_mix_value >9999
					*/
					if (line_number == 3) {
						mask_code[1] = number_maker(value_mix, value_mix2, value_mix3, 7, 99);
						value_mix = value_mix % 16, value_mix2 = value_mix2 % 16, value_mix3 = value_mix3 % 16;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 7) {
						mask_code[2] = number_maker(value_mix, value_mix2, value_mix3, 7, 99);
						value_mix = value_mix % 16, value_mix2 = value_mix2 % 16, value_mix3 = value_mix3 % 16;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 12) {
						mask_code[3] = number_maker(value_mix, value_mix2, value_mix3, 7, 99);
						value_mix = value_mix % 16, value_mix2 = value_mix2 % 16, value_mix3 = value_mix3 % 16;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 18) {
						mask_code[4] = number_maker(value_mix, value_mix2, value_mix3, 7, 99);
						value_mix = value_mix % 16, value_mix2 = value_mix2 % 16, value_mix3 = value_mix3 % 16;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 24) {
						mask_code[5] = number_maker(value_mix, value_mix2, value_mix3, 7, 99);
						value_mix = value_mix % 16, value_mix2 = value_mix2 % 16, value_mix3 = value_mix3 % 16;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 30) {
						mask_code[6] = number_maker(value_mix, value_mix2, value_mix3, 100, 999);
						value_mix = value_mix % 128, value_mix2 = value_mix2 % 128, value_mix3 = value_mix3 % 128;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 35) {
						mask_code[7] = number_maker(value_mix, value_mix2, value_mix3, 100, 999);
						value_mix = value_mix % 128, value_mix2 = value_mix2 % 128, value_mix3 = value_mix3 % 128;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 40) {
						mask_code[8] = number_maker(value_mix, value_mix2, value_mix3, 100, 999);
						value_mix = value_mix % 128, value_mix2 = value_mix2 % 128, value_mix3 = value_mix3 % 128;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					else if (line_number == 48) {
						mask_code[9] = number_maker(value_mix, value_mix2, value_mix3, 9999, 99999);
						value_mix = value_mix % 128, value_mix2 = value_mix2 % 128, value_mix3 = value_mix3 % 128;
						value_mix3 = value_mix + value_mix2 + value_mix3;
					}
					value_mix = value_mix % 10000 + value_mix / 100;
					value_mix2 = value_mix2 % 1000 + value_mix + il0;
					value_mix3 = value_mix3 % 1000 + line_number;
					line_number++;
				}
			}
			value_mix = value_mix + il0 + mask_code_value;
			value_mix2 = value_mix2 + value_mix2 % 23 + mask_code_value;
			value_mix3 = value_mix3 + mask_code_value * il0;
			if (il0 >= 5000)break;
		}
		//printf("\nThe key read failed and the program shuts down.\n");
		printf(lang[language].key_get_failed);
		return -1;
	}
	else {
		//printf("\nThe key read failed and the program shuts down.\n");
		printf(lang[language].key_get_failed);
		return -1;
	}
}
int password_maker(int paas[], int name[], int format[], int password[], int if_class_8, int if_weighted, int local_mix, int char_no[])
{
	int format_out[256] = { 0 }, format_size = 0, i = 0, model = 0, class8 = 0;
	int paas_mix = 0, name_mix = 0, local_mixed = 0, i1 = 0, i2 = 0, i3 = 0;
	int if_powerfull = 0;// 0 is not powerfull
	/*
	1--4   65-90 A
	5--8   97-122 a
	9--11  48-57 0
	12--14 32-47 ' ' '/'
	15--16 58-64 ':' '@'
	17     91-96
	18     123-126 '{' '`'
	19--24 128-255
	*/
	int classes[] = { 1,5,9,12,15,17,18,19,25,0,0,0 };
	int format_output[30][2] = { 0 };
	int class_number[10][2] = { 0,0,65,90,97,122,48,57,32,47,58,64,91,96,123,126,128,255,0,0 };

	//if balanced
	if (if_weighted != 1) {
		for (i1 = 0, i2 = 1;;) {
			if (classes[i1] == 0)break;
			classes[i1] = i2;
			i1++, i2++;
		}
	}
	for (i = 0, i1 = 0, i2 = 0;;) {
		if (classes[i2] == 0)break;
		format_output[i][0] = class_number[i1][0], format_output[i][1] = class_number[i1][1];
		i++;
		if (i == classes[i2])i1++, i2++;
	}
	if (if_class_8 != 1) {
		class8 = classes[7] - 1;
	}
	else {
		class8 = classes[8] - 1;
	}

	//if change size
	//-------------------------------------------------------------------------------------------
	int if_model_1_of_number = if_number(format);
	if (format[0] == 0 || format[0] == 10) {
		model = 0;
		format_size = 16;
	}
	else if (if_model_1_of_number <= 256 && if_model_1_of_number != 0) {
		model = 1;
		format_size = if_model_1_of_number;
	}
	else {
		model = 2;
	}
	//-----------------------------------------------------------------------------------------------------------------
	for (i = 0, paas_mix = 0;;) {
		if (paas[i] == 0)break;
		paas_mix = paas_mix + paas[i] * (i + 7) - paas[i] % (i + 3);
		i++, paas_mix++;
	}
	for (i = 0, name_mix = 0;;) {
		if (name[i] == 0)break;
		name_mix = name_mix + name[i] * (i + 9) - name[i] % (2 * i + 2);
		i++, name_mix++;
	}
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

	//mixs_make
	i1 = number_maker(mask_code[9] / 100 + mask_code[9] % 99, mask_code[9] / 88 + mask_code[9] % 99, 111, 111, 222);
	i2 = number_maker(mask_code[9] / 100 + mask_code[9] % 99, mask_code[9] / 88 + mask_code[9] % 99, 111, 555, 999);
	paas_mix = number_maker(paas_mix, name_mix, local_mix, i1, i2);
	i1 = number_maker(mask_code[9] / 77 + mask_code[9] % 76, mask_code[9] / 88 + mask_code[9] % 99, 555, 111, 222);
	i2 = number_maker(mask_code[9] / 77 + mask_code[9] % 76, mask_code[9] / 88 + mask_code[9] % 99, 555, 555, 999);
	name_mix = number_maker(name_mix, paas_mix, local_mix, i1, i2);
	i1 = number_maker(mask_code[9] / 55 + mask_code[9] % 54, mask_code[9] / 88 + mask_code[9] % 99, 777, 111, 222);
	i2 = number_maker(mask_code[9] / 55 + mask_code[9] % 54, mask_code[9] / 88 + mask_code[9] % 99, 777, 555, 999);
	//printf("\n-------------------------------mask9 | %d |\n", mask_code[9]);
	local_mixed = number_maker(local_mix, paas_mix, name_mix, i1, i2);
	/*
	paas_mix = number_maker(paas_mix, name_mix, local_mix, 100, 500);
	name_mix = number_maker(name_mix, paas_mix, local_mix, 177, 599);
	local_mixed = number_maker(local_mix, paas_mix, name_mix, 199, 623);
	*/

	//size=17 or ?   like  Aa**************1
	if (model == 0 || model == 1) {
		if (if_powerfull == 0) {
			format_out[0] = 1, format_out[1] = 2;
			if (format_size != 1)
				format_out[format_size - 1] = 3;
		}
		else {
			format_out[0] = 1, format_out[1] = 5;
			if (format_size != 1)
				format_out[format_size - 1] = 9;
		}
		for (i = 2, i1 = 0, i2 = 1399, i3 = 0;;) {
			if (i >= format_size - 1)break;
			if (paas[i1] == 0)i1 = 0;
			format_out[i] = number_maker(paas[i1] + i2, paas_mix + local_mixed, name_mix + local_mixed, 1, class8);
			i++, i1++, i2 = i2 * i + i2 / 2 + i1 - i3, i3++;
			if (i % 7 == 0)i2 = 2310, i3 = 2;
		}
	}
	else {
		for (i = 0, i1 = 1, i2 = 0;;) {
			if (format[i] == 0 || format[i] == 10)break;
			if (format[i] >= format_output[i1][0] && format[i] <= format_output[i1][1]) {
				format_out[i] = i1;
				i1 = 0, i++, format_size++;
			}
			i1++, i2++;
			if (i1 >= class8 + 1)i1 = 1;
			if (i2 >= 999)break;
		}
	}
model0:
	for (int i = 0;;) {
		if (password[i] != 0 || password[i + 1] != 0 || password[i + 2] != 0) {
			password[i] = 0;
			i++;
		}
		else break;
	}

	int i_no_times = 0, i_no_temp = 0, i_same_times = 0;

	for (i = 0, i1 = 0, i2 = 213, i3 = 2;;) {
		if (name[i1] == 0)i1 = 0;
		password[i] = number_maker(name[i1] + i2 + i1 + i + if_weighted + if_class_8 + if_class_8 + i_no_times, paas_mix + local_mixed + i_no_temp + 91, name_mix + local_mixed + 23, format_output[format_out[i]][0], format_output[format_out[i]][1]);
		//防止使用禁用字符
		if (char_no[0] != 0) {
			for (int il0 = 0;;) {
				if (char_no[il0] == 0 || il0 >= 100)break;
				if (password[i] == char_no[il0]) {
					if (i_no_temp == i)i_no_times++;
					else {
						if (i >= 2) {
							////防止连续相同数值
							if (!(password[i] == password[i - 1] && password[i] == password[i - 2])) {
								i_no_times = 0;
								i_no_temp = i;
							}
						}
						else {
							i_no_times = 0;
							i_no_temp = i;
						}
					}
					i--;
					break;
				}
				////防止连续相同数值
				if (i >= 2) {
					if ((password[i] == password[i - 1] && password[i] == password[i - 2])) {
						i--;
					}
				}
				il0++;
			}
		}
		//无法获得非禁用字符的补救方案
		if (i_no_times >= 399) {
			i_no_times = 0;
			i++;
			if (i >= 2) {
				if ((password[i - 1] == password[i - 2])) {
					password[i] = '&';
					//printf("\n    Error Unable to get a valid distinct value!    The value is replaced with &.");
					printf(lang[language].unable_get_value_1);
				}
				else {
					password[i] = '!';
					//printf("\n    Error Unable to get a valid value!    The value is replaced with !.");
					printf(lang[language].unable_get_value_2);
				}
			}
			else {
				password[i] = '!';
				//printf("\n    Error Unable to get a valid value!    The value is replaced with !.");
				printf(lang[language].unable_get_value_2);
			}
		}
		//防止连续相同数值
		if (i >= 2&& char_no[0] == 0) {
			if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
				i_same_times++;
				i--;
			}
			else {
				i_same_times = 0;
			}
			if (i_same_times >= 399) {
				i_same_times = 0;
				i++;
				password[i] = '&';
				//printf("\n    Error Unable to get a valid distinct value!    The value is replaced with &.");
				printf(lang[language].unable_get_value_1);
			}
		}
		i++, i1++, i2 = i2 * i3 + i2 % i3 + i1 * 7 + i1 % 25 + i3, i3++;
		if (i % 57 == 0)i2 = 231, i3 = 12;
		if (i >= format_size)break;
	}
	return 0;
}

