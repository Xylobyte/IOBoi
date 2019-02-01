/*
Donovan Griego
CSCI 1151
11/12/18
IOBoi
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLINE 10000
#define MAXMAPLINE 15
unsigned int ifN, ifE, ifS, ifW, pos, gameinsession = 1, mapenabled, startpos, endpos;		//position variables, <<required to be global>>
char desc[MAXLINE];
	char mapln1[MAXLINE];	//mapline variable <<required to be global>>
	char mapln2[MAXLINE];	//mapline variable <<required to be global>>
	char mapln3[MAXLINE];	//mapline variable <<required to be global>>
	char mapln4[MAXLINE];	//mapline variable <<required to be global>>
	char mapln5[MAXLINE];	//mapline variable <<required to be global>>
	char mapln6[MAXLINE];	//mapline variable <<required to be global>>


void clear()
{
	system("cls");
}

void delay(float number_of_seconds)
{
	// Converting time into milli_seconds
	float milli_seconds = 1000 * number_of_seconds;

	// Stroing start time
	clock_t start_time = clock();

	// looping till required time is not acheived
	while (clock() < start_time + milli_seconds)
		;
}

int findend(char *line)
{
	char *lineends = "\r\n";
	unsigned int len = strlen(line);
	unsigned int span = strcspn(line, lineends);

	return span == len ? -1 : span;
}

void chomp(char *line)
{
	int firstend = findend(line);

	if (firstend >= 0)
		line[firstend] = '\0';
}

void drawmap()
{ //displays map for that current postition. map is defined in cartridge.
	if (mapenabled == 1)
	{
		printf("		___  ___  ___  ______ \n");
		printf("		|  \\/  | / _ \\ | ___ \\ \n");
		printf("		| .  . |/ /_\\ \\| |_/ /\n");
		printf("		| |\\/| ||  _  ||  __/ \n");
		printf("		| |  | || | | || |    \n");
		printf("		\\_|  |_/\\_| |_/\\_|    \n");
		printf("	______________________________________");
		printf("\n\n");
		printf("%s\n", mapln1);
		printf("%s\n", mapln2);
		printf("%s\n", mapln3);
		printf("%s\n", mapln4);
		printf("%s\n", mapln5);
		printf("%s\n", mapln6);
		printf("\n\n");
	}
}

void checkpos(char *fname)
{ //check current position and check what to do in cartridge.
	//int try =0;
	char line[MAXLINE];
	FILE *inf;
	char getAfter = ':', *character;
	if ((inf = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open cartridge '%s': %s\n", fname, strerror(errno));
		exit(1);
	}
	while (fgets(line, MAXLINE, inf) != NULL)
	{
		//printf("line:%s", line);
		if (strchr(line, getAfter) != NULL)
		{
			character = strchr(line, getAfter);
			if (atoi(++character) == pos)
			{
				//printf("atoi: %d\n",atoi(character));
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					ifN = atoi(line);
				}
				else
				{
					printf("There is a problem with the cartridge. (Most likely a typo)");
				}
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					ifS = atoi(line);
				}
				else
				{
					printf("There is a problem with the cartridge. (Most likely a typo)");
				}
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					ifE = atoi(line);
				}
				else
				{
					printf("There is a problem with the cartridge. (Most likely a typo)");
				}
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					ifW = atoi(line);
				}
				else
				{
					printf("There is a problem with the cartridge. (Most likely a typo)");
				}
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					strcpy(desc, line);
				}
				else
				{
					printf("There is a problem with the cartridge. (Most likely a typo)");
				}
				if (fgets(line, MAXLINE, inf) != NULL)
				{
					chomp(line);
					mapenabled = atoi(line);
					if(mapenabled==1){

						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln1, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln2, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln3, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln4, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln5, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
						if (fgets(line, MAXLINE, inf) != NULL)
						{
							chomp(line);
							strcpy(mapln6, line);
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
							}
						}
						else
						{
							printf("There is a problem with the cartridge. (Most likely a typo)");
						}
				
				break;
			}
		}
		//printf("try:%d\n",++try);
	}
	fclose(inf);
}

void checkavail()
{ //check and display available commands to the user

	if (ifN != 0)
		printf("'N' ");
	if (ifS != 0)
		printf("'S' ");
	if (ifE != 0)
		printf("'E' ");
	if (ifW != 0)
		printf("'W' ");
	printf("'quit'");
	printf("\n");
}

void showinfo()
{ //display map, description, etc.
	delay(.5);
	drawmap();
	delay(1);
	printf("%s\n", desc);
}

void input(char *fname)
{
	char cmd[MAXLINE], rdchr, excmd[MAXLINE];
	printf("Available commands: ");
inputcheck:
	checkavail();
	printf("Enter a command:\n");
entercheck:
	printf("/");
	fgets(cmd, MAXLINE, stdin); //get input command
	chomp(cmd);
	if (strcmp(cmd, "quit") == 0)
	{ //quit command
	quitting:
		printf("Are you sure you want to quit? (Y/N)\n");
	newlinecheck:
		printf("/");
		switch (getchar())
		{
		case '*':
		case ' ':
		case '\n':
			goto newlinecheck;
			break;
		case 'Y':
		case 'y':
			printf("Quitting...\n");
			gameinsession = 0;
			return;
			break;
		case 'N':
		case 'n':
			printf("Oops, my mistake. Carry on!\n");
			fgets(cmd, MAXLINE, stdin);
			input(fname);
			break;
		default:
			printf("Huh? I have no idea what you just said.\n");
			goto quitting;
		}
	}
	if (strcmp(cmd, "*clear") == 0)
	{ //admin command
		clear();
		printf("ADMIN CONSOLE- Done; Screen Cleared\n");
	}
	if (strcmp(cmd, "*showinfo") == 0)
	{ //admin command
		showinfo();
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*checkpos") == 0)
	{ //admin command
		checkpos(fname);
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*checkavail") == 0)
	{ //admin command
		checkavail();
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*drawmap") == 0)
	{ //admin command
		drawmap();
		printf("ADMIN CONSOLE- Done; Map Drawn\n");
	}
	if (strcmp(cmd, "*quit") == 0)
	{ //admin command
		printf("ADMIN CONSOLE- Done; Shutting down\n");
		exit(1);
	}
	if (strcmp(cmd, "*go S") == 0)
	{ //admin command
		pos = ifS;
		checkpos(fname);
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*go N") == 0)
	{ //admin command
		pos = ifN;
		checkpos(fname);
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*go E") == 0)
	{ //admin command
		pos = ifE;
		checkpos(fname);
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*go W") == 0)
	{ //admin command
		pos = ifW;
		checkpos(fname);
		printf("ADMIN CONSOLE- Done\n");
	}
	if (strcmp(cmd, "*pos") == 0)
	{ //admin command
		printf("ADMIN CONSOLE- Current position is '%d'\n", pos);
	}
	if (strcmp(cmd, "*//") == 0)
	{ //admin command
		printf("ADMIN CONSOLE- Executing next command\n");
		scanf("%s", excmd);
		system(excmd);
		fgets(cmd, MAXLINE, stdin);
	}
	rdchr = cmd[0]; //convert possible move command to character
	switch (rdchr)
	{

	case '*':
	case ' ':
	case '\n':
		goto entercheck;
	case 'N':
	case 'n':
		if (ifN != 0)
		{
			printf("You traveled North.\n");
			pos = ifN;
			checkpos(fname);
		}
		else
			goto dflt;
		break;
	case 'E':
	case 'e':
		if (ifE != 0)
		{
			printf("You traveled East.\n");
			pos = ifE;
			checkpos(fname);
		}
		else
			goto dflt;
		break;
	case 'W':
	case 'w':
		if (ifW != 0)
		{
			printf("You traveled West.\n");
			pos = ifW;
			checkpos(fname);
		}
		else
			goto dflt;
		break;
	case 'S':
	case 's':
		if (ifS != 0)
		{
			printf("You traveled South.\n");
			pos = ifS;
			checkpos(fname);
		}
		else
			goto dflt;
		break;

	default:
	dflt:
		printf("Invalid command! Enter one of these commands: ");
		goto inputcheck;
		break;
	}

}

void config(char *fname)
{
	char line[MAXLINE];
	FILE *inf;
	if ((inf = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open cartridge '%s': %s\n", fname, strerror(errno));
		exit(1);
	}
	if (fgets(line, MAXLINE, inf) != NULL)
	{ //read cartridge for starting position
		chomp(line);
		startpos = atoi(line);
	}
	if (fgets(line, MAXLINE, inf) != NULL)
	{ //read cartridge for ending position (will stop cartridge)
		chomp(line);
		endpos = atoi(line);
	}
	printf("SYSTEM: BOOTING '%s'\n", fname);
	gameinsession = 1;
}

int main(int argc, char *argv[])
{
	system("cls");
	delay(1);
	printf("SYSTEM: BOOTING\n");
	delay(1);
	printf("  _____ ____  ____   ____ _____ \n");
	printf(" |_   _/ __ \\|  _ \\ / __ \\_   _|\n");
	printf("   | || |  | | |_) | |  | || |  \n");
	printf("   | || |  | |  _ <| |  | || |  \n");
	printf("  _| || |__| | |_) | |__| || |_ \n");
	printf(" |_____\\____/|____/ \\____/_____|\n");
	delay(1);
	char fname[MAXLINE];

	if (argc == 2)
	{
		strcpy(fname, argv[1]);
		//fname = argv[1];
	}
	else
	{
		printf("SYSTEM: Enter Cartridge Name: ");
		if (fgets(fname, MAXLINE, stdin) == NULL)
		{
			fprintf(stderr, "Cartridge read failed: Field cannot be empty!\n");
			exit(1);
		}
	}
	chomp(fname);
	config(fname);
	pos = startpos;

	while (gameinsession == 1)
	{
		checkpos(fname);
		delay(1);
		clear();
		delay(.5);
		showinfo();
		input(fname);
		if (pos == endpos)
		{
			delay(1);
			clear();
			delay(0.5);
			showinfo();
			gameinsession = 0;
		}
	}
	printf("SYSTEM: Done reading: '%s'\n", fname);
	return 0;
}