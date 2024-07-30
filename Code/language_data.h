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
		"\n  0  Version = %s ;\n\nYou can use other modes of the app by modifying the file name or entering more parameters;\n\n    Use [ ! ] Disable [ ! ] The last character, if you limit multiple characters, please all use [ ! ];\n    Use [ + ] , [ Power ] or [ Plus ] Enable strong mode to get higher password complexity;\n    Use [ Weighted ] or [ Balanced ] Enable the weighting algorithm\n        , the selection of character types will obtain a bonus to the total number of characters of that type\n        , so as to achieve a balance in type allocation;\n    Use [ Local ] Enable localization mode, the password will change after software migration, please use carefully;\n    Use [ Reset ] Reset the key;\n    Use [EN-US] Switch to English 使用 ZH-CN 切换语言到简体中文;\n\n    Use [ ? ] or [ Help ] Get help.\n\n"
	},
	{
		"[简体中文-中国大陆]",
		"[ZH-CN]",
		"\n请输入平台名称：",
		"\n请输入账户名称：",
		"\n密码格式空缺则使用默认格式，输入数字则限制密码位数(最大不超过256位），输入其它内容自动识别格式。\n请输入密码格式：",
		"\n请确认如下数据是否正确：\n登录平台：",
		"\n账号名称：",
		"\n密码格式：",
		"\n\n    计算中...",
		"\n\n密码为：",
		"计算结束。",
		"\n正在检查密钥:\n",
		"文件准备中……",
		"文件已找到。\n检查文件状态……\n",
		"\n检测到文件缺失。",
		"\n找到 %d 个错误。",
		"\n请检查密钥文件完整性。\n若要重新生成密钥，请输入“Y”，输入其余值退出。\n请输入：",
		"\n文件已就绪。\n",
		"文件准备失败！\n未知错误！\n\n请重试！\n输入其余值退出。",
		"\n正式使用之前，需要您输入三个值以生成专属密钥。\n注：输入值的最大长度为99位，超过99位的值将忽略。\n\n\n    请输入第一个值：",
		"\n    请输入第二个值：",
		"\n    请输入第三个值：",
		"\n\n    处理中……",
		"\n密钥读取失败，程序关闭。\n",
		"\n    Error 不能获得有效非重复值!该值用 & 替代。",
		"\n    Error 不能获得有效值!          该值用 ! 替代。",
		"\n要使用 ",
		" ,请输入 ",
		"\n已选择：",
		"\n输入[Y] 确认选择。\n",
		"    确认。\n",

		"不可用字符超过最大限额！\n",
		"\n  1  版本号 = %s ;\n\n您可以通过修改文件名或输入更多参数使用应用的其他模式：\n\n    使用 ! 禁用 ! 后的一个字符，若限制多个字符，请全部使用 ! ；\n    使用 + 、 Power 或 Plus 启用加强模式，可以获得更高的密码复杂度；\n    使用 Weighted 或 Balanced 启用加权算法，字符类型的选取将获得该类型字符总量的加成，从而达到类型分配的平衡；\n    使用 Local 启用本地化模式，软件迁移后密码将改变，请慎重使用；\n    使用 Reset 重新设置密钥；\n    使用 ZH-CN 切换语言到简体中文 Use [EN-US] Switch to English;\n\n    使用 ？ 或 Help 获取帮助。\n\n"
	}
};
int language = -1;
