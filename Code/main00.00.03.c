#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include"line.h"
#include"language_data.h"
#include"language.h"
#include"autoputin.h"
#include"mader.00.00.04.h"
#include"finded.h"
#include"help.h"


char version[4] = "1.0";
/*
{
useable:
autoputin.h;
finded.h;
mader.00.00.02.h;
mader.00.00.02_repassword.h
mader.00.00.03.h;
mader.00.00.04.h;
}
*/
int paas[100] = { 0 }, name[100] = { 0 }, format[256] = { 0 }, password[256] = { 0 }, find[20] = { 0 };

int main(int put_in, char** words[]) {
	int sum_paas = 0, title[100] = { 0 }, if_seted = 0, if_help = 0, if_reset = 0, if_plus = 0, if_local = 0, if_weighted = 0, if_ilogle = 0 ,local_mix = 0, ctrl[100] = { 0 }, ctrl0[] = { '+',0,'p','l','u','s',0,'p','o','w','e','r',0,'l','o','c','a','l',0,'w','e','i','g','h','t','e','d',0,'b','a','l','a','n','c','e','d',0,'?',0,'h','e','l','p',0,'!',0,'r','e','s','e','t',0,'z','h','-','c','n',0,'e','n','-','u','s',0,0,0,0,0,0,0,0,0};
	int if_mask_ready = 0;
	char title_p[100] = "title=";
	int char_no[100] = { 0,0,0,0 };
	char* p = 0, * p1 = 0;
	int* title_order = 0;
	p = words[0];
	for (int i = 0, i1 = 0;;) {
		if (*p == 0 || i >= 99) {
			break;
		}
		if (*p == '\\') {
			p1 = p + 1;
			i1 = i;
		}
		p++, i++;
	}
	p = words[0];
	for (int i = 0;;) {
		if (*p == 0 || i >= 99) {
			break;
		}
		if (p >= p1)break;
		local_mix = local_mix + *p % 9 + *p % (i + 7);
		p++, i++;
	}
	p = title_p + 6;
	for (int i = 0;;) {
		if (*p1 == 0 || i >= 99) {
			*p = 0;
			break;
		}
		title[i] = *p = *p1;
		if (title[i] >= 'A' && title[i] <= 'Z')title[i] = title[i] + 32;
		p++, i++, p1++;
	}
	*p = 0, * (p - 1) = 0, * (p - 2) = 0, * (p - 3) = 0, * (p - 4) = 0;
	system(title_p);
	system("color 8b");
	//if (title[0] == 'p' && title[1] == 'a' && title[2] == 's' && title[3] == 's' && title[4] == 'w' && title[5] == 'o' && title[6] == 'r' && title[7] == 'd' && title[8] == ' ' && title[9] == 'm' && title[10] == 'a' && title[11] == 'k' && title[12] == 'e' && title[13] == 'r' && (title[14] == '-' || title[14] == ' ' || title[14] == '_' || title[14] == '+') && (title[14] == '+' || title[15] == '+' || (title[15] == 'p' && title[16] == 'l' && title[17] == 'u' && title[18] == 's') || (title[15] == 'p' && title[16] == 'o' && title[17] == 'w' && title[18] == 'e' && title[19] == 'r')))
		//if_plus = 1;
	if_finded(title, ctrl0, find);
	if (find[8] == 1) {
		if_ilogle = 1;
		find_no(title, char_no);
	}
	if (find[10] == 1) {
		language = 1;
	}
	if (find[11] == 1) {
		language = 2;
	}
	if (find[6] == 1 || find[7] == 1) {
		if_help = 1;
		find[6] = 0, find[7] = 0;
		printf(line.l1);
		//goto help_box;
	}
	if (find[9] == 1) {
		if_reset = 1;
		find[9] = 0;
	}
	if (put_in <= 1) {
		if_mask_ready = select_language(put_in,if_reset);
		//help at here is old
		if_mask_ready = ctr_number_maker(put_in, &if_reset);
		if (if_mask_ready == -1)return -1;
		if_mask_ready = ctr_number_get();
		if (if_mask_ready == -1)return -1;
		//help at here is new
		if_help = help_box(if_help);
	}
input:
	if (put_in <= 1) {
		if (if_help != 1) {
			printf(line.l1);
			/*if (language == 1)printf("\n请输入平台名称：");
			else printf("\nPlease enter a platform name:");
			*/
			printf(lang[language].platform_name);
			sum_paas = autoputin(paas,100);
			/*if (language == 1)printf("\n请输入账户名称：");
			else printf("\nPlease enter an account name:");
			*/
			printf(lang[language].account_name);
			autoputin(name,100);
			/*if (language == 1)printf("\n密码格式空缺则使用默认格式，输入数字则限制密码位数(最大不超过256位），输入其它内容自动识别格式。\n请输入密码格式：");
			else printf("\nIf the password format is blank, the default format is used\n    , and entering a number limits the number of digits in the password (maximum 256 digits)\n    , enter other content to automatically recognize the format.\n\nPlease enter the password format:");
			*/
			printf(lang[language].password_format);
			autoputin(format,256);
		}
	}
	else {
		if (words[1] != 0) {
			p = words[1];
			for (int i = 0;;) {
				if (*p == 0 || i >= 99)break;
				paas[i] = *p;
				i++, p++;
			}
			if (words[2] != 0) {
				p = words[2];
				for (int i = 0;;) {
					if (*p == 0 || i >= 99)break;
					name[i] = *p;
					i++, p++;
				}

				if (words[3] != 0) {
					p = words[3];
					for (int i = 0;;) {
						if (*p == 0 || i >= 99)break;
						format[i] = *p;
						i++, p++;
					}
					for (int i = 4;;) {
						if (words[i] != 0 && i <= 99) {
							p = words[i];
							for (int i1 = 0;;) {
								if (*p == 0 || i1 >= 99)break;
								ctrl[i1] = *p;
								i1++, p++;
							}
							if_finded(ctrl, ctrl0, find);
						}
						else break;
						i++;
					}
				}
			}
		}
	}
	if (if_seted == 0) {
		if_seted = 1;
		if (find[0] == 1 || find[1] == 1 || find[2] == 1)if_plus = 1;
		if (find[3] == 1)if_local = 1;
		if (find[4] == 1 || find[5] == 1)if_weighted = 1;
		if (find[10] == 1) {
			language = 1;
		}
		if (find[11] == 1) {
			language = 2;
		}
		if (find[6] == 1 || find[7] == 1)if_help = 1;
		find[5] = 0, find[6] = 0;
		if (find[8] == 1) {
			if_ilogle = 1;
			find_no(ctrl, char_no);
		}
		if (find[9] == 1) {
			if_reset = 1;
		}
		if (put_in > 1) {
			if_mask_ready = select_language(put_in,if_reset);
			if_help = help_box(if_help);
			if_mask_ready = ctr_number_maker(put_in, &if_reset);
			if (if_mask_ready == -1)return -1;
			if_mask_ready = ctr_number_get();
			if (if_mask_ready == -1)return -1;
		}
		if (if_local != 1)local_mix = 0;
	}
	//printf("\n    |   %d    |     %d    |    %d    |",if_plus,if_local,if_weighted);
	if (put_in <= 1)printf("\n");
	printf(line.l4);
	if (if_help != 1) {
		/*if (language == 1)printf("\n请确认如下数据是否正确：\n登录平台：");
		else printf("\nPlease confirm that the following data is correct:\nPlatform Name  :");
		*/
		printf(lang[language].chack_platform_name);
		for (int i = 0;;) {
			if (paas[i] == 0 || paas[i] == 10)break;
			printf("%c", (char)paas[i]);
			i++;
		}
		/*if (language == 1)printf("\n账号名称：");
		else printf("\nAccount  Name  :");
		*/
		printf(lang[language].chack_account_name);
		for (int i = 0;;) {
			if (name[i] == 0 || name[i] == 10)break;
			printf("%c", (char)name[i]);
			i++;
		}
		//if (language == 1)printf("\n密码格式：");
		//else printf("\nPassword Normat:");
		printf(lang[language].chack_password_format);
		for (int i = 0;;) {
			if (format[i] == 0 || format[i] == 10)break;
			printf("%c", (char)format[i]);
			i++;
		}
		for (int i = 0;;) {
			if (char_no[0] && !i)printf("     --|  !  ");
			if (char_no[i] || (i >= 100))printf("%c ", char_no[i]);
			else break;
			i++;
		}
		if (char_no[0])printf(" |--");
		if (if_plus)printf("  +");
		if (if_weighted)printf("  Weighted");
		if (if_local)printf("  Local");
		//-------------------------------------------------------------------------------------------------------------------------------
compute:
		//if (language == 1)printf("\n\n    计算中...");
		//else printf("\n\n    Calculating...");
		printf(lang[language].createing);
		password_maker(paas, name, format, password, if_plus, if_weighted, local_mix,char_no);
		//if (language == 1)printf("\n\n密码为：");
		//else printf("\n\n[ Password ] :");
		printf(lang[language].password);

		for (int i = 0;;) {
			if (password[i] == 0 || i >= 256)break;
			//printf("\n%d", (int)password[i]);
			printf("%c", (char)password[i]);
			i++;
		}
		//if (language == 1)printf("\n\n                                                                                                       计算结束。");
		//else printf("\n\n                                                                                                         Done.");
		printf(line.null);
		printf(lang[language].done);
	}
	printf(line.l1);
	printf("\n");
	if (put_in <= 1)goto input;
	else return 1;
}