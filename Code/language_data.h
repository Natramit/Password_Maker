struct langs {
	char language_name[28];
	char language_id[8];
	char platform_name[31];
	char account_name[31];
	char password_format[254];
	char chack_platform_name[69];
	char chack_account_name[18];
	char chack_password_format[18];
	char createing[21];
	char password[17];
	char done[16];
	char chack_encryption[23];
	char file_preparation[23];
	char chacking_file[45];
	char file_corruption_detected[26];
	char error_finds[24];
	char file_error[124];
	char file_ready[21];
	char file_failed[95];
	char value_1[207];
	char value_2[36];
	char value_3[36];
	char processing[23];
	char key_get_failed[50];
	char unable_get_value_1[82];
	char unable_get_value_2[73];
	char chouse_language_l[12];
	char chouse_language_r[13];
	char chouse_language_chouse_return[14];
	char chouse_language_confirm[57];
	char chouse_language_done[15];
	char unavailable_chars_over[50];
	char help[809];
};

struct langs lang[] = {
	{
		"[English-USA]",
		"[EN-US]",
		"\nPlease enter a platform name:",
		"\nPlease enter an account name:",
		"\nIf the password format is blank, the default format is used\n    , and entering a number limits the number of digits in the password (maximum 256 digits)\n    , enter other content to automatically recognize the format.\n\nPlease enter the password format:",
		"\nPlease confirm that the following data is correct:\nPlatform Name  :",
		"\nAccount  Name  :",
		"\nPassword Normat:",
		"\n\n    Calculating...",
		"\n\n[ Password ] :",
		"  Done.",
		"\nChacking Encryption:\n",
		"File preparation......",
		"File found.\nCheck file status...\n",
		"\nFile corruption detected",
		"\n %d errors found.",
		"\nCheck the key file integrity. \nTo regenerate the key, enter [ Y ] and enter the rest of the values to exit. \nPlease enter:",
		"\nThe file is ready.\n",
		"File preparation failed!\nUnknown error!\n\nPlease try again!\nEnter the remaining values to exit.",
		"\nYou need to enter three values to generate a private key before using it.\nNote: The maximum length of the input value is 99 bits, values beyond 99 bits will be ignored.\n\n\n    Please enter the first  value:",
		"\n    Please enter the second value:",
		"\n    Please enter the third  value:",
		"\n\n    Processing......",
		"\nThe key read failed and the program shuts down.\n",
		"\n    Error Unable to get a valid distinct value!    The value is replaced with &.",
		"\n    Error Unable to get a valid value!    The value is replaced with !.",
		"\nTo use ",
		" , enter ",
		"\nSelected: ",
		"\nEnter [Y] to confirm the selection.\n",
		"    Done.\n",

		"Unavailable characters exceed the maximum limit!\n",
		"\n  0  Version = %s ;\n\nYou can use other modes of the app by modifying the file name or entering more parameters;\n\n    Use [ ! ] Disable [ ! ] The last character, if you limit multiple characters, please all use [ ! ];\n    Use [ + ] , [ Power ] or [ Plus ] Enable strong mode to get higher password complexity;\n    Use [ Weighted ] or [ Balanced ] Enable the weighting algorithm\n        , the selection of character types will obtain a bonus to the total number of characters of that type\n        , so as to achieve a balance in type allocation;\n    Use [ Local ] Enable localization mode, the password will change after software migration, please use carefully;\n    Use [ Reset ] Reset the key;\n    Use [EN-US] Switch to English ʹ�� ZH-CN �л����Ե���������;\n\n    Use [ ? ] or [ Help ] Get help.\n\n"
	},
	{
		"[��������-�й���½]",
		"[ZH-CN]",
		"\n������ƽ̨���ƣ�",
		"\n�������˻����ƣ�",
		"\n�����ʽ��ȱ��ʹ��Ĭ�ϸ�ʽ��������������������λ��(��󲻳���256λ�����������������Զ�ʶ���ʽ��\n�����������ʽ��",
		"\n��ȷ�����������Ƿ���ȷ��\n��¼ƽ̨��",
		"\n�˺����ƣ�",
		"\n�����ʽ��",
		"\n\n    ������...",
		"\n\n����Ϊ��",
		"���������",
		"\n���ڼ����Կ:\n",
		"�ļ�׼���С���",
		"�ļ����ҵ���\n����ļ�״̬����\n",
		"\n��⵽�ļ�ȱʧ��",
		"\n�ҵ� %d ������",
		"\n������Կ�ļ������ԡ�\n��Ҫ����������Կ�������롰Y������������ֵ�˳���\n�����룺",
		"\n�ļ��Ѿ�����\n",
		"�ļ�׼��ʧ�ܣ�\nδ֪����\n\n�����ԣ�\n��������ֵ�˳���",
		"\n��ʽʹ��֮ǰ����Ҫ����������ֵ������ר����Կ��\nע������ֵ����󳤶�Ϊ99λ������99λ��ֵ�����ԡ�\n\n\n    �������һ��ֵ��",
		"\n    ������ڶ���ֵ��",
		"\n    �����������ֵ��",
		"\n\n    �����С���",
		"\n��Կ��ȡʧ�ܣ�����رա�\n",
		"\n    Error ���ܻ����Ч���ظ�ֵ!��ֵ�� & �����",
		"\n    Error ���ܻ����Чֵ!          ��ֵ�� ! �����",
		"\nҪʹ�� ",
		" ,������ ",
		"\n��ѡ��",
		"\n����[Y] ȷ��ѡ��\n",
		"    ȷ�ϡ�\n",

		"�������ַ���������޶\n",
		"\n  1  �汾�� = %s ;\n\n������ͨ���޸��ļ���������������ʹ��Ӧ�õ�����ģʽ��\n\n    ʹ�� ! ���� ! ���һ���ַ��������ƶ���ַ�����ȫ��ʹ�� ! ��\n    ʹ�� + �� Power �� Plus ���ü�ǿģʽ�����Ի�ø��ߵ����븴�Ӷȣ�\n    ʹ�� Weighted �� Balanced ���ü�Ȩ�㷨���ַ����͵�ѡȡ����ø������ַ������ļӳɣ��Ӷ��ﵽ���ͷ����ƽ�⣻\n    ʹ�� Local ���ñ��ػ�ģʽ�����Ǩ�ƺ����뽫�ı䣬������ʹ�ã�\n    ʹ�� Reset ����������Կ��\n    ʹ�� ZH-CN �л����Ե��������� Use [EN-US] Switch to English;\n\n    ʹ�� �� �� Help ��ȡ������\n\n"
	}
};
int language = -1;
