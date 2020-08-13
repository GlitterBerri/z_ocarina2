/************************************************************************
 *									*
 *	����������Υ�å��������Ѵ�					*
 *				1998ǯ 6��10��(������) 14��26ʬ37�� JST	*
 ************************************************************************/

/*#include <iostream.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define         MAX(a, b)       ((a) >= (b) ? (a) : (b))
#define         STRNCMP(a, b)	(!strncmp((a), (b), strlen((b))))

#define		RTF_BUFFER	0x100000

char	label_name[0x100];

int	rtf_buffer_cnt = 0;
char	rtf_buffer[RTF_BUFFER + 1];
char	rtf_buffer_name[0x100];
int	txt_buffer_cnt = 0;
char	txt_buffer[RTF_BUFFER + 1];

/*======================================================================*
 *	ʸ����θ���							*
 *======================================================================*/
int find_string(
    char	*s,
    int		idx
    )
{
    int	i;

    if(s == 0) {
	return -1;
    }

    for(i = idx; i < rtf_buffer_cnt; i += 1) {
	if(!strncmp(&rtf_buffer[i], s, strlen(s))) {
	    return i;
	}
    }
    return -1;
}

/*======================================================================*
 *	���顼�ơ��֥��Ĥ���						*
 *======================================================================*/
char	color_tbl[0x100];

void make_color_tbl(void)
{
    int	color_p, r, g, b;
    int	color_tbl_cnt = 1;

    color_p = find_string("colortbl", 0) + strlen("colortbl") + 1;
    while(rtf_buffer[color_p] != ';') {
	color_p += 1;
    }
    color_p += 1;

    while(rtf_buffer[color_p] == '\\') {
	sscanf(&rtf_buffer[color_p], "\\red%d\\green%d\\blue%d;", &r, &g, &b);
	while(rtf_buffer[color_p] != ';') {
	    color_p += 1;
	}
	color_p += 1;
	if((r == 255 && g == 0 && b == 0) || (r == 221 && g == 8 && b == 6)) {
	    color_tbl[color_tbl_cnt] = 1;
	} else if((r == 0 && g == 255 && b == 0) || (r == 31 && g == 183 && b == 20) || (r == 0 && g == 100 && b == 17)) {
	    color_tbl[color_tbl_cnt] = 2;
	} else if((r == 0 && g == 0 && b == 255) || (r == 0 && g == 0 && b == 212)) {
	    color_tbl[color_tbl_cnt] = 3;
	} else if((r == 128 && g == 128 && b == 255) || (r == 192 && g == 192 && b == 192) || (r == 2 && g == 171 && b == 234)) {
	    color_tbl[color_tbl_cnt] = 4;
	} else if((r == 255 && g == 0 && b == 255) || (r == 242 && g == 8 && b == 132)) {
	    color_tbl[color_tbl_cnt] = 5;
	} else if((r == 255 && g == 255 && b == 0) || (r == 252 && g == 243 && b == 5)) {
	    color_tbl[color_tbl_cnt] = 6;
	} else if(r == 0 && g == 0 && b == 0) {
	    color_tbl[color_tbl_cnt] = 0;
	} else {
	    color_tbl[color_tbl_cnt] = 255;
	}
	color_tbl_cnt += 1;
    }
}

/*======================================================================*
 *	�ƥ����Ȥ��Ѵ������ǡ�����ƥ����ȥХåե��˳�Ǽ����		*
 *======================================================================*/
void printf_txt(
    char	*s
    )
{
    strcat(&txt_buffer[txt_buffer_cnt], s);
    txt_buffer_cnt += strlen(s);
}

/*======================================================================*
 *	�ƥ����Ȥ���							*
 *======================================================================*/
unsigned char	pal_chg_code[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x80, 0x81, 0x82, 0x00, 0x83, 0x00, 0x00, 0x84,
    0x85, 0x86, 0x87, 0x88, 0x00, 0x00, 0x00, 0x89,

    0x00, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x8b, 0x00,
    0x00, 0x8c, 0x00, 0x8d, 0x8e, 0x00, 0x00, 0x8f,

    0x90, 0x91, 0x92, 0x00, 0x93, 0x00, 0x00, 0x94,
    0x95, 0x96, 0x97, 0x98, 0x00, 0x00, 0x00, 0x99,

    0x00, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x9b, 0x00,
    0x00, 0x9c, 0x00, 0x9d, 0x9e, 0x00, 0x00, 0x00,};
void make_txt(void)
{
    int		i = 0, cc, c = 0, j;
    char	wb[0x100];

    if((i = find_string("\\pard", i)) < 0) {
	return;
    }
    while(rtf_buffer_cnt > i) {
	if(rtf_buffer[i] == 0xd && rtf_buffer[i + 1] == 0xa) {
	    printf_txt("\n");
	    i += 2;
	} else if(STRNCMP(&rtf_buffer[i], "\\nooverflow")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\nowidctlpar")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\nowwrap")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\ulnone")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\pard")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\lang")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\plain")) {
	    if(c != 0) {
		printf_txt("@#00");
		c = 0;
	    }
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\par")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\tab")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	    printf_txt("\t");
	} else if(STRNCMP(&rtf_buffer[i], "\\fs")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\cf")) {
	    if(STRNCMP(&txt_buffer[txt_buffer_cnt - 4], "@#0")) {
		txt_buffer_cnt -= 4;
		txt_buffer[txt_buffer_cnt] = '\0';
		sscanf(&rtf_buffer[i], "\\cf%d", &cc);
		c = color_tbl[cc];
		sprintf(wb, "@#0%1d", c);
		printf_txt(wb);
	    } else {
		sscanf(&rtf_buffer[i], "\\cf%d", &cc);
		if(c != color_tbl[cc]) {
		    c = color_tbl[cc];
		    sprintf(wb, "@#0%1d", c);
		    printf_txt(wb);
		}
	    }
	    if(c == 255) {
		printf_txt("----ERROR----:COLOR");
	    }
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\f")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\i")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else if(STRNCMP(&rtf_buffer[i], "\\{")) {
	    c = 0;
	    sprintf(wb, "{%s_ ", rtf_buffer_name);
	    printf_txt(wb);
	    i += strlen("\\{");
	} else if(STRNCMP(&rtf_buffer[i], "\\}")) {
	    c = 0;
	    printf_txt("}");
	    i += strlen("\\}");
	} else if(STRNCMP(&rtf_buffer[i], "\\\\")) {
	    printf_txt("\\");
	    i += strlen("\\\\");
	} else if(STRNCMP(&rtf_buffer[i], "\\\'")) {
	    sscanf(&rtf_buffer[i], "\\\'%02x;", &j);
	    /*
	    if(j >= 0x80) {
		if(pal_chg_code[j - 0x80] == 0) {
		    printf_txt("----ERROR----:PAL CODE");
		} else {
		    j = pal_chg_code[j - 0x80];
		}
	    }
	    */
	    if (j>=0xA0) {
	        sprintf(wb, "@!%02x", j);
	    } else {
	        sprintf(wb, "%c", (char)j);
	    }
	    printf_txt(wb);
	    i += strlen("\\\'") + 2;
	} else if(STRNCMP(&rtf_buffer[i], "{")) {
	    i += strlen("{");
	} else if(STRNCMP(&rtf_buffer[i], "}")) {
	    i += strlen("}");
	} else if(STRNCMP(&rtf_buffer[i], "/")) {
	    printf_txt("/");
	    i += strlen("/");
	    i = find_string("\\par", i);
	    if(STRNCMP(&rtf_buffer[i], "\\par")) {
		do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
				 && rtf_buffer[i] != 0xd);
		if(rtf_buffer[i] == ' ') i += 1;
	    }
	    if(rtf_buffer[i] == 0xd && rtf_buffer[i + 1] == 0xa) {
		printf_txt("\n");
		i += 2;
	    }
	    if(c != 0) {
		sprintf(wb, "@#0%1d", c);
		printf_txt(wb);
	    }
	} else if(STRNCMP(&rtf_buffer[i], "\\")) {
	    do i += 1; while(rtf_buffer[i] != '\\' && rtf_buffer[i] != ' '
			     && rtf_buffer[i] != 0xd);
	    if(rtf_buffer[i] == ' ') i += 1;
	} else {
	    sprintf(wb, "%c", rtf_buffer[i]);
	    printf_txt(wb);
	    i += 1;
	}
    }
}

/*======================================================================*
 *	�ǡ���������Ϥ���						*
 *======================================================================*/
void print_define(
    FILE *fp
    )
{
    fprintf(fp, "#define ND_SYURYOU\t0x02\t/* �ǡ����ţΣ� (}) */\n");
    fprintf(fp, "#define NZ_KEYWAIT\t0x04\t/* �����Ԥ� (@02) */\n");
    fprintf(fp, "#define NZ_BLANK\t0x06\t/* ���� (_\?\?) */\n");
    fprintf(fp, "#define NZ_NEXTMSG\t0x07\t/* �Σţأԥ�å������ֹ� (#\?\?\?\?) */\n");
    fprintf(fp, "#define NZ_START\t0x08\t/* ���ɽ������ ([) */\n");
    fprintf(fp, "#define NZ_STOP\t\t0x09\t/* ���ɽ����λ (]) */\n");
    fprintf(fp, "#define NZ_DISPSTOP\t0x0a\t/* ɽ����� (@00) */\n");
    fprintf(fp, "#define NZ_ENEMY\t0x0b\t/* Ũ¦���楳���� (@01) */\n");
    fprintf(fp, "#define NZ_TIMER\t0x0c\t/* �ԣɣͣţ� (+\?\?) */\n");
    fprintf(fp, "#define NZ_PAUSE\t0x0d\t/* �����Ԥ� (@02) */\n");
    fprintf(fp, "#define NZ_TIMER_END\t0x0e\t/* �����ޡ��ս�λ������ (=\?\?) */\n");
    fprintf(fp, "#define NZ_NAME\t\t0x0f\t/* �ץ쥤�䡼��Ͽ̾�� (%%) */\n");
    fprintf(fp, "#define NZ_OCARINA\t0x10\t/* ������� ��@03��*/\n");
    fprintf(fp, "#define NZ_BGM\t\t0x11\t/* ������ɡʣ£ǣ͡�(*\?\?\?\?) */\n");
    fprintf(fp, "#define NZ_SE\t\t0x12\t/* ������ɡʣӣš�($\?\?\?\?) */\n");
    fprintf(fp, "#define NZ_DPITEM\t0x13\t/* �����ƥ� (&\?\?\?) */\n");
    fprintf(fp, "#define NZ_SPEED\t0x14\t/* ʸ��ɽ�����ԡ��� (~\?\?)*/\n");
    fprintf(fp, "#define NZ_TEXTURE\t0x15\t/* ����ƥ������� (^\?\?\?\?\?\?) */\n");
    fprintf(fp, "#define NZ_EVENT_0\t0x16\t/* �ţ֣ţΣԥ����ޡ��� (@04) */\n");
    fprintf(fp, "#define NZ_EVENT_1\t0x17\t/* �ţ֣ţΣԥ����ޡ��� (@05) */\n");
    fprintf(fp, "#define NZ_YABUSAME\t0x18\t/* ήŭ�ϥ����� (@06) */\n");
    fprintf(fp, "#define NZ_KINSTA\t0x19\t/* �⥹�� (@10) */\n");
    fprintf(fp, "#define NZ_NONONO\t0x1a\t/* ������ػ� (@07) */\n");
    fprintf(fp, "#define NZ_SENTAKU_2\t0x1b\t/* ���� (@08) */\n");
    fprintf(fp, "#define NZ_SENTAKU_3\t0x1c\t/* ���� (@09) */\n");
    fprintf(fp, "#define NZ_FISHSZ\t0x1d\t/* ����ٵ������� (@11) */\n");
    fprintf(fp, "#define NZ_RANKING\t0x1e\t/* ����������ɽ�� (<\?\?) */\n");
    fprintf(fp, "#define NZ_ZELDATM\t0x1f\t/* �����������ɽ�� (@12) */\n");
    fprintf(fp, "#define NKAIGYO\t\t0x01\t/* ���� */\n");
    fprintf(fp, "#define NCHANGE\t\t0x05\t/* ʸ�������� (@#0?) */\n");
    fprintf(fp, "#define NSPACE\t\t0x20\t/* ���ڡ��� */\n");
}

void make_data1(
    char *fname
    )
{
    FILE	*fp;
    char	nm[0x100];
    int		i = 0, no, dt;

    if((fp = fopen(fname, "w")) == 0) {
	printf("�ե����뤬�����ץ�Ǥ��ޤ���Ǥ���\n");
	exit(1);
    }

    print_define(fp);
    
    while(txt_buffer_cnt > i) {
	if(txt_buffer[i] == '{') {
	    sscanf(&txt_buffer[i + 1], "%s %X\\%X", &nm, &no, &dt);
	    fprintf(fp, "extern unsigned char %s%04X[];\n", nm, no);
	}
	i += 1;
    }

    fclose(fp);
}

/*======================================================================*
 *	�ǡ���������Ϥ���						*
 *======================================================================*/
void make_data2(
    char *fname
    )
{
    FILE	*fp;
    char	nm[0x100];
    int		i = 0, no, dt;

    if((fp = fopen(fname, "w")) == 0) {
	printf("�ե����뤬�����ץ�Ǥ��ޤ���Ǥ���\n");
	exit(1);
    }

    fprintf(fp, "static MSG_NT message_tbl_%s[] = {\n", label_name);

    while(txt_buffer_cnt > i) {
	if(txt_buffer[i] == '{') {
	    sscanf(&txt_buffer[i + 1], "%s %X\\%X", &nm, &no, &dt);
	    fprintf(fp, "\t{0x%04X, 0x%02X, %s%04X}, /*	%d */ \n",
		    no, dt, nm, no, no);
	}
	i += 1;
    }

    fprintf(fp, "\t{0xFFFF, 0x00, NULL}};\n");

    fclose(fp);
}

/*======================================================================*
 *	�ǡ���������Ϥ���						*
 *======================================================================*/
void make_data3(
    char *fname
    )
{
    FILE	*fp;
    char	nm[0x100];
    int		i = 0, no, dt;

    if((fp = fopen(fname, "w")) == 0) {
	printf("�ե����뤬�����ץ�Ǥ��ޤ���Ǥ���\n");
	exit(1);
    }

    print_define(fp);
    
    while(txt_buffer_cnt > i) {
	if(txt_buffer[i] == '{') {
	    sscanf(&txt_buffer[i + 1], "%s %X\\%X", &nm, &no, &dt);
	    fprintf(fp, "unsigned char %s%04X[] = {\n", nm, no);
	    while(txt_buffer[i] != '\n') i += 1;
	    i += 1;
	    while(txt_buffer[i] != '}') {
		switch(txt_buffer[i]) {
		case '\n':
		    fprintf(fp, " NKAIGYO,\n");
		    i += 1;
		    break;
		case '\t':
		    fprintf(fp, "\t");
		    i += 1;
		    break;
		case '/':
		    fprintf(fp, " NZ_KEYWAIT,");
		    i += 1;
		    if(txt_buffer[i] == '\n') {
			fprintf(fp, "\n");
			i += 1;
		    }
		    break;
		case '_':
		    sscanf(&txt_buffer[i + 1], "%02d", &dt);
		    fprintf(fp, " NZ_BLANK, 0x%02X,", dt);
		    i += 3;
		    break;
		case '#':
		    sscanf(&txt_buffer[i + 1], "%04X", &dt);
		    fprintf(fp, " NZ_NEXTMSG, 0x%02X,", (dt >> 8) & 0xff);
		    fprintf(fp, " 0x%02X,", dt & 0xff);
		    i += 5;
		    break;
		case '[':
		    fprintf(fp, " NZ_START,");
		    i += 1;
		    break;
		case ']':
		    fprintf(fp, " NZ_STOP,");
		    i += 1;
		    break;
		case '+':
		    sscanf(&txt_buffer[i + 1], "%02d", &dt);
		    fprintf(fp, " NZ_TIMER, 0x%02X,", dt);
		    i += 3;
		    if(txt_buffer[i] == '\n') {
			fprintf(fp, "\n");
			i += 1;
		    }
		    break;
		case '=':
		    sscanf(&txt_buffer[i + 1], "%02d", &dt);
		    fprintf(fp, " NZ_TIMER_END, 0x%02X,", dt);
		    i += 3;
		    break;
		case '%':
		    fprintf(fp, " NZ_NAME,");
		    i += 1;
		    break;
		case '*':
		    sscanf(&txt_buffer[i + 1], "%04X", &dt);
		    fprintf(fp, " NZ_BGM, 0x%02X,", (dt >> 8) & 0xff);
		    fprintf(fp, " 0x%02X,", dt & 0xff);
		    i += 5;
		    break;
		case '$':
		    sscanf(&txt_buffer[i + 1], "%04X", &dt);
		    fprintf(fp, " NZ_SE, 0x%02X,", (dt >> 8) & 0xff);
		    fprintf(fp, " 0x%02X,", dt & 0xff);
		    i += 5;
		    break;
		case '&':
		    sscanf(&txt_buffer[i + 1], "%03d", &dt);
		    fprintf(fp, " NZ_DPITEM, 0x%02X,", dt);
		    i += 4;
		    break;
		case '~':
		    sscanf(&txt_buffer[i + 1], "%02d", &dt);
		    fprintf(fp, " NZ_SPEED, 0x%02X,", dt);
		    i += 3;
		    break;
		case '<':
		    sscanf(&txt_buffer[i + 1], "%02d", &dt);
		    fprintf(fp, " NZ_RANKING, 0x%02X,", dt);
		    i += 3;
		    break;
		case '^':
		    sscanf(&txt_buffer[i + 1], "%06X", &dt);
		    fprintf(fp, " NZ_TEXTURE, 0x%02X,", (dt >> 16) & 0xff);
		    fprintf(fp, " 0x%02X,", (dt >> 8) & 0xff);
		    fprintf(fp, " 0x%02X,", dt & 0xff);
		    i += 7;
		    break;
		case '@':
		    if(txt_buffer[i + 1] == '#') {
			sscanf(&txt_buffer[i + 2], "%1d", &dt);
			i += 3;
			switch(dt) {
			case 0:
			    sscanf(&txt_buffer[i], "%1d", &dt);
			    fprintf(fp, " NCHANGE, 0x%x,", dt + 0x40);
			    i += 1;
			    break;
			default:
			    break;
			}
		    } else if(txt_buffer[i + 1] == '!') {
		    	sscanf(&txt_buffer[i + 2], "%02X", &dt);
		    	fprintf(fp, " 0x%02X,", dt);
		    	i +=4;
		    	break;
		    } else {
			sscanf(&txt_buffer[i + 1], "%02d", &dt);
			i += 3;
			switch(dt) {
			case 0:
			    fprintf(fp, " NZ_DISPSTOP,");
			    break;
			case 1:
			    fprintf(fp, " NZ_ENEMY,");
			    break;
			case 2:
			    fprintf(fp, " NZ_PAUSE,");
			    break;
			case 3:
			    fprintf(fp, " NZ_OCARINA,");
			    break;
			case 4:
			    fprintf(fp, " NZ_EVENT_0,");
			    break;
			case 5:
			    fprintf(fp, " NZ_EVENT_1,");
			    break;
			case 6:
			    fprintf(fp, " NZ_YABUSAME,");
			    break;
			case 7:
			    fprintf(fp, " NZ_NONONO,");
			    break;
			case 8:
			    fprintf(fp, " NZ_SENTAKU_2,");
			    break;
			case 9:
			    fprintf(fp, " NZ_SENTAKU_3,");
			    break;
			case 10:
			    fprintf(fp, " NZ_KINSTA,");
			    break;
			case 11:
			    fprintf(fp, " NZ_FISHSZ,");
			    break;
			case 12:
			    fprintf(fp, " NZ_ZELDATM,");
			    break;
			case 20:
			case 21:
			case 22:
			case 23:
			case 24:
			case 25:
			case 26:
			case 27:
			case 28:
			case 29:
			case 30:
			case 31:
			    fprintf(fp, " 0xAA, 0x%02X,", 0x9f + (dt - 20));
			    break;
			default:
			    break;
			}
		    }
		    break;
		default:
		    fprintf(fp, " 0x%02X,", txt_buffer[i]);
		    i += 1;
		    break;
		}
	    }
	    fprintf(fp, " ND_SYURYOU};\n");
	} else {
	    i += 1;
	}
    }

    fclose(fp);
}

/*======================================================================*
 *	�ᥤ��								*
 *======================================================================*/
int main(
    int		argc,
    char	*argv[]
)
{
    FILE	*fp;
    int		i;
    char	name[0x100];
    
    /*ios::sync_with_stdio();*/

    if(argc < 3) {
	printf("��٥�̾�ȳ�����å�����(RTF)����ꤷ�Ƥ�������\n");
	exit(1);
    }

    strcpy(label_name, argv[1]);

    for(i = 2; i < argc; i += 1) {
	if((fp = fopen(argv[i], "r")) == 0) {
	    printf("�ե����뤬�����ץ�Ǥ��ޤ���Ǥ���\n");
	    exit(1);
	}

	strcpy(rtf_buffer_name, argv[i]);
	rtf_buffer_name[strlen(rtf_buffer_name) - 4] = '\0';

	if((rtf_buffer_cnt = fread(rtf_buffer, sizeof(char),
				   RTF_BUFFER + 1, fp)) == RTF_BUFFER + 1) {
	    printf("�ƥ����ȥХåե���­��ޤ���\n");
	    exit(1);
	}

	fclose(fp);
	
	make_color_tbl();
	
	make_txt();
    }

    printf("%s", txt_buffer);

    sprintf(name, "%s_a", label_name);
    make_data1(name);
    sprintf(name, "%s_b", label_name);
    make_data2(name);
    sprintf(name, "%s_c.c", label_name);
    make_data3(name);
}