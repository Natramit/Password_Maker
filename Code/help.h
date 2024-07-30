int help_box(int if_help) {
	extern char version[4];
	if (if_help == 1) {
		printf(lang[language].help, version);
		printf(line.l1);
		printf("\n");
	}
	return 0;
}